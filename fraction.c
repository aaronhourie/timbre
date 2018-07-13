#include "stdio.h"
#include "ezdsp5535.h"

#include "fraction.h"

Int16 fMultInt(Fraction* f, Int16 i) {
	Int16 retval = 0;
	retval = (i * f->n) / f->d;
	return retval;
}
