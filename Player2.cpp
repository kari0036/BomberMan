#include "Player2.hpp"


Player2::Player2(sf::RectangleShape player, Bomb& bomb) :
    player_(player),
    bomb_(bomb) {
        player_.setFillColor(sf::Color::Yellow);
        player_.setPosition(650,500);
}

void Player2::move(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ){
        player_.move(-moveSpeed_, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        player_.move(moveSpeed_, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        player_.move(0.f, -moveSpeed_);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        player_.move(0.f, moveSpeed_);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
        bomb_.setPosition(player_.getPosition());
    }
    
    
}

void Player2::savePosition(){
    lastPosition_ = player_.getPosition();
}

void Player2::undo(){
    player_.setPosition(lastPosition_);

}




