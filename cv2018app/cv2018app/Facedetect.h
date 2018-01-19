
#pragma once

#include <iostream>
#include "opencv2\opencv.hpp"

using namespace std;

class Facedetect {

private:


public:
	Facedetect();
	~Facedetect();

	int Init();
	int Detect(cv::Mat in_Img, vector<cv::Rect> &out_Vec);
	int UnInit();

};