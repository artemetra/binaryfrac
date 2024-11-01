#include <bitset>
#include <iostream>

#include "binaryfraction.hpp"

const size_t NBITS = 256;

int main() {
    for (size_t i = 2; i <= 10; i++) {
        auto res = BinaryFraction<100>(i);
        std::cout << i << "\t res " << res << "\n";
    }

    return 0;
}