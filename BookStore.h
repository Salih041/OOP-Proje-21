// BookStore.h
// Salih Özbek
// 20.12.2025

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include "Product.h"
#include "Customer.h"
#include "ShoppingCart.h"
#include <iostream>
#include <string>
#include <vector>

class BookStore
{
private:
	std::vector<Product*> products; // sistemdeki ürünler
	std::vector<Customer*> customers; // sistemdeki müþteriler
	Customer* currentCustomer; // giriþ yapan müþteri
	ShoppingCart* currentCart; // giriþ yapan müþterinin sepeti

public:
	BookStore();
	~BookStore();

	void Run();
	void LoadData();  // baþlangýç verilerini (5 ürün, 5 müþteri) yükleyen fonksiyon

	void Login();
	void DisplayMenu(); // Programýn ana menüsü
	void DisplayShoppingMenu();

	void DisplayAdminProductsMenu();
	void AddNewProduct();
	void ShowAllProducts();
	void DisplayAdminCustomersMenu();
	void AddNewCustomer();
	void ShowAllCustomers();
	
};

#endif