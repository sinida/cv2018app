//
#include "Eyedetect.h"

Eyedetect::Eyedetect() {

}

Eyedetect::~Eyedetect() {

}

int Eyedetect::Init() {
	//cout << "Eye Init" << endl;
	cv::String eyes_cascade_name = "model/opencv/haarcascade_eye_tree_eyeglasses.xml";
	if (!eyes_cascade.load(eyes_cascade_name)){ printf("--(!)Error loading-[eye model]\n"); return -1; };
	return 0;
}

int Eyedetect::Detect(cv::Mat in_img, vector<cv::Rect> &eyeRect) {
	//cout << "Eye Detect" << endl;
	eyes_cascade.detectMultiScale(in_img, eyeRect, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
	return 0;
}

int Eyedetect::UnInit() {
	cout << "Eye UnInit" << endl;
	return 0;
}