//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//

#include "Player.h"

Player::Player(std::string name) : GenericPlayer(name)
{
    is_hitting = true;
}

bool Player::isHitting() const
{
    if (isBusted()) {
        return false;
    } else {
        return is_hitting;
    }
}

void Player::setHitting(bool hitting)
{
    is_hitting = hitting;
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
