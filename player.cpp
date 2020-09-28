#include "player.hpp"

#include "iostream"

Player::Player(sf::RectangleShape player, Bomb& bomb) :
    player_(player),
    bomb_(bomb) {
        player_.setFillColor(sf::Color::Green);
        player_.setPosition(50,50);
}

void Player::move(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ){
        player_.move(-moveSpeed_, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        player_.move(moveSpeed_, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        player_.move(0.f, -moveSpeed_);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        player_.move(0.f, moveSpeed_);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
        bomb_.setPosition(player_.getPosition());
    }
    
    
}

void Player::savePosition(){
    lastPosition_ = player_.getPosition();
}

void Player::undo(){
    player_.setPosition(lastPosition_);

}




