/*
Menu.cpp
Salih Özbek
19.12.2025
*/

#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Menu::Menu(string menuTitle) {
	this->title = menuTitle;    // alýnan title ile yeni bir menu objesi olusturan constructor
}
Menu::~Menu(){} // default destructor

void Menu::AddOption(string option) {
	options.push_back(option); // yeni secenek ekle
}

void Menu::ClearScreen() { // ekraný temizleme
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void Menu::WaitForUser() { // kullanýcý yazýlarý okuyabilsin diye ekraný bekletme
	#ifdef _WIN32
		cout << endl;
		system("pause");
	#else
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	#endif
}

int Menu::DisplayAndGetChoice() {
	ClearScreen();
	cout << "|=========" << this->title << "=========|" << endl;
	
	for (int i = 0; i < options.size(); i++) {   // option'larý yazdýr
		cout << (i + 1) << "- " << options[i] << endl;
	}
	cout << "____________________________" << endl;
	cout << "Choose one : ";

	int choice;
	cin >> choice;
	while (cin.fail() || choice < 1 || choice > options.size()) { // hata kontrolu-> eger gecersiz secim yapilirsa yeniden sor
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid Choice! Please Try Again : ";
		cin >> choice;
	}

	return choice;  // alinan secimi geri dondur. BookStore'da ona gore islem yapilacak
}