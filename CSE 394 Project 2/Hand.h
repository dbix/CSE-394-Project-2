//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//


#include <vector>
#include <iostream>
#include <random>
#include "Card.h"

#ifndef __Hand_H_
#define __Hand_H_

class Hand {
private:
    std::vector<Card> handVector;
    int number_of_aces;
public:
    Hand();
    //Hand(std::initializer_list<Card> list);
    Hand(Card one, Card two);
    bool add(Card card);
    void clear();
    int getTotal();
    virtual Hand getHand();
    Card* get(unsigned long index);
    unsigned long size();
};

#endif //__Hand_H_
