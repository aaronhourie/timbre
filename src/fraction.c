#include "stdio.h"
#include "ezdsp5535.h"

#include "fraction.h"

Int16 fMultInt(Fraction* f, Int16 i) 
{
	Int16 retval = 0;
	if (abs(i) >= 180 || abs(f->n) >= 180){
		retval = (i / f->d) * f->n;
	}
	else {
		retval = (i * f->n) / f->d;
	}
	return retval;
}

Int16 ndMultInt(Int16 n, Int16 d, Int16 i)
{
	Int16 retval = 0;
	if (abs(i) >= 180 || abs(n) >= 180){
		retval = (i / d) * n;
	}
	else {
		retval = (i * n) / d;
	}
	
	return retval;
}

Fraction getUnitFraction(Fraction *other)
{
	Fraction f;
	f.n = other->d - other->n;
	f.d = other->d;
	return f;
}
