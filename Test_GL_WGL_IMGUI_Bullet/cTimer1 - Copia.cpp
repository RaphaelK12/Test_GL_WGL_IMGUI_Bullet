#include "pch.h"
#include "Utils.h"
#include "cTimer1 - Copia.h"
#pragma once
cTimer1::cTimer1() :
	fr(0),
	c1(0),
	c2(0)
{
	//c2=c1=0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&fr);
	QueryPerformanceCounter((LARGE_INTEGER*)&c1);
	c2 = c1;
}

cTimer1::~cTimer1() {};

void cTimer1::reset() {
	QueryPerformanceFrequency((LARGE_INTEGER*)&fr);
	QueryPerformanceCounter((LARGE_INTEGER*)&c1);
	c2 = c1;

}

LONGLONG cTimer1 :: get() {
	set();
	return c2 - c1;
}

float cTimer1 :: getns() {
	set();
	return (c2 - c1) * (1000000.0f / fr);
}

float cTimer1 :: getms() {
	set();
	return (c2 - c1) * (1000000.0f / fr) / 1000.0f;
}

float cTimer1 :: gets() {
	set();
	return (c2 - c1) * (1000000.0f / fr) / 1000000.0f;
}

double cTimer1 :: getdns() {
	return double((c2 - c1) * (1000000.0 / fr));
}

double cTimer1 :: getdms() {
	return double((c2 - c1) * (1000000.0 / fr) / 1000.0);
}

double cTimer1:: getds() {
	return double((c2 - c1) * (1000000.0 / fr) / 1000000.0);
}

void cTimer1 :: set() {
	QueryPerformanceFrequency((LARGE_INTEGER*)&fr);
	QueryPerformanceCounter((LARGE_INTEGER*)&c2);

}

float cTimer1 :: getFPS() {
	return 1.0f / (getns() / 1000000.0f);
}

float cTimer1 :: FPS() {
	set();
	return 1.0f / (getns() / 1000000.0f);
}
	
