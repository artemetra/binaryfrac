#include <bitset>
#include <iomanip>
#include <iostream>

#include "binaryfraction.hpp"

const size_t NBITS = 20;
typedef BinaryFraction<NBITS> Bf;

const size_t DEC_PREC = 50;
const size_t N_POW = 32;
const size_t N = std::numeric_limits<size_t>::max();

void start_test() {
    std::cout << "N=" << N << "\n";

    // empty bitset
    Bf res = Bf(std::bitset<NBITS>{0});
    for (size_t i = 2; i < 1000; i++) {
        auto bf = Bf(i);
        res = res ^ bf;
        std::cout << i << "\t\t\t" << bf.get_bitset() << "\n";
    }
    std::cout << "bs: " << res.get_bitset() << "\n";
    std::cout << N_POW << " bits *should* be correct!\n";
    std::cout << "bf:" << res << "\n";
    std::cout << "dec:" << res.to_long_double() + 1 << "\n";
}

int main() {
    std::cout << std::setprecision(DEC_PREC);
    start_test();
    // std::cout << std::numeric_limits<uint64_t>::max() << "\n";
    return 0;
}