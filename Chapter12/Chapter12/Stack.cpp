#include "Stack.h"
#include <iostream>


Stack::Stack(int n)
{
	pitems = new Item[n];
	size = n;
	top = 0;
}

Stack::Stack(const Stack & st)
{
	size = st.size;
	pitems = new Item[size];
	top = st.top;
	for (int i = 0; i < top; i++)
	{
		pitems[i] = st.pitems[i];
	}
}

Stack::~Stack()
{
	delete[] pitems;
	pitems = nullptr;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == size;
}

bool Stack::push(const Item & item)
{
	if (isfull())
	{
		return false;
	}
	
	pitems[top++] = item;
	return true;
}

bool Stack::pop(Item & item)
{
	if (isempty())
	{
		return false;
	}

	item = pitems[--top];
	return true;
}

Stack & Stack::operator=(const Stack & st)
{
	size = st.size;
	pitems = new Item[size];
	top = st.top;
	for (int i = 0; i < top; i++)
	{
		pitems[i] = st.pitems[i];
	}

	return *this;
}


