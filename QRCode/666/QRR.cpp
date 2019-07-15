
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

int thresholdValue = 110;//the threshold for each image=============================================================================================

void threshold_selection(int, void*);// by sliding the trackbar to select a good threshold
void qr_find_row();// search finder locations row by row
void qr_find_col();// search finder locations column by column
bool qr_checkRatio();// judge whether a similar pattern is a possible finder or not
void group_points(vector<Point>& points);// find the three largest vote locations in the accumulator array
void draw_crosshair(Point qr_point, Mat src, CvScalar color);// draw a red crosshair on some point of the image
void affine_trans(); // through affine transformation to create a normalized version of each image 

//-----------------------------------------Main Function------------------------------------------------------------------------------
int _tmain(int argc, char** argv)
{

	// read a color qr code image which is used to display the red crosshairs(detected finder locations) and green crosshairs(manually marked finder locations)
	const char* imagename = "1111.jpg";
	src = imread(imagename, 1);
	namedWindow("original image", CV_WINDOW_AUTOSIZE);
	imshow("original image", src);

	// convert the color image into gray image
	cvtColor(src, gray_img, CV_BGR2GRAY);

	// slide the threshold value trackbar to observe the binary image until the finder locations in the binary image are clear, then we get a good threshold value
	namedWindow("binary image", CV_WINDOW_AUTOSIZE);
	createTrackbar("threshold value", "binary image", &thresholdValue, 255, threshold_selection);
	threshold_selection(0, 0);
	bw_img = gray_img > thresholdValue; //bw_img is our final binary image

	//cout<<"press c to continue after choosing a threshold"<<endl;
	//char c;
	/*while(1)
	{
	c = waitKey(0);
	if(c =='c') break;
	}*/

	// detect qr code finders and mark finder centers as red crosshairs
	qr_find_row();
	//qr_find_col();
	group_points(points_row);
	imshow("original image", src); // display the color qr code image with red crosshairs

	//determine an affine mapping from the detected mark locations to predefined locations and use this mapping to create a normalized image 
	//affine_trans();

	// wait for any key to quit
	waitKey(0);

	// release memory for images and destroy windows
	src.release();
	gray_img.release();
	bw_img.release();
	cvDestroyWindow("original image");
	cvDestroyWindow("binary image");

	return 0;

}
//-----------------------------------------------------------------------------------------------------------------------------------

// use trackbar to get the threshold value
void threshold_selection(int, void*)
{
	threshold(gray_img, bw_img, thresholdValue, 255, 0);
	imshow("binary image", bw_img);
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


/* search possible qr finder locations column by column
This function is similar to qr_find_row(). And the possible finder locations are
still pushed into vector points_row
*/
void qr_find_col()
{
	int skipCols = 1;
	int currentState = 0;
	int x, y;
	for (int col = skipCols - 1; col< bw_img.cols; col += skipCols)
	{
		stateCount[0] = 0;
		stateCount[1] = 0;
		stateCount[2] = 0;
		stateCount[3] = 0;
		stateCount[4] = 0;
		currentState = 0;

		uchar* ptr_col = bw_img.ptr<uchar>(col);
		for (int row = 0; row< bw_img.rows; row++)
		{
			if (ptr_col[row]<128)
			{
				if ((currentState & 0x1) == 1)
				{
					currentState++;
				}
				stateCount[currentState]++;
			}
			else
			{
				if ((currentState & 0x1) == 1)
				{
					stateCount[currentState]++;
				}
				else
				{
					if (currentState == 4)
					{
						if (qr_checkRatio())
						{
							y = row - totalFinderSize / 2;;
							x = col;
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

		// output the final finder center location      
		cout << qr_point1 << endl;
		cout << qr_point2 << endl;
		cout << qr_point3 << endl;
		draw_crosshair(qr_point1, src, red);
		draw_crosshair(qr_point2, src, red);
		draw_crosshair(qr_point3, src, red);
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
	line(src, up1, up2, color, 1, 8);
	line(src, down1, down2, color, 1, 8);
}


void affine_trans()
{
	Point2f srcPoints[3];
	Point2f dstPoints[3];

	Mat mapping(2, 3, CV_32FC1);
	Mat src_img, wrap_dst_img;
	src_img = imread("1.jpg", 1);//for final affine transform result because src has red crosshairs now
	wrap_dst_img = Mat::zeros(700, 700, CV_8UC3); // create an output image of size 700*700 and 24-bit color

	//set detected mark locations 
	srcPoints[0] = qr_point1;
	srcPoints[1] = qr_point2;;
	srcPoints[2] = qr_point3;
	cout << "original finder locations" << endl;
	cout << srcPoints[0] << '\n' << srcPoints[1] << '\n' << srcPoints[2] << endl;

	//decide which one is finder mark location 1
	double diffx0, diffy0, diffx1, diffy1, diffx2, diffy2;
	diffx0 = srcPoints[0].x - srcPoints[1].x;
	diffy0 = srcPoints[0].y - srcPoints[1].y;
	diffx1 = srcPoints[1].x - srcPoints[2].x;
	diffy1 = srcPoints[1].y - srcPoints[2].y;
	diffx2 = srcPoints[2].x - srcPoints[0].x;
	diffy2 = srcPoints[2].y - srcPoints[0].y;

	//use cos(theta)=<x,y>/(|x||y|) to calculate angle
	double norm[3];
	norm[0] = sqrt(diffx0*diffx0 + diffy0*diffy0);
	norm[1] = sqrt(diffx1*diffx1 + diffy1*diffy1);
	norm[2] = sqrt(diffx2*diffx2 + diffy2*diffy2);

	double angle[3];
	angle[0] = acos((-diffx0*diffx2 - diffy0*diffy2) / (norm[0] * norm[2]));
	angle[1] = acos((-diffx0*diffx1 - diffy0*diffy1) / (norm[0] * norm[1]));
	angle[2] = acos((-diffx2*diffx1 - diffy2*diffy1) / (norm[2] * norm[1]));
	cout << "angles between any two of the three edges" << endl;
	cout << angle[0] << '\n' << angle[1] << '\n' << angle[2] << endl;


	Point2f temp;
	if ((angle[1]>angle[0]) && (angle[1]>angle[2]))
	{
		temp = srcPoints[0];
		srcPoints[0] = srcPoints[1];
		srcPoints[1] = temp;
	}
	else if ((angle[2]>angle[1]) && (angle[2]>angle[0]))
	{
		temp = srcPoints[0];
		srcPoints[0] = srcPoints[2];
		srcPoints[2] = temp;
	}

	//decide which one is finder mark location 2 and finder mark location 3
	//note in the example of assignment 3, direction from vector 12 to vector 13 is clockwise
	diffx0 = srcPoints[1].x - srcPoints[0].x;
	diffy0 = srcPoints[1].y - srcPoints[0].y;
	diffx2 = srcPoints[2].x - srcPoints[0].x;
	diffy2 = srcPoints[2].y - srcPoints[0].y;

	double det = diffx0*diffy2 - diffy0*diffx2;
	if (det<0)
	{
		temp = srcPoints[1];
		srcPoints[1] = srcPoints[2];
		srcPoints[2] = temp;
	}

	cout << "final ordered finder locations" << endl;
	cout << srcPoints[0] << '\n' << srcPoints[1] << '\n' << srcPoints[2] << endl;

	//set 3 predefined output locations
	dstPoints[0] = Point2f(400, 50);
	dstPoints[1] = Point2f(600, 50);
	dstPoints[2] = Point2f(400, 250);

	//get the Affine Transform
	mapping = getAffineTransform(srcPoints, dstPoints);
	cout << "mapping = " << mapping << endl;

	//check whether the mapping is correct or not
	cout << "test the mapping is correct or not" << endl;
	Point2f test;
	for (int i = 0; i < 3; i++)
	{
		double* ptr_row = mapping.ptr<double>(0);
		//cout<<ptr_row[0]<<endl;
		test.x = (ptr_row[0] * srcPoints[i].x + ptr_row[1] * srcPoints[i].y + ptr_row[2] * 1);
		ptr_row = mapping.ptr<double>(1);
		test.y = (ptr_row[0] * srcPoints[i].x + ptr_row[1] * srcPoints[i].y + ptr_row[2] * 1);
		cout << test << endl;
	}

	//apply the Affine Transform just found to the src_img
	warpAffine(src_img, wrap_dst_img, mapping, wrap_dst_img.size());
	imwrite("1.normalized.jpg", wrap_dst_img);

	//display the normalized version of each image
	namedWindow("transform image", CV_WINDOW_AUTOSIZE);
	imshow("transform image", wrap_dst_img);

	wrap_dst_img.release();
	src_img.release();
}