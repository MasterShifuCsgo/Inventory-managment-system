#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Item.h"

class Collection {
 public:
  Collection(std::vector<Item> items);
  Collection();
  
  void setItemName(Item* item, std::string newName);
  void setItemDetails(Item* item, std::string newDetails);
  void setQuantity(Item* item, int newQuantity);
  void setPrice(Item* item, int newPrice);
    
  std::string getItemName(Item* item) const;
  std::string getItemDetails(Item* item) const;
  int getQuantity(Item* item) const;
  int getPrice(Item* item) const;
    
    


 private:

  std::vector<Item> items = {};

  std::vector<std::function<void()>> functions = {

  };    


};

