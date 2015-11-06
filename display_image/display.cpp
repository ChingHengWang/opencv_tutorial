#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;



int main(int argc,char** argv)
{


	Mat image =imread("me.jpg");
	
	namedWindow("Display Image",WINDOW_AUTOSIZE);
	imshow("Display",image);
        imwrite("qq.jpg",image);
	waitKey(0);
	return 0;


}


