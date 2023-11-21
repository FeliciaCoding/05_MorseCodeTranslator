#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>

#include "userInputs.h"
#include "fileOperations.h"
#include "morseTranslator.h"

using namespace std;

int main() {

    const int  COLUMN_WIDTH      = 18;
    const char POSITIVE_RESPONSE = 'Y';
    const char NEGATIVE_RESPONSE = 'N';
    const char ENCODE            = '1';
    const char DECODE            = '2';

    char restartChoice;
    do {
      // Utilisation des constantes ENCODE et DECODE
      cout << "This program allows you to translate a .txt file you provided from text to Morse (1) "
                "and Morse to Text (2).\n";
        // Utilisation des constantes ENCODE et DECODE
        cout << setw(COLUMN_WIDTH) << "1 - encode" << endl;
        cout << setw(COLUMN_WIDTH) << "2 - decode" << endl;

        // Utilisation des constantes ENCODE et DECODE dans le text
        int translateChoice = getUserChoice("Your choice [1-2] : ", ENCODE, DECODE);

        // Déclaration des variables sur plusieurs lignes
        string inputFileName, outputFileName;
        cout << "file in : ";
        cin  >> inputFileName;
        cout << "file out : ";
        cin  >> outputFileName;

        ifstream inputFile;
        ofstream outputFile;

        if (!openFiles(inputFileName, outputFileName, inputFile, outputFile)) {
            return EXIT_FAILURE;
        }

        if (translateChoice == ENCODE) {
            encodeTextToMorse(inputFileName, outputFileName);
        } else {
            decodeMorseToText(inputFileName, outputFileName);
        }

        closeFiles(inputFile, outputFile);

        //Utilisation des constantes POSITIVE_RESPONSE et NEGATIVE_RESPONSE
        restartChoice = getUserChoice("Do you want to continue ? [Y/N] : ", POSITIVE_RESPONSE,
                                          NEGATIVE_RESPONSE);

        if (restartChoice == NEGATIVE_RESPONSE) {
            cout << "Ending program...";
        }
    } while (restartChoice == POSITIVE_RESPONSE);

    return EXIT_SUCCESS;
}
