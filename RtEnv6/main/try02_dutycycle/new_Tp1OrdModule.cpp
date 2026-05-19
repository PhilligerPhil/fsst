
#include "new_Tp1Ord.h"

//---------------------------------------------------------------
//---------------------------------------------------------------

new_Tp1Ord::new_Tp1Ord()
{
	y = y_n1 = 0;
	setAlpha(0.1f);
}

void new_Tp1Ord::setAlpha(float cAlpha)
{
	_alpha = cAlpha;
	_beta = 1.0f - cAlpha;
}

void new_Tp1Ord::Calconestep(float cFunc)
{
	y = cFunc * _alpha + y_n1 * _beta;
	y_n1 = y;
}

//---------------------------------------------------------------
//---------------------------------------------------------------

new_Hp1Ord::new_Hp1Ord()
{
	y = 0;
}

void new_Hp1Ord::setAlpha(float cAlpha)
{
	_tp.setAlpha(cAlpha);
}

void new_Hp1Ord::Calconestep(float cFunk)
{
	_tp.Calconestep(cFunk);
	y = cFunk - _tp.y;
}

//---------------------------------------------------------------
//---------------------------------------------------------------

new01_Hp1Ord::new01_Hp1Ord()
{
	y = 0;
}

void new01_Hp1Ord::Calconestep(float cFunk, float ctpf01)
{
	y = cFunk - ctpf01;
}