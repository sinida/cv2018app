#pragma once

#include <iostream>
#include "opencv2\opencv.hpp"

using namespace std;

class Eyerecognition {

private:


public:
	Eyerecognition();
	~Eyerecognition();

	int Init();

	/** Enroll(cv::Mat in_Img, cv::Rect in_Rect, std::string in_ID)
	\in_Img: input a image
	\in_Rect: object position
	\out_ID: assign a ID number to object
	\ return flag: 0: error, 1: success
	*/
	int Enroll(cv::Mat in_Img, cv::Rect in_Rect, int &out_ID);

	/** Matching(cv::Mat in_Img, cv::Rect in_Rect)
	\in_Img: input a image
	\in_Rect: object position
	\ return match ID number
	*/
	int Matching(cv::Mat in_Img, cv::Rect in_Rect);

	int UnInit();

};