#include <iostream>
#include <unordered_map>
using namespace std;



class Bird {
public:
    virtual void makeSound() = 0;

    // Prototype method
    virtual Bird* clone() = 0;

    virtual ~Bird() {}
};


class Sparrow : public Bird {
public:
    void makeSound() override {
        cout << "Sparrow chirps\n";
    }

    Bird* clone() override {
        return new Sparrow(*this);   // copy constructor cloning
    }
};

class Eagle : public Bird {
public:
    void makeSound() override {
        cout << "Eagle screeches\n";
    }

    Bird* clone() override {
        return new Eagle(*this);
    }
};

class Penguin : public Bird {
public:
    void makeSound() override {
        cout << "Penguin squawks\n";
    }

    Bird* clone() override {
        return new Penguin(*this);
    }
};

class Ostrich : public Bird {
public:
    void makeSound() override {
        cout << "Ostrich booms\n";
    }

    Bird* clone() override {
        return new Ostrich(*this);
    }
};

class Duck : public Bird {
public:
    void makeSound() override {
        cout << "Duck quacks\n";
    }

    Bird* clone() override {
        return new Duck(*this);
    }
};



class BirdRegistry {
private:
    unordered_map<string, Bird*> prototypes;

public:
    void registerBird(string type, Bird* bird) {
        prototypes[type] = bird;
    }

    Bird* createBird(string type) {
        return prototypes[type]->clone();
    }
};


int main() {

    BirdRegistry registry;

  
    registry.registerBird("sparrow", new Sparrow());
    registry.registerBird("eagle", new Eagle());
    registry.registerBird("penguin", new Penguin());
    registry.registerBird("ostrich", new Ostrich());
    registry.registerBird("duck", new Duck());

   
    Bird* b1 = registry.createBird("sparrow");
    Bird* b2 = registry.createBird("eagle");
    Bird* b3 = registry.createBird("duck");

    b1->makeSound();
    b2->makeSound();
    b3->makeSound();

    delete b1;
    delete b2;
    delete b3;

    return 0;
}

