#include "OI.h"
#include "Gamepad.h"
#include "Console.h"
#include "MathUtil.h"
#include "Subsystems/Chassis.h"
#include "CommandBase.h"
#include "Commands/LowerElevator.h"
#include "Commands/RaiseElevator.h"
#include "Commands/FixedElevation.h"
#include "Commands/FixedDeclination.h"
#include "Commands/NearVision.h"
#include "Commands/DistVision.h"

OI::OI()
: m_magnitude(0.0f),
 m_elevatorRate(0.0f), m_disable(true){
	driverCtrl = new Gamepad(0);
	systemCtrl = new Gamepad(1);
}

void OI::Init() {
	if(CONTROLLER_TP()){
		driverCtrl->m_port = 1;
		systemCtrl->m_port = 0;
	}

	driverCtrl->m_deadzone = DEADZONE_GMPD();
	systemCtrl->m_deadzone = DEADZONE_GMPD();

	//TODO: add commands
	driverCtrl->m_bttns[LB].Held(new LowerElevator());
	driverCtrl->m_bttns[RB].Held(new RaiseElevator());
	driverCtrl->m_bttns[L3].Held(new FixedElevation());
	driverCtrl->m_bttns[R3].Held(new FixedDeclination());
	driverCtrl->m_bttns[A].Held(new NearVision());
	driverCtrl->m_bttns[Y].Held(new DistVision());
	systemCtrl->m_bttns[A].Held(new NearVision());
	systemCtrl->m_bttns[Y].Held(new DistVision());
}

void OI::Update() {
	if(driverCtrl->m_bttns[BACK].Get() && !m_disable){
		C::Out("Control Disabled");
		Disable();
	}else if(driverCtrl->m_bttns[START].Get() && m_disable){
		C::Out("Control Enabled");
		Enable();
	}

	m_magnitude = ZaeemMohamedInterpolation(SPEED_MINIMUM(),SPEED_DEFAULT(),SPEED_MAXIMUM(),driverCtrl->T());
	m_elevatorRate = Lerp(SPEED_DEFAULT(), SPEED_MAXIMUM(), NormalizeAlpha(driverCtrl->T()));

	Scheduler::GetInstance()->Run();
	//if(!disable){
	CommandBase::chassis->Update();
	//}else{
	// CommandBase::chassis->RawDrive(0.0f, 0.0f);
	//}
}
