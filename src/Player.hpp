#pragma once
#include <string>
#include <string_view>
#include "Creature.hpp"
#include <iostream>
class Player : public Creature
{
public:
    Player(std::string name);
    void levelUp();
    int getLevel() const;
    bool hasWon() const;
    void playerInfo() const;
    void welcomePlayer() const;

private:
    int level_{1};
};
