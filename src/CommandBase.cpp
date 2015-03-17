#include "CommandBase.h"
#include <Commands/Scheduler.h>
#include "Console.h"

// Initialize a single static instance of all of your subsystems to NULL

OI* CommandBase::oi = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{
}

void CommandBase::Init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	chassis = new Chassis();
	elevator = new Elevator();
	camera = new Camera();

	oi = OI::GetInstance();
	C::Out("CommandBase Initialized!");
}
