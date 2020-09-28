#pragma once

#include <vector>

#include <SFML/Graphics.hpp>
#include "baryl.hpp"


class BarylMap{
public:
    BarylMap();
    std::vector<Baryl> baryls_;
private:
    std::vector<sf::Vector2f> mapa_;
    
};