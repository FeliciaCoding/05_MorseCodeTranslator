#include <iostream>
#include <string>
#include <fstream>
#include "morseTranslator.h"

using namespace std;

char morseToChar(const string &morse) {

    if (morse == ".-") return 'A';
    else if (morse == "-...") return 'B';
    else if (morse == "-.-.") return 'C';
    else if (morse == "-..") return 'D';
    else if (morse == ".") return 'E';
    else if (morse == "..-.") return 'F';
    else if (morse == "--.") return 'G';
    else if (morse == "....") return 'H';
    else if (morse == "..") return 'I';
    else if (morse == ".---") return 'J';
    else if (morse == "-.-") return 'K';
    else if (morse == ".-..") return 'L';
    else if (morse == "--") return 'M';
    else if (morse == "-.") return 'N';
    else if (morse == "---") return 'O';
    else if (morse == ".--.") return 'P';
    else if (morse == "--.-") return 'Q';
    else if (morse == ".-.") return 'R';
    else if (morse == "...") return 'S';
    else if (morse == "-") return 'T';
    else if (morse == "..-") return 'U';
    else if (morse == "...-") return 'V';
    else if (morse == ".--") return 'W';
    else if (morse == "-..-") return 'X';
    else if (morse == "-.--") return 'Y';
    else if (morse == "--..") return 'Z';

    else if (morse == ".-.-.-") return '.';
    else if (morse == "--..--") return ',';
    else if (morse == "..--..") return '?';
    else if (morse == ".----.") return '\'';
    else if (morse == "-.-.--") return '!';
    else if (morse == "-..-.") return '/';
    else if (morse == "-.--.") return '(';
    else if (morse == "-.--.-") return ')';
    else if (morse == ".-...") return '&';
    else if (morse == "---...") return ':';
    else if (morse == "-.-.-.") return ';';
    else if (morse == "-...-") return '=';
    else if (morse == ".-.-.") return '+';
    else if (morse == "-....-") return '-';
    else if (morse == "..--.-") return '_';
    else if (morse == ".-..-.") return '"';
    else if (morse == "...-..-") return '$';
    else if (morse == ".--.-.") return '@';

    else if (morse == "-----") return '0';
    else if (morse == ".----") return '1';
    else if (morse == "..---") return '2';
    else if (morse == "...--") return '3';
    else if (morse == "....-") return '4';
    else if (morse == ".....") return '5';
    else if (morse == "-....") return '6';
    else if (morse == "--...") return '7';
    else if (morse == "---..") return '8';
    else if (morse == "----.") return '9';

    else return ' ';
}
// La référence pour un type primitif est-ce utile ?
string charToMorse(const char &c) {

    switch (c) {
        case 'A' :
            return ".-";
        case 'B' :
            return "-...";
        case 'C' :
            return "-.-.";
        case 'D' :
            return "-..";
        case 'E' :
            return ".";
        case 'F' :
            return "..-.";
        case 'G' :
            return "--.";
        case 'H' :
            return "....";
        case 'I' :
            return "..";
        case 'J' :
            return ".---";
        case 'K' :
            return "-.-";
        case 'L' :
            return ".-..";
        case 'M' :
            return "--";
        case 'N' :
            return "-.";
        case 'O' :
            return "---";
        case 'P' :
            return ".--.";
        case 'Q' :
            return "--.-";
        case 'R' :
            return ".-.";
        case 'S' :
            return "...";
        case 'T' :
            return "-";
        case 'U' :
            return "..-";
        case 'V' :
            return "...-";
        case 'W' :
            return ".--";
        case 'X' :
            return "-..-";
        case 'Y' :
            return "-.--";
        case 'Z' :
            return "--..";

        case '.' :
            return ".-.-.-";
        case ',' :
            return "--..--";
        case '?' :
            return "..--..";
        case '\'' :
            return ".----.";
        case '!' :
            return "-.-.--";
        case '/' :
            return "-..-.";
        case '(' :
            return "-.--.";
        case ')' :
            return "-.--.-";
        case '&' :
            return ".-...";
        case ':' :
            return "---...";
        case ';' :
            return "-.-.-.";
        case '=' :
            return "-...-";
        case '+' :
            return ".-.-.";
        case '-' :
            return "-....-";
        case '_' :
            return "..--.-";
        case '"' :
            return ".-..-.";
        case '$' :
            return "...-..-";
        case '@' :
            return ".--.-.";

        case '0' :
            return "-----";
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";

        default :
            return "";

    }
}

// D'après le nom de la fonction je m'attend à ce qu'elle ne fasse que traduire du morse en texte pas d'écrire dans un fichier
// Du coup votre fonction fait 2 choses, elle traduit le message écrit dans le fichier de sortie
void decodeMorseToText(const string &inputFileName, const string &outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    string morseCode;
    string text;
    while (inputFile >> morseCode) {
        if (morseCode == "/") {
            text += " ";
        } else {
            char letter = morseToChar(morseCode);
            text += letter;
        }
    }

    outputFile << text;
}
// Pareil que pour l'autre fonction
void encodeTextToMorse(const string &inputFileName, const string &outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    char c;
    while (inputFile.get(c)) {
        if (c == ' ') {
            outputFile << "/ ";
        } else {
            string morseCode = charToMorse(c);
            outputFile << morseCode << ' ';
        }
    }
}
