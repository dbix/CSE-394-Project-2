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
protected:
    Hand hand;
    bool busted = false;
    std::string playerName;
public:
    GenericPlayer() {};
    GenericPlayer(std::string name) : Hand() {
        playerName = name;
    }
    virtual bool isHitting() const = 0;
    bool isBusted() const;
    void bust() const;
    Hand getHand();
    virtual std::string getPlayerName() const;
    void setName(std::string name);
    void setBusted(bool is_busted);
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& dt);
};

#endif //__GenericPlayer_H_
