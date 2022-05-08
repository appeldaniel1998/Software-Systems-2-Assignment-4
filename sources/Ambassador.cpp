#include "Ambassador.hpp"
#include "Captain.hpp"
using namespace std;
using namespace coup;
namespace coup
{
    Ambassador::Ambassador(Game &game, std::string name): Player(move(name))
    {
        const int maxPlayerSize = 6;
        if (game.getPlayerList().size() >= maxPlayerSize)
        {
            __throw_invalid_argument("Too many players!");
        }
        this->playerGame = &game;
        game.addPlayer(*this);
    }
    void Ambassador::transfer(Player &fromPlayer, Player &toPlayer)
    {
        const int maxLegitCoins = 10;
        if(this->coins() >= maxLegitCoins)
        {
            __throw_invalid_argument("A coup should be made!");
        }
        if(fromPlayer.coins() < 1)
        {
            __throw_invalid_argument("Transfer impossible!");
        }
        this->playerGame->makeTurn(*this);
        fromPlayer.addCoins(-1);
        toPlayer.addCoins(1);
    }
    void Ambassador::block(Player &player)
    {
        if(player.getLastOper() == "steal")
        {
            player.addCoins(-2);
            player.getOperatedOn()->addCoins(2);
        }
    }
    void Ambassador::coup(Player &player)
    {
        const int coupCost = 7;
        if (this->coins() < coupCost)
        {
            __throw_invalid_argument("There are not enough coins for a coup!");
        }
        if (!player.getIsInGame())
        {
            __throw_invalid_argument("Player already dead!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(-coupCost);
        this->excludeFromGame(player);
        this->setLastOper("coup");
    }
    void Ambassador::excludeFromGame(Player &player)
    {
        player.setIsInGame(false);
        this->playerGame->removePlayer(player);
    }
    std::string Ambassador::role()
    {
        return "Ambassador";
    }

    void Ambassador::income()
    {
        const int maxCoinNum = 10;
        if(this->coins() >= maxCoinNum)
        {
            __throw_invalid_argument("A coup should be made!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(1);
        this->setLastOper("income");
    }
    void Ambassador::foreign_aid()
    {
        const int maxCoinNum = 10;
        if(this->coins() >= maxCoinNum)
        {
            __throw_invalid_argument("A coup should be made!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(2);
        this->setLastOper("foreign_aid");
    }

}