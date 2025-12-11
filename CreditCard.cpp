/*
    Enes Kılıç - 11.12.2025
*/

#include <iostream>
#include <string>
#include "CreditCard.h"     // Header dosyası dahil ediliyor.

using namespace std;

void CreditCard::performPayment()       // Payment class'ında virtual olarak oluşturulan fonksiyonun görev tanımı.
{
    cout << "Credit card payment done" << endl;
}

long CreditCard::getNumber()        // number değişkeni döndürülüyor.
{
    return number;
}

void CreditCard::setNumber(long n)      // number değişkeni değiştiriliyor.
{
    number = n;
}

string CreditCard::getType()        // type değişkeni döndürülüyor.
{
    return type;
}

void CreditCard::setType(string t)      // type değişkeni değiştiriliyor.
{
    type = t;
}

string CreditCard::getExpDate()     // expDate değişkeni döndürülüyor.
{
    return expDate;
}

void CreditCard::setExpDate(string e)       // expDate değişkeni değiştiriliyor.
{
    expDate = e;
}