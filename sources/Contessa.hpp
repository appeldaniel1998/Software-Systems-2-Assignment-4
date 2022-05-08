#include "Player.hpp"
#include "Game.hpp"
namespace coup
{
    class Contessa: public Player
    {
        private:
            Game *playerGame;
        public:
            Contessa(Game &game, std::string name);
            void block(Player &player);
            void coup(Player &player) override;
            std::string role() override;
            void income() override;
            void foreign_aid() override;
            void excludeFromGame(Player &player);
    };
};