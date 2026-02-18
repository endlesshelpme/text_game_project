#include "Player.hpp"
#include "Monster.hpp"
#include "Creature.hpp"
#include <string>
#pragma once
void setColor(int color);


void fightMonster(Player &player);

bool attackMonster(Player &player, Monster &monster);

bool attackPlayer(Player &player, Monster &monster);

void battleCycle(Player &player, Monster &monster);

void faultDodge(Player &player, Monster &monster);

std::string makeCharacter();

void gameCycle(Player &player);