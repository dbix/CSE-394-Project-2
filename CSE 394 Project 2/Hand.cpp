//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//

#include "Hand.h"

Hand::Hand()
{
    handVector = std::vector<Card>();
    number_of_aces = 0;
}

Hand::Hand(Card one, Card two)
{
	handVector.push_back(one);
	handVector.push_back(two);
}

bool Hand::add(Card card)
{
    if (Card::valueOfRank(card.getRank()) == 11) {
        number_of_aces++;
    }
    handVector.push_back(card);
    return true;
}

int Hand::getTotal()
{
    int total = 0;
    for (int i = 0; i < handVector.size(); i++) {
        if (!handVector[i].isFaceUp()) return 0;
        total += Card::valueOfRank(handVector[i].getRank());
    }
    for (int i = 0; i < number_of_aces && total > 21; i++) {
        if (total > 21) total = total - 10;
    }
    return total;
}

Card* Hand::get(unsigned long index)
{
    return &handVector[index];
}

Hand Hand::getHand()
{
    return *this;
}

void Hand::clear()
{
    std::vector<Card>::iterator it = handVector.begin(), itEnd = handVector.end();
    handVector.erase(it, itEnd);
}

unsigned long Hand::size()
{
    return handVector.size();
}