#include "inv.h"
#include <iostream>

using namespace std;

inventory::inventory()
{
  inv_size = 100; // المساحة الأساسية للانفينتوري
}

void inventory::set_size(int size)
{
  inv_size = size;
}

bool inventory::check(int size)
{
  if (inv_size + size >= 0)
    return true;
  else
    return false;
}

void inventory::add_item(int size)
{
  if (check(size))
  {
    inv_size += size;
    cout << "Item added. Inventory size: " << inv_size << endl;
  }
  else
  {
    cout << "Inventory full!" << endl;
  }
}

void inventory::delet_item(int size)
{
  inv_size -= size;
  cout << "Item deleted. Inventory size: " << inv_size << endl;
}

void inventory::get_item(int item)
{
  cout << "Item number " << item << " selected." << endl;
}