// Copyright 2023
// By Jake Shick
// FibLFSR.cpp for PS1a

#include "FibLFSR.hpp"
#include <iostream>
#include <string>
#include <sstream>

const int zero = 0;
const int two = 2;
const int three = 3;
const int five = 5;
const int fifteen = 15;

FibLFSR::FibLFSR():FibLFSR("1011011000110110") {}

FibLFSR::FibLFSR(std::string seed) {
    bits = seed;
}

int FibLFSR::step()  {
    int temp = 1;
    temp = XOR();
    set_bits(temp);
    int num = get_seed(count);
    return num;
}

int FibLFSR::generate(int n) {
    count = n;
    int num = 0;
    for (int i = 0; i < n; i++) {
        num = step();
    }
    return num;
}

void FibLFSR::set_bits(int temp) {
    for (int i = 0; i < fifteen; i++) {
        bits[i] = bits[i + 1];
    }

    bits[fifteen] = temp + '0';
}

int FibLFSR::XOR() {
    int temp = bits[zero] ^ bits[two];
    temp = temp ^ bits[three];
    temp = temp ^ bits[five];
    return temp;
}
int FibLFSR::get_seed(int n) {
    std::string test;
    int base = 1, decimal = 0;

    test = bits.substr(bits.length() - n);
    for (int i = test.length() - 1; i >= 0; i--) {
        if (test[i] == '1')
            decimal += base;
        base = base * 2;
    }
    return decimal;
}
std::ostream& operator<<(std::ostream& out, const FibLFSR& lfsr) {
    std::string temp = lfsr.bits;
    out << temp;
    return out;
}
