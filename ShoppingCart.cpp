/*
    Kerem Riza Özerdem - 23.12.2025
*/

#include "ShoppingCart.h"

// Degiskenlere varsayilan degerleri veriyoruz
ShoppingCart::ShoppingCart() {
    customer = nullptr;
    paymentMethod = nullptr;
    isBonusUsed = false;
}

// Nesne silindiginde vector icindeki pointerlari temizliyoruz (Memory leak olmamasi icin)
ShoppingCart::~ShoppingCart() {
    for (auto item : productsToPurchase) {
        delete item;
    }
    productsToPurchase.clear();
}

Payment* ShoppingCart::getPaymentMethod() const {
    return paymentMethod;
}

void ShoppingCart::setPaymentMethod(Payment* method) {
    this->paymentMethod = method;
}

Customer* ShoppingCart::getCustomer() const {
    return customer;
}

void ShoppingCart::setCustomer(Customer* c) {
    this->customer = c;
}

void ShoppingCart::setBonusUsed(bool used) {
    this->isBonusUsed = used;
}

bool ShoppingCart::getBonusUsed() const {
    return isBonusUsed;
}

// Sepete yeni urun ekleme islemi
void ShoppingCart::addProduct(Product* product, int quantity) {
    // Dinamik bellek kullanarak yeni urun olusturuyoruz
    ProductToPurchase* newItem = new ProductToPurchase(product, quantity);
    productsToPurchase.push_back(newItem);
    cout << "Urun sepete eklendi: " << product->getName() << endl;
}

// Sepetten urun silme islemi
void ShoppingCart::removeProduct(Product* product) {
    // Vector icinde dolasip ilgili urunu buluyoruz
    for (size_t i = 0; i < productsToPurchase.size(); i++) {
        if (productsToPurchase[i]->getProduct()->getID() == product->getID()) {
            delete productsToPurchase[i]; // Bellegi temizle
            productsToPurchase.erase(productsToPurchase.begin() + i); // Listeden sil
            cout << "Urun sepetten cikarildi." << endl;
            return;
        }
    }
    cout << "Urun sepetinizde bulunamadi." << endl;
}

// Sepetteki urunleri listeleme
void ShoppingCart::printProducts() {
    if (productsToPurchase.empty()) {
        cout << "Sepetiniz bos." << endl;
        return;
    }
    cout << "--- Sepetteki Urunler ---" << endl;
    for (auto item : productsToPurchase) {
        item->getProduct()->printProperties(); 
        cout << "Adet: " << item->getQuantity() << endl;
        cout << "-------------------------" << endl;
    }
}

// Siparisi tamamlama ve odeme islemleri
void ShoppingCart::placeOrder() {
    if (productsToPurchase.empty()) {
        cout << "Sepet bos, siparis verilemez." << endl;
        return;
    }

    double total = 0;
    // Toplam tutari hesapliyoruz
    for (auto item : productsToPurchase) {
        total += item->getProduct()->getPrice() * item->getQuantity();
    }

    // Eger musteri bonus kullanmak isterse
    if (isBonusUsed && customer->getBonus() > 0) {
        if (customer->getBonus() >= total) {
            customer->setBonus(customer->getBonus() - total);
            total = 0; // Hepsi bonustan odendi
        } else {
            total -= customer->getBonus();
            customer->setBonus(0); // Bonus bitti
        }
    }

    // Kalan tutari odeme yontemi ile ode
    paymentMethod->setAmount(total);
    paymentMethod->performPayment();

    // Odenen tutarin %1'i kadar bonus ekle
    double newBonus = paymentMethod->getAmount() * 0.01;
    customer->addBonus(newBonus);

    showInvoice();

    // Siparis tamamlandigi icin sepeti bosaltiyoruz
    cancelOrder(); 
}

// Siparis iptali veya sepeti bosaltma
void ShoppingCart::cancelOrder() {
    for (auto item : productsToPurchase) {
        delete item;
    }
    productsToPurchase.clear();
    cout << "Sepet bosaltildi." << endl;
}

// Fatura detaylarini gosterme
void ShoppingCart::showInvoice() {
    cout << "\n****** FATURA ******" << endl;
    cout << "Musteri: " << customer->getName() << endl;
    cout << "Odenen Tutar: " << paymentMethod->getAmount() << " TL" << endl;
    cout << "********************\n" << endl;
}