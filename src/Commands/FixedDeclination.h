#ifndef FIXED_DECLINATION_5428_H
#define FIXED_DECLINATION_5428_H

#include "../CommandBase.h"
#include "WPILib.h"

class FixedDeclination: public CommandBase
{
public:
	FixedDeclination();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
