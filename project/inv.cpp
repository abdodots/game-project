#include "inv.h"
#include <iostream>

using namespace std;

inventory::inventory()
{
  inv_size = 100; // المساحة الأساسية للانفينتوري
  x = 0; // عدد البوشن في الانفينتوري
  y = 0; // عدد البويسين في الانفينتوري
  z = 0; // عدد الشيلد الي في الانفينتوري
  a = 0; // عدد الويبون الي في الانفينتوري
}

// الفانكشن دي الي هتشيك ينفع نضيف عنصر ولا لا

bool inventory::check(int item_size)
{
  if (inv_size + item_size >= 0)
    return true;
  else
    return false;
}

// الفانكشن دي هتضيف العنصر للانفينتوري

void inventory::add_item(int item_size)
{
  if (check(item_size))
  {
    inv_size += item_size;

    // هنا علشان نشوف هو اختار ايه ونزوده

    if (item_size == -10) 
    {
        x++; 
    }
    else if (item_size == -15)
    {
        y++;
    }
    else if (item_size == -30) {
        z++;
    }
    else if (item_size == -40)
    {
        a++;
    }
    cout << "Item added. Inventory size: " << inv_size << endl;
  }
  else
  {
    cout << "Can`t add this item!" << endl;
  }
}

void inventory::delet_item(int item_size)
{
  inv_size -= item_size;

  // هنا علشان نشوف هو استعمل ايه ونمسحه

  if (item_size == -10)
  {
      x--;
  }
  else if (item_size == -15)
  {
      y--;
  }
  else if (item_size == -30) {
      z--;
  }
  else if (item_size == -40)
  {
      a--;
  }
  cout << "Item deleted. Inventory size: " << inv_size << endl;
}

void inventory::get_items()
{
    cout << "your potions number : " << x << endl;
    cout << "your poisons number : " << y << endl;
    cout << "your shields number : " << z << endl;
    cout << "your weapons number : " << a << endl;
}