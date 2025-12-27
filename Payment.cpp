/*
    Enes Kılıç - 11.12.2025
*/

#include <iostream>
#include "Payment.h"    // Header dosyası dahil ediliyor.

Payment::Payment(double amount) : amount(amount) {}

double Payment::getAmount() const     // amount değeri döndürülüyor.
{
    return amount;
}

void Payment::setAmount(double a)   // amount değeri değiştiriliyor.
{
    amount = a;
}

