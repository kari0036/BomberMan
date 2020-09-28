#include "baryl.hpp"

Baryl::Baryl(sf::RectangleShape box, sf::Vector2f position) :
    box_(box) {
        box_.setFillColor(sf::Color(139,69,19));
        box_.setPosition(position);
}
