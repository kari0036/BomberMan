#pragma once

#include <SFML/Graphics.hpp>



class Box{
public:
    Box(sf::RectangleShape box, sf::Vector2f position);
    sf::RectangleShape getBox() {return box_;}

private:
    sf::RectangleShape box_;
};