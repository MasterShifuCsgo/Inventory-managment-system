#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Item.h"

class Inventory {
 public:
  std::vector<Item> items = {};

  Inventory(std::vector<Item> items);
  
  int itemIdToIndex(int id) const;

  void setItemName(int itemId, const std::string& newName);
  void setItemDetails(int itemId, const std::string& newDetails);
  void setQuantity(int itemId, int newQuantity);
  void setPrice(int itemId, float newPrice);

  int getItemId(int itemId) const;
  std::string getItemName(int itemId) const;
  std::string getItemDetails(int itemId) const;
  int getQuantity(int itemId) const;
  float getPrice(int itemId) const;

  Item getItem(int itemId) const;

  void addItem(Item item);
  void deleteItem(int itemIndex);    

  std::vector<Item> searchItemName(std::string& name);  // returns an array of all the matching names. no fuzzy find
  std::vector<Item> searchQuantity(int min, int max);  // returns an array of items matching the range of quantity
  std::vector<Item> searchPrice(float min, float max);  // returns an array of items matching the range of price
  std::vector<Item> searchDetails(std::string& query);
 private:
  
  std::vector<Item> search(std::function<bool(Item&)>);

};


