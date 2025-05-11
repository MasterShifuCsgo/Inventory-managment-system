#pragma once
#include <string>
#include <unordered_map>
#include <fstream>
#include <optional>
#include "Item.h"

// how the csv file is formatted. 
// 
// file should be formatted based on Items, but i have no idea how to make a string to a custom type.
// let alone reference it to a variable in a class. 
// instead of a csv it would read a json, but that is out of my scope.
// 
// right now, i know what type each data is, this wouldn't work universally.
// 
// name, price, quantity, details 
// a, 0.1, 0,details here

class ItemCsvFileManager {
   
  std::ifstream csvFile;
  char delimiter = ',';
  std::vector<Item> items {};
  
  std::optional<Item> ConvertToItem(const std::string& row) const;
  // reads a row from the csv file, returns an item if didnt fail.
  std::optional<Item> readRow(const int& i = 1) const;

  public:
  ItemCsvFileManager(const std::string& fileName);
  ItemCsvFileManager();
  std::vector<Item> getItems() const;
  void open(const std::string& fileName);
  
   
  
};
