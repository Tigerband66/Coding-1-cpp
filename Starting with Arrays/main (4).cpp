// Brian Foster Coding 1 at 11am 
// Spring 2024 Week 5
// Loops and Lists

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Hello World!\n";
    // it's important to have our computers tell us what they're doing.

    // keep playing(yes/no)? do-while loop
    // random name generator
    // battle bot orderer (shuffles list) (with vector)

    // while (true) {
    //     cout << "My name is dan.\n";
    // }

    // do-while loops tests at the end of the loop.

    string response = "";
    // cout << "Do you want to keep adventuring? (yes/no)\n";
    // cin >> response;

    // while(response != "no") {
    //     cout << "Here we are adventuring!!!!\nYaaaay!!!\n";

    //     cout << "Do you want to keep adventuring? (yes/no)\n";
    //     cin >> response;
    // }

    // enter the do-while loop, which tests at the end.

    do {
        cout << "yay adventure!\n";
        cout << "Do you want to keep adventuring?\n";
        cin >> response;
        
    } while(response != "no");


    // do the test inside the loop.

    while(true) {
        string response;
        cout << "yay adventure!\n";
        cout << "Do you want to keep adventuring?\n";
        cin >> response;

        if(response == "no") {
            cout << "Alright! Let's go home.\n";
            break;        // break out of the loop
        }
    }

    cout << "Here we are, safely outside of the last while loop.\n";

    // let's build a list of names!

    // build an array of strings named "names" with a size of 10.
    string names[10];
    names[0] = "Bryce";        // the number between the [square brackets]
    names[1] = "Hunt";        // is called the index.
    names[2] = "Ruhn";
    names[3] = "Tharion";
    names[4] = "Lidia";

    cout << "My favorite character is " << names[1] << ".\n";

    // the for loop is a great way to go through a list of things.
    // it has a built in counter named 'i' for "iterator"
    // you can name it whatever you want though.
    // this is what's happening in english:
    // for(initialization, test, action) { code block }

    // in code, by default, this looks like:
    for(int i = 0; i < 10; i += 1) {
        if(names[i] == "") continue;        // go back to top of loop
        cout << names[i] << "\n";
    }

    cout << "And that's all the characters in my array of names.\n";

    // create an array of favorite games
    string favGames[10];
    int index = 0;            // index points at the current empty space.
    // create a while loop that asks the player what they would like to do.
    while (true) {
        // the player can "add" a game, or "show" the games, or "quit
        string input = "";
        cout << "What would you like to do?\n";
        cin >> input;
        
        
        if(input == "add") {
            if(index >= 10) {
                cout << "The list is full!\n";
                
            }
            else {
                // when adding, if size is MAX, don't let them add any more.
                cout << "What name would you like to add?\n";
                cin >> input;
                favGames[index] = input;
                index += 1;        // add one to index so that it's pointing at
                                    // the next free space.
            }
        }
        else if(input == "show") {
            // when showing, ignore blank spaces
            for(int i = 0; i < 10; i += 1) {
                if(favGames[i] == "") continue;        // go back to top of loop
                cout << i + 1 << ". " << favGames[i] << "\n";
            }
        }
        else if (input == "quit") {
            // when quitting, tell them thanks for playing.
            cout << "Thanks for playing!\n";
            break;        // out of the loop
        }
        
    } // end of favGames loop.
    
    
    

    
}