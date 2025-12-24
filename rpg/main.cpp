#include <iostream>
#include <string>

using namespace std;

// Базовый класс для всех персонажей
class Character {
private:
    string name;
    int health;
    int damage;

public:
    // Конструктор
    Character(string n, int h, int d) {
        name = n;
        health = h;
        damage = d;
    }

    // Метод для получения информации
    void getInfo() {
        cout << name << " (HP: " << health << ", Урон: " << damage << ")" << endl;
    }
};

int main() {
    return 0;
}
