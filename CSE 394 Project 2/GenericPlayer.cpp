//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//

#include "GenericPlayer.h"

using namespace std;

GenericPlayer::GenericPlayer(string name) : Hand()
{
	playerName = name;
}

bool GenericPlayer::isBusted() const
{
    return false;
}

void GenericPlayer::bust() const
{
    cout << this << " has busted.\n";
}

string GenericPlayer::getPlayerName() const
{
    return playerName;
}

Hand GenericPlayer::getHand()
{
    return hand;
}

void GenericPlayer::setName(string name)
{
    playerName = name;
}

ostream& operator<<(ostream& os, const GenericPlayer& gp)
{
	os << gp.getPlayerName().c_str();
	return os;
}
