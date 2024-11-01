#ifndef BINARYFRACTION__HPP
#define BINARYFRACTION__HPP

#include <bit>
#include <bitset>
#include <iostream>
#include <vector>

typedef uint32_t NType;
const size_t NTypeBits = 32;

template <std::size_t Prec>
class BinaryFraction {
   private:

   public:
    std::bitset<Prec> m_bitset;
    BinaryFraction(NType n);
    BinaryFraction(std::bitset<Prec> bs);
    friend std::ostream& operator<<(std::ostream& os, const BinaryFraction<Prec>& obj);
};

// TODO: MOVE TO .CPP
template<size_t Prec>
std::ostream& operator<<(std::ostream& os, const BinaryFraction<Prec>& bf) {
    os << "0.";
    for (size_t i=0; i< Prec; i++)
    {
        os << bf.m_bitset[i];
    }
}

// TODO: MOVE TO .CPP
template <size_t Prec>
BinaryFraction<Prec>::BinaryFraction(NType num) {
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


uint8_t bit_count(NType n);

#endif