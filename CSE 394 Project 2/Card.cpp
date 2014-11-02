//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//

#include "Card.h"

Card::Card() {}

Card::Card(Suit s, Rank r) : suit{s}, rank{r}, faceUp{false} {}

bool Card::isFaceUp() const
{
    return faceUp;
}

void Card::flip()
{
    faceUp = true;
}

int Card::getValue() const
{
    if (faceUp) {
        return rank;
    } else {
        return -1;
    }
}

Rank const &Card::getRank()
{
    return rank;
}

Suit const &Card::getSuit()
{
    return suit;
}
