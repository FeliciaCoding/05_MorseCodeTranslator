#include <iostream>
#include <limits>
#include <cctype>

#include "userInputs.h"

using namespace std;

void handleReadError() {

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

}

char getUserChoice(const string &text, char choice1, char choice2) {

    //Nom de variable pas clair entre choice, choice1 et choice2 on peut vite se perdre
    char choice;
    do {
        cout << text;
        cin >> choice;

        // Assume restart program accept both lowercase & uppercase (Case-insensitive).
        // Tu parles de "restart" dans le commentaire mais dans cette fonction le concepte de restart n'est pas présent
        if (islower(choice)){
            choice = toupper(choice);
        }

        handleReadError();

    } while (choice != choice1 && choice != choice2);

    return choice;
}
