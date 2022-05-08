#include "Player.hpp"
#include "Game.hpp"
namespace coup
{
    class Assassin: public Player
    {
        private:
            Game *playerGame;
        public:
            Assassin(Game &game, std::string name);
            void coup(Player &player) override;
            std::string role() override;
            void income() override;
            void foreign_aid() override;
            void excludeFromGame(Player &player);
    };
};