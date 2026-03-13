#include "items.h"
using namespace std;

potion::potion()
{
}

potion::~potion()
{
}

int potion::healing()
{
	return 25; // دي علشان لما الشخصية تستدعاها تزودلها الهيلث بمقدار 25
}
int potion::size()
{
	return -10; // دي بقي علشان لما نستدعي الفانكشن دي في الانفينتوري تنقص 10 من مساحتها
}

poison::poison()
{
}

poison::~poison()
{
}

int poison::damage()
{
	return -15; // دي لما العدو يستدعاها عنده هتنقصله هيله بمقدار -15
}
int poison::size()
{
	return -10; // ودي لما الانفينتوري تستدعاها هتنقص من مساحتها -10
}
