/*
Book.cpp
Salih Özbek
10.12.2025
*/

#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

Book::Book(string name, double price, string author, string publisher, int page) : Product(name, price) {
this->author = author;
this->publisher = publisher;
this->page = page;
}

Book::Book() : Product() {
this->author = "";
this->publisher = "";
this->page = 0;
}

Book::~Book(){}

string Book::getAuthor() const {
	return this->author;
}

void Book::setAuthor(string author) {
	this->author = author;
}

string Book::getPublisher() const {
	return this->publisher;
}

void Book::setPublisher(string publisher) {
    this->publisher = publisher;
}

int Book::getPage() const {
	return this->page;
}

void Book::setPage(int page) {
	this->page = page;
}

void Book::printProperties() const {
    cout << "---------------------------------" << endl;
    cout << "ID        : " << ID << endl;
    cout << "Name      : " << name << endl;
    cout << "Price     : " << price << " TL" << endl;
    cout << "Author    : " << author << endl;
    cout << "Publisher : " << publisher << endl;
    cout << "Page      : " << page << endl;
    cout << "---------------------------------" << endl;
}