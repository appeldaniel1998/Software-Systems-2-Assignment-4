#include "Contessa.hpp"
using namespace std;
using namespace coup;
namespace coup
{
    const int maxPlayers = 6;
    const int coupCost = 7;
    const int maxCoinsAllowed = 10;
    Contessa::Contessa(Game &game, string name): Player(move(name))
    {
        if (game.getPlayerList().size() >= maxPlayers)
        {
            __throw_invalid_argument("Too many players!");
        }
        this->playerGame = &game;
        game.addPlayer(*this);
    }
    void Contessa::block(Player &player)
    {
        if (player.role() == "Assassin" && player.getLastOper() == "coup" && player.getBlockable())
        {
            this->playerGame->returnPlayer(*(player.getOperatedOn()));
        }
        else
        {
            __throw_invalid_argument("Block impossible!");
        }
    }
    void Contessa::coup(Player &player)
    {
        this->playerGame->makeTurn(*this);
        if (this->coins() < coupCost)
        {
            __throw_invalid_argument("There are not enough coins for a coup!");
        }
        this->addCoins(-coupCost);
        this->excludeFromGame(player);
        this->setLastOper("coup");
    }
    void Contessa::excludeFromGame(Player &player)
    {
        player.setIsInGame(false);
        this->playerGame->removePlayer(player);
    }
    std::string Contessa::role()
    {
        return "Contessa";
    }

    void Contessa::income()
    {
        if(this->coins() >= maxCoinsAllowed)
        {
            __throw_invalid_argument("A coup should be made!");
        }
        this->playerGame->makeTurn(*this);
        this->addCoins(1);
        this->setLastOper("income");
    }
    void Contessa::foreign_aid()
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