#pragma once
#include "Creature.hpp"
#include <array>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "ClassesLogic.hpp"

class Monster : public Creature
{
public:
  enum class Type
  {
    DRAGON,
    ORC,
    SLIME,
    max_types_
  };

private:
  static const Creature &getDefaultCreature(Type type)
  {
    static const std::array<Creature,
                            static_cast<std::size_t>(Type::max_types_)>
        monsterData{{{"dragon", 'D', 20, 4, 100},
                     {"orc", 'o', 4, 2, 25},
                     {"slime", 's', 1, 1, 10}}};
    return monsterData[static_cast<std::size_t>(type)];
  }

public:
  Monster(Type type);
  static Monster getRandomMonster()
  {
    int num{getRandomNumber(0, static_cast<int>(Type::max_types_) - 1)};
    return Monster{static_cast<Type>(num)};
  }
  void monsterAnnounce() const;
};
