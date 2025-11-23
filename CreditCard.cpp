#include <iostream>
#include <string>
#include "CreditCard.h"

using namespace std;

void CreditCard::performPayment()
{
    cout << "Credit card payment done" << endl;
}

long CreditCard::getNumber()
{
    return number;
}

void CreditCard::setNumber(long n)
{
    number = n;
}

string CreditCard::getType()
{
    return type;
}

void CreditCard::setType(string t)
{
    type = t;
}

string CreditCard::getExpDate()
{
    return expDate;
}

void CreditCard::setExpDate(string e)
{
    expDate = e;
}