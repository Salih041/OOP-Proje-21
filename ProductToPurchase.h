/*
    Kerem Riza Özerdem - 23.12.2025
*/

#ifndef PRODUCTTOPURCHASE_H
#define PRODUCTTOPURCHASE_H

#include "Product.h" 

class ProductToPurchase {
private:
    Product* product; // Urun pointer'ı (Abstract sınıf oldugu icin)
    int quantity;     // Urun adedi

public:
    ProductToPurchase(Product* p, int q);

    Product* getProduct() const;
    void setProduct(Product* p);

    int getQuantity() const;
    void setQuantity(int q);
};

#endif