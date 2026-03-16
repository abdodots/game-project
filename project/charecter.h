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
	int basic_attack(); // دي هتبقي اكنه بيضرب بايده وهتعمل دامج -5 
	void take_damage(int x); // دي بقي هتاخد قيمة الدامج وتشوف تنقصه من الدرع ولا من الدم 
	void set_stamina(); // دي هتزود قيمة الستامينا 5 بعد كل راوند
	void set_sp_po(int x); // ودي بقي الي هتاخد قيمة الدامج الي بعمله للعدو وتزوده علي الاسبيشيال باور
	virtual int special_attack() = 0; // ودي بقي الفانكشن الي الكاركترز التانيين لما يورثوها تكتبها علي حسب الشخصية 
	void set_shield(int x);

private:

protected:
	string name; // دي انا مش ادتها قيمة ابتدائية علشان كل شخصية تكتب القيمة الابتدائية بتاعتها علي حسب اسمها
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





