#include "pch.h"
#include "Utils.h"
#include "cTimer.h"
#pragma once
tuple::tuple() : ms(0), desc(" ") {};
tuple::~tuple() {};
tuple::tuple(float _ms, string _desc) : ms(_ms), desc(_desc) {};
tuple::tuple(const tuple& v) {
	ms = v.ms;
	desc = v.desc;
};
tuple::tuple(tuple& v) {
	ms = v.ms;
	desc = v.desc;
};
tuple& tuple::operator = (const tuple& v) {
	ms = v.ms;
	desc = v.desc;
	return *this;
};
tuple& tuple::operator = (tuple& v) {
	ms = v.ms;
	desc = v.desc;
	return *this;
};

cTimer::cTimer() :
	fr(0),
	t1(0),
	t2(0),
	f1(0),
	f2(0) {
	//c2=c1=0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&fr);
	QueryPerformanceCounter((LARGE_INTEGER*)&f2);
	t1 = t2 = f1 = f2;
	//timers.reserve(1000);
	//FPSs.reserve(1000);
	//framesMS.reserve(1000);

	timers.push_back(tuple(0, "cTimer Startup"));
}
cTimer::~cTimer() {};
void  cTimer::clear() {
	QueryPerformanceFrequency((LARGE_INTEGER*)&fr);
	QueryPerformanceCounter((LARGE_INTEGER*)&f2);
	timers.clear();
	framesMS.clear();
	FPSs.clear();
	t1 = t2 = f1 = f2;
	timers.push_back(tuple(0, "cTimer Restart"));
}

void  cTimer::setTimer(const string& info) {
	t1 = t2;
	QueryPerformanceCounter((LARGE_INTEGER*)&t2);
	if (timers.size() > count1)
		timers.pop_front();
	timers.push_back(tuple(getTimerMS(), info));
}
void  cTimer::setTimer(string info) {
	t1 = t2;
	QueryPerformanceCounter((LARGE_INTEGER*)&t2);
	if (timers.size() > count1)
		timers.pop_front();
	timers.push_back(tuple(getTimerMS(), info));
}
void  cTimer::setTimer(const char* info) {
	t1 = t2;
	QueryPerformanceCounter((LARGE_INTEGER*)&t2);
	if (timers.size() > count1)
		timers.pop_front();
	timers.push_back(tuple(getTimerMS(), info));
}
float cTimer::getTimerMS() {
	return (t2 - t1) * (1000000.0f / fr) / 1000.0f;
}
float cTimer::getTimerS() {
	return (t2 - t1) * (1000000.0f / fr) / 1000000.0f;
}

void  cTimer::setFrameStart() {
	QueryPerformanceCounter((LARGE_INTEGER*)&f1);
	t1 = t2;
	t2 = f1;
	if (timers.size() > count1)
		timers.pop_front();
	timers.push_back(tuple(getTimerMS(), "__________Frame Startup_________"));
}
void  cTimer::setFrameEnd() {
	QueryPerformanceCounter((LARGE_INTEGER*)&f2);
	t1 = t2;
	t2 = f2;
	if (timers.size() > count1)
		timers.pop_front();
	timers.push_back(tuple(getFrameMS(), "__________Frame End_________"));
	if (framesMS.size() > count2)
		framesMS.pop_front();
	framesMS.push_back(getFrameMS());
	if (FPSs.size() > count3)
		FPSs.pop_front();
	FPSs.push_back(getFPS());
}
float cTimer::getFrameMS() {
	LONGLONG t = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&t);
	return (t - f1) * (1000000.0f / fr) / 1000.0f;
}
float cTimer::getFrameS() {
	LONGLONG t = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&t);
	return (t - f1) * (1000000.0f / fr) / 1000000.0f;
}
float cTimer::getFPS() {
	QueryPerformanceCounter((LARGE_INTEGER*)&f2);
	//return (f2 - f1) * (1000000.0f / fr) / 1000.0f;
	return 1.0f / (((f2 - f1) * (1000000.0f / fr)) / 1000000.0f);
}
float cTimer::getMedianFPS(uint number) {
	number =/* min(number, */ (uint)FPSs.size()/*)*/;
	float fps = 0;
	for (float n : FPSs) {
		fps += n;
	}
	//for (uint i = FPSs.size()-1; i > FPSs.size() - number; i--) {
	//	FPSs.
	//	fps += FPSs[i];
	//}
	return fps / number;
}