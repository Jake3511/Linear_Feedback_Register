// Copyright 2023
// By Jake Shick
// FibLFSR.hpp for PS1a

#pragma once
#include <string>

class FibLFSR {
 public:
    FibLFSR();
// Constructor to create LFSR with the given initial seed
    explicit FibLFSR(std::string seed);
// Simulate one step and return the new bit as 0 or 1
    int step();
// Simulate k steps and return a k-bit integer
    int generate(int k);

    std::string get_bits();

    int get_count();

    void set_bits(int temp);

    int XOR();

    int get_seed(int k);

    friend std::ostream& operator<<(std::ostream&, const FibLFSR& lfsr);

 private:
    std::string bits;
    int count = 1;
};
