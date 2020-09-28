#pragma once

#include <vector>

#include <SFML/Graphics.hpp>
#include "box.hpp"


class WallMap{
public:
    WallMap();
    std::vector<Box> getBloks(){return blocks_;}

private:
    std::vector<sf::Vector2f> map_;
    std::vector<Box> blocks_;
};