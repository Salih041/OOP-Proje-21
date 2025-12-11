#include <iostream>
#include <string>
#include "Payment.h"

using namespace std;

double Payment::getAmount()
{
    return amount;
}

void Payment::setAmount(double a)
{
    amount = a;
}
