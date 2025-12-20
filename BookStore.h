// BookStore.h
// Salih Özbek
// 20.12.2025

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

// include lar gelecek
#include "Product.h"
class Customer;

#include <iostream>
#include <string>
#include <vector>

class BookStore
{
private:
	std::vector<Product*> products;
	std::vector<Customer*> customers;
	Customer* currentCustomer;

public:
	BookStore();
	~BookStore();

	void Run();
	void LoadData();

	void Login();
	void DisplayMenu();
	void DisplayShoppingMenu();

	void DisplayAdminProductsMenu();
	void AddNewProduct();

	void DisplayAdminCustomersMenu();
	void ShowAllProducts();
};

#endif