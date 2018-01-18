#include "header.h"

void main() {

	Facedetect faceDet;
	faceDet.Init();
	faceDet.Detect();
	faceDet.UnInit();

	Eyedetect eyeDet;
	eyeDet.Init();
	eyeDet.Detect();
	eyeDet.UnInit();
	
	system("pause");
}