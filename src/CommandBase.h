#ifndef COMMAND_BASE_5428_H
#define COMMAND_BASE_5428_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Camera.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	// Create a single static instance of all of your subsystems

	glob OI *oi;
	glob Chassis* chassis;
	glob Elevator* elevator;
	glob Camera* camera;

	CommandBase(char const *name);
	CommandBase();

	glob void Init();

};

#endif
