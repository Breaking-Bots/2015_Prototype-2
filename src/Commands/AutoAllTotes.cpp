#include "AutoAllTotes.h"

#include "../Elon.h"
#include "AutoLift.h"

AutoAllTotes::AutoAllTotes()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	AddSequential(new AutoLift(AUTO_TIME_AU1(), AUTO_SPEED_A1()));
	AddSequential(new AutoTurn(90.0f, SPEED_DEFAULT()));
	AddSequential(new AutoBasicRush(AUTO_TIME_AU1(), AUTO_SPEED_A1()));
	AddSequential(new AutoLift(AUTO_TIME_AU1(), AUTO_SPEED_A1()));
}
