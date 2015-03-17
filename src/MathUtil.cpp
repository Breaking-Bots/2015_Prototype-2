#include "MathUtil.h"
#include "Typedefs_5428.h"

#include <cmath>

F32 ZaeemMohamedInterpolation(F32 a, F32 b, F32 c, F32 alpha){
	//		F32 alphaN = 0.5f * alpha + 0.5f;
	//		F32 alphaAB = alpha + 1;
	//		F32 lerpAB = (1 - alphaAB) * a + alphaAB * b;
	//		F32 lerpBC = (1 - alpha) * b + alpha * c;
	//		return (1 - alphaN) * lerpAB + lerpBC * alphaN;
	return (alpha * (a * (alpha - 1.0f) + c * (alpha + 1.0f)) - 2.0f * b * (alpha * alpha - 1.0f)) * 0.5f;
}

//Normalizes alpha of (-1 to +1)  to (0 to +1)
F32 NormalizeAlpha(F32 alpha){
	return 0.5f * alpha + 0.5f;
}

F32 Lerp(F32 min, F32 max, F32 alpha){
	return min - alpha * (min - max);
}

F32 SamWongInterpolation(F32 a, F32 b, F32 c, F32 alpha){
	F32 alphaN = 0.5f * alpha + 0.5f;
	b+= 0.0001f;
	F32 f = (a * a - 2 * a * b + b * b) / (a - 2 * b + c);
	F32 g = ((b * b - 2 * b * c + c * c) / (a * a - 2 * a * b + b * b));
	F32 k = (a * c - b * b) / (a - 2 * b + c);
	return f * pow(g, alphaN) + k;
}

B8 EpsilonEquals(F32 a, F32 b, F32 epsilon){
	return (a-b) * (a-b) < (epsilon * epsilon);
}

F32 HanzhenLinCoeeficientOfRotationalAlteration(F32 theta0, F32 theta, F32 mgntd, F32 time){
	return (theta - theta0)/(mgntd * time);
}

