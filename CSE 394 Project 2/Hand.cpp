//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//

#include "Hand.h"

Hand::Hand()
{
}

Hand::Hand(Card one, Card two)
{
	handVector.push_back(one);
	handVector.push_back(two);
}

bool Hand::add(Card card)
{
    handVector.push_back(card);
    return true;
}

int Hand::getTotal()
{
    int total = 0;
    for (unsigned int i = 0; i < handVector.size(); i++) {
        total += handVector[i].getRank();
    }
    return total;
}

Card Hand::get(int index)
{
    return handVector[index];
}

Hand Hand::getHand()
{
    std::cout << "getHand called from Hand.cpp\n";
    return *this;
}

void Hand::clear()
{
    std::vector<Card>::iterator it = handVector.begin(), itEnd = handVector.end();
    handVector.erase(it, itEnd);
}