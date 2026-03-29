#ifndef INVENTORY_H
#define INVENTORY_H
#include "items.h"
#include <vector>

using namespace std;

class inventory
{
private:
    int inv_size;
    int pos_num;
    int poi_num;
    int shi_num;
    int wea_num;

public:
    inventory();
    void get_items();
    bool check(int item_size); 
    void add_item(int item_size);
    void add_item_pl2(int item_size);
    void delet_item(int item_size);
    int get_size();
    int get_pos_num();
    int get_poi_num();
    int get_shi_num();
    int get_wea_num();
    void set_pos_num();
    void set_poi_num();
    void set_shi_num();
    void set_wea_num();
};

#endif
