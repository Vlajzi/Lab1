#pragma once
#include "ListNode.h"

class SortedList
{
public:
	SortedList();
	~SortedList();
	void AddElem(short value);
	short Get();
private:
	ListNode* Root;
	int n;


};
