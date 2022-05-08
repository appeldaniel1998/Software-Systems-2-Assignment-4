#pragma once
#include<iostream>
namespace coup
{
    class Player
    {
        private:
            static int countPlayers;
            int numOfCoins;
            std::string name;
            bool isInGame;
            int id;
            std::string lastOper;
            Player *operatedOn;
            bool blockable;
        public:
            Player(std::string name);
            Player(const Player &player);
            virtual void income();
            virtual void foreign_aid();
            virtual void coup(Player &player);
            int coins() const;
            virtual std::string role();
            std::string getName() const;
            int getId() const;
            void addCoins(int num);
            void setLastOper(std::string oper);
            std::string getLastOper() const;
            void setIsInGame(bool val);
            bool getIsInGame() const;
            bool operator ==(const Player &player) const;
            bool operator != (const Player &player) const;
            Player* getOperatedOn() const;
            void setOperatedOn(Player &player);
            bool getBlockable() const;
            void setBlockable(bool val);
    };
};