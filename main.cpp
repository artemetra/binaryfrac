#include <bitset>
#include <iomanip>
#include <iostream>

#include "binaryfraction.hpp"

const size_t NBITS = 200;
const size_t DEC_PREC = 50;
typedef BinaryFraction<NBITS> Bf;

int main() {
    auto t = (Bf(5) ^ Bf(7));
    std::cout << t << "\n";
    std::cout << std::setprecision(DEC_PREC) << t.to_double() << "\n";
    return 0;
}