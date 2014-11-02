//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//

#include "Player.h"

Player::Player(std::string name) : GenericPlayer(name)
{
}

bool Player::isHitting() const
{
    return false;
}

void Player::win()
{
    std::cout << *this << " wins.\n";
}

void Player::lose()
{
    std::cout << *this << " loses.\n";
}

void Player::push()
{
    std::cout << *this << " pushes.\n";
}
