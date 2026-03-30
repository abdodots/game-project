#include "items.h"
#include <iostream>
using namespace std;

potion::potion()
{
}

potion::~potion()
{
}

int potion::healing()
{
	return 25; 
}

int potion::size()
{
	return -10; 
}

poison::poison()
{
}

poison::~poison()
{
}

int poison::damage()
{
	return -15; 
}
int poison::size()
{
	return -15; 
}

shield::shield():health(50)
{
}

shield::~shield()
{
}



void shield::set_health(int x)
{
	health += x ; 
}

int shield::size()
{
	return -30; 
}

weapon::weapon():health(100)
{
}

weapon::~weapon()
{
}


int weapon::heavy_attack()
{
	health -= 50; 
	return -50; 
}


int weapon::melee_attack()
{
	health -= 20; 
	return -25; 
}



int weapon::size()
{
	return -40; 
}

int weapon::get_health()
{
	return health;
}

void weapon::set_health()
{
	health = 100;
}
