#pragma once


class ListNode
{
public:
	ListNode()
	{
		next = nullptr;
	}

	~ListNode() = default;

	inline short Value()
	{
		return value;
	}
	inline void Value(short value)
	{
		this->value = value;
	}
	inline ListNode* Next()
	{
		return next;
	}
	inline void Next(ListNode* next)
	{
		this->next = next;
	}
private:
	short value;
	ListNode* next;
};
