//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//

#include "Hand.h"
#include "Deck.h"
#include <random>
#include <algorithm>
#include <ctime>

Deck::Deck() : Hand({})
{
}

void Deck::populate()
{
    deckVector = {
            new Card(Suit::CLUB, Rank::TWO),
            new Card(Suit::CLUB, Rank::THREE),
            new Card(Suit::CLUB, Rank::FOUR),
            new Card(Suit::CLUB, Rank::FIVE),
            new Card(Suit::CLUB, Rank::SIX),
            new Card(Suit::CLUB, Rank::SEVEN),
            new Card(Suit::CLUB, Rank::EIGHT),
            new Card(Suit::CLUB, Rank::NINE),
            new Card(Suit::CLUB, Rank::TEN),
            new Card(Suit::CLUB, Rank::JACK),
            new Card(Suit::CLUB, Rank::QUEEN),
            new Card(Suit::CLUB, Rank::KING),
            new Card(Suit::CLUB, Rank::ACE),
            new Card(Suit::DIAMOND, Rank::TWO),
            new Card(Suit::DIAMOND, Rank::THREE),
            new Card(Suit::DIAMOND, Rank::FOUR),
            new Card(Suit::DIAMOND, Rank::FIVE),
            new Card(Suit::DIAMOND, Rank::SIX),
            new Card(Suit::DIAMOND, Rank::SEVEN),
            new Card(Suit::DIAMOND, Rank::EIGHT),
            new Card(Suit::DIAMOND, Rank::NINE),
            new Card(Suit::DIAMOND, Rank::TEN),
            new Card(Suit::DIAMOND, Rank::JACK),
            new Card(Suit::DIAMOND, Rank::QUEEN),
            new Card(Suit::DIAMOND, Rank::KING),
            new Card(Suit::DIAMOND, Rank::ACE),
            new Card(Suit::HEART, Rank::TWO),
            new Card(Suit::HEART, Rank::THREE),
            new Card(Suit::HEART, Rank::FOUR),
            new Card(Suit::HEART, Rank::FIVE),
            new Card(Suit::HEART, Rank::SIX),
            new Card(Suit::HEART, Rank::SEVEN),
            new Card(Suit::HEART, Rank::EIGHT),
            new Card(Suit::HEART, Rank::NINE),
            new Card(Suit::HEART, Rank::TEN),
            new Card(Suit::HEART, Rank::JACK),
            new Card(Suit::HEART, Rank::QUEEN),
            new Card(Suit::HEART, Rank::KING),
            new Card(Suit::HEART, Rank::ACE),
            new Card(Suit::SPADE, Rank::TWO),
            new Card(Suit::SPADE, Rank::THREE),
            new Card(Suit::SPADE, Rank::FOUR),
            new Card(Suit::SPADE, Rank::FIVE),
            new Card(Suit::SPADE, Rank::SIX),
            new Card(Suit::SPADE, Rank::SEVEN),
            new Card(Suit::SPADE, Rank::EIGHT),
            new Card(Suit::SPADE, Rank::NINE),
            new Card(Suit::SPADE, Rank::TEN),
            new Card(Suit::SPADE, Rank::JACK),
            new Card(Suit::SPADE, Rank::QUEEN),
            new Card(Suit::SPADE, Rank::KING),
            new Card(Suit::SPADE, Rank::ACE)
    };
}

void Deck::shuffle()
{
    srand((unsigned int) time(0));
    random_shuffle(deckVector.begin(), deckVector.end());
}

void Deck::deal(Hand &hand)
{
    Card c1 = *deckVector.back();
    hand.add(c1);
    deckVector.pop_back();
    deckVector.shrink_to_fit();
    
    Card c2 = *deckVector.back();
    hand.add(c2);
    deckVector.pop_back();
    deckVector.shrink_to_fit();
}

void Deck::dealOne(Hand &hand)
{
    Card c = *deckVector.back();
    hand.add(c);
    deckVector.pop_back();
    deckVector.shrink_to_fit();
}

void Deck::additionalCards(GenericPlayer &gp)
{
    deal(gp);
}

int Deck::remaining()
{
    deckVector.shrink_to_fit();
    return (int) deckVector.size();
}

void Deck::printDeck()
{
    
    for (int i = 0; i < DECK_SIZE; i++) {
        std::cout << i+1 << " " << deckVector[i]->getRankSuit() << ", valueOfRank=" << Card::valueOfRank(deckVector[i]->getRank()) << "\n";
    }
    std::cout << std::endl;
}
