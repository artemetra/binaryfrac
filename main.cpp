#include <bitset>
#include <iostream>

#include "binaryfraction.hpp"

const size_t NBITS = 256;

int main() {
    auto res = to_reciproc<200>(31);
    std::cout << "res " << res << "\n";
    return 0;
}