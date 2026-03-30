#ifndef INVENTORY_H
#define INVENTORY_H
#include "items.h"
#include <vector>

using namespace std;

class inventory
{
private:
    int inv_size;
    int pos_number;
    int poi_number;
    int shie_number;
    int wea_number;

public:
    inventory();
    void get_items();
    bool check(int item_size); 
    void add_item(int item_size);
    void add_item_player2(int item_size);
    void delet_item(int item_size);
    int get_size();
    int get_pos_number();
    int get_poi_number();
    int get_shie_number();
    int get_wea_number();
    void set_pos_number();
    void set_poi_number();
    void set_shie_number();
    void set_wea_number();
};

#endif
