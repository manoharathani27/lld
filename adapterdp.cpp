#include <iostream>
using namespace std;


enum class PaymentStatus {
    SUCCESS,
    FAILURE
};


class PaymentGateway {
public:
    virtual long payViaCC(string cardNumber,
                           int cvv,
                           int expiryMonth,
                           int expiryYear) = 0;

    virtual PaymentStatus getStatus(long id) = 0;

    virtual ~PaymentGateway() {}
};


class RazorpayGateway {
public:
    string payByCreditCard(string creditCard,
                            string cvv,
                            string expiry) {

        cout << "Payment Done by Razorpay\n";
        return "123";   
    }

    bool checkPaymentStatus(string id) {
        return true;   
    }
};


class RazorpayAdapter : public PaymentGateway {
private:
    RazorpayGateway razorpayGateway;

public:
    long payViaCC(string cardNumber,
                  int cvv,
                  int expiryMonth,
                  int expiryYear) override {

      
        string cvvStr = to_string(cvv);
        string expiry = to_string(expiryMonth) + "/" + to_string(expiryYear);

        
        string result = razorpayGateway.payByCreditCard(cardNumber, cvvStr, expiry);

        
        return stol(result);
    }

    PaymentStatus getStatus(long id) override {

        bool status = razorpayGateway.checkPaymentStatus(to_string(id));

        if (status)
            return PaymentStatus::SUCCESS;

        return PaymentStatus::FAILURE;
    }
};


class Flipkart {
private:
    PaymentGateway* paymentGateway;

public:
    Flipkart(PaymentGateway* gateway) {
        paymentGateway = gateway;
    }

    void makePayment() {
        long transactionId = paymentGateway->payViaCC(
                                "1234567890123456",
                                123,
                                12,
                                2027);

        PaymentStatus status = paymentGateway->getStatus(transactionId);

        if (status == PaymentStatus::SUCCESS)
            cout << "Payment Successful\n";
        else
            cout << "Payment Failed\n";
    }
};

int main() {

    PaymentGateway* gateway = new RazorpayAdapter();

    Flipkart flipkart(gateway);
    flipkart.makePayment();

    delete gateway;

    return 0;
}