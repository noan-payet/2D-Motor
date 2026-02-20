#ifndef TIMER
#define TIMER

#include <chrono>
using namespace std::chrono;

class Timer
{
private:
	duration<float> _deltaTime = duration<float>(0.f);
	time_point<high_resolution_clock> _start, _end;

public:
	Timer() {}

	void startTimer();
	void resetTimer();
	void stopTimer();

	float getTimer() const;
};

#endif // !TIMER