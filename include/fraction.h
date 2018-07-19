#ifndef FRACTION_H_
#define FRACTION_H_

typedef struct Fraction_t{
	Int16 n;
	Int16 d;	
} Fraction;

Int16 fMultInt(Fraction*, Int16 i);
Int16 ndMultInt(Int16 n, Int16 d, Int16 i);

Fraction getUnitFraction(Fraction *f);

#endif /*FRACTION_H_*/
