#include "system.h"
#include "charecter.h"
#include "inv.h"
#include "items.h"
#include <iostream>
using namespace std;
void GameSystem::showStats(string name, int hp, int st, int sp)
{
  cout << "Name: " << name << endl;
  cout << "Health: " << hp << endl;
  cout << "Stamina: " << st << endl;
  cout << "Special Power: " << sp << endl;
}
int GameSystem::showMenu()
{
  cout << "1. Basic Attack" << endl;
  cout << "2. Special Attack" << endl;
  cout << "3. Use Item" << endl;
  cout << "4. Show Inventory" << endl;
  cout << "5. Exit" << endl;
  int choice;
  cin >> choice;
  return choice;
}
int GameSystem::basic_Attack()
{
  return charecter::basic_attack();
}
void GameSystem::sp_po(int x)
{
  charecter::set_sp_po(x);
}
void GameSystem::take_damage(int x)
{
  charecter::take_damage(x);
}
void GameSystem::set_stamina()
{
  charecter::set_stamina();
}
void GameSystemInventory::get_items()
{
  cout << "Inventory: " << endl;
  cout << "Potions: " << x << endl;
  cout << "Poisons: " << y << endl;
  cout << "Shields: " << z << endl;
  cout << "Weapons: " << a << endl;
}
void GameSystemPotion::get_items()
{
  cout << "Potion Healing: " << healing() << endl;
  cout << "Potion Size: " << size() << endl;
}
void GameSystemPoison::get_items()
{
  cout << "Poison Damage: " << damage() << endl;
  cout << "Poison Size: " << size() << endl;
}
void GameSystemShield::set_health(int x)
{
  shield::set_health(x);
}
void GameSystemShield::get_items()
{
  cout << "Shield Size: " << size() << endl;
}
void GameSystemWeapon::heavy_attack()
{
  cout << "Heavy Attack Damage: " << heavy_attack() << endl;
}void GameSystemWeapon::get_items()
{
  cout << "Weapon Size: " << size() << endl;
}