/*
Product.h
Salih Özbek
08.12.2025
*/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

class Product {
	protected:
		int ID;
		string name;
		double price;
	public:
		Product(int id, string name, double price);
		Product();
		virtual ~Product();

		int getID() const;
		void SetID(int id);

		string getName() const;
		void SetName(string name);

		double getPrice() const;
		void SetPrice(double price);

		virtual void printProperties() = 0;
};
#endif