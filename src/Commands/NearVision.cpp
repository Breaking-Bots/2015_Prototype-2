#include "NearVision.h"
#include "../MathUtil.h"
#include "../Elon.h"

NearVision::NearVision()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(camera);
}

// Called just before this Command runs the first time
void NearVision::Initialize()
{
	camera->SetPos(CAM_NEAR_POSY());
}

// Called repeatedly when this Command is scheduled to run
void NearVision::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool NearVision::IsFinished()
{
	return EpsilonEquals(CAM_NEAR_POSY(), camera->Pos(), 0.01f);
}

// Called once after isFinished returns true
void NearVision::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void NearVision::Interrupted()
{
}
