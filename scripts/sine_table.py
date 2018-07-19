import sys
import math
from fractions import Fraction

default_entries = 64
default_denom_limit = 10000

def main():

    entries = default_entries
    denom_limit = default_denom_limit

    if len(sys.argv) > 1:
        entries = int(sys.argv[1])
    if len(sys.argv) > 2:
        denom_limit = int(sys.argv[2])
		
    sinetable = generate_sinetable(entries, denom_limit)
    c_init = generate_c_init(sinetable)
    print(c_init)

def generate_sinetable(entries, denom_limit):
    # type: (int) -> list
    sinetable = list()
    for i in range(0, entries):
        val = math.sin(i*2*math.pi/entries)
        frac = Fraction(val).limit_denominator(denom_limit)
        sinetable.append(frac)

    return sinetable

def generate_c_init(sinetable):
    # type: (list) -> str
    c_init = "int sinetable[" + str(len(sinetable)) + "][2] = {\n"

    i = 0
    for frac in sinetable:
        c_init += "{" + str(frac.numerator) + ", " + str(frac.denominator) + "}"
        if i % 4 == 0:
            c_init += ", \n"
        else:
            c_init += ", "
        i += 1

    c_init += "\n}"

    return c_init


if __name__ == "__main__":
    main()
