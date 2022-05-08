#include "Player.hpp"
#include "Game.hpp"
namespace coup
{
    class Captain: public Player
    {
        private:
            Game *playerGame;
        public:
            Captain(Game &game, std::string name);
            void steal(Player &player);
            static void block(Player &player);
            void coup(Player &player) override;
            std::string role() override;
            void income() override;
            void foreign_aid() override;
            void excludeFromGame(Player &player);
    };
};