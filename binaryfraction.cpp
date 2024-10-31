#include <bitset>
#include <iostream>

#include "binaryfraction.hpp"

uint8_t bit_count(NType n) {
    uint8_t count = 0;
    while (n) {
        count++;
        n >>= 1;
    }
    return count;
}

template <size_t Prec>
BinaryFraction<Prec>::BinaryFraction(std::bitset<Prec> bs) {}

template <size_t Prec>
BinaryFraction<Prec>::BinaryFraction(NType num) {
    uint8_t trailing_zero_count = 0;
    NType new_n = num;
    // While n has a trailing zero, divide by 2.
    while (!(new_n & 1)) {
        new_n >>= 1;
        trailing_zero_count++;
    }

    uint8_t k = bit_count(new_n) + 1;
    auto ys = std::bitset<Prec>{0};
    auto n_bitset = std::bitset<NTypeBits>(num);
    ys[k - 1] = 1;
    for (size_t n = k; n < Prec; n++) {
        bool sum = 0;
        for (size_t j = 1; j < k; j++) {
            sum += (!n_bitset[j]) * ys[j];
        }
        sum += n_bitset[0] * ys[0];
        ys[n] = sum;
    }

    std::cout << ys << "\n";

    m_bitset = std::bitset<Prec>(0);
}

template <size_t Prec>
BinaryFraction<Prec>::~BinaryFraction() {}

unsigned int log2(unsigned int x) {
    unsigned int ans = 0;
    while (x >>= 1)
        ans++;
    return ans;
}
