#include "inv.h"
#include <iostream>

using namespace std;

inventory::inventory()
{
  inv_size = 100; 
  pos_num = 0; 
  poi_num = 0; 
  shi_num = 0; 
  wea_num = 0; 
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
        pos_num++;
    }
    else if (item_size == -15)
    {
        poi_num++;
    }
    else if (item_size == -30) {
        shi_num++;
    }
    else if (item_size == -40)
    {
        wea_num++;
    }
    cout << "Item added. Inventory size: " << inv_size << endl;
  }
  else
  {
    cout << "Don`t Have Enogh Space!" << endl;
  }
}

void inventory::add_item_pl2(int item_size)
{
    if (check(item_size))
    {
        inv_size += item_size;

        if (item_size == -10)
        {
            pos_num++;
        }
        else if (item_size == -15)
        {
            poi_num++;
        }
        else if (item_size == -30) {
            shi_num++;
        }
        else if (item_size == -40)
        {
            wea_num++;
        }
    }
}

void inventory::delet_item(int item_size)
{
  inv_size -= item_size;


  if (item_size == -10)
  {
      pos_num--;
  }
  else if (item_size == -15)
  {
      poi_num--;
  }
  else if (item_size == -30) {
      shi_num--;
  }
  else if (item_size == -40)
  {
      wea_num--;
  }
  cout << "Item deleted. Inventory size: " << inv_size << endl;
}

void inventory::get_items()
{
    cout << "your potions number : " << pos_num << endl;
    cout << "your poisons number : " << poi_num << endl;
    cout << "your shields number : " << shi_num << endl;
    cout << "your weapons number : " << wea_num << endl;
}

int inventory::get_size()
{
    return inv_size;
}
int inventory::get_pos_num()
{
    return pos_num;
}
int inventory::get_poi_num()
{
    return poi_num;
}
int inventory::get_shi_num()
{
    return shi_num;
}
int inventory::get_wea_num()
{
    return wea_num;
}
void inventory::set_pos_num()
{
    pos_num--;
}
void inventory::set_poi_num()
{
    poi_num--;
}
void inventory::set_shi_num()
{
    shi_num--;
}
void inventory::set_wea_num()
{
    wea_num--;
}

