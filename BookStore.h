// BookStore.h
// Salih Özbek
// 20.12.2025

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

// include lar gelecek
#include "Product.h"
#include "Customer.h"

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
	void ShowAllProducts();
	void DisplayAdminCustomersMenu();
	void AddNewCustomer();
	void ShowAllCustomers();
	
};

#endif