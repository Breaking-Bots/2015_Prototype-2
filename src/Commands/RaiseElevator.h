#ifndef RAISE_ELEVATOR_5428_H
#define RAISE_ELEVATOR_5428_H

#include "../CommandBase.h"
#include "WPILib.h"

class RaiseElevator: public CommandBase
{
public:
	RaiseElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
