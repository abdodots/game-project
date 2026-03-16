#include <iostream>
using namespace std;

//الكلاس دي هتكون كل مهمتها انها بتزود هيلث الشخصية
//وهعملها فاكنشن لكدا وواحده تانية علشان تحدد مساحتها في الانفينتوري

class potion
{
public:
	potion();
	~potion();
	int healing();
	int size();

private:

};

//الكلاس ده كل مهمته انه لما بنرميه علي العدو الي قدامنا بينقص من هيله
//وهنعمل فانكشن لكدا ودي لما العدو بيستدعاها بتنقص من هيله
//وهنعمل كمان فانكشن علشان تحدد مساحتها من الانفينتوري
//والسم ده لو استعملته ضد الشخصية الي قدامك هياثر علي الهيلث بتاعه بس ومش هياثر علي الدرع لو معاه درع

class poison
{
public:
	poison();
	~poison();
	int damage();
	int size();

private:

};

//ده الدرع ولو اللاعب اختاره هيضيفله حاجة زي الهيلث 
//بس ده مش بيتاثر بالسم لاكن هيلث الشخصية بيتاثر بالسم عادي

class shield
{
public:
	shield();
	~shield();
	void set_health(int x);
	int size();

private:
	int health;

};

class weapon
{
public:
	weapon();
	~weapon();
	int heavy_attack();
	int melee_attack();
	int size();

private:
	int health ;

};


