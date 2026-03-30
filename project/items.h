#ifndef PROJECT_ITEMS_H
#define PROJECT_ITEMS_H

#include <iostream>
using namespace std 


class potion
{
public:
	potion();
	~potion();
	int healing();
	int size();

private:

};



class poison
{
public:
	poison();
	~poison();
	int damage();
	int size();

private:

};

class shield
{
public:
	shield();
	~shield();
	void set_health(int x);
	int size();

private:
	int health;

};

class weapon
{
public:
	weapon();
	~weapon();
	int heavy_attack();
	int melee_attack();
	int size();
	int get_health();
	void set_health();

private:
	int health ;

};



#endif 



