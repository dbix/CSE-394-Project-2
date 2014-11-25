//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//

#include "blackjack.h"
#include "Player.h"
#include <string>
#include <iostream>

#ifndef __Game_H_
#define __Game_H_


class Game {
private:
    std::vector<Player> players;
public:
    Game();
    void play();
    int playersLeft();
    void displayPlayerScore(GenericPlayer p);
};


#endif //__Game_H_
