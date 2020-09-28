#pragma once

#include <SFML/Graphics.hpp>



class Baryl{
public:
    Baryl(sf::RectangleShape box, sf::Vector2f position);
    sf::RectangleShape getBox() {return box_;}
    void getOutOfMyWay(){box_.setPosition({-100,-100});}

private:
    sf::RectangleShape box_;
};