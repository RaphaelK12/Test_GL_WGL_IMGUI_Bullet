#pragma once
//typedef std::tuple< LONGLONG, float, string> tuple;
class tuple {
public:
	tuple();
	~tuple();
	tuple(float _ms, string _desc);
	tuple& operator = (tuple& v);
	tuple& operator = (const tuple& v);
	tuple(tuple& v);
	tuple(const tuple& v);

	float ms;
	string desc;
};

class cTimer {
public:
	//std::vector<tuple>& frame;
	//std::list<std::vector<tuple>> timers;

	std::list<tuple> timers;

	std::list<float> FPSs;
	std::list<float> framesMS;
	LONGLONG fr; // processador frequencia
	LONGLONG t1; // timer1
	LONGLONG t2; // timer2
	LONGLONG f1; // counter1
	LONGLONG f2; // counter2
	static const int count1 = 1000;
	static const int count2 = 100;
	static const int count3 = 100;
	cTimer();
	~cTimer();
	void   clear();

	void   setTimer(const string& info);
	void   setTimer(string info);
	void   setTimer(const char* info);
	float  getTimerMS();
	float  getTimerS();

	void   setFrameStart();
	void   setFrameEnd();
	float  getFrameMS();
	float  getFrameS();
	float  getFPS();
	float  getMedianFPS(uint number);
};
