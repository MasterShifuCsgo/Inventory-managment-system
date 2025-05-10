#include "Inventory.h"
#include "Item.h"
#include <vector>
#include <functional>


Inventory::Inventory(std::vector<Item> items) { this->items = items; }

int Inventory::itemIdToIndex(int id) const { 
  for (int i = 0; i < this->items.size(); i++) {
    if (items[i].getId() == id) {
      return i;
    }
  }
}

void Inventory::setItemName(int itemId, const std::string& newName) {
  if (itemId >= 0 && itemId < static_cast<int>(items.size())) {
    items[itemIdToIndex(itemId)].name = newName;
  } else {
    std::cout << "Item does not exist\n";
  }
}

void Inventory::setItemDetails(int itemId, const std::string& newDetails) {
  if (itemId >= 0 && itemId < static_cast<int>(items.size())) {
    items[itemIdToIndex(itemId)].details = newDetails;
  } else {
    std::cout << "Item does not exist\n";
  }
}

void Inventory::setQuantity(int itemId, int newQuantity) {
  if (itemId >= 0 && itemId < static_cast<int>(items.size())) {
    items[itemIdToIndex(itemId)].quantity = newQuantity;
  } else {
    std::cout << "Item does not exist\n";
  }
}

void Inventory::setPrice(int itemId, float newPrice) {
  if (itemId >= 0 && itemId < static_cast<int>(items.size())) {
    items[itemIdToIndex(itemId)].price = newPrice;
  } else {
    std::cout << "Item does not exist\n";
  }
}

int Inventory::getItemId(int itemId) const {
  if (itemId >= 0 && itemId < static_cast<int>(items.size())) {
    return items[itemIdToIndex(itemId)].getId();
  } else {
    std::cout << "Item does not exist\n";
  }
  return -1;
};

std::string Inventory::getItemName(int itemId) const {
  if (itemId >= 0 && itemId < static_cast<int>(items.size())) {
    return items[itemIdToIndex(itemId)].name;
  } else {
    std::cout << "Item does not exist\n";
  }
  return "";
}

std::string Inventory::getItemDetails(int itemId) const {
  if (itemId >= 0 && itemId < static_cast<int>(items.size())) {
    return items[itemIdToIndex(itemId)].details;
  } else {
    std::cout << "Item does not exist\n";
  }
  return "";
}

int Inventory::getQuantity(int itemId) const {
  if (itemId >= 0 && itemId < static_cast<int>(items.size())) {
    return items[itemIdToIndex(itemId)].quantity;
  } else {
    std::cout << "Item does not exist\n";
  }
  return -1;
}

float Inventory::getPrice(int itemId) const {
  if (itemId >= 0 && itemId < static_cast<int>(items.size())) {
    return items[itemIdToIndex(itemId)].price;
  } else {
    std::cout << "Item does not exist\n";
  }
  return -1.0f;
}

void Inventory::addItem(Item item) { this->items.push_back(item); }

void Inventory::deleteItem(int itemId) {
  if (itemId >= 0 && itemId < static_cast<int>(this->items.size())) {
    this->items.erase(items.begin() + itemIdToIndex(itemId));
  } else {
    std::cout << "Invalid index for item deletion\n";
  }
}

Item Inventory::getItem(int itemId) const {
  if (itemId >= 0 && itemId < static_cast<int>(items.size())) {
    return this->items[itemIdToIndex(itemId)];
  } else {
    std::cout << "Item does not exist\n";
    // Consider returning a default Item object or throwing an exception
    return Item();
  }
}

std::vector<Item> Inventory::search(std::function<bool(Item&)> condition) {
  std::vector<Item> matchingItems;
  for (Item& item : this->items) {
    if (condition(item)) {
      matchingItems.push_back(item);
    }
  }
  return matchingItems;
}

// returns an array of all the matching names
std::vector<Item> Inventory::searchItemName(std::string& name) {  
  return Inventory::search([&](Item& item) { return item.name == name; });
}  
// returns an array of Items matching the quantity range
std::vector<Item> Inventory::searchQuantity(int min, int max) {
  return Inventory::search(
      [&](Item& item) { return min <= item.quantity && item.quantity <= max; });
}  
// returns an array of Items matching the price range
std::vector<Item> Inventory::searchPrice(float min, float max) {
  return Inventory::search(
      [&](Item& item) { return min <= item.price && item.price <= max; });
}
// returns an array of Items matching the details
std::vector<Item> Inventory::searchDetails(std::string& query) {
  return Inventory::search([&](Item& item) {
    // check every word inside details for a match in the query
    std::string word = "";
    for (int i = 0; i < item.details.size(); i++) {
      
      
      //create word
      while (item.details[i] != ' ' && i < item.details.size()) {        
        word += item.details[i];    
        i++;
      }
      
      if (word == query) {
        return true;
      }
    }
    return false;
  });
}

