// This is for Coding 1a
// Week 11 Adventure


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Weapon class definition
class Weapon {
public:
    string name;
    int damage;

    Weapon(string name, int damage) {
        this->name = name;
        this->damage = damage;
    }
};

// Enemy class definition
class Enemy {
public:
    string name;
    int health;
     Weapon weapon;

    Enemy(string name, int health, Weapon weapon): 
    name(name), 
    health(health), 
    weapon(weapon)
{
        this->name = name;
        this->health = health;
        this->weapon = weapon;
    }
};

// Player class definition
class Player {
public:
    string name;
    int health;
    vector<Weapon> inventory;
    Player(string name, int health) {
        this->name = name;
        this->health = health;
    }
    void useItem(int itemIndex) {
        if (itemIndex < 0 || itemIndex >= inventory.size()) {
            cout << "Invalid item index!" << endl;
            return;
        }
        cout << "Used " << inventory[itemIndex].name << endl;
    }
};

int main() {
    srand(time(0));

    // Player Setup
    string playerName;
    cout << "Enter your name, brave adventurer: ";
    cin >> playerName;
    Player player(playerName, 100);

    // Enemy Setup
    vector<Enemy> enemies = {
        Enemy("Goblin", 50, Weapon("Rusty Dagger", 10)),
        Enemy("Skeleton", 75, Weapon("Bone Sword", 15)),
        Enemy("Ogre", 100, Weapon("Giant Club", 20))
    };

    // Game Loop
    int enemyIndex = 0;
    while (player.health > 0 && enemyIndex < enemies.size()) {
        Enemy &enemy = enemies[enemyIndex];

        cout << "\nYou encounter a " << enemy.name << "!" << endl;

        while (player.health > 0 && enemy.health > 0) {
            cout << "\nWhat do you do?" << endl;
            cout << "1. Attack" << endl;
            if (!player.inventory.empty()) {
                cout << "2. Use item" << endl;
            }
            int choice;
            cin >> choice;

            if (choice == 1) {
                if (player.inventory.empty()) {
                    cout << "You punch " << enemy.name << "!" << endl;
                    enemy.health -= 5;
                    cout << enemy.name << " takes 5 damage." << endl;
                } else {
                    cout << "Choose a weapon to attack with:" << endl;
                    for (int i = 0; i < player.inventory.size(); i++) {
                        cout << i + 1 << ". " << player.inventory[i].name << endl;
                    }
                    int weaponChoice;
                    cin >> weaponChoice;
                    if (weaponChoice >= 1 && weaponChoice <= player.inventory.size()) {
                        cout << "You attack " << enemy.name << " with your " << player.inventory[weaponChoice - 1].name << "!" << endl;
                        enemy.health -= player.inventory[weaponChoice - 1].damage;
                        cout << enemy.name << " takes " << player.inventory[weaponChoice - 1].damage << " damage." << endl;
                    } else {
                        cout << "Invalid choice. You punch " << enemy.name << "!" << endl;
                        enemy.health -= 5;
                        cout << enemy.name << " takes 5 damage." << endl;
                    }
                }
            } else if (choice == 2 && !player.inventory.empty()) {
                cout << "Choose an item to use:" << endl;
                for (int i = 0; i < player.inventory.size(); i++) {
                    cout << i + 1 << ". " << player.inventory[i].name << endl;
                }
                int itemChoice;
                cin >> itemChoice;
                player.useItem(itemChoice - 1);
            } else {
                cout << "Invalid choice." << endl;
            }

            if (enemy.health > 0) {
                cout << enemy.name << " attacks you with their " << enemy.weapon.name << "!" << endl;
                player.health -= enemy.weapon.damage;
                cout << "You take " << enemy.weapon.damage << " damage." << endl;
            }
        }

        if (player.health > 0) {
            cout << "You defeated the " << enemy.name << "!" << endl;
            if (enemyIndex == enemies.size() - 1) {
                cout << "Congratulations! You have defeated all enemies and won the game!" << endl;
            } else {
                cout << "You find a Health Potion on the slain enemy." << endl;
                player.inventory.push_back(Weapon("Health Potion", 0));
                enemyIndex++;
            }
        }
    }

    if (player.health <= 0) {
        cout << "Game Over. You have died." << endl;
    }

    return 0;
}
