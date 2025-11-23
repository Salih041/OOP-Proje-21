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

/*

bu kısım main'e yazılacak:

Payment* p;

int choice;
cout << "Odeme yontemi sec: (1=Kart, 2=Nakit, 3=Cek): ";
cin >> choice;
if (choice == 1)
p = new CreditCard();
else if (choice == 2)
p = new Cash();
else
p = new Check();
p->performPayment();

*/
