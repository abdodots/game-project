#ifndef INVENTORY_H
#define INVENTORY_H

class inventory
{
private:
    int inv_size;

public:
    inventory();

    void set_size(int size);

    void get_item(int item);

    bool check(int size);

    void add_item(int size);

    void delet_item(int size);
};

#endif
