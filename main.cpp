#include <bitset>
#include <iomanip>
#include <iostream>

#include "binaryfraction.hpp"

const size_t NBITS = 200;
const size_t DEC_PREC = 50;
typedef BinaryFraction<NBITS> Bf;
const size_t N_POW = 23;
const size_t N = (1 << N_POW);

int main() {
    std::cout << std::setprecision(DEC_PREC);

    std::cout << "N=" << N << "\n";

    // empty bitset
    Bf res = Bf(std::bitset<NBITS>{0});
    for (size_t i = 2; i < N+1; i++) {
        res = res ^ Bf(i);
    }
    std::cout << res << "\n";

    std::cout << N_POW << " bits *should* be correct!\n";
    // std::cout << res.to_long_double() << "\n";
    return 0;
}