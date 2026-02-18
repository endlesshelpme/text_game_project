#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <chrono>
#include <windows.h>
#include "Logic.hpp"
#include "Creature.hpp"
#include "Monster.hpp"
#include "Player.hpp"
#include "Ui.hpp"

int main()
{
    Player playerCharacter{makeCharacter()};
    gameCycle(playerCharacter);
    return 0;
}