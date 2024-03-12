// Copyright 2023
// By Jake Shick
// main.cpp for PS1a

#include <iostream>
#include <string>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char** argv) {
    sf::Image image;
    if (!image.loadFromFile(argv[1])) {
        return -1;
    }
    FibLFSR lfsr(argv[3]);

    sf::Vector2u size1 = image.getSize();
    sf::RenderWindow window1(sf::VideoMode(size1.x, size1.y), "Orginal");
    sf::RenderWindow window2(sf::VideoMode(size1.x, size1.y), "Decrypt");

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    PhotoMagic::transform(image, &lfsr);

    sf::Texture texture2;
    texture2.loadFromImage(image);

    sf::Sprite sprite2;
    sprite2.setTexture(texture2);

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(sprite);
        window1.display();
        window2.clear();
        window2.draw(sprite2);
        window2.display();
}


    // fredm: saving a PNG segfaults for me, though it does properly
    //   write the file
    if (!image.saveToFile(argv[2]))
        return -1;
    return 0;
}
