//152120231053 Zeynep Alara Taş 27.11.2025
//Customer.h
#pragma once
#include <string>
#include <iostream>

using namespace std;
// Customer class definition
class Customer {
private:
    //Customer's private attributes
    long customerID;

    // Auto-increment ID generator (used when menu passes 0)
    static long nextCustomerID;

    string name;
    string address;
    string phone;
    string email;
    double bonus = 0;
    string username;
    string password;

public:
    // Constructors
    Customer();
    Customer(long cID, string name, string address, string phone,
        string email, string username, string pass);

    // UML methods
    void sendBill() const;
    // Getter methods
    long getCustomerID() const;
    string getName() const;
    string getAddress() const;
    string getPhone() const;
    string getEmail() const;
    double getBonus() const;
    string getUsername() const;
    string getPassword() const;
    // Setter methods
    void setCustomerID(long cID);
    void setName(string name);
    void setAddress(string address);
    void setPhone(string phone);
    void setEmail(string email);
    void setBonus(double bonus);
    void setUsername(string username);
    void setPassword(string pass);

    bool checkAccount(string username, string password) const;  // UML → bool

    void addBonus(double amount);
    void useBonus();

    bool login(string username, string password) const;
    void printCustomerInfo() const;

    // Helper for auto ID (internal use)
    static long generateCustomerID();
};
