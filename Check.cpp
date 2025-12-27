/*
    Enes Kılıç - 11.12.2025
*/

#include <iostream>
#include "Check.h" // Header dosyası dahil ediliyor.


Check::Check(double amount, const string& name, const string& bankID)
    : Payment(amount), name(name), bankID(bankID) {}

void Check::performPayment() // Payment class'ında virtual olarak oluşturulan fonksiyonun görev tanımı.
{
    cout << "Check payment done" << endl;
}

string Check::getName() const // name değişkeni döndürülüyor.
{
    return name;
}

void Check::setName(const string& n) // name değişkeni değiştiriliyor.
{
    name = n;
}

string Check::getBankID() const // bankID değişkeni döndürülüyor.
{
    return bankID;
}

void Check::setBankID(const string& b) // bankID değişkeni değiştiriliyor.
{
    bankID = b;
}