#include "Monster.hpp"
#include <iostream>
#include <windows.h>
#include "Logic.hpp"

void Monster::monsterAnnounce() const
{
    setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "You have encountered a " << getName() << " (" << getSym() << ").\n";
}
Monster::Monster(Type type)
    : Creature{getDefaultCreature(type)}
{
}
