//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//


#include "GenericPlayer.h"

#ifndef __House_H_
#define __House_H_


class House : public GenericPlayer {
public:
    House(std::string name);
    bool isHitting() const;
    void flipFirstCard();
};


#endif //__House_H_
