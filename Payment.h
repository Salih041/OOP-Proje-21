/*
    Enes Kılıç - 11.12.2025
*/

#ifndef PAYMENT_H
#define PAYMENT_H


class Payment   // Payment class'ı oluşturuluyor.
{
    private:
    double amount;

    public:
    Payment(double amount);
    double getAmount() const;
    void setAmount(double a);
    virtual void performPayment() = 0;  // Fonksiyonu miras alan class'lar kullanacağı için, virtual kullanıldı.
                                        // Miras alan class'larda tanım zorunluluğu için = 0 kullanıldı.
    virtual ~Payment() = default;
};
#endif // !PAYMENT_H