#ifndef GenModules_h
#define GenModules_h


class Mean3
{
private:
	float Xn_1;
	float Xn_2;
public:
	float _Y;
	
	Mean3();

	void CalcOneStep(float cSignal);
};
#endif