
#include "Bsp2_Mean3.h"
#include "math.h"



Mean3::Mean3()
{
	Xn_1 = 0;
	Xn_2 = 0;
	_Y = 0;
}

void Mean3::CalcOneStep(float cSignal)
{
	_Y = (cSignal + Xn_1 + Xn_2) / 3.0f;
	Xn_2 = Xn_1;
	Xn_1 = cSignal;
}