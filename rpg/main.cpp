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
        cout << name << " (HP: " << health << ", Урон: " << damage << ")" << endl;}

    // метод: получение урона
    void takeDamage(int dmg) {
        health -= dmg;
        if (health < 0) health = 0;
        cout << name << " получил " << dmg << " урона. Осталось HP: " << health << endl;
    }

    //  метод: атака другого персонажа
    void attack(Character* target) {
        cout << name << " атакует " << target->name << "!" << endl;
        target->takeDamage(damage);
    }

    // Геттер для имени
    string getName() {
        return name;
    }

};
int main() {
    return 0;
}
