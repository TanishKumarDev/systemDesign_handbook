#include <iostream>
using namespace std;

// ---------------- Legacy System ----------------
class OldPaymentGateway {
public:
    void makePayment(int amount) {
        cout << "Payment of Rs." << amount << " processed using Old Gateway.\n";
    }
};

// ---------------- Target Interface ----------------
class NewPaymentSystem {
public:
    virtual void pay(int amount) = 0;
    virtual ~NewPaymentSystem() {}
};

// ---------------- Adapter ----------------
class PaymentAdapter : public NewPaymentSystem {
private:
    OldPaymentGateway* oldGateway;
public:
    PaymentAdapter(OldPaymentGateway* gateway) : oldGateway(gateway) {}
    
    void pay(int amount) override {
        // Adapting old method to new method
        oldGateway->makePayment(amount);
    }
};

// ---------------- Client Code ----------------
int main() {
    // Using new interface directly
    NewPaymentSystem* payment = nullptr;

    // Suppose we still need to use old gateway
    OldPaymentGateway* oldGateway = new OldPaymentGateway();
    payment = new PaymentAdapter(oldGateway);

    payment->pay(500);  // Client thinks it's using "NewPaymentSystem"

    delete payment;
    delete oldGateway;
    return 0;
}

// Suppose we have a new payment system, but we need to use an old legacy gateway as well.

// 🔑 Key Points

// Client expects NewPaymentSystem.

// OldPaymentGateway has a different method name (makePayment).

// Adapter (PaymentAdapter) converts pay() calls into makePayment() calls.

// Client stays unaware of the adaptation.

// ⚡ This is widely used in:

// Connecting legacy code with modern systems.

// Adapting 3rd party libraries (e.g., integrating different logging/payment/database APIs).

// UI frameworks where you need to adapt widge