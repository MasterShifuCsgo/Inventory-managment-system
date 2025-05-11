#pragma once
#include <string>
#include <fstream>

class InventoryFileManager {

  std::ifstream currentFile;

  // checks 4 last letters. return true if .csv is found     
  bool checkIfCSV(std::string fileName);                                       

  public:
  InventoryFileManager(std::string fileName);


  
};
