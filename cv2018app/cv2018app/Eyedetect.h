
#pragma once

#include <iostream>
#include "opencv2\opencv.hpp"

using namespace std;

class Eyedetect {

private:


public:
	Eyedetect();
	~Eyedetect();

	int Init();
	int Detect(cv::Mat in_Img, vector<cv::Rect> &out_Vec);
	int UnInit();

};