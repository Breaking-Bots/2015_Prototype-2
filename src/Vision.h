#ifndef VISION_5428_H
#define VISION_5428_H

#include "TypeDefs_5428.h"
#include "Elon.h"
#include <CameraServer.h>

namespace Vision{

INLINEFORCE void Init(){
	CameraServer::GetInstance()->SetQuality(VISIONQUALITY());
	CameraServer::GetInstance()->StartAutomaticCapture("cam1");
}

}



#endif
