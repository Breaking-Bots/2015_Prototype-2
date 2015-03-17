#include "Camera.h"
#include "../Commands/ControlCamera.h"
#include "../RobotMap.h"


Camera::Camera() :
		Subsystem("ExampleSubsystem")
{
	m_servo = new Servo(CAM_SERVO);
}

void Camera::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlCamera());
}

Camera::~Camera() {
	if(m_servo) delete m_servo;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
