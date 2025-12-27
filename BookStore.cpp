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

#include <iostream>
#include <vector>
using namespace std;

BookStore::BookStore() { // baþlangýçta müþteri ve sepeti boþ pointera ata
	currentCustomer = nullptr;  
	currentCart = nullptr;
	LoadData(); // baþlangýç verilerini yükle
}

BookStore::~BookStore() { // Belleði temizle
	for (Product* p : products) delete p;
	for (Customer* c : customers) delete c;
	products.clear();
	customers.clear();
	cout << "Memory Cleared" << endl;
}

void BookStore::LoadData() {
	products.push_back(new Book("Suc ve Ceza", 150, "Dostoyevski", "Is Bankasi", 688));
	products.push_back(new Book("Kasagi", 80, "Omer Seyfettin", "Can", 124));
	products.push_back(new Book("Beyaz Diþ", 100, "Jack London", "Can", 298));
	products.push_back(new MusicCD("Bertaraf Et", 50, "Hayko Cepkin", "Metal"));
	products.push_back(new MusicCD("Paramparça", 300, "Müslüm Gürses", "Arabesk"));
	products.push_back(new MusicCD("Sokak Lambasý", 150, "Yirmi7", "Rock"));
	products.push_back(new Magazine("Bilim ve Gelecek", 120, 5, "Bilim ve Teknoloji"));
	products.push_back(new Magazine("National Geographic", 300, 18, "Dünya Kültürü"));
	products.push_back(new Magazine("Meraklý Minik", 40, 2, "Çocuk"));

	customers.push_back(new Customer(0, "Zeynep", "Eskiþehir", "05554442211", "zeynep123@gmail.com", "zeynep1", "123456"));
	customers.push_back(new Customer(0, "Kerem", "Eskiþehir", "05223334488", "kerem123@gmail.com", "kerem2", "kerem123"));
	customers.push_back(new Customer(0, "Emre", "Eskiþehir", "05112551414", "emre123@gmail.com", "emre6", "emre4380"));
	customers.push_back(new Customer(0, "Enes", "Eskiþehir", "05402502121", "enes123@gmail.com", "enes2", "guclusifre"));
	customers.push_back(new Customer(0, "Salih", "Eskiþehir", "05382001212", "salih4141@gmail.com", "salih4", "123789"));
}

void BookStore::Login()
{
	if (currentCustomer != nullptr) {
	cout << "\nAlready Logged In: " << currentCustomer->getUsername() << endl;
		return;
	}
	cin.ignore();
	cout << "==== LOG IN ====" << endl;
	string usernameInput, passwordInput;
	cout << "Username : ";
	getline(cin, usernameInput);
	cout << "Password : ";
	getline(cin, passwordInput);

	bool isFound = false;
	for (Customer* c : customers) {  // girilen username ve password e ait kullanýcý sistemde var mý?
		if (c->checkAccount(usernameInput, passwordInput)) {
			currentCustomer = c;  // sistemde bulunan kullanýcýyý mevcut kullanýcý olarak ata
			isFound = true;

			currentCart = new ShoppingCart();
			currentCart->setCustomer(currentCustomer);  // kullanýcýya yeni bir sepet tanýmla
			break;
		}
	}

	if (isFound)
	{
		cout << "WELCOME! " << currentCustomer->getName() << endl;
	}
	else {
		cout << "\nINVALID USERNAME OR PASSWORD" << endl;
		cout << "Please try again or register" << endl;
	}

}

void BookStore::Run() { // Ana Program Akýþý
	cout << "WELCOME" << endl;
	Menu::WaitForUser();
	DisplayMenu();
}

// ANA MENU
void BookStore::DisplayMenu() {
	Menu mainMenu("MAIN MENU");
	mainMenu.AddOption("Customers Menu");
	mainMenu.AddOption("Products Menu");
	mainMenu.AddOption("Shopping Menu");
	mainMenu.AddOption("EXIT");

	while (true) { // sonsuz döngü case 4-de kýrýlacak
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
			cout << "Exiting..." << endl;
			return;
		}
	}
}

// 1- CUSTOMERS MENU
void BookStore::DisplayAdminCustomersMenu() {
	Menu customersAdminMenu("CUSTOMERS MENU");
	customersAdminMenu.AddOption("Add New Customer");
	customersAdminMenu.AddOption("List Customers");
	customersAdminMenu.AddOption("Back");

	while (true)
	{
		int secim = customersAdminMenu.DisplayAndGetChoice();
		switch (secim) {
		case 1:
			AddNewCustomer();
			break;
		case 2:
			ShowAllCustomers();
			break;
		case 3:
			return;
		}
		Menu::WaitForUser();
	}
}
// customers admin menu icin yardimci fonksiyon
void BookStore::AddNewCustomer() {
	cout << "\n--- ADD CUSTOMER ---" << endl;
	string name, address, phone, email, username, password;
	cin.ignore();

	cout << "Name Surname: ";
	getline(cin, name);
	cout << "Address     : ";
	getline(cin, address);
	cout << "Phone No    : ";
	getline(cin, phone);
	cout << "E-Mail      : ";
	getline(cin, email);
	cout << "Username    : ";
	getline(cin, username);
	cout << "Password    : ";
	getline(cin, password);

	customers.push_back(new Customer(0, name, address, phone, email, username, password)); // yeni customerý ekle
	
	cout << "Customer Created Successfully" << endl;
}

void BookStore::ShowAllCustomers() {
	cout << "CUSTOMERS" << endl;
	if (customers.empty()) {
		cout << "No customers found" << endl;
		return;
	}
	for (Customer* c : customers) {
		c->printCustomerInfo();
		cout << "==================================================" << endl;
	}
}

// 2- PRODUCTS MENU
void BookStore::DisplayAdminProductsMenu() {
	Menu productsAdminMenu("PRODUCTS MENU");
	productsAdminMenu.AddOption("Add New Product");
	productsAdminMenu.AddOption("List Products");
	productsAdminMenu.AddOption("Back");

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
		Menu::WaitForUser();
	}
}


// products admin menu icin yardimci fonksiyon
void BookStore::AddNewProduct() {
	cout << "\n--- ADD PRODUCT ---" << endl;
	cout << "1- Book" << endl;
	cout << "2- Magazine" << endl;
	cout << "3- Music CD" << endl;
	cout << "Choice (0 to cancel): ";
	int turSecim;
	cin >> turSecim;

	if (turSecim == 0) return;

	// önce bütün ürünler için ortak olan alanlar alýnýr
	string name;
	double price;
	cout << "Product Name : ";
	cin.ignore();
	getline(cin, name);
	cout << "Price        : ";
	cin >> price;

	// sonrasýnda ürün türüne özel girdiler alýnýr
	if (turSecim == 1) {

		string author, publisher;
		int page;
		cout << "Author    : ";
		cin.ignore();
		getline(cin, author);
		cout << "Publisher : ";
		getline(cin, publisher);
		cout << "Pages     : ";
		cin >> page;

		products.push_back(new Book(name, price, author, publisher, page));
	}
	else if (turSecim == 2) {
		int issue;
		string type;
		cout << "Issue     : ";
		cin.ignore();
		cin >> issue;
		cout << "Type      : ";
		cin.ignore();
		getline(cin, type);
		
		products.push_back(new Magazine(name, price, issue, type));
	}
	else if (turSecim == 3)
	{
		string singer, type;
		cout << "Singer    : ";
		cin.ignore();
		getline(cin, singer);
		cout << "Type      : ";
		cin.ignore();
		getline(cin, type);

		products.push_back(new MusicCD(name,price,singer,type));
	}
	else {
		cout << "Invalid Choice!!" << endl;
	}
}
// products admin ve shopping menuleri için yardýmcý fonksiyon
void BookStore::ShowAllProducts() {
	cout << "Products" << endl;
	if (products.empty()) {
		cout << "No Products Found" << endl;
		return;
	}
	for (Product* p : products) {
		p->printProperties();
		cout << "==================================================" << endl;
	}
}

// 3- Shopping Menu : Musterinin asil kullanacagi yer
void BookStore::DisplayShoppingMenu() {
	Menu customerMenu("SHOPPING MENU");
	customerMenu.AddOption("Login");
	customerMenu.AddOption("Products"); // yeni urun almak icin
	customerMenu.AddOption("My Cart");
	customerMenu.AddOption("Add Product to Cart");       // sepete urun ekle
	customerMenu.AddOption("Remove Product from Cart"); // cikar
	customerMenu.AddOption("Show Bonus");
	customerMenu.AddOption("Use Bonus");
	customerMenu.AddOption("Place Order");
	customerMenu.AddOption("Cancel Order"); // sipariþ iptali
	customerMenu.AddOption("Show Invoice"); // fatura
	customerMenu.AddOption("Log Out");

	bool stayInMenu = true;
	while (stayInMenu) {
		int secim = customerMenu.DisplayAndGetChoice();
		if (currentCustomer == nullptr && !(secim == 1 || secim == 2 || secim == 11))  // 1, 2 ,11 basarsa switch case e geç 
		{
			cout << "You must log in to perform this operation!" << endl;
			Menu::WaitForUser(); // konsolu temizlemeden önce okunmasý için kullanýcýdan girdi bekler
			continue;
		}
		if (currentCustomer != nullptr && currentCart == nullptr) { // kullanýcý var ama sepeti yoksa
			currentCart = new ShoppingCart(); 
			currentCart->setCustomer(currentCustomer); // yeni bir sepet oluþtur ve kullancýya ver
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
				cout << "Your Cart is Empty" << endl;
			break;
		case 4:
		{// add product to cart
			cout << "=== Add Product to Cart ===" << endl;
			cout << "Product ID to add : ";
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
				cout << "Product: " << selectedProduct->getName() << " ( " << selectedProduct->getPrice() << " TL )" << endl;
				cout << "Quantity : ";
				int quantityInput;
				cin >> quantityInput;
				currentCart->addProduct(selectedProduct, quantityInput);
			}
			else
			{
				cout << "No product found with the entered ID!" << endl;
			}
			break;
		}
		case 5:
		{
			// sepetten cikar
			cout << "=== Remove Product from Cart ===" << endl;
			cout << "Product ID to remove: ";
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
				cout << "No product found with the entered ID!" << endl;
			}
			break;
		}
		case 6:
			// bonus goster
			cout << "Your Bonus : " << currentCustomer->getBonus() << endl;
			break;
		case 7:
			// bonus kullan
			currentCart->setBonusUsed(true);
			cout << "Bonus Activated" << endl;
			break;
		case 8:
		{
			// siparis ver
			cout << "Select Payment Method" << endl;
			cout << "1. Credit Cart" << endl;
			cout << "2. Cash" << endl;
			cout << "3. Check" << endl;
			cout << "Your choice: ";
			int paySecim;
			cin >> paySecim;

			// amount deðerleri ShoppingCart dan geleceði için baþlangýçta 0.0 ile oluþturuyoruz
			Payment* newPayment = nullptr;
			if (paySecim == 1) {
				// credit card
				long no;
				string cardType, expDate;
				cout << "Card Number     : "; cin >> no;
				cout << "Card Type       : "; cin.ignore(); getline(cin, cardType);
				cout << "Expiration Date : "; getline(cin, expDate);

				CreditCard* cc = new CreditCard(0.0,no,cardType,expDate);
				newPayment = cc;
			}
			else if (paySecim == 2)
			{
				// cash
				newPayment = new Cash(0.0);
			}
			else if (paySecim == 3)
			{
				// check
				string name, bankId;
				cout << "Name Surname : ";
				cin.ignore(); getline(cin, name);
				cout << "Bank ID      : "; getline(cin, bankId);

				Check* c = new Check(0.0,name,bankId);
				newPayment = c;
			}
			else
			{
				cout << "Invalid choice! Operation cancelled." << endl;
				break;
			}

			if (newPayment != nullptr) {
				currentCart->setPaymentMethod(newPayment);
				currentCart->placeOrder();
			}
			break;
		}
		case 9:
			// siparis iptali
			currentCart->cancelOrder();
			cout << "Order cancelled, cart cleared." << endl;
			break;
		case 10:
			// fatura göster
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
				cout << "Logged Out" << endl;
			}
			stayInMenu = false;
			break;
		}
		if (stayInMenu)
		{
			Menu::WaitForUser();
		}
	}
}


