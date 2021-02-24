#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>


int main(int argCount, char** argValues)
{
	
	cv::Mat imageParameter = cv::imread(argValues[1], -1);
	cv::Mat image2Output ;

	cv::namedWindow ("InputImage",cv::WINDOW_AUTOSIZE);
	cv::namedWindow ("OutputImage",cv::WINDOW_AUTOSIZE);

	cv::imshow("InputImage", imageParameter);
	cv::medianBlur(imageParameter,image2Output,5);
	cv::medianBlur(image2Output,image2Output,5);
	cv::imshow("OutputImage", image2Output);

	cv::waitKey(0);
	return 0;

} //Last closing brackets


