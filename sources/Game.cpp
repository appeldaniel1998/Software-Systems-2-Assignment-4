 #include "Game.hpp"
 using namespace std;
 using namespace coup;
 namespace coup
 {
    const int maxPlayers = 6;
    const int coupCost = 7;
    const int maxCoinsAllowed = 10;
    Game::Game()
    {
        this->playerList= {};
        this->turnQueue = {};
        this->moveMade = false;
    }
    string Game::turn()
    {
        return this->turnQueue.front().getName();
    }
    vector<string> Game::players()
    {
        vector<string> ret = {};
        for(uint i = 0; i < this->playerList.size(); i++)
        {
            ret.push_back(this->playerList.at(i).getName());
        }
        return ret;
    }
    string Game::winner()
    {
        if(this->playerList.size() == 1 && this->moveMade)
        {
            return this->playerList.at(0).getName();
        }
        __throw_invalid_argument("No winner available!");
    }
    vector<Player> Game::getPlayerList()
    {
        return this->playerList;
    }
    void Game::addPlayer(coup::Player &player)
    {
        if(this->moveMade)
        {
            __throw_invalid_argument("A move was already made!");
        }
        this->playerList.push_back(player);
        this->turnQueue.push_back(player);
    }
    void Game::removePlayer(Player &player)
    {
        for(uint i = 0; i < this->playerList.size(); i++)
        {
            if(this->playerList.at(i).getId() == player.getId())
            {
                this->playerList.erase(this->playerList.begin() + i);
            }
        }
        this->turnQueue.remove(player);
    }
    void Game::makeTurn(Player &player)
    {
        if(this->playerList.size() < 2 || this->playerList.size() > maxPlayers)
        {
            __throw_invalid_argument("Invalid game!");
        }
        if(player.getId() == this->turnQueue.front().getId())
        {
            this->turnQueue.pop_front();
            this->turnQueue.push_back(player);
            this->moveMade = true;
        }
        else
        {
            __throw_invalid_argument("Its another player's turn!");
        }
    }
    void Game::sortPlayerList()
    {
        vector<Player> tempVec;
        while(!playerList.empty())
        {
            Player minIdPlayer = playerList.at(0);
            for (size_t i = 1; i < playerList.size(); i++)
            {
                if(minIdPlayer.getId() > playerList.at(i).getId())
                {
                    minIdPlayer = playerList.at(i);
                }
            }
            tempVec.push_back(minIdPlayer);
            playerList.erase(remove(playerList.begin(), playerList.end(), minIdPlayer), playerList.end());
        }
        this->playerList = tempVec;
    }
    void Game::returnPlayer(Player &player)
    {
        player.setIsInGame(true);
        this->playerList.push_back(player);
        this->sortPlayerList();
        list<Player> newQueue;
        bool flag = false;
        if (this->playerList.size() != 3)
        {
            while(!turnQueue.empty())
            {
                if(turnQueue.front().getId() == player.getId() + 1)
                {
                    newQueue.push_back(player);
                    flag = true;
                }
                newQueue.push_back(turnQueue.front());
                turnQueue.pop_front();
            }
        }

        else
        {
            while(!turnQueue.empty())
            {
                newQueue.push_back(turnQueue.front());
                if(turnQueue.front().getId() == player.getId() - 1)
                {
                    newQueue.push_back(player);
                    flag = true;
                }
                turnQueue.pop_front();
            }
        }
        
        if(!flag)
        {
            newQueue.push_front(player);
        }
        this->turnQueue = newQueue;
    }
 }
