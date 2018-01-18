#pragma once

#include <iostream>

using namespace std;

class Eyedetect {

private:


public:
	Eyedetect();
	~Eyedetect();

	int Init();
	int Detect();
	int UnInit();

};