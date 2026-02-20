#include "Header_Files/Timer.h"

void Timer::startTimer()
{
	_start = high_resolution_clock::now();
	_end = high_resolution_clock::now();
}

void Timer::resetTimer()
{
	_start = high_resolution_clock::now();
}

void Timer::stopTimer()
{
	_end = high_resolution_clock::now();

	_deltaTime = duration<float>(_end - _start);
}

float Timer::getTimer() const
{
	return _deltaTime.count();
}
