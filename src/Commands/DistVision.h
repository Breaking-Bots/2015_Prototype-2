#ifndef DIST_VISION_5428_H
#define DIST_VISION_5428_H

#include "../CommandBase.h"
#include "WPILib.h"

class DistVision: public CommandBase
{
public:
	DistVision();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
