#include "bomb.hpp"
#include <iostream>


sf::Time timeToBoom = sf::seconds(3.f);

Bomb::Bomb(sf::RectangleShape bomb,sf::RectangleShape explosion, sf::Vector2f place) :
    bomb_(bomb),
    explosion_(explosion)
    {
        bomb_.setFillColor(sf::Color::Blue);
        bomb_.setPosition(place);
        explosion_.setFillColor(sf::Color(255, 165, 0));
        explosion_.setPosition(place);
    }
void Bomb::setPosition(sf::Vector2f place){
    
    if(!exist_){
        exist_ = true;
        bomb_.setPosition(place);
    }
}
void Bomb::explosion(){
    explosion_.setPosition({bomb_.getPosition().x - 50,bomb_.getPosition().y-50,});
    // auto pos = bomb_.getPosition();
    back();
}
void Bomb::back(){
    bomb_.setPosition({-100,-100});
}
