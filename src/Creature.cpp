#include "Creature.hpp"


Creature::Creature(std::string name, char sym, int hp, int damage, int gold) : name_{name}, sym_{sym}, hp_{hp}, damage_{damage}, gold_{gold} {}

const std::string &Creature::getName() const { return name_; }
const char Creature::getSym() const { return sym_; }
const int Creature::getHp() const { return hp_; }
const int Creature::getDamage() const { return damage_; }
const int Creature::getGold() const { return gold_; }
void Creature::reduceHp(int x) { hp_ -= x; }
bool Creature::isDead() const
{
    if (hp_ <= 0)
        return true;
    else
        return false;
}

void Creature::addGold(int x) {gold_+= x;}