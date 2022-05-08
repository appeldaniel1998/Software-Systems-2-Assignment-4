#include "Duke.hpp"
using namespace std;
using namespace coup;
namespace coup
{
    const int maxPlayers = 6;
    const int coupCost = 7;
    const int maxCoinsAllowed = 10;
    Duke::Duke(Game &game, string name): Player(move(name))
    {
        if (game.getPlayerList().size() >= maxPlayers)
        {
            __throw_invalid_argument("Too many players!");
        }
        this->playerGame = &game;
        game.addPlayer(*this);
    }
    void Duke::tax()
    {
        if(this->coins() >= maxCoinsAllowed)
        {
            __throw_invalid_argument("A coup should be made!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(3);
        this->setLastOper("tax");
    }
    void Duke::block(Player &player)
    {
        if(player.getLastOper() == "foreign_aid")
        {
            player.addCoins(-2);
        }
        else
        {
            __throw_invalid_argument("cannot block this move");
        }
    }
    void Duke::coup(Player &player)
    {
        if (this->coins() < coupCost)
        {
            __throw_invalid_argument("There are not enough coins for a coup!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(-coupCost);
        this->excludeFromGame(player);
        this->setLastOper("coup");
    }
    void Duke::excludeFromGame(Player &player)
    {
        player.setIsInGame(false);
        this->playerGame->removePlayer(player);
    }
    std::string Duke::role()
    {
        return "Duke";
    }


    void Duke::income()
    {
        if(this->coins() >= maxCoinsAllowed)
        {
            __throw_invalid_argument("A coup should be made!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(1);
        this->setLastOper("income");
    }
    void Duke::foreign_aid()
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