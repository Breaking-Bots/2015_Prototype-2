#ifndef NEAR_VISION_5428_H
#define NEAR_VISION_5428_H

#include "../CommandBase.h"
#include "WPILib.h"

class NearVision: public CommandBase
{
public:
	NearVision();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
