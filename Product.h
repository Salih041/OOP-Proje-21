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
	private:
		static int lastProductId; // ürünlere eşsiz id vermek için static tanımlandı.
		int ID;
		string name;
		double price;
	public:
		// contructor destructor
		Product(string name, double price);
		Product();
		virtual ~Product();

		// getter ve setter fonksiyonlar

		int getID() const;
		void setID(int id);

		string getName() const;
		void setName(string name);

		double getPrice() const;
		void setPrice(double price);

		// bilgileri yazdıran const fonksiyon
		virtual void printProperties() const = 0;
};
#endif