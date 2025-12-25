// BookStore.cpp
// Salih Özbek
// 20.12.2025

#include "MusicCD.h"
#include "BookStore.h"
#include "Menu.h"
#include "Book.h"
#include "Cash.h"
#include "Check.h"
#include "CreditCard.h"
#include "Payment.h"
#include "Magazine.h"
#include "ProductToPurchase.h"
#include "ShoppingCart.h"
// includelar

#include <iostream>
#include <vector>
using namespace std;

BookStore::BookStore() {
	currentCustomer = nullptr;
	currentCart = nullptr;
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
	products.push_back(new MusicCD("Bertaraf Et", 50, "Hayko Cepkin", "Metal"));
	products.push_back(new MusicCD("Paramparça", 300, "Müslüm Gürses", "Arabesk"));
	products.push_back(new Magazine("Bilim ve Gelecek", 120, 5, "Bilim ve Teknoloji"));

	customers.push_back(new Customer(0, "Zeynep", "Eskiþehir", "05554442211", "zeynep123@gmail.com", "zeynep1", "123456"));
	customers.push_back(new Customer(0, "Kerem", "Eskiþehir", "05223334488", "kerem123@gmail.com", "kerem2", "kerem123"));
	customers.push_back(new Customer(0, "Emre", "Eskiþehir", "05112551414", "emre123@gmail.com", "emre6", "emre4380"));
	customers.push_back(new Customer(0, "Enes", "Eskiþehir", "05402502121", "enes123@gmail.com", "enes2", "guclusifre"));
	customers.push_back(new Customer(0, "Salih", "Eskiþehir", "05382001212", "salih4141@gmail.com", "salih4", "123789"));
}

void BookStore::Login()
{
	if (currentCustomer != nullptr) {
	cout << "\nZaten Giris Yapildi: " << currentCustomer->getUsername() << endl;
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
	for (Customer* c : customers) {
		if (c->checkAccount(usernameInput, passwordInput)) {
			currentCustomer = c;
			isFound = true;

			currentCart = new ShoppingCart();
			currentCart->setCustomer(currentCustomer);
			break;
		}
	}

	if (isFound)
	{
		cout << "HOS GELDÝNÝZ!" << currentCustomer->getName() << endl;
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
			DisplayAdminCustomersMenu();
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
	Menu customersAdminMenu("KULLANICILAR MENUSU (ADMIN)");
	customersAdminMenu.AddOption("Yeni Kullanýcý Ekle");
	customersAdminMenu.AddOption("Kullanýcýlarý Listele");
	customersAdminMenu.AddOption("Geri");

	while (true)
	{
		int secim = customersAdminMenu.DisplayAndGetChoice();
		switch (secim) {
		case 1:
			AddNewCustomer(); // yapilcak
			break;
		case 2:
			ShowAllCustomers();
			break;
		case 3:
			return;
		}
	}
}
// customers admin menu icin yardimci fonksiyon
void BookStore::AddNewCustomer() {
	cout << "\n--- KULLANICI EKLEME ---" << endl;
	string name, address, phone, email, username, password;
	cin.ignore();

	cout << "Ad Soyad: ";
	getline(cin, name);
	cout << "Adres: ";
	getline(cin, address);
	cout << "Telefon No: ";
	getline(cin, phone);
	cout << "E-Mail: ";
	getline(cin, email);
	cout << "Kullanýcý Adý: ";
	getline(cin, username);
	cout << "Þifre: ";
	getline(cin, password);

	customers.push_back(new Customer(0, name, address, phone, email, username, password));
	
	cout << "Müþteri Baþarýyla Eklendi" << endl;
}

void BookStore::ShowAllCustomers() {
	cout << "KULLANICILAR" << endl;
	if (customers.empty()) {
		cout << "Kullanýcý Yok" << endl;
		return;
	}
	for (Customer* c : customers) {
		c->printCustomerInfo();
		cout << "==================================================" << endl;
	}
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
		cout << "Sayfa Sayisi : ";
		cin >> page;

		products.push_back(new Book(name, price, author, publisher, page));
	}
	else if (turSecim == 2) {
		int issue;
		string type;
		cout << "Basim : ";
		cin.ignore();
		cin >> issue;
		cout << "Type : ";
		cin.ignore();
		getline(cin, type);
		
		products.push_back(new Magazine(name, price, issue, type));
	}
	else if (turSecim == 3)
	{
		string singer, type;
		cout << "Sarkici : ";
		cin.ignore();
		getline(cin, singer);
		cout << "Type : ";
		cin.ignore();
		getline(cin, type);

		products.push_back(new MusicCD(name,price,singer,type));
	}
	else {
		cout << "Hatali Secim!!" << endl;
	}
}
// products admin ve shopping menuleri için yardýmcý fonksiyon
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
		if (currentCustomer != nullptr && currentCart == nullptr) {
			currentCart = new ShoppingCart();
			currentCart->setCustomer(currentCustomer);
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
			if (currentCart)
				currentCart->printProducts();
			else
				cout << "Sepetiniz bos." << endl;
			break;
		case 4:
		{// add to cart
			cout << "=== SEPETE EKLE ===";
			cout << "Eklemek istediginiz urun id'si : ";
			int idToAdd;
			cin >> idToAdd;
			Product* selectedProduct = nullptr;
			for (Product* p : products) {
				if (p->getID() == idToAdd) {
					selectedProduct = p;
					break;
				}
			}
			if (selectedProduct != nullptr)
			{
				cout << "Urun: " << selectedProduct->getName() << " ( " << selectedProduct->getPrice() << " TL )" << endl;
				cout << "Kac adet eklemek istersiniz?: ";
				int quantityInput;
				cin >> quantityInput;
				currentCart->addProduct(selectedProduct, quantityInput);
			}
			else
			{
				cout << "Girdiðiniz id ile eþlesen bir ürün bulunamadý!" << endl;
			}
			break;
		}
		case 5:
		{
			// sepetten cikar
			cout << "=== SEPETTEN ÇIKAR ===" << endl;
			cout << "Sepetinizden çýkarmak istediðiniz ürünün id'si : ";
			int idToDel;
			cin >> idToDel;
			Product* productToRemove = nullptr;
			for (Product* p : products) {
				if (p->getID() == idToDel) {
					productToRemove = p;
					break;
				}
			}
			if (productToRemove != nullptr) {
				currentCart->removeProduct(productToRemove);
			}
			else {
				cout << "Girilen id ile eþleþen bir ürün bulunamadý!" << endl;
			}
			break;
		}
		case 6:
			// b onus goster
			cout << "Mevcut Bonusunuz : " << currentCustomer->getBonus() << endl;
			break;
		case 7:
			// bonus kullan
			currentCart->setBonusUsed(true);
			cout << "Bonusunuz aktif edildi." << endl;
			break;
		case 8:
		{
			// siparis
			cout << "Ödeme Yöntemini Seçiniz" << endl;
			cout << "1. Kredi Kartý" << endl;
			cout << "2. Nakit (Cash)" << endl;
			cout << "3. Çek (Check)" << endl;
			cout << "Seçiminiz: ";
			int paySecim;
			cin >> paySecim;

			Payment* newPayment = nullptr;
			if (paySecim == 1) {
				//kredi kartý
				long no;
				string cardType, expDate;
				cout << "Kart Numarasý : "; cin >> no;
				cout << "Kart Tipi : "; cin.ignore(); getline(cin, cardType);
				cout << "Son Kullaným Tarihi : "; getline(cin, expDate);

				CreditCard* cc = new CreditCard();
				cc->setNumber(no);
				cc->setType(cardType);
				cc->setExpDate(expDate);
				newPayment = cc;
			}
			else if (paySecim == 2)
			{
				// nakit
				newPayment = new Cash();
			}
			else if (paySecim == 3)
			{
				// çek
				string name, bankId;
				cout << "Ad Soyad : ";
				cin.ignore(); getline(cin, name);
				cout << "Banka ID : "; getline(cin, bankId);

				Check* c = new Check();
				c->setBankID(bankId);
				c->setName(name);
				newPayment = c;
			}
			else
			{
				cout << "Gecersiz secim! Islem iptal edildi." << endl;
				break;
			}

			if (newPayment != nullptr) {
				currentCart->setPaymentMethod(newPayment);
				currentCart->placeOrder();
			}
			break;
		}
		case 9:
			// siparis itpali
			currentCart->cancelOrder();
			cout << "Siparis iptal edildi, sepet bosaltildi." << endl;
			break;
		case 10:
			// fatura
			currentCart->showInvoice();
			break;
		case 11:
			if (currentCustomer != nullptr)
			{
				currentCustomer = nullptr;
				if (currentCart != nullptr)
				{
					delete currentCart;
					currentCart = nullptr;
				}
				cout << "Oturum Kapatildi" << endl;
			}
			stayInMenu = false;
			break;
		}

	}
}


