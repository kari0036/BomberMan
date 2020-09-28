#include "box.hpp"

Box::Box(sf::RectangleShape box, sf::Vector2f position) :
    box_(box) {
        box_.setFillColor(sf::Color::Red);
        box_.setPosition(position);
}
