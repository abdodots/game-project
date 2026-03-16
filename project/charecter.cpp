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

warrior::warrior():charecter()
{
	name = "Warrior";
}

warrior::~warrior()
{
}

// السبيشيال اتتاك بتاعت المحارب انه بيرجع دامع بمقدار -70 للعدو الي قدامه
// وهيزود الاستامينا بمقدار 50

int warrior::special_attack()
{
	if (special_power == 100)
	{
		return -70;
		stamina += 50;
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

// دي بقي هتسحب من العدو 50 من الاسبيشيال باور بتاعته وهتزودهم عندها 
// وهتزود الهيلث بتاعها بمقدار 50

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

// ده هيرجع الستامينا بتاعته 100 تاني والهيلث برضو 100

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
	health += x;
}
