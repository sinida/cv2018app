//
#include "Eyedetect.h"

Eyedetect::Eyedetect() {

}

Eyedetect::~Eyedetect() {

}

int Eyedetect::Init() {
	cout << "Eye Init" << endl;
	return 0;
}

int Eyedetect::Detect(cv::Mat in_Img, vector<cv::Rect> &out_Vec) {
	cout << "Eye Detect" << endl;
	return 0;
}

int Eyedetect::UnInit() {
	cout << "Eye UnInit" << endl;
	return 0;
}