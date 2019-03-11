#include "SortedList.h"



SortedList::SortedList()
{
	Root = nullptr;
	int n = 0;
}

SortedList::~SortedList()
{
	if (Root != nullptr)
	{
		while (n != 0)
		{
			Get();
		}
	}

}

void SortedList::AddElem(short value)
{
	ListNode* newValue = new ListNode();
	newValue->Value(value);
	n++;
	if (Root == nullptr)
	{
		Root = newValue;
	}
	else
	{
		if (Root->Value() <= value)
		{
			newValue->Next(Root);
			Root = newValue;
		}
		else
		{
			ListNode* Back = Root;
			ListNode* Fort = Root->Next();
			while (true)
			{
				if (Fort == nullptr)
				{
					Back->Next(newValue);
					newValue->Next(Fort);
					break;
				}

				if (Fort->Value() < value)
				{
					Back->Next(newValue);
					newValue->Next(Fort);
					break;
				}
				Back = Fort;
				Fort = Back->Next();
			}

		}
	}

}



short SortedList::Get()
{

	short val = Root->Value();
	ListNode* tmp = Root;
	Root = Root->Next();
	tmp->~ListNode();
	n--;
	return val;
}