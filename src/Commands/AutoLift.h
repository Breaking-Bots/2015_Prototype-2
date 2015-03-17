#ifndef AutoLift_H
#define AutoLift_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoLift: public CommandBase
{
private:
	F32 m_time;
	F32 m_speed;
	B8 m_isRising;
public:
	AutoLift(F32 time, F32 speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
