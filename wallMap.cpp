#include "wallMap.hpp"

sf::RectangleShape boxxi({50,50});

WallMap::WallMap(){
    map_ = {
        {0,0},   {50,0},  {100,0},  {150,0},  {200,0},  {250,0},  {300,0},  {350,0},  {400,0},  {450,0},  {500,0},  {550,0},  {600,0},  {650,0},  {700,0},
        {0,50},                                                                                                                                   {700,50},
        {0,100},          {100,100},          {200,100},          {300,100},          {400,100},          {500,100},          {600,100},          {700,100},
        {0,150},                                                                                                                                  {700,150},
        {0,200},          {100,200},          {200,200},          {300,200},          {400,200},          {500,200},          {600,200},          {700,200},                                 
        {0,250},                                                                                                                                  {700,250},
        {0,300},                                                                                                                                  {700,300},
        {0,350},          {100,350},          {200,350},          {300,350},          {400,350},          {500,350},          {600,350},          {700,350},
        {0,400},                                                                                                                                  {700,400},
        {0,450},          {100,450},          {200,450},          {300,450},          {400,450},          {500,450},          {600,450},          {700,450},
        {0,500},                                                                                                                                  {700,500},
        {0,550}, {50,550},{100,550},{150,550},{200,550},{250,550},{300,550},{350,550},{400,550},{450,550},{500,550},{550,550},{600,550},{650,550},{700,550},

    };
    for(auto it : map_){
        blocks_.push_back((Box(boxxi, it)));
    }
    
}
