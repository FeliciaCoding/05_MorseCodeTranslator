#ifndef INC_05_TITANIC_MORSETRANSLATOR_H
#define INC_05_TITANIC_MORSETRANSLATOR_H

std::string charToMorse(const char &c);

char morseToChar(const std::string &morse);

void decodeMorseToText(const std::string &inputFileName, const std::string &outputFileName);

void encodeTextToMorse(const std::string &inputFileName, const std::string &outputFileName);

#endif //INC_05_TITANIC_MORSETRANSLATOR_H
