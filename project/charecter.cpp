#include "charecter.h"
#include <iostream>

using namespace std;


charecter::charecter():health(100),defence(0),stamina(100),special_power(0)
{
}

charecter::~charecter()
{
}

int charecter::basic_attack()
{
	stamina -= 5;
	return -10;
}

void charecter::take_damage(int x)
{
	if (x == -15) {
		health += x; 
	}
	else 
	{
		if (defence + x >= 0)
		{
			defence += x;
		}
		else if (defence + x < 0 )
		{
			int stp = x;
			stp += defence;
			defence = 0;
			health += stp;
		}
		else
		{
			health += x;
		}
	}
}

void charecter::set_stamina()
{
	if (stamina + 5 >= 100) {
		stamina = 100;
	}
	else
	{
		stamina += 5;
	}
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

warrior::warrior():charecter()
{
	name = "Warrior";
}

warrior::~warrior()
{
}


int warrior::special_attack()
{
	if (special_power == 100)
	{
		stamina += 50;
		return -70;
	}
	else
	{
		cout << "You Don`t Have Enogh Special Power points!" << endl;

	}
}

mage::mage():charecter()
{
	name = "Mage";
}

mage::~mage()
{
}

int mage::special_attack()
{
	if (special_power == 100)
	{
		health += 50;
		return -50;

	}
	else
	{
		cout << "You Don`t Have Enogh Special Power points!" << endl;
	}
}

archer::archer():charecter()
{
	name = "Archer";
}

archer::~archer()
{
}


int archer::special_attack()
{
	if (special_power == 100)
	{
		stamina = 100;
		health = 100;
		return 0;
	}
	else
	{
		cout << "You Don`t Have Enogh Special Power points!" << endl;
	}
}

int charecter::get_sp_po()
{
	return special_power;
}

int charecter::get_health()
{
	return health;
}

int charecter::get_defence()
{
	return defence;
}

int charecter::get_stamina()
{
	return stamina;
}

void charecter::set_health(int x)
{
	if (health + x >= 100) {
		health = 100;
	}
	else
	{
		health += x;
	}
}

void charecter::set_defence()
{
	defence += 50;
}

void charecter::set_stamina(int x)
{
	if (stamina + x >= 100) {
		stamina = 100;
	}
	else
	{
		stamina += x;
	}
}