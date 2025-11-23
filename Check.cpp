#include <iostream>
#include <string>
#include "Check.h"

using namespace std;

void Check::performPayment()
{
    cout << "Check payment done" << endl;
}

string Check::getName()
{
    return name;
}

void Check::setName(string n)
{
    name = n;
}

string Check::getBankID()
{
    return bankID;
}

void Check::setBankID(string b)
{
    bankID = b;
}