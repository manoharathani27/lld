#include <iostream>
#include <map>
#include <memory>
using namespace std;

enum class TransportMode {
    CAR,
    BIKE,
    WALK
};

class PathCalculationStrategy {
public:
    virtual void calculatePath(string from, string to) = 0;
    virtual ~PathCalculationStrategy() {}
};

class CarPathCalculationStrategy : public PathCalculationStrategy {
public:
    void calculatePath(string from, string to) override {
        cout << "Finding fastest car route from "
             << from << " to " << to << endl;
    }
};

class BikePathCalculationStrategy : public PathCalculationStrategy {
public:
    void calculatePath(string from, string to) override {
        cout << "Finding bike-friendly route from "
             << from << " to " << to << endl;
    }
};

class WalkPathCalculationStrategy : public PathCalculationStrategy {
public:
    void calculatePath(string from, string to) override {
        cout << "Finding walking path from "
             << from << " to " << to << endl;
    }
};

class PathCalculationStrategyRegistry {
private:
    map<TransportMode, PathCalculationStrategy*> strategies;

public:
    void registerStrategy(TransportMode mode,
                          PathCalculationStrategy* strategy) {
        strategies[mode] = strategy;
    }

    PathCalculationStrategy* get(TransportMode mode) {
        return strategies[mode];
    }

    ~PathCalculationStrategyRegistry() {
        for (auto& pair : strategies) {
            delete pair.second;
        }
    }
};

class GoogleMaps {
private:
    PathCalculationStrategyRegistry* registry;

public:
    GoogleMaps(PathCalculationStrategyRegistry* registry) {
        this->registry = registry;
    }

    void findPath(string from,
                  string to,
                  TransportMode mode) {

        PathCalculationStrategy* strategy =
            registry->get(mode);

        strategy->calculatePath(from, to);
    }
};

int main() {

    PathCalculationStrategyRegistry registry;

    registry.registerStrategy(
        TransportMode::CAR,
        new CarPathCalculationStrategy()
    );

    registry.registerStrategy(
        TransportMode::BIKE,
        new BikePathCalculationStrategy()
    );

    registry.registerStrategy(
        TransportMode::WALK,
        new WalkPathCalculationStrategy()
    );

    GoogleMaps googleMaps(&registry);

    googleMaps.findPath("Bangalore", "Mysore", TransportMode::CAR);
    googleMaps.findPath("Bangalore", "Mysore", TransportMode::BIKE);
    googleMaps.findPath("Bangalore", "Mysore", TransportMode::WALK);

    return 0;
}