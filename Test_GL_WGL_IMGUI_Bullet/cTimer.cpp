#include "pch.h"
#include "Utils.h"
#include "cTimer.h"
#pragma once
tuple::tuple() : st(0), fps(0), desc(" ") {};
tuple::~tuple() {};
tuple::tuple(LONGLONG _st, float _fps, string _desc) : st(_st), fps(_fps), desc(_desc) {};
tuple::tuple(const tuple& v) {
	st = v.st;
	fps = v.fps;
	desc = v.desc;
};
tuple::tuple(tuple& v) {
	st = v.st;
	fps = v.fps;
	desc = v.desc;
};
tuple& tuple::operator = (const tuple& v) {
	st = v.st;
	fps = v.fps;
	desc = v.desc;
	return *this;
};
tuple& tuple::operator = (tuple& v) {
	st = v.st;
	fps = v.fps;
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

	timers.push_back(tuple(f1, 0, "cTimer Startup"));
}
cTimer::~cTimer() {};
void  cTimer::clear() {
	QueryPerformanceFrequency((LARGE_INTEGER*)&fr);
	QueryPerformanceCounter((LARGE_INTEGER*)&f2);
	timers.clear();
	framesMS.clear();
	FPSs.clear();
	t1 = t2 = f1 = f2;
	timers.push_back(tuple(f1, 0,"cTimer Restart"));
}

void  cTimer::setTimer(const string& info) {
	t1 = t2;
	QueryPerformanceCounter((LARGE_INTEGER*)&t2);
	if (timers.size() > count1)
		timers.pop_front();
	timers.push_back(tuple(t2, getTimerMS(),  info));
}
void  cTimer::setTimer(string info) {
	t1 = t2;
	QueryPerformanceCounter((LARGE_INTEGER*)&t2);
	if (timers.size() > count1)
		timers.pop_front();
	timers.push_back(tuple(t2, getTimerMS(), info));
}
void  cTimer::setTimer(const char* info) {
	t1 = t2;
	QueryPerformanceCounter((LARGE_INTEGER*)&t2);
	if (timers.size() > count1)
		timers.pop_front();
	timers.push_back(tuple(t2, getTimerMS(), info));
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
	timers.push_back(tuple(f1, getTimerMS(),"Frame Startup"));
}
void  cTimer::setFrameEnd() {
	QueryPerformanceCounter((LARGE_INTEGER*)&f2);
	t1 = t2;
	t2 = f2;
	if (timers.size() > count1)
		timers.pop_front();
	timers.push_back(tuple(f2, getFrameMS(),  "__________Frame End_________"));
	if (framesMS.size() > count2)
		framesMS.pop_front();
	framesMS.push_back( getFrameMS());
	if (FPSs.size() > count3)
		FPSs.pop_front();
	FPSs.push_back(getFPS());
}
float cTimer::getFrameMS(){
	LONGLONG t=0;
	QueryPerformanceCounter((LARGE_INTEGER*)&t);
	return (t - f1) * (1000000.0f / fr) / 1000.0f;
}
float cTimer::getFrameS (){
	LONGLONG t=0;
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
	
