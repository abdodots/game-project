#include <iostream>
#include "items.h"
#include "charecter.h"
#include "inv.h"
#include "GameSystem.h"


using namespace std;

int main()
{
	GameSystem G1;
	G1.choose_charecter();
	G1.select_items();
	
	return 0;
}
