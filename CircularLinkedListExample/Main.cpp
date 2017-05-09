#include <iostream>
#include "InfiniteList.h"

int main()
{
	//create a new infinitlist
	InfiniteList<int> list = InfiniteList<int>();

	for (int i = 0; i < 10; i++)
	{
		list.addItem(i);
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << list.getCurrentItem();
		list.next();
	}

	//wait for char
	getchar();

	//delete the memory for the list
	list.clear();

	return 0;
}