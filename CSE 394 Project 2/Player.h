//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//


#include <vector>
#include <iostream>
#include <random>
#include "GenericPlayer.h"

#ifndef __Player_H_
#define __Player_H_

class Player : public GenericPlayer {
private:
    bool is_hitting = true;
	int *n;
public:
    Player(std::string name);
    virtual bool isHitting() const;
    void setHitting(bool hitting);
    void win();
    void lose();
    void push();
};

#endif //__Player_H_
