#include "Elevator.h"
#include "../RobotMap.h"
#include <Victor.h>

Elevator::Elevator() :
		Subsystem("Elevator")
{
	m_victor = new Victor(ELEVATOR);
	m_limitSwitch = new DigitalInput(LIMIT_SWITCH);
	m_counter = new Counter(m_limitSwitch);
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Elevator::Elevate(F32 mgntd) {
	m_victor->Set(mgntd);
}

Elevator::~Elevator() {
	if(m_victor) delete m_victor;
	if(m_limitSwitch) delete m_limitSwitch;
	if(m_counter) delete m_counter;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
