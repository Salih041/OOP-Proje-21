/*
    Enes Kılıç - 11.12.2025
*/

#include <iostream>
#include "CreditCard.h" // Header dosyası dahil ediliyor.


CreditCard::CreditCard(double amount, long number, const string& type, const string& expDate)
    : Payment(amount), number(number), type(type), expDate(expDate) {}

void CreditCard::performPayment() // Payment class'ında virtual olarak oluşturulan fonksiyonun görev tanımı.
{
    cout << "Credit card payment done" << endl;
}

long CreditCard::getNumber() const // number değişkeni döndürülüyor.
{
    return number;
}

void CreditCard::setNumber(long n) // number değişkeni değiştiriliyor.
{
    number = n;
}

string CreditCard::getType() const // type değişkeni döndürülüyor.
{
    return type;
}

void CreditCard::setType(const string& t) // type değişkeni değiştiriliyor.
{
    type = t;
}

string CreditCard::getExpDate() const // expDate değişkeni döndürülüyor.
{
    return expDate;
}

void CreditCard::setExpDate(const string& e) // expDate değişkeni değiştiriliyor.
{
    expDate = e;
}