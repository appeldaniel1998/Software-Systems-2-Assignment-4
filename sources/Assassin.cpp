#include "Assassin.hpp"
using namespace std;
using namespace coup;
namespace coup
{
    Assassin::Assassin(Game &game, std::string name): Player(move(name))
    {
        const int maxLegitPlayerSize = 6;
        if (game.getPlayerList().size() >= maxLegitPlayerSize)
        {
            __throw_invalid_argument("Too many players!");
        }
        this->playerGame = &game;
        game.addPlayer(*this);
    }

    void Assassin::coup(Player &player)
    {
        if (this->coins() < 3)
        {
            __throw_invalid_argument("There are not enough coins for a coup!");
        }
        if (!player.getIsInGame())
        {
            __throw_invalid_argument("Player already dead!");
        }
        const int normalCoupCost = 7;
        if (this->coins() < normalCoupCost)
        {
            this->addCoins(-3);
            this->setBlockable(true);
        }
        else
        {
            this->addCoins(-normalCoupCost);
            this->setBlockable(false);
        }
        this->playerGame->makeTurn(*this);
        this->setOperatedOn(player);
        this->excludeFromGame(player);
        this->setLastOper("coup");
    }
    void Assassin::excludeFromGame(Player &player)
    {
        player.setIsInGame(false);
        this->playerGame->removePlayer(player);
    }
    
    std::string Assassin::role()
    {
        return "Assassin";
    }

    void Assassin::income()
    {
        const int maxCoins = 10;
        if(this->coins() >= maxCoins)
        {
            __throw_invalid_argument("A coup should be made!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(1);
        this->setLastOper("income");
    }
    void Assassin::foreign_aid()
    {
        const int maxCoins = 10;
        if(this->coins() >= maxCoins)
        {
            __throw_invalid_argument("A coup should be made!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(2);
        this->setLastOper("foreign_aid");
    }
}