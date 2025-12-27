/*
Product.cpp
Salih Özbek
10.12.2025
*/

#include "Product.h"
#include <iostream>
#include <string>
using namespace std;

int Product::lastProductId = 0;

Product::Product(string name, double price) {
	this->ID = ++lastProductId;  // static tutulan son ürün id si 1 artýrýlýp yeni ürüne atanýr
	this->name = name;
	this->price = price;
}

Product::Product() { // constructor a veri gönderilmezse default deðerlerle oluþturulur
	this->ID = ++lastProductId;
	this->name = "";
	this->price = 0.0;
}

Product::~Product(){}

int Product::getID() const {
	return this-> ID;
}

void Product::setID(int id) {
	this->ID = id;
}

string Product::getName() const {
	return this->name;
}

void Product::setName(string name) {
	this->name = name;
}

double Product::getPrice() const {
	return this->price;
}

void Product::setPrice(double price) {
	this->price = price;
}
