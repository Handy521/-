
// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <math.h>

// we can adjust these parameters for different qr code images
#define tol_factor 0.5
#define tol_distance 8

using namespace std;
using namespace cv;

Mat gray_img, bw_img;
Mat src;
int stateCount[5] = { 0 };// store the number of pixels in each state of the state machine
int totalFinderSize;// store the size of the Finder
vector<Point> points_row;// store the possible locations of finders
Point qr_point1; // final finder center locations
Point qr_point2;
Point qr_point3;
Point card1, card2, card3, card4;
Point temppoint;
Point tempswap;
int thresholdValue = 110;//the threshold for each image=============================================================================================

void threshold_selection(int, void*);// by sliding the trackbar to select a good threshold
void qr_find_row();// search finder locations row by row
bool qr_checkRatio();// judge whether a similar pattern is a possible finder or not
void group_points(vector<Point>& points);// find the three largest vote locations in the accumulator array
void draw_crosshair(Point qr_point, Mat src, CvScalar color);// draw a red crosshair on some point of the image


//-----------------------------------------Main Function------------------------------------------------------------------------------
//int _tmain(int argc, char** argv)
int _tmain()
{
	Mat roi_img;
	int a, b,c,d;
	CvScalar red = CV_RGB(255, 0, 0);
	CvScalar white = CV_RGB(255, 255, 255);
	Mat src = imread("1122.png",1);
	//namedWindow("original image", 0);
	//imshow("original image", src);
	namedWindow("original image2", 0);
	cvtColor(src, gray_img, CV_BGR2GRAY);
	threshold_selection(0, 0);
	bw_img = gray_img > thresholdValue;   //bw_img is our final binary image
	qr_find_row();
	group_points(points_row);
	draw_crosshair(qr_point3, src, red);
	draw_crosshair(qr_point2, src, red);
	draw_crosshair(card1, src, white);
	draw_crosshair(card2, src, white);
	draw_crosshair(card3, src, white);
	draw_crosshair(card4, src, white);
	/*line(src, card1, card2, Scalar(255, 255, 255), 1, 8);
	line(src, card1, card3, Scalar(255, 255, 255), 1, 8);
	line(src, card2, card4, Scalar(255, 255, 255), 1, 8);
	line(src, card3, card4, Scalar(255, 255, 255), 1, 8);*/
	if (card1.y < card3.y)
	{
		a = card2.x;
		b = card1.y;
		c = card4.y - card1.y;
		d = card3.x - card2.x;
	}
	else
	{
		a = card1.x;
		b = card3.y;
		c = card2.y - card3.y;
		d = card4.x - card1.x;
	}
	//a = abs(card3.x - card1.x);
	//b = abs(card2.y - card1.y);
	imshow("original image2", src); // display the color qr code image with red crosshairs*/
	//Rect rect(card1.x, card1.y, a, b);
	Rect rect(a, b, d, c);
	src (rect).copyTo(roi_img);
	namedWindow("cut image",0);
	imshow("cut image", roi_img);

	waitKey(0);
	return 0;
}
// use trackbar to get the threshold value
void threshold_selection(int, void*)
{
	threshold(gray_img, bw_img, thresholdValue, 255, 0);
	//imshow("binary image", bw_img);
}



/* search possible qr finder locations row by row
This function goes through every row and keeps a track of the number of white or black
pixels it encounters. It also keeps a track of the order in which they're found. whenever
it founds something like b:w:b:w:b = 1:1:3:1:1, it will put the location of this possible
finder into vector<Point> points_row
*/

void qr_find_row()
{
	int skipRows = 1;
	int currentState = 0;
	int x, y;
	for (int row = skipRows - 1; row< bw_img.rows; row += skipRows)
	{
		stateCount[0] = 0; // inside black pixels
		stateCount[1] = 0; // inside white pixels
		stateCount[2] = 0; // inside black pixels
		stateCount[3] = 0; // inside white pixels
		stateCount[4] = 0; // inside black pixels
		currentState = 0; // record the current state, b,w,b,w,b

		uchar* ptr_row = bw_img.ptr<uchar>(row); // get a pointer to the current row
		for (int col = 0; col< bw_img.cols; col++)
		{
			if (ptr_row[col]<128)
			{
				// we are at a black pixel

				if ((currentState & 0x1) == 1)
				{
					// W->B transition
					currentState++;
				}

				// works for W->B and B->B
				stateCount[currentState]++;
			}
			else
			{
				// we are at a white pixel

				if ((currentState & 0x1) == 1)
				{
					// the current state is state 1 or state 3 (white pixel state)
					// W->W
					stateCount[currentState]++;
				}
				else
				{
					// the current state is state 0, state 2 or state 4 (black pixel state)

					if (currentState == 4)
					{
						// we found the "white" area after one finder pattern
						// use ratio requirement to check whether it is a possible finder or not
						if (qr_checkRatio())
						{
							// ratio is correct, push this possible location into vector
							y = row;
							x = col - totalFinderSize / 2;
							points_row.push_back(Point(x, y));
							currentState = 0;
							stateCount[0] = 0;
							stateCount[1] = 0;
							stateCount[2] = 0;
							stateCount[3] = 0;
							stateCount[4] = 0;
						}
						else
						{
							// ratio is not correct, do the switch
							currentState = 3;
							stateCount[0] = stateCount[2];
							stateCount[1] = stateCount[3];
							stateCount[2] = stateCount[4];
							stateCount[3] = 1;
							stateCount[4] = 0;
						}

					}
					else
					{
						// the current state is state 0 or state 2
						// B->W transition
						currentState++;
						stateCount[currentState]++;
					}
				}
			}
		}
	}
}

// check ratio requirement b:w:b:w:b = 1:1:3:1:1
bool qr_checkRatio()
{
	totalFinderSize = 0;
	for (int i = 0; i<5; i++)
	{
		int count = stateCount[i];
		totalFinderSize += count;
		if (count == 0)
			return false;
	}
	if (totalFinderSize<7)
		return false;

	int moduleSize = ceil(totalFinderSize / 7.0); // scale factor of the finder

	// tolerate some "slop" of the ratio
	double maxVariance = moduleSize*tol_factor;
	bool retVal = ((abs(moduleSize - (stateCount[0]))< maxVariance) &&
		(abs(moduleSize - (stateCount[1]))< maxVariance) &&
		(abs(3 * moduleSize - (stateCount[2]))< 3 * maxVariance) &&
		(abs(moduleSize - (stateCount[3]))< maxVariance) &&
		(abs(moduleSize - (stateCount[4]))< maxVariance));

	return retVal;
}

/* group possible finder locations, that is, each location vote in an array, so that
we can find three largest votes, calculate the mean location of these three groups and
finally draw them on the image
*/
void group_points(vector<Point>& points)
{

	CvScalar red = CV_RGB(255, 0, 0);
	CvScalar white = CV_RGB(255, 255, 255);
	

	/* if the size of vector, number of possible finder locations is greater than 3,
	we need to group them. if not, then just draw them on the image
	*/
	if (points.size() >= 3)
	{
		double distance;
		vector<vector<Point>> group(points.size());// every vector stores the finder locations which belong to one group
		vector<int> score(points.size());// store the number of votes
		vector<int> score_index(points.size());// store the index of score when we sort the score
		int temp1;
		int temp2;
		double perpixel,cta;
		 
		// set values for score_index
		for (size_t k = 0; k < points.size(); ++k)
		{
			score_index[k] = k;
		}
		/* group the points by distance
		check whether point i is near enough to point j (j<i), if so, then vote for j.
		No matter whether i is near to j or not, it will vote for itself
		*/
		for (size_t i = 0; i < points.size(); ++i)
		{
			for (size_t j = 0; j < i; ++j)
			{
				distance = sqrt(double((points[i].x - points[j].x)*(points[i].x - points[j].x) + (points[i].y - points[j].y)*(points[i].y - points[j].y)));
				if (distance < tol_distance)
				{
					score[j] += 1;
					group[j].push_back(points[i]);
					break;
				}
			}
			score[i] += 1;
			group[i].push_back(points[i]);
		}
		// sort the score and write new index into score_index
		for (size_t m = 0; m < points.size() - 1; ++m)
		{
			for (size_t n = m; n < points.size(); ++n)
			{
				if (score[m] <= score[n])
				{
					temp1 = score_index[m];
					score_index[m] = score_index[n];
					score_index[n] = temp1;
					temp2 = score[m];
					score[m] = score[n];
					score[n] = temp2;
				}
			}
		}

		// calculate the mean location of three groups with largest votes
		vector<Point>::iterator it;
		for (it = group[score_index[0]].begin(); it != group[score_index[0]].end(); ++it)
		{
			qr_point1 += (*it);
		}
		qr_point1.x = qr_point1.x / score[0];
		qr_point1.y = qr_point1.y / score[0];

		for (it = group[score_index[1]].begin(); it != group[score_index[1]].end(); ++it)
		{
			qr_point2 += (*it);
		}
		qr_point2.x = qr_point2.x / score[1];
		qr_point2.y = qr_point2.y / score[1];

		for (it = group[score_index[2]].begin(); it != group[score_index[2]].end(); ++it)
		{
			qr_point3 += (*it);
		}
		qr_point3.x = qr_point3.x / score[2];
		qr_point3.y = qr_point3.y / score[2];
		//handy find colorcard location
		perpixel = sqrt(pow ((qr_point2.x - qr_point3.x),2)+ pow((qr_point2.y - qr_point3.y),2))/2.4;
		if (qr_point2.x <qr_point3.x)
		{
			 tempswap= qr_point2;		 
			 qr_point2 = qr_point3;	
			 qr_point3 = tempswap;
		}
			temppoint.x = (qr_point2.x - qr_point3.x) / 3 + qr_point3.x;
			temppoint.y = (qr_point2.y - qr_point3.y) / 3 + qr_point3.y;
			cta  = atan2(qr_point2.y - qr_point3.y , qr_point2.x - qr_point3.x);		 
			card1.x = temppoint.x-3.6*sin(cta)*perpixel;
			card1.y = 3.6*cos(cta)*perpixel + temppoint.y;
			card2.x = card1.x - 1.8*sin(cta)*perpixel;
			card2.y = card1.y + 1.8*cos(cta)*perpixel; 
			card3.x = card1.x + 18.2 * perpixel*cos(cta);
			card3.y = card1.y + 18.2 * perpixel*sin(cta);
			card4.x = card2.x + 18.2 * perpixel*cos(cta);
			card4.y = card2.y + 18.2 * perpixel*sin(cta);
		// output the final finder center location      
		cout << "QR左上角坐标:"<<qr_point3 << endl;
		cout << "QR右上角坐标:"<<qr_point2 << endl; 
		cout << "第一色卡坐标:"<<card1 << endl;
		/*draw_crosshair(qr_point3, src, red);   
		draw_crosshair(qr_point2, src, red);
		draw_crosshair(card1 , src, white);
		draw_crosshair(card2, src, white);
		draw_crosshair(card3, src, white);
		draw_crosshair(card4, src, white);
		line(src, card1, card2, Scalar(255,255,255), 2, 8);
		line(src, card1, card3, Scalar(255, 255, 255), 2, 8);
		line(src, card2, card4, Scalar(255, 255, 255), 2, 8);
		line(src, card3, card4, Scalar(255, 255, 255), 2, 8);*/
	}
	else
	{
		for (int v = 0; v < points.size(); ++v)
		{
			draw_crosshair(points[v], src, red);
		}
	}

}


//draw a red crosshair on some point of the image
void draw_crosshair(Point qr_point, Mat src, CvScalar color)
{
	Point up1, up2;
	up1.x = qr_point.x;
	up1.y = qr_point.y - 2;
	up2.x = qr_point.x;
	up2.y = qr_point.y + 2;
	Point down1, down2;
	down1.x = qr_point.x - 2;
	down1.y = qr_point.y;
	down2.x = qr_point.x + 2;
	down2.y = qr_point.y;
	// draw two lines that intersects on qr_point
	line(src, up1, up2, color, 4, 8);
	line(src, down1, down2, color, 4, 8); 
}



