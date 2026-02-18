#include "Player.hpp"


Player::Player(std::string name) : Creature{name, '@', 10, 1, 0} {}

void Player::levelUp()
{
    ++level_;
    ++damage_;
}

int Player::getLevel() const { return level_; }

bool Player::hasWon() const
{
    if (level_ >= 20)
        return true;
    else
        return false;
}

void Player::playerInfo() const { std::cout << "You have " << getHp() << " health and are carrying " << getGold() << " gold.\n"; }

void Player::welcomePlayer() const { std::cout << "Welcome, " << getName() << "\n"; }
