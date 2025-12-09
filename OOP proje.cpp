#include <iostream>
#include "Customer.h"
using namespace std;

int main() {

    // 1) Default constructor testi
    cout << "---- Default Constructor Test ----" << endl;
    Customer c1;
    c1.setCustomerID(101);
    c1.setName("Zeynep Alara Tas");
    c1.setAddress("Eskisehir");
    c1.setPhone("0555 555 55 55");
    c1.setEmail("alara@example.com");
    c1.setUsername("alara");
    c1.setPassword("123456"); // 6 karakter altı uyarı verir

    c1.printCustomerInfo();
    cout << endl;


    // 2) Parametreli constructor testi
    cout << "---- Parameterized Constructor Test ----" << endl;
    Customer c2(102, "Ali Kaya", "Ankara", "0544 444 44 44",
        "alikaya@example.com", "alik", "password123");

    c2.printCustomerInfo();
    cout << endl;


    // 3) Login test
    cout << "---- Login Test ----" << endl;
    if (c2.login("alik", "password123"))
        cout << "Login successful!" << endl;
    else
        cout << "Login FAILED!" << endl;

    if (c2.login("wrong", "wrong"))
        cout << "Login successful (should not happen)!" << endl;
    else
        cout << "Login FAILED correctly." << endl;

    cout << endl;


    // 4) checkAccount test
    cout << "---- checkAccount Test ----" << endl;
    if (c2.checkAccount("alik", "password123"))
        cout << "Account verified!" << endl;
    else
        cout << "Account verification failed!" << endl;

    cout << endl;


    // 5) Bonus ekleme testi
    cout << "---- Bonus Test ----" << endl;
    cout << "Initial bonus: " << c2.getBonus() << endl;
    c2.addBonus(500); // 500 TL alışveriş = 5 TL bonus
    cout << "After purchase bonus: " << c2.getBonus() << endl;

    c2.useBonus();
    cout << "Bonus after reset: " << c2.getBonus() << endl;

    cout << endl;


    // 6) sendBill testi
    cout << "---- sendBill Test ----" << endl;
    c2.sendBill();

    cout << endl;

    cout << "All tests finished successfully!" << endl;

    return 0;
}
