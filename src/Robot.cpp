#include "WPILib.h"
#include "Preferences.h"
#include "Elon.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "OI.h"
#include "Typedefs_5428.h"
#include "Vision.h"

//TODO: IMPORTANT: CHECK GYRO AND PID CONTROL

glob const I32 dVISIONQUALITY = 0000000031;
glob const I32 dCONTROLLER_TP = 0000000000;
glob const F32 dSPEED_MINIMUM = 0.30000000;
glob const F32 dSPEED_DEFAULT = 0.65000000;
glob const F32 dSPEED_MAXIMUM = 1.00000000;
glob const F32 dAUTO_DRV_TIME = 6.00000000;
glob const F32 dAUTO_TIME_AU1 = 6.00000000;
glob const F32 dAUTO_TIME_AU2 = 6.00000000;
glob const F32 dAUTO_TIME_AU3 = 6.00000000;
glob const F32 dAUTO_TIME_AU4 = 6.00000000;
glob const F32 dAUTO_TIME_AU5 = 6.00000000;
glob const F32 dAUTO_TIME_AU6 = 0.65000000;
glob const F32 dAUTO_SPEED_A1 = 6.00000000;
glob const F32 dAUTO_SPEED_A2 = 6.00000000;
glob const F32 dAUTO_SPEED_A3 = 6.00000000;
glob const F32 dAUTO_SPEED_A4 = 6.00000000;
glob const F32 dAUTO_SPEED_A5 = 6.00000000;
glob const F32 dAUTO_SPEED_A6 = 6.00000000;
glob const F32 dDRIVE_TRAIN_P = 1.00000000;
glob const F32 dDRIVE_TRAIN_I = 0.00000000;
glob const F32 dDRIVE_TRAIN_D = 0.00000000;
glob const F32 dDRIVE_TRAIN_A = 0.00000000;
glob const F32 dDRIVE_TRAIN_K = 1.00000000;
glob const F32 dELEVATOR_TIME = 1.40000000;
glob const F32 dDECLINER_TIME = 0.35000000;
glob const F32 dCAM_NEAR_POSY = 0.32050000;
glob const F32 dCAM_DIST_POSY = 0.59880000;
glob const F32 dCAM_PAN_SPEED = 2.50000000;
glob const F32 dDEADZONE_GMPD = 0.20000000;
glob I32 vVISIONQUALITY  =  dVISIONQUALITY;
glob I32 vCONTROLLER_TP  =  dCONTROLLER_TP;
glob F32 vSPEED_MINIMUM  =  dSPEED_MINIMUM;
glob F32 vSPEED_DEFAULT  =  dSPEED_DEFAULT;
glob F32 vSPEED_MAXIMUM  =  dSPEED_MAXIMUM;
glob F32 vAUTO_DRV_TIME  =  dAUTO_DRV_TIME;
glob F32 vAUTO_TIME_AU1  =  dAUTO_TIME_AU1;
glob F32 vAUTO_TIME_AU2  =  dAUTO_TIME_AU2;
glob F32 vAUTO_TIME_AU3  =  dAUTO_TIME_AU3;
glob F32 vAUTO_TIME_AU4  =  dAUTO_TIME_AU4;
glob F32 vAUTO_TIME_AU5  =  dAUTO_TIME_AU5;
glob F32 vAUTO_TIME_AU6  =  dAUTO_TIME_AU6;
glob F32 vAUTO_SPEED_A1  =  dAUTO_SPEED_A1;
glob F32 vAUTO_SPEED_A2  =  dAUTO_SPEED_A2;
glob F32 vAUTO_SPEED_A3  =  dAUTO_SPEED_A3;
glob F32 vAUTO_SPEED_A4  =  dAUTO_SPEED_A4;
glob F32 vAUTO_SPEED_A5  =  dAUTO_SPEED_A5;
glob F32 vAUTO_SPEED_A6  =  dAUTO_SPEED_A6;
glob F32 vDRIVE_TRAIN_P  =  dDRIVE_TRAIN_P;
glob F32 vDRIVE_TRAIN_I  =  dDRIVE_TRAIN_I;
glob F32 vDRIVE_TRAIN_D  =  dDRIVE_TRAIN_D;
glob F32 vDRIVE_TRAIN_A  =  dDRIVE_TRAIN_A;
glob F32 vDRIVE_TRAIN_K  =  dDRIVE_TRAIN_K;
glob F32 vELEVATOR_TIME  =  dELEVATOR_TIME;
glob F32 vDECLINER_TIME  =  dDECLINER_TIME;
glob F32 vCAM_NEAR_POSY  =  dCAM_NEAR_POSY;
glob F32 vCAM_DIST_POSY  =  dCAM_DIST_POSY;
glob F32 vCAM_PAN_SPEED  =  dCAM_PAN_SPEED;
glob F32 vDEADZONE_GMPD  =  dDEADZONE_GMPD;
I32 VISIONQUALITY(){return vVISIONQUALITY;}
I32 CONTROLLER_TP(){return vCONTROLLER_TP;}
F32 SPEED_MINIMUM(){return vSPEED_MINIMUM;}
F32 SPEED_DEFAULT(){return vSPEED_DEFAULT;}
F32 SPEED_MAXIMUM(){return vSPEED_MAXIMUM;}
F32 AUTO_DRV_TIME(){return vAUTO_DRV_TIME;}
F32 AUTO_TIME_AU1(){return vAUTO_TIME_AU1;}
F32 AUTO_TIME_AU2(){return vAUTO_TIME_AU2;}
F32 AUTO_TIME_AU3(){return vAUTO_TIME_AU3;}
F32 AUTO_TIME_AU4(){return vAUTO_TIME_AU4;}
F32 AUTO_TIME_AU5(){return vAUTO_TIME_AU5;}
F32 AUTO_TIME_AU6(){return vAUTO_TIME_AU6;}
F32 AUTO_SPEED_A1(){return vAUTO_SPEED_A1;}
F32 AUTO_SPEED_A2(){return vAUTO_SPEED_A2;}
F32 AUTO_SPEED_A3(){return vAUTO_SPEED_A3;}
F32 AUTO_SPEED_A4(){return vAUTO_SPEED_A4;}
F32 AUTO_SPEED_A5(){return vAUTO_SPEED_A5;}
F32 AUTO_SPEED_A6(){return vAUTO_SPEED_A6;}
F32 DRIVE_TRAIN_P(){return vDRIVE_TRAIN_P;}
F32 DRIVE_TRAIN_I(){return vDRIVE_TRAIN_I;}
F32 DRIVE_TRAIN_D(){return vDRIVE_TRAIN_D;}
F32 DRIVE_TRAIN_A(){return vDRIVE_TRAIN_A;}
F32 DRIVE_TRAIN_K(){return vDRIVE_TRAIN_K;}
F32 ELEVATOR_TIME(){return vELEVATOR_TIME;}
F32 DECLINER_TIME(){return vDECLINER_TIME;}
F32 CAM_NEAR_POSY(){return vCAM_NEAR_POSY;}
F32 CAM_DIST_POSY(){return vCAM_DIST_POSY;}
F32 CAM_PAN_SPEED(){return vCAM_PAN_SPEED;}
F32 DEADZONE_GMPD(){return vDEADZONE_GMPD;}

class Elon: public IterativeRobot
{
public:
	OI* oi;
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	Preferences* prefs;

	void RobotInit()
	{
		CommandBase::Init();
		//autonomousCommand = new ExampleCommand();

		oi = OI::GetInstance();
		oi->Init();
		lw = LiveWindow::GetInstance();
		prefs = Preferences::GetInstance();
		Vision::Init();
	}
	
	void DisabledInit()
	{
		//Scheduler::GetInstance()->Run();
	}

	void DisabledPeriodic()
	{
		//Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		vAUTO_DRV_TIME = prefs->GetDouble("AUTO_RUN_TIME", dAUTO_DRV_TIME);
		vAUTO_SPEED_A6 = prefs->GetDouble("AUTO_SPEED_A6", dAUTO_SPEED_A6);
		if (autonomousCommand)autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		if (autonomousCommand)autonomousCommand->Cancel();

		{
			vSPEED_MINIMUM = prefs->GetDouble("MIN_SPEED", dSPEED_MINIMUM);
			vSPEED_DEFAULT = prefs->GetDouble("DEF_SPEED", dSPEED_DEFAULT);
			vSPEED_MAXIMUM = prefs->GetDouble("MAX_SPEED", dSPEED_MAXIMUM);

			vVISIONQUALITY = prefs->GetInt("CAM_QUALITY_MAX", dVISIONQUALITY);
			vCONTROLLER_TP = prefs->GetInt("CONTROLLER_TYPEV", dCONTROLLER_TP);

			vDRIVE_TRAIN_P = prefs->GetDouble("DRIVE_TRAIN_P", dDRIVE_TRAIN_P);
			vDRIVE_TRAIN_I = prefs->GetDouble("DRIVE_TRAIN_I", dDRIVE_TRAIN_I);
			vDRIVE_TRAIN_D = prefs->GetDouble("DRIVE_TRAIN_D", dDRIVE_TRAIN_D);
			vDRIVE_TRAIN_A = prefs->GetDouble("DRIVE_TRAIN_A", dDRIVE_TRAIN_A);
			vDRIVE_TRAIN_K = prefs->GetDouble("DRIVE_TRAIN_K", dDRIVE_TRAIN_K);

			vELEVATOR_TIME = prefs->GetDouble("RISE_TIME_STEP", dELEVATOR_TIME);
			vDECLINER_TIME = prefs->GetDouble("FALL_TIME_STEP", dDECLINER_TIME);

			vCAM_PAN_SPEED = prefs->GetDouble("CAM_PAN_SPEED", dCAM_PAN_SPEED);
			vCAM_NEAR_POSY = prefs->GetDouble("CAM_NEAR_POSY", dCAM_NEAR_POSY);
			vCAM_DIST_POSY = prefs->GetDouble("CAM_DIST_POSY", dCAM_DIST_POSY);

			vDEADZONE_GMPD = prefs->GetDouble("DEADZONE_GMPD", dDEADZONE_GMPD);
		} // This block gets input from the users preferences to get default values

	}

	void TeleopPeriodic()
	{
		oi->Update();
	}

	void TestPeriodic()
	{
		lw->Run();
	}

};

START_ROBOT_CLASS(Elon);

