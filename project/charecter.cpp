#include "charecter.h"
#include <iostream>

using namespace std;


charecter::charecter():health(100),defence(0),stamina(100),special_power(100)
{
}

charecter::~charecter()
{
}

int charecter::basic_attack()
{
	stamina -= 5;
	return -5;
}

void charecter::take_damage(int x)
{
	if (x == -15) {
		health += x; // دي علشان لو العدو رمي عليا بويزين واحنا قولنا انه هياثر علي الدم علي طول حتي لو في درع
	}
	else 
	{
		if (defence + x >= 0)
		{
			defence += x;
		}
		else
		{
			health += x;
		}
	}
}

void charecter::set_stamina()
{
	stamina += 5;
}

void charecter::set_sp_po(int x)
{
	if (special_power + x > 100)
	{
		special_power = 100;
	}
	else
	{
		special_power += x;
	}
}

