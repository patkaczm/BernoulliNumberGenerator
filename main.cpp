#include <iostream>
#include <cstdint>

template<uint8_t N>
struct Factorial {
    static const uint64_t value;
};

template<uint8_t N>
const uint64_t Factorial<N>::value = N * Factorial<N-1>::value;

template<>
struct Factorial<0> {
    static const uint64_t value;
};

const uint64_t Factorial<0>::value = 1;

template<uint16_t N, uint16_t K>
struct Newton {
    static const double value;
};

template<uint16_t N, uint16_t K>
const double Newton<N, K>::value = Factorial<N>::value / ( Factorial<K>::value * Factorial<N - K>::value);

template<uint16_t START, uint16_t END>
struct BernoulliSigma {
    static const double value;
};

template<uint8_t N>
struct Bernoulli {
    static const double value;
};

// calcucate <Start, End)
template<uint16_t START, uint16_t END>
const double BernoulliSigma<START, END>::value = Newton<END, START>::value * Bernoulli<START>::value / (END - START + 1) + BernoulliSigma<START + 1, END>::value;

template<uint16_t END>
struct BernoulliSigma<END, END> {
    static const double value;
};

template<uint16_t END>
const double BernoulliSigma<END, END>::value = 0;


template<uint8_t N>
const double Bernoulli<N>::value = 1 - BernoulliSigma<0, N>::value;

template<>
struct Bernoulli<0> {
    static const double value;
};

const double Bernoulli<0>::value = 1.0;

int main() {
    std::cout << "Bernoulli<0> = " << Bernoulli<0>::value << "\n";
    std::cout << "Bernoulli<1> = " << Bernoulli<1>::value << "\n";
    std::cout << "Bernoulli<2> = " << Bernoulli<2>::value << "\n";
    std::cout << "Bernoulli<3> = " << Bernoulli<3>::value << "\n";
    std::cout << "Bernoulli<4> = " << Bernoulli<4>::value << "\n";
    std::cout << "Bernoulli<5> = " << Bernoulli<5>::value << "\n";
    std::cout << "Bernoulli<6> = " << Bernoulli<6>::value << "\n";
    std::cout << "Bernoulli<7> = " << Bernoulli<7>::value << "\n";
    std::cout << "Bernoulli<8> = " << Bernoulli<8>::value << "\n";
    std::cout << "Bernoulli<9> = " << Bernoulli<9>::value << "\n";
    std::cout << "Bernoulli<10> = " << Bernoulli<10>::value << "\n";
    std::cout << "Bernoulli<11> = " << Bernoulli<11>::value << "\n";
    std::cout << "Bernoulli<12> = " << Bernoulli<12>::value << "\n";
    std::cout << "Bernoulli<13> = " << Bernoulli<13>::value << "\n";
    std::cout << "Bernoulli<14> = " << Bernoulli<14>::value << "\n";
    std::cout << "Bernoulli<15> = " << Bernoulli<15>::value << "\n";
    std::cout << "Bernoulli<16> = " << Bernoulli<16>::value << "\n";
    std::cout << "Bernoulli<17> = " << Bernoulli<17>::value << "\n";
    std::cout << "Bernoulli<19> = " << Bernoulli<18>::value << "\n";
    std::cout << "Bernoulli<19> = " << Bernoulli<19>::value << "\n";
    std::cout << "Bernoulli<20> = " << Bernoulli<20>::value << "\n";

    return 0;
}
