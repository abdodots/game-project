#include "inv.h"
#include <iostream>

using namespace std;

inventory::inventory()
{
  inv_size = 100; 
  pos_number = 0; 
  poi_number = 0; 
  shi_number = 0; 
  wea_number = 0; 
}


bool inventory::check(int item_size)
{
  if (inv_size + item_size >= 0)
    return true;
  else
    return false;
}


void inventory::add_item(int item_size)
{
  if (check(item_size))
  {
    inv_size += item_size;

    if (item_size == -10) 
    {
        pos_number++;
    }
    else if (item_size == -15)
    {
        poi_number++;
    }
    else if (item_size == -30) {
        shie_number++;
    }
    else if (item_size == -40)
    {
        wea_number++;
    }
    cout << "Item added. Inventory size: " << inv_size << endl;
  }
  else
  {
    cout << "Don`t Have Enogh Space!" << endl;
  }
}

void inventory::add_item_plyer2(int item_size)
{
    if (check(item_size))
    {
        inv_size += item_size;

        if (item_size == -10)
        {
            pos_number++;
        }
        else if (item_size == -15)
        {
            poi_number++;
        }
        else if (item_size == -30) {
            shie_number++;
        }
        else if (item_size == -40)
        {
            wea_number++;
        }
    }
}

void inventory::delet_item(int item_size)
{
  inv_size -= item_size;


  if (item_size == -10)
  {
      pos_number--;
  }
  else if (item_size == -15)
  {
      poi_number--;
  }
  else if (item_size == -30) {
      shie_number--;
  }
  else if (item_size == -40)
  {
      wea_number--;
  }
  cout << "Item deleted. Inventory size: " << inv_size << endl;
}

void inventory::get_items()
{
    cout << "your potions number : " << pos_number << endl;
    cout << "your poisons number : " << poi_number << endl;
    cout << "your shields number : " << shie_number << endl;
    cout << "your weapons number : " << wea_number << endl;
}

int inventory::get_size()
{
    return inv_size;
}
int inventory::get_pos_number()
{
    return pos_number;
}
int inventory::get_poi_number()
{
    return poi_number;
}
int inventory::get_shie_number()
{
    return shie_number;
}
int inventory::get_wea_number()
{
    return wea_number;
}
void inventory::set_pos_number()
{
    pos_number--;
}
void inventory::set_poi_number()
{
    poi_number--;
}
void inventory::set_shie_number()
{
    shie_number--;
}
void inventory::set_wea_number()
{
    wea_number--;
}

