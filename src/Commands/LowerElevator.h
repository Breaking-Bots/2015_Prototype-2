#ifndef LOWER_ELEVATOR_H
#define LOWER_ELEVATOR_H

#include "../CommandBase.h"
#include "WPILib.h"

class LowerElevator: public CommandBase
{
public:
	LowerElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
