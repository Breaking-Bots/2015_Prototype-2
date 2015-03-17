#ifndef MATH_UTIL_5428_H
#define MATH_UTIL_5428_H

#include "Typedefs_5428.h"

F32 ZaeemMohamedInterpolation(F32 a, F32 b, F32 c, F32 alpha);

//Normalizes alpha of (-1 to +1)  to (0 to +1)
F32 NormalizeAlpha(F32 alpha);

F32 Lerp(F32 min, F32 max, F32 alpha);

F32 SamWongInterpolation(F32 a, F32 b, F32 c, F32 alpha);

B8 EpsilonEquals(F32 a, F32 b, F32 epsilon);

F32 HanzhenLinCoeeficientOfRotationalAlteration(F32 theta0, F32 theta, F32 mgntd, F32 time);

#endif
