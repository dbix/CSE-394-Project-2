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
	string playerName, *userIn;
	char playAgain;
	int nPlayers;
	std::vector<Player> players;

    do {
        if (players.size() > 0) players.clear();

        /* Create the players */
        cout << "How many players? (1-7): ";
        cin >> nPlayers;
        if (nPlayers > 0) {
            for (int i = 0; i < nPlayers; i++) {
                cout << "Enter player name: ";
                cin >> playerName;
                Player player(playerName);
                cout << "player.getPlayerName()=" << player<< "\n";
                cout << "playerName=" << player << "\n";
                players.push_back(player);
                cout << "players[i].getPlayerName()=" << players[i] << "\n\n";

            }
        }
        cout << players.size() << endl;
        for (unsigned int i = 0; i < players.size(); i++) {
            cout << players[i] << "\n";
        }

        cout << "Do you want to play playAgain? (y/n): ";
        cin >> playAgain;

    } while (tolower(playAgain) == 'y');
}
