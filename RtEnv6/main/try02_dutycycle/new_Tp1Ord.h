#ifndef new_Tp1Ord_h
#define new_Tp1Ord_h

//---------------------------------------------------------------
//---------------------------------------------------------------

class new_Tp1Ord
{
public:
	float y;
private:
	float y_n1;
	float _alpha;
	float _beta;
public:
	new_Tp1Ord();

	void setAlpha(float cAlpha);

	void Calconestep(float cFunc);
};

//---------------------------------------------------------------
//---------------------------------------------------------------

class new_Hp1Ord
{
public:
	float y;
private:
	new_Tp1Ord _tp;
public:
	new_Hp1Ord();

	void setAlpha(float cAlpha);

	void Calconestep(float cFunk);
};

//---------------------------------------------------------------
//---------------------------------------------------------------

class new01_Hp1Ord
{
public:
	float y;
public:
	new01_Hp1Ord();

	void Calconestep(float cFunk, float ctpf01);
};
#endif