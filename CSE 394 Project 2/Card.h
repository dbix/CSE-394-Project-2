//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//


#ifndef __Card_H_
#define __Card_H_

enum Suit {
    CLUB = 0, DIAMOND = 1, HEART = 2, SPADE = 3, len = 4
};

enum Rank {
    TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8,
    NINE = 9, TEN = 10, JACK = 10, QUEEN = 10, KING = 10, ACE = 11, length = 13
};

class Card {
private:
    Suit suit;
    Rank rank;
    bool faceUp;
public:
    Card();
    Card(Suit s, Rank r);
    bool isFaceUp() const;
    void flip();
    int getValue() const;
    Rank const &getRank();
    Suit const &getSuit();
};

#endif //__Card_H_
