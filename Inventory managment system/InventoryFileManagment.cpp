#include "InventoryFileManagment.h"
#include <fstream>
#include <iostream>

// checks 4 last letters. return true if .csv is found
bool InventoryFileManager::checkIfCSV(std::string fileName){
  return fileName.size() >= 4 && fileName.substr(fileName.size() - 4) == ".csv";
}
InventoryFileManager::InventoryFileManager(std::string fileName) {

  if (!InventoryFileManager::checkIfCSV(fileName)){
    std::cerr << "File is not a '.csv' ";
    return;
  }

  InventoryFileManager::currentFile.open(fileName);
  
  if (!currentFile.is_open()) {
    std::cerr << ".csv file failed to open. please try again.";
  }

}
