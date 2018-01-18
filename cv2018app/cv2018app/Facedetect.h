
#pragma once

#include <iostream>

using namespace std;

class Facedetect {

private:


public:
	Facedetect();
	~Facedetect();

	int Init();
	int Detect();
	int UnInit();

};