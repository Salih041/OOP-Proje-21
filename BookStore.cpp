// BookStore.cpp
// Salih Özbek
// 20.12.2025

#include "BookStore.h"
#include "Menu.h"
#include "Product.h"
#include "Book.h"
#include "Cash.h"
#include "Check.h"
#include "CreditCard.h"
#include "Payment.h"

// includelar

#include <iostream>
#include <vector>
using namespace std;

BookStore::BookStore() {
	currentCustomer = nullptr;
	LoadData();
}

BookStore::~BookStore() {
	for (Product* p : products) delete p;
	for (Customer* c : customers) delete c;
	products.clear();
	customers.clear();
	cout << "Bellek temizlendi" << endl;
}

void BookStore::LoadData() {
	products.push_back(new Book("Suc ve Ceza", 150, "Dostoyevski", "Is Bankasi", 688));
	products.push_back(new Book("Kasagi", 80, "Omer Seyfettin", "Can", 124));
	//music
	//magazine

	//customers
}

void BookStore::Login()
{
	if (currentCustomer != nullptr) {
	cout << "\nZaten Giris Yapildi: " /*<< currentCustomer->getUsername()*/ << endl;
		return;
	}
	cin.ignore();
	cout << "==== GIRIS YAP ====" << endl;
	string usernameInput, passwordInput;
	cout << "Kullanýcý Adý : ";
	getline(cin, usernameInput);
	cout << "Sifre         : ";
	getline(cin, passwordInput);

	bool isFound = false;
	// customerlar icinde arama 
	// if (c->username == usinput && psw == pswinput ...

	if (isFound)
	{
		cout << "HOS GELDÝNÝZ!" << endl;
	}
	else {
		cout << "\nHATALI KULLANICI ADI VEYA SIFRE!" << endl;
		cout << "Lutfen tekrar deneyin veya kayit olun." << endl;
	}

}

void BookStore::Run() {
	cout << "HOSGELDINIZ" << endl;
	DisplayMenu();
}

// ANA MENU
void BookStore::DisplayMenu() {
	Menu mainMenu("ANA MENU");
	mainMenu.AddOption("Customers (admin)");
	mainMenu.AddOption("Products (admin)");
	mainMenu.AddOption("Shopping");
	mainMenu.AddOption("Cikis Yap");

	while (true) {
		int secim = mainMenu.DisplayAndGetChoice();

		switch (secim) {
		case 1:
			// displaycustomeradminmenu
			break;
		case 2:
			DisplayAdminProductsMenu();
			break;
		case 3:
			DisplayShoppingMenu();
			break;
		case 4:
			cout << "Cikis Yapiliyor..." << endl;
			return;
		}
	}
}

// 1- ADMIN MENU <- customers
void BookStore::DisplayAdminCustomersMenu() {
	// customer ekle
	// customerlari goster
}

// 2- ADMIN MENU <- products
void BookStore::DisplayAdminProductsMenu() {
	Menu productsAdminMenu("URUNLER MENUSU (ADMIN)");
	productsAdminMenu.AddOption("Yeni Urun Ekle");
	productsAdminMenu.AddOption("Urunleri Listele");
	productsAdminMenu.AddOption("Geri");

	while (true)
	{
		int secim = productsAdminMenu.DisplayAndGetChoice();

		switch (secim) {
		case 1:
			AddNewProduct();
			break;
		case 2:
			ShowAllProducts();
			break;
		case 3:
			return;
		}
	}
}
// products admin menu icin yardimci fonksiyon
void BookStore::AddNewProduct() {
	cout << "\n--- URUN EKLEME ---" << endl;
	cout << "1- Kitap" << endl;
	cout << "2- Dergi" << endl;
	cout << "3- Muzik CD" << endl;
	cout << "Seciminiz (Iptal icin 0): ";
	int turSecim;
	cin >> turSecim;

	if (turSecim == 0) return;

	string name;
	double price;
	cout << "Urun Adi : ";
	cin.ignore();
	getline(cin, name);
	cout << "Fiyat : ";
	cin >> price;


	if (turSecim == 1) {

		string author, publisher;
		int page;
		cout << "Yazar : ";
		cin.ignore();
		getline(cin, author);
		cout << "Yayinci : ";
		getline(cin, publisher);
		cout << "Sayfa Sayisi : "; cin >> page;

		products.push_back(new Book(name, price, author, publisher, page));
	}
	else if (turSecim == 2) {
		// magazine
	}
	else if (turSecim == 3)
	{
		// music
	}
	else {
		cout << "Hatali Secim!!" << endl;
	}
}

// 3- Shopping Menu : Musterinin asil kullanacagi yer
void BookStore::DisplayShoppingMenu() {
	Menu customerMenu("MUSTERI PANELI");
	customerMenu.AddOption("Giris Yap");
	customerMenu.AddOption("Urunleri Kesfet"); // yeni urun almak icin
	customerMenu.AddOption("Sepetim");
	customerMenu.AddOption("Sepete Ekle");       // sepete urun ekle
	customerMenu.AddOption("Sepetten Kaldýr"); // cikar
	customerMenu.AddOption("Bonusumu Goster");
	customerMenu.AddOption("Bonusu Kullan");
	customerMenu.AddOption("Siparisi Tamamla");
	customerMenu.AddOption("Siparisi Iptal Et");
	customerMenu.AddOption("Fatura Goster");
	customerMenu.AddOption("Oturumu Kapat");

	bool stayInMenu = true;
	while (stayInMenu) {
		int secim = customerMenu.DisplayAndGetChoice();
		if (currentCustomer == nullptr && !(secim == 1 || secim == 2 || secim == 11))  // 1, 2 ,11 basarsa switch case e geç 
		{
			cout << "Bu Islemi Yapmak Icin Once Giris Yapmalisiniz ! " << endl;
			continue;
		}

		switch (secim)
		{
		case 1:
			Login();
			break;
		case 2:
			ShowAllProducts();
			break;
		case 3:
			// sepet
			break;
		case 4:
			// add to cart
			break;
		case 5:
			// sepetten cikar
			break;
		case 6:
			// b onus goster
			break;
		case 7:
			// bonus kullan
			break;
		case 8:
			// siparis
			break;
		case 9:
			// siparis itpali
			break;
		case 10:
			// fatura
			break;
		case 11:
			if (currentCustomer != nullptr)
			{
				currentCustomer = nullptr;
				cout << "Oturum Kapatildi" << endl;
			}
			stayInMenu = false;
			break;
		}

	}
}





void BookStore::ShowAllProducts() {
	cout << "URUNLER" << endl;
	if (products.empty()) {
		cout << "Urun Yok" << endl;
		return;
	}
	for (Product* p : products) {
		p->printProperties();
		cout << "==================================================" << endl;
	}
}

