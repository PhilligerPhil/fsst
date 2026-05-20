
#ifndef SineGen_h
#define SineGen_h

#include "math.h"

class Complex
{
public:
	float _re, _im;

	Complex();

	void SetPolar(float cBetrag, float cPhi);

	Complex Mult(Complex Zcahl2);
};




Complex::Complex()
{
	_re = 0;
	_im = 0;
}

void Complex::SetPolar(float cBetrag, float cPhi)
{
	re = aR * cos(aPhi);
	im = aR * sin(aPhi);
}

Complex::Mult(Complex cZahl2)
{
	Complex _produkt;
	_produkt._re = _re*cZahl2._re
}




class SineGen
{
public:
	Complex _increment;
private:

};
#endif