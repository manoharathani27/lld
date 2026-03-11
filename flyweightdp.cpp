#include <iostream>
#include <map>
#include <vector>
using namespace std;

enum class BulletType {
    FIVE_MM,
    SEVEN_MM,
    NINE_MM
};


class Bullet {
private:
    double radius;
    double weight;
    BulletType type;
    vector<char> image;  
public:
    Bullet(BulletType type, double radius, double weight)
        : type(type), radius(radius), weight(weight) {

       
        image.resize(1000000, 'X');
        cout << "Creating Bullet Type: " << static_cast<int>(type) << endl;
    }

    BulletType getType() const {
        return type;
    }

    double getRadius() const {
        return radius;
    }

    double getWeight() const {
        return weight;
    }
};

class BulletRegistry {
private:
    map<BulletType, Bullet*> bullets;

public:
    void registerBullet(BulletType type, Bullet* bullet) {
        bullets[type] = bullet;
    }

    Bullet* getBullet(BulletType type) {
        return bullets[type];
    }

    ~BulletRegistry() {
        for (auto& pair : bullets) {
            delete pair.second;
        }
    }
};

class FlyingBullet {
private:
    double speed;
    double x, y, z;  
    long userId;

    Bullet* bullet;   

public:
    FlyingBullet(double speed,
                 double x,
                 double y,
                 double z,
                 long userId,
                 Bullet* bullet)
        : speed(speed), x(x), y(y), z(z), userId(userId), bullet(bullet) {}

    void display() {
        cout << "User " << userId
             << " fired bullet type "
             << static_cast<int>(bullet->getType())
             << " at speed " << speed << endl;
    }
};

int main() {

    BulletRegistry registry;

   
    registry.registerBullet(
        BulletType::FIVE_MM,
        new Bullet(BulletType::FIVE_MM, 5.0, 10.0)
    );

    registry.registerBullet(
        BulletType::SEVEN_MM,
        new Bullet(BulletType::SEVEN_MM, 7.0, 15.0)
    );

    registry.registerBullet(
        BulletType::NINE_MM,
        new Bullet(BulletType::NINE_MM, 9.0, 20.0)
    );

    vector<FlyingBullet*> flyingBullets;

    
    for (int i = 0; i < 200000; i++) {
        FlyingBullet* fb = new FlyingBullet(
            120.0,
            1.0, 0.0, 0.0,
            i,
            registry.getBullet(BulletType::FIVE_MM)
        );

        flyingBullets.push_back(fb);
    }

    cout << "Created 200000 bullets using Flyweight pattern.\n";

    
    for (auto fb : flyingBullets) {
        delete fb;
    }

    return 0;
}