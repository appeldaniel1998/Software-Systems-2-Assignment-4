#pragma once
#include<iostream>
#include<vector>
#include<list>
#include "Player.hpp"
#include <string>
using namespace coup;
namespace coup
{
    class Game
    {
        private:
            std::vector<Player> playerList;
            std::list<Player> turnQueue;
            bool moveMade;
        public:
            Game();
            std::string turn();
            std::vector<std::string> players();
            std::string winner();
            std::vector<Player> getPlayerList();
            void addPlayer(Player &player);
            void removePlayer(Player &player);
            void makeTurn(Player &player);
            void returnPlayer(Player &player);
            int find(int id);
            void sortPlayerList();
    };
};