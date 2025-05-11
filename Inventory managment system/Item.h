#pragma once
#include <string>

class Item {
 private:
  static int nextId;
  int id;  
 public:
  // member variables
  float price = 0;
  int quantity = 0;
  std::string name = "";
  std::string details = "";

  // constructors
  Item(float price, int quantity, std::string itemName, std::string details);
  Item();

  int getId() const;
};
