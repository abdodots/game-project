#include "GameSystem.h"
#include "charecter.h"
#include "inv.h"
#include "items.h"
#include <iostream>
using namespace std;

GameSystem::GameSystem()
{
}

GameSystem::~GameSystem()
{
}

// ?? ??? ??? ??????? ????? ?????? ????? ??????? 

void GameSystem::choose_charecter()
{
	int x;
	while (true) {
		cout << "==========Charecters=========" << endl;
		cout << "1- Warrior\n2-Mage\n3-Archer\n";
		cout << "=============================" << endl;
		cout << "Choose Player One Charecter: ";
		cin >> x;
		if (x == 1)
		{
			player1 = new warrior();
			break;
		}
		else if (x == 2)
		{
			player1 = new mage();
			break;
		}
		else if (x == 3)
		{
			player1 = new archer();
			break;
		}
		else
		{
			cout << "please choose from 1 to 3 !" << endl;
			cout << "=============================" << endl;
		}
	}
	srand(time(0));
	int pl2[3] = { 1,2,3 };
	int pl3[2];
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		if (pl2[i] != x)
		{
			pl3[counter] = pl2[i];
			counter++;
		}
	}
	int plran = pl3[rand() % 2];

	if (plran == 1)
	{
		player2 = new warrior();
	}
	else if (plran == 2)
	{
		player2 = new mage();
	}
	else if (plran == 3)
	{
		player2 = new archer();
	}
	
}

// ?? ??? ????? ?????? ????? ?????? ??? ????? ?? ??????????? ?????? 

void GameSystem::select_items()
{
	cout << "==========Inventory==========" << endl;
	cout << "1- Potion\n2-Poison\n3-Shield\n4-Weapon\n";
	cout << "=============================" << endl;
	cout << "Enter A Number TO Choose Element :) ";
	int x;
	while (inv_player1.get_size()) {
		cin >> x;
		if (x == 1) {
			x = -10;
		}
		else if (x == 2)
		{
			x = -15;
		}
		else if (x == 3)
		{
			x = -30;
		}
		else if (x == 4)
		{
			x = -40;
		}
		else
		{
			cout << "Please Choose Form 1 To 4 !\n=============================\n";
			continue;
		}
		inv_player1.add_item(x);
		if (inv_player1.get_size() < 10) {
			break;
		}
	}
	srand(time(0));
	int y;
	int arr[4] = { 1 ,2,3,4 };
	while (inv_player2.get_size()) {
		y = arr[rand() % 4];
		if (y == 1) {
			y = -10;
		}
		else if (y == 2)
		{
			y = -15;
		}
		else if (y == 3)
		{
			y = -30;
		}
		else if (y == 4)
		{
			y = -40;
		}
		else
		{
			cout << "Please Choose Form 1 To 4 !\n=============================\n";
			continue;
		}
		inv_player2.add_item(y);
		if (inv_player2.get_size() < 10) {
			break;
		}
	}

	cout << "\n=======Player 1 Inventory========\n";
	inv_player1.get_items();
	cout << "==================================\n";
	cout << "\n=======Player 2 Inventory========\n";
	inv_player2.get_items();
	cout << "==================================\n";
}

void GameSystem::round1()
{
	cout << "===========Player 1 Status============\n";
	cout << "Health: " << player1->get_health() << " Defence: " << player1->get_defence() << " Stamina: " << player1->get_stamina() << " Special Power: " << player1->get_sp_po() << endl;
	cout << "=======================================\n";
	cout << "1- Basic Attack\n2- Inventory\n" << endl;
	if (player1->get_sp_po() == 100)
	{
		cout << "3- Special Power"<<endl;
	}
	cout << "=======================================\n";
	cout << "Choose: ";
	int x;
	while (true) {
		cin >> x;
		if (x == 1 || x == 2) {
			break;
		}
		else if (x == 3 && player1->get_sp_po() == 100)
		{
			break;
		}
		else
		{
			cout << "Please Choose A Choise From Up There :( ";
		}
	}
	if (x == 1)
	{
		player2->take_damage(player1->basic_attack());
		player1->set_stamina();
		player1->set_sp_po(5);
	}
	else if (x == 2)
	{
		cout << "===========Player 1 Inventory============\n";
		cout << "1- Potion: " << inv_player1.get_x() << endl;
		cout << "2- Poison: " << inv_player1.get_y() << endl;
		cout << "3- Weapon: " << inv_player1.get_a() << endl;
		cout << "=========================================\n";
		cout << "Choose: ";
		int y;
		while (true) {
			cin >> y;
			if (y == 1 && inv_player1.get_x() >= 1)
			{
				break;
			}
			else if (y == 2 && inv_player1.get_y())
			{
				break;
			}
			else if (y == 3 && inv_player1.get_a())
			{
				break;
			}
			else
			{
				cout << "Please Choose A Choise From Up There :( ";
			}
		}
		if (y == 1 && inv_player1.get_x() >= 1)
		{
			player1->set_health(pot_player1.healing());
			inv_player1.set_x();
			player1->set_stamina();
		}
		else if (y == 2 && inv_player1.get_y())
		{
			player2->take_damage(poi_player1.damage());
			inv_player1.set_y();
			player1->set_stamina();
			player1->set_sp_po(15);
		}
		else if (y == 3 && inv_player1.get_a() >= 1)
		{
			cout << "========================\n";
			cout << "1- Heavy Attack\n2-Melee Attack\n";
			cout << "========================\n";
			int z;
			while (true) {
				cin >> z;
				if (z == 1 && player1->get_stamina() >= 30) {
					break;
				}
				else if (z == 2 && player1->get_stamina() >= 15)
				{
					break;
				}
				else
				{
					cout << "you don`t have enogh stamina! " << endl;
					break;
				}
			}
			if (z == 1 && player1->get_stamina() >= 30) {
				player2->take_damage(wea_player1.heavy_attack());
				player1->set_stamina();
				if (wea_player1.get_health() <= 0) {
					inv_player1.set_a();
				}
			}
			else if (z == 2 && player1->get_stamina() >= 15)
			{
				player2->take_damage(wea_player1.melee_attack());
				player1->set_stamina();
				if (wea_player1.get_health() <= 0) {
					inv_player1.set_a();
				}
			}
		}

	}
	else if (x == 3)
	{
		player2->take_damage(player1->special_attack());
	}
}

void GameSystem::round2()
{
	cout << "===========Player 2 Status============\n";
	cout << "Health: " << player2->get_health() << " Defence: " << player2->get_defence() << " Stamina: " << player2->get_stamina() << " Special Power: " << player2->get_sp_po() << endl;
	cout << "=======================================\n";
	cout << "1- Basic Attack\n2- Inventory\n" << endl;
	if (player2->get_sp_po() == 100)
	{
		cout << "3- Special Power" << endl;
	}
	cout << "=======================================\n";
	cout << "Choose: ";
	int x;
	while (true) {
		cin >> x;
		if (x == 1 || x == 2) {
			break;
		}
		else if (x == 3 && player2->get_sp_po() == 100)
		{
			break;
		}
		else
		{
			cout << "Please Choose A Choise From Up There :( ";
		}
	}
	if (x == 1)
	{
		player1->take_damage(player2->basic_attack());
		player2->set_stamina();
		player2->set_sp_po(5);
	}
	else if (x == 2)
	{
		cout << "===========Player 1 Inventory============\n";
		cout << "1- Potion: " << inv_player2.get_x() << endl;
		cout << "2- Poison: " << inv_player2.get_y() << endl;
		cout << "3- Weapon: " << inv_player2.get_a() << endl;
		cout << "=========================================\n";
		cout << "Choose: ";
		int y;
		while (true) {
			cin >> y;
			if (y == 1 && inv_player2.get_x() >= 1)
			{
				break;
			}
			else if (y == 2 && inv_player2.get_y())
			{
				break;
			}
			else if (y == 3 && inv_player2.get_a())
			{
				break;
			}
			else
			{
				cout << "Please Choose A Choise From Up There :( ";
			}
		}
		if (y == 1 && inv_player2.get_x() >= 1)
		{
			player2->set_health(pot_player2.healing());
			inv_player2.set_x();
			player2->set_stamina();
		}
		else if (y == 2 && inv_player2.get_y())
		{
			player1->take_damage(poi_player2.damage());
			inv_player2.set_y();
			player2->set_stamina();
			player2->set_sp_po(15);
		}
		else if (y == 3 && inv_player2.get_a() >= 1)
		{
			cout << "========================\n";
			cout << "1- Heavy Attack\n2-Melee Attack\n";
			cout << "========================\n";
			int z;
			while (true) {
				cin >> z;
				if (z == 1 && player2->get_stamina() >= 30) {
					break;
				}
				else if (z == 2 && player2->get_stamina() >= 15)
				{
					break;
				}
				else
				{
					cout << "you don`t have enogh stamina! " << endl;
					break;
				}
			}
			if (z == 1 && player2->get_stamina() >= 30) {
				player1->take_damage(wea_player2.heavy_attack());
				player2->set_stamina();
				if (wea_player2.get_health() <= 0) {
					inv_player2.set_a();
				}
			}
			else if (z == 2 && player2->get_stamina() >= 15)
			{
				player1->take_damage(wea_player2.melee_attack());
				player2->set_stamina();
				if (wea_player2.get_health() <= 0) {
					inv_player2.set_a();
				}
			}
		}

	}
	else if (x == 3)
	{
		player1->take_damage(player2->special_attack());
	}
}