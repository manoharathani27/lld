#include <iostream>
using namespace std;



class IceCream {
public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
    virtual ~IceCream() {}
};


class Cone : public IceCream {
public:
    string getDescription() override {
        return "Cone";
    }

    double getCost() override {
        return 20.0;
    }
};


class IceCreamDecorator : public IceCream {
protected:
    IceCream* iceCream;

public:
    IceCreamDecorator(IceCream* ic) {
        iceCream = ic;
    }
};



class Vanilla : public IceCreamDecorator {
public:
    Vanilla(IceCream* ic) : IceCreamDecorator(ic) {}

    string getDescription() override {
        return iceCream->getDescription() + " + Vanilla";
    }

    double getCost() override {
        return iceCream->getCost() + 10.0;
    }
};

class Chocolate : public IceCreamDecorator {
public:
    Chocolate(IceCream* ic) : IceCreamDecorator(ic) {}

    string getDescription() override {
        return iceCream->getDescription() + " + Chocolate";
    }

    double getCost() override {
        return iceCream->getCost() + 15.0;
    }
};

class Nuts : public IceCreamDecorator {
public:
    Nuts(IceCream* ic) : IceCreamDecorator(ic) {}

    string getDescription() override {
        return iceCream->getDescription() + " + Nuts";
    }

    double getCost() override {
        return iceCream->getCost() + 8.0;
    }
};



int main() {

   
    IceCream* iceCream = new Cone();

 
    iceCream = new Vanilla(iceCream);

   
    iceCream = new Chocolate(iceCream);


    iceCream = new Nuts(iceCream);

    cout << "Order: " << iceCream->getDescription() << endl;
    cout << "Total Cost: ₹" << iceCream->getCost() << endl;

    delete iceCream;  

    return 0;
}