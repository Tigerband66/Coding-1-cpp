#include <iostream>
#include <ctime>
using namespace std;
int RollDie(int sides = 6) {
  return (rand() % sides) + 1;
}
string askYesNo(string question) {
  string input;
  do {
    cout << question << " (y/n): ";
    cin >> input;
  } while (input != "y" && input != "n");
  return input;
}
int main() {
  srand(time(0));
  int health = 10;
  int gold = 0;
  int turns = 0;
  string input;
  do {
      input = askYesNo("Would you like to go adventuring?\n");
      if (input == "y") {
        turns++;
        int attack = RollDie();
        int block = RollDie();
        if (block >= attack) {
          health--;
          cout << "You successfully blocked the attack and ran away!\n";
          gold += RollDie();
          cout << "You found " << gold << " gold!\n";
        } 
        else {
          health -= attack;
          cout << "You were hit by the attack and lost " << attack << " health points!\n";
          if (input == "n") {
            cout << "You escaped without finding any gold.\n";
          }
        }
      } 
  } while (health > 0 && input == "y");
  if (health <= 0) {
    cout << "You died! Your body was found with " << gold << " gold.\n";
  } 
  else {
    cout << "You are still alive!\n";
    cout << "You lasted " << turns << " turns and found " << gold << " gold.\n";
    if (health < 5) {
      cout << "You should go to the doctor. Your health is low.\n";
    };
  }
  return 0;
}