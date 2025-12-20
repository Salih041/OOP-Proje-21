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
Menu::~Menu(){} // default destructor. bir sey yapmayacak

void Menu::AddOption(string option) {
	options.push_back(option); // yeni secenek ekle
}

int Menu::DisplayAndGetChoice() {
	cout << "|=========" << this->title << "=========|" << endl;
	
	for (int i = 0; i < options.size(); i++) {   // option'larý yazdýr
		cout << (i + 1) << "- " << options[i] << endl;
	}
	cout << "____________________________" << endl;
	cout << "Ýþlem Seçiniz : ";

	int choice;
	cin >> choice;
	while (cin.fail() || choice < 1 || choice > options.size()) { // hata kontrolu-> eger gecersiz secim yapilirsa yeniden sor
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Gecersiz Secim !! Tekrar Deneyin : ";
		cin >> choice;
	}

	return choice;  // alinan secimi geri dondur ona gore islem yapilacak
}