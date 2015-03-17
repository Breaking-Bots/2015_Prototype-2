#ifndef FIXED_ELEVATION_5428_H
#define FIXED_ELEVATION_5428_H

#include "../CommandBase.h"
#include "WPILib.h"

class FixedElevation: public CommandBase
{
public:
	FixedElevation();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
