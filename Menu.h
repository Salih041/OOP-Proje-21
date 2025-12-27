// Menu.h
// Salih Özbek
// 19.12.2025


#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

class Menu
{
private:
	std::string title;   // menu basligi
	std::vector<std::string> options;  // seceneklerin tutuldugu vector
public:
	Menu(std::string menuTitle); // constructor fonksiyon
	~Menu(); // default destructure
	int DisplayAndGetChoice(); // Secenekleri basan ve kullanýcýdan secim alan fonksiyon
	void AddOption(std::string option); // yeni secenek ekleme fonksiyonu

	static void ClearScreen(); // ekraný temizle
	static void WaitForUser(); // kullanýcýdan bir tuþa basmasýný iste, ekran temizlenmeden önce okunmasý için
};

#endif