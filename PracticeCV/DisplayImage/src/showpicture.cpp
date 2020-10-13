#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main( )
{
	Mat img = imread("scones.jpg");
	if (img.empty())
	{
		 cout << "Invalid File Name passed charlie" << endl;
	}
	else
	{
		 cout << "Filename be " << "argv"  << endl;
		return 0;
	}; 
}


