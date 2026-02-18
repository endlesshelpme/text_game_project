#pragma once
#include <string>
#include <string_view>
class Creature
{
public:
    Creature(std::string name, char sym, int hp, int damage, int gold);
    const std::string &getName() const;
    const char getSym() const;
    const int getHp() const;
    const int getDamage() const;
    const int getGold() const;
    void reduceHp(int x);
    bool isDead() const;
    void addGold(int x);

protected:
    std::string name_;
    char sym_;
    int hp_;
    int damage_;
    int gold_;
};