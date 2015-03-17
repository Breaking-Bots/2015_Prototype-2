#include "ControlCamera.h"

ControlCamera::ControlCamera()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(camera);
}

// Called just before this Command runs the first time
void ControlCamera::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlCamera::Execute()
{
	if(oi->driverCtrl->GetPOV() == 0)
		camera->Orient(CAM_PAN_SPEED());
	else if(oi->driverCtrl->GetPOV() == 180)
		camera->Orient(-CAM_PAN_SPEED());

	camera->Orient(CAM_PAN_SPEED() * -oi->systemCtrl->RY());
}

// Make this return true when this Command no longer needs to run execute()
bool ControlCamera::IsFinished()
{
	return IsCanceled();
}

// Called once after isFinished returns true
void ControlCamera::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlCamera::Interrupted()
{

}
