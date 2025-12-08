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

class Book : public Product {
	private:
		string author;
		string publisher;
		int page;
	public:
		Book(int id, string name, double price, string author, string pulbisher, int page);
		Book();
		~Book();

		string getAuthor() const;
		void SetAuthor(string author);

		string getPublisher() const;
		void SetPublisher(string publisher);

		int getPage() const;
		void SetPage(int page);

		void printProperties() override;
};

#endif