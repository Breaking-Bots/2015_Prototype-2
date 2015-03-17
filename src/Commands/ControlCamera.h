#ifndef ControlCamera_H
#define ControlCamera_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlCamera: public CommandBase
{
public:
	ControlCamera();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
