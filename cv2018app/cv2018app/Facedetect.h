
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "opencv2\opencv.hpp"

using namespace std;

class Facedetect {

private:
	cv::CascadeClassifier face_cascade;

public:
	Facedetect();
	~Facedetect();

	int Init();
	int Detect(cv::Mat in_Img, vector<cv::Rect> &out_Vec);
	int UnInit();

};