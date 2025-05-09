#pragma once
#include <string>

class Item {
 private:
  // member variables   
    int id = -1;
    
 public:
    // member variables     
  int price = 0;
  int quantity = 0;
  std::string itemName = "";
  std::string details = ""; 
    
    Item(int price, int quantity, std::string itemName, std::string details);    
};
