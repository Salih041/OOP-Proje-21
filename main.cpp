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
	setlocale(LC_ALL, "tr_TR"); // türkçe karakterler
	BookStore myStore; // Programýn ana kontrolcüsü: BookStore classýndan üretilen nesne
	myStore.Run(); // programýn ana döngüsünü çalýþtýran fonksiyon.
	return 0;
}