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
	int player_choise;
	while (true) {
		cout << "==========Charecters=========" << endl;
		cout << "1- Warrior      Special Power :- \"Give 70 of damage And Recharge Stamina With 50\"\n2- Mage         Special Power :- \"She Will Take 50 From the Enemy`s SP Power To Her And Recharge Her Health With 50\"\n3- Archer       Special Power :- \"Recharge Health Full And Stamina\"\n";
		cout << "=============================" << endl;
		cout << "Choose Player One Charecter: ";
		cin >> player_choise;
		if (player_choise == 1)
		{
			player1 = new warrior();
			break;
		}
		else if (player_choise == 2)
		{
			player1 = new mage();
			break;
		}
		else if (player_choise == 3)
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
	int choises[3] = { 1,2,3 };
	int allowed_choises[2];
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		if (choises[i] != player_choise)
		{
			allowed_choises[counter] = choises[i];
			counter++;
		}
	}
	int ran_choise = allowed_choises[rand() % 2];

	if (ran_choise == 1)
	{
		player2 = new warrior();
		cout << "\nThe Computer Choosen ==> Warrior\n\n";
	}
	else if (ran_choise == 2)
	{
		player2 = new mage();
		cout << "\nThe Computer Choosen ==> Mage\n\n";
	}
	else if (ran_choise == 3)
	{
		player2 = new archer();
		cout << "\nThe Computer Choosen ==> Archer\n\n";
	}
	
}


void GameSystem::select_items()
{
	cout << "==========Inventory==========" << endl;
	cout << "1- Potion    Take From Inventory Size ==> 10  \"Healing You With 25\" \n2- Poison    Take From Inventory Size ==> 15  \"Damage Your Enemy With 15 And Charge Your SP With 15\"\n3- Shield    Take From Inventory Size ==> 30  \"Increase Charecter`s Defence With 50\"\n4- Weapon    Take From Inventory Size ==> 40  \"It Has Melee And Heavy Attack But Keep An Eye ON Your stamina And His Health\"\n";
	cout << "=============================" << endl;
	cout << "Enter A Number TO Choose Element :) ";
	int pl1_choise;
	while (inv_player1.get_size()) {
		cin >> pl1_choise;
		if (pl1_choise == 1) {
			pl1_choise = -10;
		}
		else if (pl1_choise == 2)
		{
			pl1_choise = -15;
		}
		else if (pl1_choise == 3)
		{
			pl1_choise = -30;
			player1->set_defence();
		}
		else if (pl1_choise == 4)
		{
			pl1_choise = -40;
		}
		else
		{
			cout << "Please Choose Form 1 To 4 !\n=============================\n";
			continue;
		}
		inv_player1.add_item(pl1_choise);
		if (inv_player1.get_size() < 10) {
			break;
		}
	}
	srand(time(0));
	int pl2_choise;
	int choises[4] = { 1 ,2,3,4 };
	while (inv_player2.get_size()) {
		pl2_choise = choises[rand() % 4];
		if (pl2_choise == 1) {
			pl2_choise = -10;
		}
		else if (pl2_choise == 2)
		{
			pl2_choise = -15;
		}
		else if (pl2_choise == 3)
		{
			pl2_choise = -30;
			player2->set_defence();
		}
		else if (pl2_choise == 4)
		{
			pl2_choise = -40;
		}
		else
		{
			cout << "Please Choose Form 1 To 4 !\n=============================\n";
			continue;
		}
		inv_player2.add_item_pl2(pl2_choise);
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
	cout << "\n===========Player 1 Status============\n";
	cout << "Health: " << player1->get_health() << " Defence: " << player1->get_defence() << " Stamina: " << player1->get_stamina() << " Special Power: " << player1->get_sp_po() << endl;
	cout << "=======================================\n";
	cout << "1- Basic Attack  ==> Make 10 of Damage\n";
	if (inv_player1.get_pos_num() >= 1 || inv_player1.get_poi_num() >= 1 || inv_player1.get_wea_num() >= 1)
	{
		cout <<"2- Inventory     ==> Choose To View Your Items And You Can`t Return\n";
	}
	if (player1->get_sp_po() == 100)
	{
		cout << "3- Special Power ==> This is Our Secrect To Win :)"<<endl;
	}
	cout << "=======================================\n";
	cout << "Choose: ";
	int pl1_choise;
	while (true) {
		cin >> pl1_choise;
		if (pl1_choise == 1 ) {
			break;
		}
		else if (pl1_choise == 2 && inv_player1.get_pos_num() >= 1 || inv_player1.get_poi_num() >= 1 || inv_player1.get_wea_num() >= 1)
		{
			break;
		}
		else if (pl1_choise == 3 && player1->get_sp_po() == 100)
		{
			break;
		}
		else
		{
			cout << "Please Choose A Choise From Up There :( ";
		}
	}
	if (pl1_choise == 1)
	{
		player2->take_damage(player1->basic_attack());
		player1->set_stamina();
		player1->set_sp_po(10);
		cout << "\n ==> Take This Light Punch !\n";
	}
	else if (pl1_choise == 2)
	{
		cout << "\n===========Player 1 Inventory============\n";
		cout << "1- Potion: " << inv_player1.get_pos_num()  << endl;
		cout << "2- Poison: " << inv_player1.get_poi_num() << endl;
		cout << "3- Weapon: " << inv_player1.get_wea_num() <<" Your Weapon Health: "<<wea_player1.get_health()<< endl;
		cout << "=========================================\n";
		cout << "Choose: ";
		int pl1_inv;
		while (true) {
			cin >> pl1_inv;
			if (pl1_inv == 1 && inv_player1.get_pos_num() >= 1)
			{
				break;
			}
			else if (pl1_inv == 2 && inv_player1.get_poi_num() >= 1)
			{
				break;
			}
			else if (pl1_inv == 3 && inv_player1.get_wea_num() >= 1)
			{
				break;
			}
			else
			{
				cout << "Please Choose A Choise From Up There :( ";
			}
		}
		if (pl1_inv == 1 && inv_player1.get_pos_num() >= 1)
		{
			player1->set_health(pot_player1.healing());
			inv_player1.set_pos_num();
			player1->set_stamina();
			cout << "\n ==> You Healed Yourself !!\n";
			
		}
		else if (pl1_inv == 2 && inv_player1.get_poi_num() >= 1)
		{
			player2->take_damage(poi_player1.damage());
			inv_player1.set_poi_num();
			player1->set_stamina();
			player1->set_sp_po(15);
			cout << "\n ==> Take This poison in Your Mouth My Dear Enemy :}\n";
		}
		else if (pl1_inv == 3 && inv_player1.get_wea_num() >= 1)
		{
			cout << "\n========================\n";
			cout << "1- Heavy Attack   \" Takes 60 From Stamina And 50 From Weapon Health\"\n2- Melee Attack   \" Takes 40 From Stamina And 20 From Weapon Health\"\n";
			cout << "========================\n";
			int z;
			while (true) {
				cin >> z;
				if (z == 1 && player1->get_stamina() >= 60) {
					break;
				}
				else if (z == 2 && player1->get_stamina() >= 40)
				{
					break;
				}
				else
				{
					cout << "you don`t have enogh stamina! " << endl;
					break;
				}
			}
			if (z == 1 && player1->get_stamina() >= 60) {
				player2->take_damage(wea_player1.heavy_attack());
				player1->set_stamina(-60);
				player1->set_stamina();
				if (wea_player1.get_health() <= 0) {
					inv_player1.set_wea_num();
					if (inv_player1.get_wea_num() >= 1)
					{
						wea_player1.set_health();
					}
				}
				player1->set_sp_po(50);
				cout << "\n ==> So Strong, isn`t it ?\n";
			}
			else if (z == 2 && player1->get_stamina() >= 40)
			{
				player2->take_damage(wea_player1.melee_attack());
				player1->set_stamina(-40);
				player1->set_stamina();
				if (wea_player1.get_health() <= 0) {
					inv_player1.set_wea_num();
					if (inv_player1.get_wea_num() >= 1)
					{
						wea_player1.set_health();
					}
				}
				player1->set_sp_po(25);
				cout << "\n ==> Hearts?...It Just A Light Attack!\n";
			}
		}

	}
	else if (pl1_choise == 3)
	{
		player2->take_damage(player1->special_attack());
		player1->set_sp_po(-100);
		cout << "\n ==> Now You Will See The real Power....POV !! \n";
	}
}

void GameSystem::round2()
{
	srand(time(0));
	cout << "\n===========Player 2 Status============\n";
	cout << "Health: " << player2->get_health() << " Defence: " << player2->get_defence() << " Stamina: " << player2->get_stamina() << " Special Power: " << player2->get_sp_po() << endl;
	cout << "=======================================\n";
	cout << "1- Basic Attack  ==> Make 10 of Damage\n";
	if (inv_player2.get_pos_num() >= 1 || inv_player2.get_poi_num() >= 1 || inv_player2.get_wea_num() >= 1)
	{
		cout << "2- Inventory     ==> Choose To View Your Items And You Can`t Return\n";
	}
	if (player2->get_sp_po() == 100)
	{
		cout << "3- Special Power ==> This is My Secrect To Win :)" << endl;
	}
	cout << "=======================================\n";
	
	int x;
	int arx[2] = { 1,2 };
	if (player2->get_sp_po() < 100 && inv_player2.get_pos_num() >= 1 || inv_player2.get_poi_num() >= 1 || inv_player2.get_wea_num() >= 1) {
		x = arx[rand() % 2];
	}
	else if (inv_player2.get_pos_num() < 1 && inv_player2.get_poi_num() < 1 && inv_player2.get_wea_num() < 1)
	{
		x = 1;
	}
	else
	{
		x = 3;
	}
	while (true) {
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
		player2->set_sp_po(10);
		cout << "\n ==> Take This Light Punch !\n";
	}
	else if (x == 2)
	{
		cout << "\n===========Player 2 Inventory============\n";
		cout << "1- Potion: " << inv_player2.get_pos_num() << endl;
		cout << "2- Poison: " << inv_player2.get_poi_num() << endl;
		cout << "3- Weapon: " << inv_player2.get_wea_num() << " Your Weapon Health: " << wea_player2.get_health() << endl;
		cout << "=========================================\n";
		int y;
		int ary[3] = { 1,2,3 };
		while (true) {
			y = ary[rand() % 3];
			if (y == 1 && inv_player2.get_pos_num() >= 1)
			{
				break;
			}
			else if (y == 2 && inv_player2.get_poi_num() >= 1)
			{
				break;
			}
			else if (y == 3 && inv_player2.get_wea_num() >= 1)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		if (y == 1 && inv_player2.get_pos_num() >= 1)
		{
			player2->set_health(pot_player2.healing());
			inv_player2.set_pos_num();
			player2->set_stamina();
			cout << "\n ==> I Healed Myself !!\n";
		}
		else if (y == 2 && inv_player2.get_poi_num() >= 1)
		{
			player1->take_damage(poi_player2.damage());
			inv_player2.set_poi_num();
			player2->set_stamina();
			player2->set_sp_po(15);
			cout << "\n ==> Take This poison in Your Mouth Dear Human :}\n";
		}
		else if (y == 3 && inv_player2.get_wea_num() >= 1)
		{
			cout << "\n========================\n";
			cout << "1- Heavy Attack\n2-Melee Attack\n";
			cout << "========================\n";
			int z;
			int arz[2] = { 1,2 };
			while (true) {
				z = arz[rand() % 2];
				if (z == 1 && player2->get_stamina() >= 60) {
					break;
				}
				else if (z == 2 && player2->get_stamina() >= 40)
				{
					break;
				}
				else
				{
					cout << "you don`t have enogh stamina! " << endl;
					break;
				}
			}
			if (z == 1 && player2->get_stamina() >= 60) {
				player1->take_damage(wea_player2.heavy_attack());
				player2->set_stamina(-60);
				player2->set_stamina();
				if (wea_player2.get_health() <= 0) {
					inv_player2.set_wea_num();
					if (inv_player2.get_wea_num() >= 1)
					{
						wea_player2.set_health();
					}
				}
				player2->set_sp_po(50);
				cout << "\n ==> This is How We Hit Weak Human *****\n";
			}
			else if (z == 2 && player2->get_stamina() >= 40)
			{
				player1->take_damage(wea_player2.melee_attack());
				player2->set_stamina(-40);
				player2->set_stamina();
				if (wea_player2.get_health() <= 0) {
					inv_player2.set_wea_num();
					if (inv_player2.get_wea_num() >= 1)
					{
						wea_player2.set_health();
					}
				}
				player2->set_sp_po(25);
				cout << "\n ==>> Don`t Cry Human it Just a Hit!!\n";
			}
		}

	}
	else if (x == 3)
	{
		player1->take_damage(player2->special_attack());
		player2->set_sp_po(-100);
		cout << "\n ==> Do You Think You Are The Only One Who Have Power....POV !! \n";
	}
}

bool GameSystem::is_alivep1()
{
	if (player1->get_health() <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GameSystem::is_alivep2()
{
	if (player2->get_health() <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}