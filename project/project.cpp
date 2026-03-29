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
	while (true) {
		G1.round1();
		if (G1.is_alivep2())
		{
			cout << "\n====================\n";
			cout << " You Won :) ";
			cout << "\n====================\n";
			break;
		}
		G1.round2();
		if (G1.is_alivep1())
		{
			cout << "\n====================\n";
			cout << " Hhhhh....Noooop :} ";
			cout << "\n====================\n";
			break;
		}
	}
	
	return 0;
}
