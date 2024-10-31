from binary_fractions import Binary
import binary_fractions as bf
from fractions import Fraction
from primefac import isprime
from datetime import datetime
from math import ceil, log10
res = Binary("0")
real = 1.5395813806374399
eps = 1e-1
N = 1/eps
print(ceil(N))
for i in range(1,ceil(N)+1):
    f = Binary(Fraction(1,i))
    res ^= f

    #print(i,res)
print(log10(eps))
print(log10(abs(real-float(res))))
#print("F:",float(res))