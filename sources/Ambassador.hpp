#include "Player.hpp"
#include "Game.hpp"

namespace coup
{
    class Ambassador: public Player
    {
        private:
            Game *playerGame;
        public:
            Ambassador(Game &game, std::string name);
            void transfer(Player &fromPlayer, Player &toPlayer);
            static void block(Player &player);
            void coup(Player &player) override;
            std::string role() override;
            void income() override;
            void foreign_aid() override;
            void excludeFromGame(Player &player);
    };
};