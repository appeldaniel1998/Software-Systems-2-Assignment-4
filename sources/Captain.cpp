#include "Captain.hpp"
using namespace std;
using namespace coup;
namespace coup
{
    Captain::Captain(Game &game, string name): Player(move(name))
    {
        const int maxPlayers = 6;
        if (game.getPlayerList().size() >= maxPlayers)
        {
            __throw_invalid_argument("Too many players!");
        }
        this->playerGame = &game;
        game.addPlayer(*this);
    }
    void Captain::steal(Player &player)
    {
        this->playerGame->makeTurn(*this);
        this->setOperatedOn(player);
        this->setLastOper("steal");
        if(player.coins() >= 2)
        {
            player.addCoins(-2);
            this->addCoins(2);
        }
        else if (player.coins() == 1)
        {
            player.addCoins(-1);
            this->addCoins(1);
        }
        else
        {
            ;
        }
    }
    void Captain::block(Player &player)
    {
        if(player.getLastOper() == "steal")
        {
            player.addCoins(-2);
            player.getOperatedOn()->addCoins(2);
        }
        else
        {
            __throw_invalid_argument("Cannot block!");
        }
    }
    void Captain::coup(Player &player)
    {
        this->playerGame->makeTurn(*this);
        const int coupCost = 7;
        if (this->coins() < coupCost)
        {
            __throw_invalid_argument("There are not enough coins for a coup!");
        }
        this->addCoins(-coupCost);
        this->excludeFromGame(player);
        this->setLastOper("coup");
    }
    void Captain::excludeFromGame(Player &player)
    {
        player.setIsInGame(false);
        this->playerGame->removePlayer(player);
    }
    std::string Captain::role()
    {
        return "Captain";
    }
    const int maxPlayers = 6;
    const int coupCost = 7;
    const int maxCoinsAllowed = 10;
    void Captain::income()
    {
        if(this->coins() >= maxCoinsAllowed)
        {
            __throw_invalid_argument("A coup should be made!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(1);
        this->setLastOper("income");
    }
    void Captain::foreign_aid()
    {
        if(this->coins() >= maxCoinsAllowed)
        {
            __throw_invalid_argument("A coup should be made!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(2);
        this->setLastOper("foreign_aid");
    }
}