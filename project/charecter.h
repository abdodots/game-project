#pragma once
#include <iostream>
#include "inv.h"
#include "items.h"

using namespace std;

class  charecter
{
public:
	 charecter();
	~ charecter();
	int basic_attack();  
	void take_damage(int x);  
	void set_stamina(); 
	void set_sp_po(int x); 
	virtual int special_attack() = 0; 
	void set_shield(int x);
	int get_sp_po();
	int get_health();
	int get_stamina();
	int get_defence();
	void set_health(int x);
	void set_defence();
	void set_stamina(int x);

private:

protected:
	string name; 
	int health;
	int defence;
	int stamina;
	int special_power;


};


class  warrior: public charecter
{
public:
	 warrior();
	~ warrior();
	int special_attack();

private:

};

class mage:public charecter
{
public:
	mage();
	~mage();
	int special_attack();

private:

};

class archer:public charecter
{
public:
	archer();
	~archer();
	int special_attack();
	

private:

};





