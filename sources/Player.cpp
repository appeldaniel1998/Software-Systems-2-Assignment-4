#include "Player.hpp"
using namespace std;
using namespace coup;
namespace coup
{
    int Player::countPlayers = 0;

    Player::Player(string name)
    {
        this->name = move(name);
        this->isInGame = true;
        this->id = countPlayers++;
        this->lastOper = "";
        this->numOfCoins = 0;
        this->operatedOn = NULL;
        this->blockable = false;
    }
    Player::Player(const Player &player)
    {
        this->numOfCoins = player.numOfCoins;
        this->name = player.name;
        this->isInGame = player.isInGame;
        this->id = player.id;
        this->lastOper = player.lastOper;
        this->operatedOn = NULL;
        this->blockable = false;
    }
    int Player::coins() const
    {
        return this->numOfCoins;
    }
    void Player::addCoins(int num)
    {
        this->numOfCoins += num;
    }
    std::string Player::getName() const
    {
        return this->name;
    }
    int Player::getId() const
    {
        return this->id;
    }
    void Player::setLastOper(std::string oper)
    {
        this->lastOper = move(oper);
    }
    std::string Player::getLastOper() const
    {
        return this->lastOper;
    }
    void Player::setIsInGame(bool val)
    {
        this->isInGame = val;
    }
    bool Player::getIsInGame() const
    {
        return this->isInGame;
    }
    void Player::income()
    {
        __throw_invalid_argument("Function should be implemented!");
    }
    void Player::foreign_aid()
    {
        __throw_invalid_argument("Function should be implemented!");
    }
    void Player::coup(Player &player)
    {
        __throw_invalid_argument("Function should be implemented!");
    }
    std::string Player::role()
    {
        __throw_invalid_argument("Function should be implemented!");
    }
    bool Player::operator==(const Player &player) const
    {
        return this->getId() == player.id;
    }
    bool Player::operator!=(const Player &player) const
    {
        return !(*this == player);
    }
    Player* Player::getOperatedOn() const
    {
        return this->operatedOn;
    }
    void Player::setOperatedOn(Player &player)
    {
        this->operatedOn = &player;
    }
    bool Player::getBlockable() const
    {
        return this->blockable;
    }
    void Player::setBlockable(bool val)
    {
        this->blockable = val;
    }
}