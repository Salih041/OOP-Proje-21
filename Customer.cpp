// 152120231053 Zeynep Alara Taş 27.11.2025
#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer() {
    bonus = 0;
}

Customer::Customer(long cID, string name, string address, string phone,
    string email, string username, string pass) {
    this->customerID = cID;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->email = email;
    this->username = username;
    this->password = pass;
    this->bonus = 0;
}

void Customer::sendBill() const {
    cout << "Invoice sent to email: " << email << endl;
}

long Customer::getCustomerID() const { return customerID; }
string Customer::getName() const { return name; }
string Customer::getAddress() const { return address; }
string Customer::getPhone() const { return phone; }
string Customer::getEmail() const { return email; }
double Customer::getBonus() const { return bonus; }
string Customer::getUsername() const { return username; }
string Customer::getPassword() const { return password; }

void Customer::setCustomerID(long cID) { customerID = cID; }
void Customer::setName(string name) { this->name = name; }
void Customer::setAddress(string address) { this->address = address; }
void Customer::setPhone(string phone) { this->phone = phone; }
void Customer::setEmail(string email) { this->email = email; }
void Customer::setBonus(double bonus) { this->bonus = bonus; }
void Customer::setUsername(string username) { this->username = username; }

void Customer::setPassword(string pass) {
    if (pass.length() < 6) {
        cout << "Password must be at least 6 characters long." << endl;
        return;
    }
    password = pass;
}

bool Customer::checkAccount(string username, string password) const {
    return (this->username == username && this->password == password);
}

void Customer::addBonus(double amount) {
    bonus += (amount * 0.01); // %1 bonus
}

void Customer::useBonus() {
    bonus = 0;
}

bool Customer::login(string username, string password) const {
    return (this->username == username && this->password == password);
}

void Customer::printCustomerInfo() const {
    cout << "Customer ID: " << customerID << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Bonus: " << bonus << endl;
    cout << "Username: " << username << endl;
}
