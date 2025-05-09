#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Item.h"

class Inventory {
 public:
  std::vector<Item> items = {};

  Inventory(std::vector<Item> items);
  
  void setItemName(int itemIndex, const std::string& newName);
  void setItemDetails(int itemIndex, const std::string& newDetails);
  void setQuantity(int itemIndex, int newQuantity);
  void setPrice(int itemIndex, float newPrice);

  std::string getItemName(int itemIndex) const;
  std::string getItemDetails(int itemIndex) const;
  int getQuantity(int itemIndex) const;
  float getPrice(int itemIndex) const;

  Item getItem(int itemIndex);


  void addItem(Item item);
  void deleteItem(int itemIndex);    

  std::vector<Item> searchItemName(std::string name);  // returns an array of all the matching names. no fuzzy find
  std::vector<Item> searchQuantity(int min, int max);  // returns an array of items matching the range of quantity
  std::vector<Item> searchPrice(float min, float max);  // returns an array of items matching the range of price

  int getSize() const;
 private:
  
  std::vector<Item> search(std::function<bool(Item&)>);

};


