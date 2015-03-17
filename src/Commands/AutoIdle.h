#ifndef AutoIdle_H
#define AutoIdle_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoIdle: public CommandBase
{
public:
	AutoIdle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
