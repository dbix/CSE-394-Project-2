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
    faceUp = !faceUp;
}

Rank const &Card::getRank()
{
    return rank;
}

Suit const &Card::getSuit()
{
    return suit;
}

std::string Card::getRankSuit()
{
    if (!faceUp) {
        return "XX";
    } else {
        std::string s;
        if (rank == 11) {
            s = "J";
        } else if (rank == 12) {
            s = "Q";
        } else if (rank == 13) {
            s = "K";
        } else if (rank == 14) {
            s = "A";
        } else {
            s = std::to_string(rank);
        }
        
        switch (suit) {
            case CLUB:
                s+="c";
                break;
            case DIAMOND:
                s+="d";
                break;
            case HEART:
                s+="h";
                break;
            case SPADE:
                s+="s";
                break;
        }
        return s;
    }
}

int Card::valueOfRank(Rank r)
{
    int val_rank = (int) r;
    if (val_rank == 11) {
        return 10;
    } else if (val_rank == 12) {
        return 10;
    } else if (val_rank == 13) {
        return 10;
    } else if (val_rank == 14) {
        return 11;
    } else {
        return val_rank;
    }
}
