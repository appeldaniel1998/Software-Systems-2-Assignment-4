#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace std;
using namespace coup;

TEST_CASE("check function operation (not throw)")
{
    Game game{};
    Duke duke{game, "Moshe"};
	Assassin assassin{game, "Yossi"};
	Ambassador ambassador{game, "Meirav"};
	Captain captain{game, "Reut"};
	Contessa contessa{game, "Gilad"};

    CHECK_NOTHROW(duke.coins());
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(duke.role());
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(duke.coins());

    CHECK_NOTHROW(assassin.coins());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(assassin.role());
    CHECK_NOTHROW(assassin.coins());

    CHECK_NOTHROW(ambassador.coins());
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(ambassador.role());
    CHECK_NOTHROW(ambassador.coins());

    CHECK_NOTHROW(captain.coins());
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(captain.role());
    CHECK_NOTHROW(captain.coins());

    CHECK_NOTHROW(contessa.coins());
    CHECK_NOTHROW(contessa.foreign_aid());
    CHECK_NOTHROW(contessa.income());
    CHECK_NOTHROW(contessa.role());
    CHECK_NOTHROW(contessa.coins());
}