#include <iostream>
using namespace std;


class Bird {
public:
    virtual void makeSound() = 0;
    virtual ~Bird() {}
};

class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() {}
};

class Swimmable {
public:
    virtual void swim() = 0;
    virtual ~Swimmable() {}
};




class Sparrow : public Bird, public Flyable {
public:
    void makeSound() override {
        cout << "Sparrow chirps\n";
    }

    void fly() override {
        cout << "Sparrow is flying\n";
    }
};


class Eagle : public Bird, public Flyable {
public:
    void makeSound() override {
        cout << "Eagle screeches\n";
    }

    void fly() override {
        cout << "Eagle is soaring high\n";
    }
};


class Penguin : public Bird, public Swimmable {
public:
    void makeSound() override {
        cout << "Penguin squawks\n";
    }

    void swim() override {
        cout << "Penguin is swimming\n";
    }
};


class Ostrich : public Bird {
public:
    void makeSound() override {
        cout << "Ostrich booms\n";
    }
};


class Duck : public Bird, public Flyable, public Swimmable {
public:
    void makeSound() override {
        cout << "Duck quacks\n";
    }

    void fly() override {
        cout << "Duck is flying\n";
    }

    void swim() override {
        cout << "Duck is swimming\n";
    }
};



void makeBirdFly(Flyable* bird) {
    bird->fly();
}

void makeBirdSwim(Swimmable* bird) {
    bird->swim();
}


int main() {

    Sparrow sparrow;
    Eagle eagle;
    Penguin penguin;
    Ostrich ostrich;
    Duck duck;

    sparrow.makeSound();
    makeBirdFly(&sparrow);

    eagle.makeSound();
    makeBirdFly(&eagle);

    penguin.makeSound();
    makeBirdSwim(&penguin);

    ostrich.makeSound();

    duck.makeSound();
    makeBirdFly(&duck);
    makeBirdSwim(&duck);

    return 0;
}