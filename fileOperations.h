#ifndef INC_05_TITANIC_FILEOPERATIONS_H
#define INC_05_TITANIC_FILEOPERATIONS_H

bool openFiles(const std::string &inputFileName, const std::string &outputFileName,
               std::ifstream &inputFile, std::ofstream &outputFile);

void closeFiles(std::ifstream &inputFile, std::ofstream &outputFile);

#endif //INC_05_TITANIC_FILEOPERATIONS_H
