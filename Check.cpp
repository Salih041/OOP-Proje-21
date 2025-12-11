/*
    Enes Kılıç - 11.12.2025
*/

#include <iostream>
#include <string>
#include "Check.h"      // Header dosyası dahil ediliyor.

using namespace std;

void Check::performPayment()        // Payment class'ında virtual olarak oluşturulan fonksiyonun görev tanımı.
{
    cout << "Check payment done" << endl;
}

string Check::getName()     // name değişkeni döndürülüyor.
{
    return name;
}

void Check::setName(string n)       // name değişkeni değiştiriliyor.
{
    name = n;
}

string Check::getBankID()       // bankID değişkeni döndürülüyor.
{
    return bankID;
}

void Check::setBankID(string b)     // bankID değişkeni değiştiriliyor.
{
    bankID = b;
}