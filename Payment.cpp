/*
    Enes Kılıç - 11.12.2025
*/

#include <iostream>
#include <string>
#include "Payment.h"    // Header dosyası dahil ediliyor.

using namespace std;

double Payment::getAmount()     // amount değeri döndürülüyor.
{
    return amount;
}

void Payment::setAmount(double a)   // amount değeri değiştiriliyor.
{
    amount = a;
}

