//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//


#include "Hand.h"
#include <ostream>

#ifndef __GenericPlayer_H_
#define __GenericPlayer_H_

class GenericPlayer : public Hand {
private:
    Hand hand;
    bool busted;
protected:
    std::string playerName;
public:
    GenericPlayer(std::string name);
    virtual bool isHitting() const = 0;
    bool isBusted() const;
    void bust() const;
    Hand getHand();
    virtual std::string getPlayerName() const;
    void setName(std::string name);
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& dt);
};

#endif //__GenericPlayer_H_
