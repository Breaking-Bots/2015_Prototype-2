#include "FixedDeclination.h"
#include "../Elon.h"

FixedDeclination::FixedDeclination()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(elevator);
}

// Called just before this Command runs the first time
void FixedDeclination::Initialize()
{
	SetTimeout(DECLINER_TIME());
}

// Called repeatedly when this Command is scheduled to run
void FixedDeclination::Execute()
{
	elevator->Elevate(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool FixedDeclination::IsFinished()
{
	return IsTimedOut() || IsCanceled();
}

// Called once after isFinished returns true
void FixedDeclination::End()
{
	elevator->Elevate(0.0f);
	elevator->ResetSwitch();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FixedDeclination::Interrupted()
{
	elevator->Elevate(0.0f);
}
