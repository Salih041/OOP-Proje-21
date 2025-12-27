/*
Book.h
Salih Özbek
08.12.2025
*/

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

class Book : public Product { // producttan miras alýr
	private:
		string author;
		string publisher;
		int page;
	public:
		// constructor destructor
		Book(string name, double price, string author, string publisher, int page);
		Book();
		~Book();

		// getter setter fonksiyonlar
		string getAuthor() const;
		void setAuthor(string author);

		string getPublisher() const;
		void setPublisher(string publisher);

		int getPage() const;
		void setPage(int page);
		// özellikleri yazdýrma fonksiyonu
		void printProperties() const override; // üst classtan gelen fonksiyon override edilir
};

#endif