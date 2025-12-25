/*
	main.cpp
	Salih Özbek
	25.12.2025
*/

#include "BookStore.h"
#include <iostream>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "tr_TR");
	BookStore myStore;
	myStore.Run();
	return 0;
}