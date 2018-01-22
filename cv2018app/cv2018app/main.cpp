#include "header.h"

int face_draw(std::vector<cv::Rect> faceRect, cv::Mat &out_img){

	for (size_t i = 0; i < faceRect.size(); i++){
		cv::Point center(faceRect[i].x + faceRect[i].width*0.5, faceRect[i].y + faceRect[i].height*0.5);
		cv::ellipse(out_img, center, cv::Size(faceRect[i].width*0.5, faceRect[i].height*0.5), 0, 0, 360, cv::Scalar(255, 0, 255), 4, 8, 0);

	}
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

void main() {

	cv::Mat img;
	img = cv::imread("Imagedata/facetest.jpg", 1);

	Facedetect faceDet;
	Eyedetect eyeDet;
	Facerecognition faceID;
	Eyerecognition eyeID;

	//-- 3. Apply the classifier to the frame
	if (!img.empty())
	{
		//-- Face detection
		vector<cv::Rect> faceXY_que;
		faceDet.Init();
		faceDet.Detect(img, faceXY_que);


		////-- Eye detection
		//vector<cv::Rect> eyeXY_que;
		//eyeDet.Init();
		//eyeDet.Detect(img, eyeXY_que);
		//cout << "img eye detect:" << eyeXY_que.size() << endl;

		//-- Draw face and eye position
		face_draw(faceXY_que, img);
		//eye_draw(eyeXY_que, img);


		//-- Face recognition
		faceID.Init();
		
		////-- Eye recognition
		//eyeID.Init();

		cv::imshow("A Face image", img);
		cv::waitKey(0);
	}
	else
	{
		printf(" --(!) No captured image ! --");
	}

	
	
	faceDet.UnInit();
	eyeDet.UnInit();
	faceID.UnInit();
	eyeID.UnInit();


}
