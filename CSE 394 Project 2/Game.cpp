//
// Created by Derek Bixler on 10/25/14.
// Copyright (c) 2014 ___DEREKBIXLER___. All rights reserved.
//


#include "Game.h"

using namespace std;

Game::Game()
{
    
}

void Game::play()
{
    players.clear();
    string playerName;
    char playAgain;
	int nPlayers;
    char playerAnswer;
    bool valid_answer;
    House house("House");
    int secret_house_total;

    do {
        if (players.size() > 0) players.clear();

        /* Create the deck */
        Deck deck;
        deck.populate();
        deck.shuffle();
        
        /* Create the players and deal their initial hand */
        cout << "How many players? (1-7): ";
        cin >> nPlayers;
        if (nPlayers > 0) {
            for (int i = 0; i < nPlayers; i++) {
                cout << "Enter player name: ";
                cin >> playerName;
                Player player(playerName);
                deck.deal(player);
                player.get(0)->flip();
                player.get(1)->flip();
                players.push_back(player);
            }
        }
        
        cout << "\n";
        
        /* Create the House */
        house = House("house");
        deck.deal(house);
        house.get(1)->flip();
        secret_house_total = 0;
        
        /* Show initial scores */
        for (int i = 0; i < players.size(); i++) {
            displayPlayerScore(players[i]);
        }
        displayPlayerScore(house);
        cout << "\n";
        
        do {
            /* Ask players if they want to draw */
            for (int i = 0; i < players.size(); i++) {
                if (players[i].isHitting()) {
                    cout << players[i] << ", do you want a hit? (Y/N): ";
                    do {
                        cin >> playerAnswer;
                        if (playerAnswer == 'Y' || playerAnswer == 'y') {
                            players[i].setHitting(true);
                            valid_answer = true;
                        } else if (playerAnswer == 'N' || playerAnswer == 'n') {
                            players[i].setHitting(false);
                            valid_answer = true;
                        } else {
                            valid_answer = false;
                        }
                    } while(!valid_answer);
                    if (players[i].isHitting()) {
                        deck.dealOne(players[i]);
                        unsigned long size = players[i].size()-1;
                        players[i].get(size)->flip();
                    }
                }
                house.get(0)->flip();
                secret_house_total = house.getTotal();
                house.get(0)->flip();
                if (secret_house_total < 16) {
                    deck.dealOne(house);
                    unsigned long size = house.size() - 1;
                    house.get(size)->flip();
                }
                
                if (players[i].getTotal() > 21) {
                    players[i].setBusted(true);
                    players.erase(players.begin()+i);
                }
                cout << "\n";

                for (int i = 0; i < players.size(); i++) {
                    displayPlayerScore(players[i]);
                }
                displayPlayerScore(house);
                
                cout << "\n";
            }
        } while (playersLeft() != 0 && secret_house_total < 21);
        if (house.isBusted()) {
            for (int i = 0; i < players.size() - 1; i++) {
                cout << players[i] << ", ";
            }
            cout << ", and " << players[players.size()] << " win!";
        } else {
            int closest[players.size()];
            int min = 21;
            int mindex = 0;
            for (int i = 0; i < players.size(); i++) {
                closest[i] = 21 - players[i].getTotal();
                if (closest[i] < min) {
                    min = closest[i];
                    mindex = i;
                }
            }
            
            house.get(0)->flip();
            cout << "\n\nGame over, ";
            if (21 - house.getTotal() < min) {
                cout <<"\n\nHouse wins!\n";
            } else if (21 - house.getTotal() == min) {
                cout << "Tie\n";
            } else {
                cout <<"\n\n" << players[mindex] << " wins!\n";
            }
            

            for (int i = 0; i < players.size(); i++) {
                displayPlayerScore(players[i]);
            }
            displayPlayerScore(house);
        }
        cout << "Do you want to play play again? (y/n): ";
        cin >> playAgain;

    } while (tolower(playAgain) == 'y');
}

int Game::playersLeft()
{
    int players_left = 0;
    for (int i = 0; i < players.size(); i++) {
        if (players[i].isHitting()) {
            players_left++;
        }
    }
    return players_left;
}

void Game::displayPlayerScore(GenericPlayer p)
{
    std::string str_out = std::string("");
    std::string looking_for = std::string("XX");
    for (int i = 0; i < p.size(); i++) {
        str_out.append(p.get(i)->getRankSuit() + "\t");
    }
    if (str_out.find(looking_for) != std::string::npos) {
        /* String not found */
        cout << p << ":\t\t" <<  str_out << "\t\t(" << "XX" << ")\n";
    } else {
        cout << p << ":\t\t" <<  str_out << "\t\t(" << p.getTotal() << ")\n";
    }
}

