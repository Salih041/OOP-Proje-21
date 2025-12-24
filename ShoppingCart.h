/*
    Kerem Riza Özerdem - 23.12.2025
*/

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include <iostream>
#include "ProductToPurchase.h"
#include "Customer.h"
#include "Payment.h"

using namespace std;

class ShoppingCart {
private:
    vector<ProductToPurchase*> productsToPurchase; // Sepetteki urunler vector icinde tutuluyor
    Customer* customer;        // Sepetin sahibi
    Payment* paymentMethod;    // Secilen odeme yontemi
    bool isBonusUsed;          // Bonus kullanimi kontrolu

public:
    ShoppingCart();
    ~ShoppingCart(); // Destructor (Pointer temizligi icin)

    Payment* getPaymentMethod() const;
    void setPaymentMethod(Payment* method);

    Customer* getCustomer() const;
    void setCustomer(Customer* c);

    void setBonusUsed(bool used);
    bool getBonusUsed() const;

    void addProduct(Product* product, int quantity);
    void removeProduct(Product* product);
    void placeOrder();
    void cancelOrder();
    void printProducts();
    void showInvoice();
};

#endif