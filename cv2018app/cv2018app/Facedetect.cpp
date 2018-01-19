//
#include "Facedetect.h"
#include "opencv2\opencv.hpp"
Facedetect::Facedetect() {

}

Facedetect::~Facedetect() {

}

int Facedetect::Init() {
	cout << "Face Init" << endl;
	return 0;
}

int Facedetect::Detect(cv::Mat in_Img, vector<cv::Rect> &out_Vec) {
	cout << "Face Detect" << endl;
	return 0;
}

int Facedetect::UnInit() {
	cout << "Face UnInit" << endl;
	return 0;
}