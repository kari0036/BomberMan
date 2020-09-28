#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "bomb.hpp"

class Player2{
public:
    Player2(sf::RectangleShape playerShape, Bomb& bomb);
    
    sf::RectangleShape getPlayer() {return player_;}

    void move();
    void savePosition();
    void undo();
    sf::Vector2f getLast(){return lastPosition_;}
    void setLive(bool die){live_ = die;}
    bool getLive(){return live_;}
    Bomb bomb_;


private:
    sf::RectangleShape player_;
    float moveSpeed_ = 50;
    sf::Vector2f lastPosition_;
    bool live_ = true;  
};