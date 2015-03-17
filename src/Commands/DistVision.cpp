#include "DistVision.h"
#include "../MathUtil.h"
#include "../Elon.h"

DistVision::DistVision()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(camera);
}

// Called just before this Command runs the first time
void DistVision::Initialize()
{
	camera->SetPos(CAM_DIST_POSY());
}

// Called repeatedly when this Command is scheduled to run
void DistVision::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool DistVision::IsFinished()
{
	return EpsilonEquals(CAM_DIST_POSY(), camera->Pos(), 0.01f);
}

// Called once after isFinished returns true
void DistVision::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DistVision::Interrupted()
{
}
