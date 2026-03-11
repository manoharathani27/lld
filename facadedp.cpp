#include <iostream>
using namespace std;

class Projector {
public:
    void on() { cout << "Projector ON\n"; }
    void off() { cout << "Projector OFF\n"; }
};

class SoundSystem {
public:
    void on() { cout << "Sound System ON\n"; }
    void setVolume(int level) {
        cout << "Volume set to " << level << endl;
    }
    void off() { cout << "Sound System OFF\n"; }
};

class DVDPlayer {
public:
    void on() { cout << "DVD Player ON\n"; }
    void play(string movie) {
        cout << "Playing movie: " << movie << endl;
    }
    void off() { cout << "DVD Player OFF\n"; }
};

class HomeTheaterFacade {
private:
    Projector projector;
    SoundSystem soundSystem;
    DVDPlayer dvdPlayer;

public:
    void watchMovie(string movie) {
        cout << "\nStarting Movie...\n";
        projector.on();
        soundSystem.on();
        soundSystem.setVolume(10);
        dvdPlayer.on();
        dvdPlayer.play(movie);
    }

    void endMovie() {
        cout << "\nShutting Down...\n";
        dvdPlayer.off();
        soundSystem.off();
        projector.off();
    }
};

int main() {

    HomeTheaterFacade homeTheater;

    homeTheater.watchMovie("Inception");
    homeTheater.endMovie();

    return 0;
}