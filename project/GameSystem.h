#pragma once
#include <iostream>
#include "charecter.h"
#include "inv.h"
#include "items.h"
using namespace std;

class GameSystem
{
public:
	GameSystem();
	~GameSystem();
	void choose_charecter();
	void select_items();
	void round1();
	void round2();
	bool is_alivep1();
	bool is_alivep2();

private:
	charecter* player1;
	inventory inv_player1;
	potion pot_player1;
	poison poi_player1;
	shield shi_player1;
	weapon wea_player1;
	charecter* player2;
	inventory inv_player2;
	potion pot_player2;
	poison poi_player2;
	shield shi_player2;
	weapon wea_player2;

};


