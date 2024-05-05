#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
  vector<string> favorite_games;
  string input;
  while (favorite_games.size() < 10) {
    cout << "Enter 'add' to add a game, 'show' to display games, or 'quit' to exit: ";
    cin >> input;
    if (input == "add") {
      string game;
      cout << "Enter the name of the game: ";
      cin.ignore();
      getline(cin, game);
      favorite_games.push_back(game);
    } else if (input == "show") {
      for (const auto& game : favorite_games) {
        cout << game << endl;
      }
    } else if (input == "quit") {
      break;
    }
  }
  return 0;
}