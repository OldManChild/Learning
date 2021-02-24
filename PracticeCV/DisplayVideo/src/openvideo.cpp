#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

//Remember to run with ./foo


using namespace std;
cv::VideoCapture gCap;
int gSliderPosition = 0;

/*void setTrackbarPosition(int pos, void *)
{
	gCap.set ( cv::CAP_PROP_POS_FRAMES, pos);
}*/

void setTrackbarPosition(int pos, void *)
{
	gSliderPosition = pos;
	gCap.set ( cv::CAP_PROP_POS_FRAMES, pos);
}


int main(int argCount, char** argValues)
{
	
	gCap.open(string(argValues[1]));

	if (!gCap.isOpened())
	{
		cout << "Failed to open the object" << endl;
		return -1;
	}
	else
	{
		int iNoOfFramesInVideo = (int) gCap.get(cv::CAP_PROP_FRAME_COUNT);
		int iFrameWidth = (int) gCap.get(cv::CAP_PROP_FRAME_WIDTH);
		int iFrameHeight = (int) gCap.get(cv::CAP_PROP_FRAME_HEIGHT);

		cout << "Video " << string(argValues[1]) << " has " << iNoOfFramesInVideo 
		<< " frames each with a width of " << iFrameWidth << " and a height of "
		<< iFrameHeight <<"." << endl;
		
		cv::namedWindow("Efua Video", cv::WINDOW_AUTOSIZE );
		cv::createTrackbar("Position","Efua Video",& gSliderPosition,iNoOfFramesInVideo,setTrackbarPosition);

		for(int i=0;i<iNoOfFramesInVideo;i++)
		{
			cv::Mat frame;
			gCap >> frame;
			if (frame.empty() ) break;
			int iCurrentFramePosition = (int) gCap.get(cv::CAP_PROP_POS_FRAMES);
			cv::setTrackbarPos("Position","Efua Video",iCurrentFramePosition);
			cv::imshow("Efua Video", frame);
			if (cv::waitKey(5) >= 0 ) break;
			
		}
	}
	

	gCap.release(); 

	cout << "released the VideoCapture Object without fuss" << endl;

return 0;

} //Last closing brackets


