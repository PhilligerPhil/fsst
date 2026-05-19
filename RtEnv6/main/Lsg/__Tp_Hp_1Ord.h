
#ifndef Tp1Ord_h
#define Tp1Ord_h

class Tp1Ord {
	private:
		float _alpha;
		float _beta;
		float yn_1; // um eine Abtastung verzögertes y
	public:
		float y; // momentaner ausgangswert des Filtes
	public:
		Tp1Ord();

		// Grenzfrequenz verstellen
		void SetAlpha(float aAlpha);
		
		void CalcOneStep(float aX);
};

class Hp1Ord {
public:
	float y;
private:
	Tp1Ord _tp;
public:
	Hp1Ord()
	{
		y = 0;
	}

	void SetAlpha(float aAlpha)
	{
		_tp.SetAlpha(aAlpha);
	}

	void CalcOneStep(float aX)
	{
		_tp.CalcOneStep(aX);
		y = aX - _tp.y;
	}
};


inline Tp1Ord::Tp1Ord()
{
	y=yn_1=0;
	SetAlpha(0.1); // Vernünftiges Alpha setzen
}

inline void Tp1Ord::SetAlpha(float aAlpha)
{
	_alpha=aAlpha;
	_beta=1.0f-aAlpha;
}

inline void Tp1Ord::CalcOneStep(float aX)
{
	y = _alpha*aX + _beta*yn_1;
	// Verzögerung berechnen
	yn_1 = y;
}

#endif



















