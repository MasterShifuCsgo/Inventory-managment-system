#pragma once
#include <string>
#include <iostream>
#include <optional>
#include <vector>
#include <sstream>
#include "ItemCsvFileManager.h"
#include "Item.h"
#include "Inventory.h"

// how the csv file is formatted.
//
// file should be formatted based on Items, but i have no idea how to make a
// string to a custom type. let alone reference it to a variable in a class.
// instead of a csv it would read a json, but that is out of my scope.
//
// right now, i know what type each data is, this wouldn't work universally.
//  
// delimiters are ",".
// name, price, quantity, details
// a, 0.1, 0,details here


  ItemCsvFileManager::ItemCsvFileManager() {}

  ItemCsvFileManager::ItemCsvFileManager(const std::string& fileName) {    
    ItemCsvFileManager::open(fileName);
  }

  std::optional<Item> ItemCsvFileManager::readRow(const int& stop) const {     
    
    std::string line;        
    for (int i = 0; i <= stop && getline(std::cin, line); i++) { /* skips lines */ }        

    if (getline(std::cin, line)) {
      return ConvertToItem(line);      
    } else {
      std::cerr << "row number dosent exist in the file.";
      return std::nullopt;
    }    
  }

  std::optional<Item> ItemCsvFileManager::ConvertToItem(
      const std::string& row)  const {

    std::vector<std::string> tokens = {};
    std::string token;
    std::stringstream ss(row);

    while (getline(ss, token, delimiter)) {
      tokens.push_back(token);
    }
    
    try {            
      if (tokens.size() == 4) {      
        std::string name = tokens[0];                  
        float price = std::stof(tokens[1]);      
        int quantity = std::stoi(tokens[2]);     
        std::string details = tokens[3];
        return Item{price, quantity, name, details};
      }      
    } catch (const std::exception& e) {
      std::cerr << "error parsing row: " << e.what() << '\n';      
    }
    return std::nullopt;
  }
      
      
  const std::vector<Item>& ItemCsvFileManager::getItems() const {
    return this->items;
  }

  void ItemCsvFileManager::open(const std::string& fileName) {
    csvFile.open(fileName);
    if (!csvFile.is_open()) {
      std::cerr << ".csv file failed to open.\n";
      return;
    }
    
    std::string row;
    int rowIndex = 1;
    while(std::getline(csvFile, row)) {
      
      auto item = ConvertToItem(row);
      
      if (!item.has_value()) {
        std::cerr << "Read " << rowIndex << " row dosent have a readable value ";
        return;
      }
      
      this->items.push_back(item.value());
      rowIndex++;
    }
  }

  void ItemCsvFileManager::save(Inventory& inv, const std::string& fileName) const
  {

    std::ofstream output(fileName);

    /* name, price, quantity, details */
    std::string row = "";        

    for (const Item &item : inv.getItems()) { //getItems() returns const and by reference. items do get added because changes can be veiwed through UI display class, which also uses getItems() to derive items from inventory.             

      row = row +item.name + delimiter + std::to_string(item.price) + delimiter +
            std::to_string(item.quantity) + delimiter + item.details + '\n';            
    }    
    

    
    output << row;
    output.flush();
    output.close();
  }