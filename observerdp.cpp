#include <iostream>
#include <map>
#include <vector>
#include <memory>

using namespace std;

enum class Events {
    ORDER_PLACED
};

class Order {
private:
    long orderId;
    int amount;

public:
    Order(long id, int amt) : orderId(id), amount(amt) {}

    long getOrderId() const { return orderId; }
    int getAmount() const { return amount; }
};

class Subscriber {
public:
    virtual void listen(Events event, const Order& order) = 0;
    virtual ~Subscriber() {}
};

class InvoiceManagementService : public Subscriber {
public:
    void listen(Events event, const Order& order) override {
        if (event == Events::ORDER_PLACED) {
            generateInvoice(order);
        }
    }

    void generateInvoice(const Order& order) {
        cout << "Generating invoice for Order ID: "
             << order.getOrderId()
             << " Amount: " << order.getAmount()
             << endl;
    }
};

class EmailService : public Subscriber {
public:
    void listen(Events event, const Order& order) override {
        if (event == Events::ORDER_PLACED) {
            sendEmail(order);
        }
    }

    void sendEmail(const Order& order) {
        cout << "Sending email for Order ID: "
             << order.getOrderId()
             << endl;
    }
};

class Flipkart {
private:
    map<Events, vector<Subscriber*>> subscribers;

public:
    void registerSubscriber(Events event, Subscriber* subscriber) {
        subscribers[event].push_back(subscriber);
    }

    void notify(Events event, const Order& order) {
        for (Subscriber* sub : subscribers[event]) {
            sub->listen(event, order);
        }
    }

    void placeOrder(const Order& order) {
        cout << "\nOrder Placed Successfully\n";
        notify(Events::ORDER_PLACED, order);
    }
};

int main() {

    Flipkart flipkart;

    InvoiceManagementService invoiceService;
    EmailService emailService;

    
    flipkart.registerSubscriber(
        Events::ORDER_PLACED,
        &invoiceService
    );

    flipkart.registerSubscriber(
        Events::ORDER_PLACED,
        &emailService
    );

 
    Order order1(101, 5000);

 
    flipkart.placeOrder(order1);

    return 0;
}