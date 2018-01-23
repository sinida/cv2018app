//#include "header.h"
//
//void main() {
//
//
//	cv::Mat img;
//	img = cv::Mat::ones(cv::Size(100, 100), CV_8UC3);
//	//cv::imshow("show a img", img);
//	//cv::waitKey(0);
//
//	vector<cv::Rect> faceXY_que;
//	Facedetect faceDet;
//	faceDet.Init();
//	faceDet.Detect(img, faceXY_que);
//	faceDet.UnInit();
//
//	vector<cv::Rect> eyeXY_que;
//	Eyedetect eyeDet;
//	eyeDet.Init();
//	eyeDet.Detect(img, eyeXY_que);
//	eyeDet.UnInit();
//	
//
//	Facerecognition faceID;
//	faceID.Init();
//	faceID.UnInit();
//
//	Eyerecognition eyeID;
//	eyeID.Init();
//	eyeID.UnInit();
//
//
//	system("pause");
//}


#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
//using namespace cv;

int facedetect(cv::Mat in_img, std::vector<cv::Rect> &faceRect){

	cv::String face_cascade_name = "model/opencv/haarcascade_frontalface_alt.xml";
	cv::CascadeClassifier face_cascade;
	if (!face_cascade.load(face_cascade_name)){ printf("--(!)Error loading - [Face model]\n"); return -1; };

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

int face_draw(std::vector<cv::Rect> faceRect, cv::Mat &out_img){
	
	for (size_t i = 0; i < faceRect.size(); i++){
		cv::Point center(faceRect[i].x + faceRect[i].width*0.5, faceRect[i].y + faceRect[i].height*0.5);
		cv::ellipse(out_img, center, cv::Size(faceRect[i].width*0.5, faceRect[i].height*0.5), 0, 0, 360, cv::Scalar(255, 0, 255), 4, 8, 0);
	
	}
	return 0;
}

int eyedetect(cv::Mat in_img, std::vector<cv::Rect> &eyeRect){
	cv::String eyes_cascade_name = "model/opencv/haarcascade_eye_tree_eyeglasses.xml";
	cv::CascadeClassifier eyes_cascade;
	if (!eyes_cascade.load(eyes_cascade_name)){ printf("--(!)Error loading-[eye model]\n"); return -1; };
	//-- In each face, detect eyes
	eyes_cascade.detectMultiScale(in_img, eyeRect, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));

	return 0;
}

int eye_draw(std::vector<cv::Rect> eyeRect, cv::Mat &out_img){
	for (size_t j = 0; j < eyeRect.size(); j++)
	{
		cv::Point center(eyeRect[j].x + eyeRect[j].width*0.5, eyeRect[j].y + eyeRect[j].height*0.5);
		int radius = cvRound((eyeRect[j].width + eyeRect[j].height)*0.25);
		circle(out_img, center, radius, cv::Scalar(255, 0, 0), 4, 8, 0);
	}
	return 0;
}

/** @function main */
int main(int argc, const char** argv)
{

	cv::Mat frame;
	//-- 2. Read the video stream

	frame = cv::imread("Imagedata/facetest.jpg", 1);


	//-- 3. Apply the classifier to the frame
	if (!frame.empty())
	{
		//detectAndDisplay(frame);
		vector<cv::Rect> face_rect, eye_rect;
		facedetect(frame, face_rect);
		eyedetect(frame, eye_rect);
		face_draw(face_rect, frame);
		eye_draw(eye_rect, frame);
	}
	else
	{
		printf(" --(!) No captured frame -- Break!");
	}
	cv::imshow("A Face image", frame);
	cv::waitKey(0);

	return 0;
}
