/*
    Kerem Riza Özerdem - 23.12.2025
*/

#include "ProductToPurchase.h"

// Constructor ile baslangic degerlerini atiyoruz
ProductToPurchase::ProductToPurchase(Product* p, int q) {
    this->product = p;
    this->quantity = q;
}

// Urunu dondurur
Product* ProductToPurchase::getProduct() const {
    return product;
}

// Urunu gunceller
void ProductToPurchase::setProduct(Product* p) {
    this->product = p;
}

// Adet bilgisini dondurur
int ProductToPurchase::getQuantity() const {
    return quantity;
}

// Adet bilgisini gunceller
void ProductToPurchase::setQuantity(int q) {
    this->quantity = q;
}