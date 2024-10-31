#ifndef BINARYFRACTION__HPP
#define BINARYFRACTION__HPP

#include <bit>
#include <bitset>
// #include <cmath>
#include <iostream>
#include <vector>

typedef uint32_t NType;
const size_t NTypeBits = 32;

template <std::size_t Prec>
class BinaryFraction {
   private:
    std::bitset<Prec> m_bitset;

   public:
    BinaryFraction(NType n);
    BinaryFraction(std::bitset<Prec> bs);
    ~BinaryFraction();
};

// // https://math.stackexchange.com/a/4884476/1153468
// template <size_t Prec>
// std::bitset<Prec> to_reciproc(NType num);

template <size_t Prec>
std::bitset<Prec> to_reciproc(NType num) {
    std::bitset<Prec> result = {0};
    // If the number is 2**k for some k
    if (std::bitset<NTypeBits>(num).count() == 1) {
        auto pos = (int)log2(num);
        result[pos] = 1;
        return result;
    }

    // If the number is of the form 2**k - 1
    if (std::bitset<NTypeBits>(num + 1).count() == 1) {
        auto pos = (size_t)log2(num + 1);
        for (size_t k = pos-1; k <= Prec; k += pos) {
            result[k] = 1;
        }
        return result;
    }

    uint8_t trailing_zero_count = 0;
    NType qprime = num;
    // While n has a trailing zero, divide by 2.
    while (!(qprime & 1)) {
        qprime >>= 1;
        trailing_zero_count++;
    }

    std::cout << "qprime: " << qprime << "\n";

    NType power = 1;
    NType n = 1;
    for (; n <= qprime; n++) {
        power *= 2;
        power %= qprime;
        std::cout << power << " ";
        if (power == 1) {
            std::cout << "\n";
            break;
        }
    }

    std::cout << "n: " << n << "\n";
    return std::bitset<Prec>(0);
}

#endif