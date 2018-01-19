#include "header.h"

void main() {


	cv::Mat img;
	img = cv::Mat::ones(cv::Size(100, 100), CV_8UC3);
	//cv::imshow("show a img", img);
	//cv::waitKey(0);

	vector<cv::Rect> faceXY_que;
	Facedetect faceDet;
	faceDet.Init();
	faceDet.Detect(img, faceXY_que);
	faceDet.UnInit();

	vector<cv::Rect> eyeXY_que;
	Eyedetect eyeDet;
	eyeDet.Init();
	eyeDet.Detect(img, eyeXY_que);
	eyeDet.UnInit();
	

	Facerecognition faceID;
	faceID.Init();
	faceID.UnInit();

	Eyerecognition eyeID;
	eyeID.Init();
	eyeID.UnInit();


	system("pause");
}