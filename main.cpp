 #include <SFML/Graphics.hpp>
 #include <iostream>
 #include <vector>

 #include "player.hpp"
 #include "Player2.hpp"
 #include "box.hpp"
 #include "baryl.hpp"
 #include "wallMap.hpp"
 #include "bomb.hpp"
 #include "barylMap.hpp"

 


 
sf::RenderWindow window(sf::VideoMode(750, 600), "Bomber man");
sf::RectangleShape explosion({150,150});
sf::RectangleShape explosion2({150,150});
sf::RectangleShape boxx({50,50});

void updateMap(Bomb bomb,Bomb bomb2, WallMap wall, Player p1, Player2 p2);
void colision(WallMap wall, Player p1, Player2 p2, sf::FloatRect playerBoand1, sf::FloatRect playerBoand2);

int main()
{
    sf::Clock clock1;
    sf::Clock clock2;
    BarylMap woodens;
    WallMap wall;
    Bomb bomb(boxx,explosion,{-100,-100});
    Bomb bomb2(boxx,explosion2,{-100,-100});
    Player p1(boxx,bomb);
    Player2 p2(boxx,bomb);

   


    
    while (window.isOpen() && p1.getLive() && p2.getLive()){
        
        sf::FloatRect playerBoand = (p1.getPlayer()).getGlobalBounds();
        sf::FloatRect playerBoand2 = (p2.getPlayer()).getGlobalBounds();
        sf::FloatRect ExplosionBoand = (p1.bomb_.getExplosion()).getGlobalBounds();
        sf::FloatRect ExplosionBoand2 = (p2.bomb_.getExplosion()).getGlobalBounds();

        sf::Event event;
        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed ){
                window.close();
            }

            if (event.type == sf::Event::KeyPressed){
                p1.savePosition();
                p1.move();

                p2.savePosition();
                p2.move();
                
            }

            

            colision(wall,p1,p2,playerBoand,playerBoand2);


            // for(auto& it : woodens.getBaryls()){
            //     sf::FloatRect hitBoxBaryl = (it.getBox()).getGlobalBounds();
            //         if (ExplosionBoand.intersects(hitBoxBaryl)){
            //             it.getOutOfMyWay();
            //         }
            // }
           








            
                // sf::FloatRect hitBoxBary2 = (woodens.baryls_[0].getBox()).getGlobalBounds();
                //     if (hitBoxBary2.intersects(ExplosionBoand2)){
                //         woodens.baryls_[0].getOutOfMyWay();
                //     }
            

            













            if (playerBoand.intersects(ExplosionBoand)){
                    p1.setLive(false);
            }
            if (playerBoand2.intersects(ExplosionBoand2)){
                    p2.setLive(false);
            }
            if (playerBoand.intersects(ExplosionBoand2)){
                    p1.setLive(false);
            }
            if (playerBoand2.intersects(ExplosionBoand)){
                    p2.setLive(false);
            }
        }

       

        updateMap(p1.bomb_,p2.bomb_,wall,p1,p2);

        if(p1.bomb_.isBombExist()){
            if(clock1.getElapsedTime().asSeconds() >= 1.0f){
                p1.bomb_.timeout();
                if(p1.bomb_.HowManyTimeIhave()==0){
                    p1.bomb_.explosion();
                }
                if(p1.bomb_.HowManyTimeIhave()==-3){
                    p1.bomb_.setExplosion();
                    p1.bomb_.NewMe();
                }
                clock1.restart();
            }

        }
        if(p2.bomb_.isBombExist()){
            if(clock2.getElapsedTime().asSeconds() >= 1.0f){
                p2.bomb_.timeout();
                if(p2.bomb_.HowManyTimeIhave()==0){
                    p2.bomb_.explosion();
                }
                if(p2.bomb_.HowManyTimeIhave()==-3){
                    p2.bomb_.setExplosion();
                    p2.bomb_.NewMe();
                }
                clock2.restart();
            }

        }
         
    }
    if(p2.getLive()){
        window.clear(sf::Color::Yellow);
    }
    if(p1.getLive()){
        window.clear(sf::Color::Green);
    }
    window.display();
    sf::Time t1 = sf::seconds(3.f);
    sf::sleep(t1);

    
    return 0;
}

void updateMap(Bomb bomb,Bomb bomb2, WallMap wall, Player p1, Player2 p2){
    window.clear(sf::Color(60,60,60));

    window.draw(bomb.getBomb());
    window.draw(bomb2.getBomb());
    window.draw(bomb.getExplosion());
    window.draw(bomb2.getExplosion());
    window.draw(p1.getPlayer());
    window.draw(p2.getPlayer());
    for(auto it : wall.getBloks()){
        window.draw(it.getBox());
    }
    
    window.display();
}

void colision(WallMap wall, Player p1, Player2 p2,  sf::FloatRect playerBoand, sf::FloatRect playerBoand2){
    
    for(auto it : wall.getBloks()){
        sf::FloatRect hitBox = (it.getBox()).getGlobalBounds();
        if (playerBoand.intersects(hitBox)){
            p1.undo();
        }
    }
    for(auto it : wall.getBloks()){
        sf::FloatRect hitBox = (it.getBox()).getGlobalBounds();
        if (playerBoand2.intersects(hitBox)){
            p2.undo();
        }
    }

    // for(auto it : woodens.baryls_){
    //     sf::FloatRect hitBox = (it.getBox()).getGlobalBounds();
    //     if (playerBoand.intersects(hitBox)){
    //             p1.undo();
    //     }
    //     if (playerBoand2.intersects(hitBox)){
    //         p2.undo();
    //     }
    // }
}







