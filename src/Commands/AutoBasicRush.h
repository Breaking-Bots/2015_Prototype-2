#ifndef AUTO_BASIC_RUSH_5428_H
#define AUTO_BASIC_RUSH_5428_H

#include "../CommandBase.h"
#include "../Typedefs_5428.h"

class AutoBasicRush: public CommandBase
{
private:
	B8 m_reinit;
public:
	F32 m_time;
	F32 m_speed;
	AutoBasicRush();
	AutoBasicRush(F32 time, F32 speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
