#pragma once
#include <iostream>
#include "charecter.h"
#include "inv.h"
#include "items.h"
using namespace std;

class GameSystem
{
public:
  // فانكشن لعرض حالة الشخصية
  void showStats(string name, int hp, int st, int sp);

  // تشيك لو الشخصية لسه عايشة
  bool isAlive(int health) { return health > 0; }

  int showMenu();
};
