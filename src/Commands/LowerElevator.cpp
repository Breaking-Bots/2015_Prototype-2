#include "LowerElevator.h"

LowerElevator::LowerElevator()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(elevator);
}

// Called just before this Command runs the first time
void LowerElevator::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void LowerElevator::Execute()
{
	elevator->Elevate(-oi->ElvRt());
}

// Make this return true when this Command no longer needs to run execute()
bool LowerElevator::IsFinished()
{
	return IsCanceled();
}

// Called once after isFinished returns true
void LowerElevator::End()
{
	elevator->Elevate(0.0f);
	elevator->ResetSwitch();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerElevator::Interrupted()
{
	elevator->Elevate(0.0f);
}
