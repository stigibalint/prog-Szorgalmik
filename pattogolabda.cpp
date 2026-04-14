#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

int main() {
    const int WIDTH = 50;
    const int HEIGHT = 15;
    int x = WIDTH / 2;
    int y = HEIGHT / 2;
    int dx = 1;
    int dy = 1;

    while (true) {
        cout << "\033[2J\033[H";

        string frame = "";

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                    frame += "#"; 
                }
                else if (i == y && j == x) {
                    frame += "O";
                }
                else {
                    frame += " ";
                }
            }
            frame += "\n";
        }

        cout << frame;
        x += dx;
        y += dy;

        if (x <= 1 || x >= WIDTH - 2) dx *= -1;
        if (y <= 1 || y >= HEIGHT - 2) dy *= -1;
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    return 0;
}