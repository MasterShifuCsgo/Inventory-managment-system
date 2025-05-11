#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Item.h"

class Inventory {
 public:
  

  Inventory(std::vector<Item> items);
  Inventory();
  
  int itemIdToIndex(int id) const;

  void setItemName(int itemId, const std::string& newName);
  void setItemDetails(int itemId, const std::string& newDetails);
  void setQuantity(int itemId, int newQuantity);
  void setPrice(int itemId, float newPrice);

  const int getItemId(int itemId) const;
  const std::string getItemName(int itemId) const;
  const std::string getItemDetails(int itemId) const;
  const int getQuantity(int itemId) const;
  const float getPrice(int itemId) const;
  const std::vector<Item>& getItems() const;

  Item getItem(int itemId) const;

  void addItem(Item item);
  void deleteItem(int itemIndex);    

  std::vector<Item> searchItemName(std::string& name);  // returns an array of all the matching names. no fuzzy find
  std::vector<Item> searchQuantity(int min, int max);  // returns an array of items matching the range of quantity
  std::vector<Item> searchPrice(float min, float max);  // returns an array of items matching the range of price
  std::vector<Item> searchDetails(std::string& query);
 private:
  std::vector<Item> items = {};
  std::vector<Item> search(std::function<bool(Item&)>);

};


