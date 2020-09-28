#pragma once

#include <SFML/Graphics.hpp>




class Bomb{
public:
    Bomb(sf::RectangleShape bomb, sf::RectangleShape explosion, sf::Vector2f place);
    sf::RectangleShape getBomb() {return bomb_;}
     sf::RectangleShape getExplosion() {return explosion_;}
    void setExplosion(){explosion_.setPosition(-100,-100);}
    void setPosition(sf::Vector2f place);
    void explosion();
    bool isBombExist(){return exist_;}
    void timeout(){timeToBum_--;}
    int HowManyTimeIhave(){return timeToBum_;}
    void NewMe(){timeToBum_=3;exist_=false;}
private:
    sf::RectangleShape bomb_;
    sf::RectangleShape explosion_;
    void back();
    int timeToBum_ = 3;
    
    bool exist_ = false;
};