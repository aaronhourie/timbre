import sys
import math
from fractions import Fraction

default_entries = 64
denom_limit = pow(2, 15) # Int16 is signed 16-bit

def main():

    entries = default_entries

    if len(sys.argv) > 1:
        entries = int(sys.argv[1])

    sinetable = generate_sinetable(entries)
    c_init = generate_c_init(sinetable)
    print(c_init)

def generate_sinetable(entries):
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
