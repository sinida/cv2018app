#include "header.h"

void main() {


	cv::Mat img;
	img = cv::Mat::ones(cv::Size(100, 100), CV_8UC3);
	//cv::imshow("show a img", img);
	//cv::waitKey(0);

	vector<cv::Rect> facepos_que;
	Facedetect faceDet;
	faceDet.Init();
	faceDet.Detect(img, facepos_que);
	faceDet.UnInit();

	Eyedetect eyeDet;
	eyeDet.Init();
	eyeDet.Detect();
	eyeDet.UnInit();
	
	system("pause");
}