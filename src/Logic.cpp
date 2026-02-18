#include "Logic.hpp"
#include <thread>
#include <chrono>
#include <string>
#include <iostream>
#include "Ui.hpp"


std::string makeCharacter()
{
    std::string name;
    makeCharacterUi();
    std::cin >> name;
    return name;
}

void gameCycle(Player &player)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    player.welcomePlayer();
    while (true)
    {
        if (player.isDead() || player.hasWon())
            break;
        fightMonster(player);
    }
    if (player.hasWon())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "You win! You have " << player.getGold() << " gold.\n";
    }
}


void fightMonster(Player &player)
{
    char playerInput;
    int dodgeChance = rand() % 2;
    Monster mob{Monster::getRandomMonster()};
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mob.monsterAnnounce();
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "(R)un or (F)ight: ";
    std::cin >> playerInput;
    switch (playerInput)
    {
    case 'f':
        battleCycle(player, mob);
        break;
    case 'r':
        if (dodgeChance)
            break;
        else
            faultDodge(player, mob);
        break;
    default:
        break;
    }
}

bool attackMonster(Player &player, Monster &monster)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    monster.reduceHp(player.getDamage());
    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << monster.getName() << " have " << monster.getHp() << " HP remaining.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return monster.isDead();
}

bool attackPlayer(Player &player, Monster &monster)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    player.reduceHp(monster.getDamage());
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "You have " << player.getHp() << " HP remaining.\n";
    return player.isDead();
}

void battleCycle(Player &player, Monster &monster)
{
    while (true)
    {
        if (attackMonster(player, monster))
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You killed the " << monster.getName() << ".\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            player.levelUp();
            player.addGold(monster.getGold());
            std::cout << "You are now level " << player.getLevel() << ".\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You found " << monster.getGold() << " gold.\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        }
        if (attackPlayer(player, monster))
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Too bad you can't take it with you!\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        }
    }
}

void faultDodge(Player &player, Monster &monster)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "You failed to flee.\n";
    while (true)
    {
        if (attackPlayer(player, monster))
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Too bad you can't take it with you!\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        }
        if (attackMonster(player, monster))
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You killed the " << monster.getName() << ".\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            player.levelUp();
            player.addGold(monster.getGold());
            std::cout << "You are now level " << player.getLevel() << ".\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "You found " << monster.getGold() << " gold.\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        }
    }
}
