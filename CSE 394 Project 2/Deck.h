//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//

#include <iostream>

#include "blackjack.h"
#include "Card.h"
#include "GenericPlayer.h"

#ifndef __Deck_H_
#define __Deck_H_

#define DECK_SIZE 52

class Deck : public Hand {
private:
    std::vector<Card*> deckVector;
public:
    Deck();
    void populate();
    void shuffle();
    void deal(Hand &hand);
    void dealOne(Hand &hand);
    void additionalCards(GenericPlayer &gp);
    int remaining();
    void printDeck();

};

#endif //__Deck_H_
