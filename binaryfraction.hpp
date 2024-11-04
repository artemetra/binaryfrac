#ifndef BINARYFRACTION__HPP
#define BINARYFRACTION__HPP

#include <bit>
#include <bitset>
#include <iostream>
#include <vector>

typedef uint32_t NType;
const size_t NTypeBits = 32;

template <size_t Prec>
class BinaryFraction {
   private:
    std::bitset<Prec> m_bitset;

   public:
    BinaryFraction(NType num) {
        NType rec = 1;
        std::bitset<Prec> result = {0};
        for (size_t i = 0; i < Prec; i++) {
            rec *= 2;
            int floored = (int)(rec >= num);
            result[i] = floored;
            rec %= num;
        }
        m_bitset = result;
    }
    BinaryFraction(std::bitset<Prec> bs) : m_bitset(bs) {}

    /* Prints the bitset in reverse. */
    friend std::ostream& operator<<(std::ostream& os, const BinaryFraction<Prec>& bf) {
        os << "0.";  // front zero
        for (size_t i = 0; i < Prec; i++) {
            os << bf.m_bitset[i];
        }
        return os;
    }

    BinaryFraction<Prec> operator^(BinaryFraction<Prec> bf2) {
        return BinaryFraction<Prec>(m_bitset ^ bf2.m_bitset);
    }

    // TODO: fix this because it's incorrect for whatever reason
    long double to_long_double() {
        long double res = 0;
        for (int i = 0; i < Prec+1; i++) {
            res += pow(2, -i) * (int)m_bitset[i];
        }
        return res;
    }
};

#endif