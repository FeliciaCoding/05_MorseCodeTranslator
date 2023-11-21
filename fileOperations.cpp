#include <iostream>
#include <fstream>
#include <string>

#include "fileOperations.h"

using namespace std;

// la fonction fait 2 choses, ouvre 2 fichiers => faire 2 fonctions
// Un commentaire utile serait d'expliquer pourquoi le type de retour est un bool et spécifier ce que chaque valeur représente
bool openFiles(const string &inputFileName, const string &outputFileName, ifstream &inputFile, ofstream &outputFile) {

    inputFile.open(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Unable to open file '" << inputFileName << "'" << endl;
        return false;
    }

    outputFile.open(outputFileName);
    if (!outputFile.is_open()) {
      cerr << "Unable to open file '" << inputFileName << "'" << endl;
        inputFile.close(); // Close successfully opened input file before returning false
        // Le commentaire me donne pas plus d'infos que ce que je lis dans le code
        return false;
    }

    return true;
}

// la fonction fait 2 choses, ouvre 2 fichiers => faire 2 fonctions
void closeFiles(ifstream &inputFile, ofstream &outputFile) {
    inputFile.close();
    outputFile.close();
}
