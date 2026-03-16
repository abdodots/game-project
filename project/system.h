#pragma once
#include <iostream>
#include "charecter.h"
#include "inv.h"
#include "items.h"
using namespace std;

class GameSystem : public charecter 
{
public:
  // فانكشن لعرض حالة الشخصية
  void showStats(string name, int hp, int st, int sp);

  // Alias for possible typo "howStats"
  void showStats(string name, int hp, int st, int sp);

  // تشيك لو الشخصية لسه عايشة
  bool isAlive(int health) { return health > 0; }

  int showMenu();

  int basic_Attack();

  void sp_po(int x);
  void take_damage(int x);
  void set_stamina();
};


class GameSystemInventory : public inventory
{
public:
	void get_items();
};

class GameSystemPotion : public potion
{
public:
	int healing();
	int size();
};

class GameSystemPoison : public poison
{
public:
	int damage();
	int size();
};

class GameSystemShield : public shield
{
public:
	void set_health(int x);
	int size();
};

class GameSystemWeapon : public weapon
{
public:
	int heavy_attack();
	int melee_attack();
};