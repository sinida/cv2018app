//
#include "Facedetect.h"
#include "opencv2\opencv.hpp"
Facedetect::Facedetect() {

}

Facedetect::~Facedetect() {

}

int Facedetect::Init() {
	//cout << "Face Init" << endl;
	cv::String face_cascade_name = "model/opencv/haarcascade_frontalface_alt.xml";
	if (!face_cascade.load(face_cascade_name)){ printf("--(!)Error loading - [Face model]\n"); return -1; };
	
	return 0;
}

int Facedetect::Detect(cv::Mat in_img, vector<cv::Rect> &faceRect) {
	//cout << "Face Detect" << endl;


	cv::Mat frame_gray;
	if (in_img.channels() >= 3){
		cv::cvtColor(in_img, frame_gray, CV_BGR2GRAY);
	}
	else{
		frame_gray = in_img.clone();
	}
	cv::equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	face_cascade.detectMultiScale(frame_gray, faceRect, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));

	return 0;
}

int Facedetect::UnInit() {
	cout << "Face UnInit" << endl;
	return 0;
}