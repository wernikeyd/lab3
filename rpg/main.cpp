#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
// Базовый класс для всех персонажей
string heroName;
string enemyName;
class Character         {
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
        cout << name << " получил " <<  dmg << " урона. Осталось HP: " << health << endl;
    }

    //  метод: атака другого персонажа
    void attack(Character* target) {
        cout << name << " атакует " << target->name << "!" << endl;
        target->takeDamage(damage);
    }


    bool isAlive() {
        return health > 0;
    }


    // Геттер для имени
    string getName() {
        return name;
    }

};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
     // Ввод имени героя
    cout << "Введите имя героя: ";
    cin >> heroName;

    // Ввод имени врага
    cout << "Введите имя врага: ";
    cin >> enemyName;

    // Создаем персонажей с пользовательскими именами
    Character hero(heroName, 100, 20);
    Character enemy(enemyName, 80, 10);

 cout << "\n=== НАЧАЛО БОЯ ===\n" << endl;
    // бой
    while (hero.isAlive() && enemy.isAlive()) {
        hero.attack(&enemy);
        if (enemy.isAlive()) {
            enemy.attack(&hero);
        }
        cout << "---" << endl;
    }
    // Результат
    cout << "\n=== БОЙ ЗАВЕРШЕН ===" << endl;
    if (hero.isAlive()) {
        cout << "Победил: " << hero.getName() << "!" << endl;
    } else {
        cout << "Победил: " << enemy.getName() << "!" << endl;
    }
    return 0;
}
