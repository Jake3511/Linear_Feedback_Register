// Copyright 2023
// By Jake Shick
// FibLFSR.cpp for PS1a

#include <iostream>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

// const int color_chanel_size;
namespace PhotoMagic {
    void transform(sf::Image& image, FibLFSR* lfsr) {
        // p is a pixelimage.getPixel(x, y);
        sf::Color p;
        const sf::Vector2 orgianl_size = image.getSize();
        int horizontal = orgianl_size.x;
        int vertical = orgianl_size.y;
        // create photographic negative image of upper-left 200 px square
        for (int x = 0; x < horizontal; x++) {
            for (int y = 0; y < vertical; y++) {
                p = image.getPixel(x, y);
                p.r = 255 - p.r;
                int8_t red = p.r ^ lfsr->generate(8);
                p.g = 255 - p.g;
                int8_t green = p.g ^ lfsr->generate(8);
                p.b = 255 - p.b;
                int8_t blue = p.b ^ lfsr->generate(8);
                sf::Color new_color(red, green, blue);
                image.setPixel(x, y, new_color);
            }
        }
    }
}  // namespace PhotoMagic
