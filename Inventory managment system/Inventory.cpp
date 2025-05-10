#include <vector>
#include <functional>
#include "Inventory.h"
#include "Item.h"

Inventory::Inventory(std::vector<Item> items) { this->items = items; }

void Inventory::setItemName(int itemIndex, const std::string& newName) {
  if (itemIndex >= 0 && itemIndex < static_cast<int>(items.size())) {
    items[itemIndex].name = newName;
  } else {
    std::cout << "Item does not exist\n";
  }
}

void Inventory::setItemDetails(int itemIndex, const std::string& newDetails) {
  if (itemIndex >= 0 && itemIndex < static_cast<int>(items.size())) {
    items[itemIndex].details = newDetails;
  } else {
    std::cout << "Item does not exist\n";
  }
}

void Inventory::setQuantity(int itemIndex, int newQuantity) {
  if (itemIndex >= 0 && itemIndex < static_cast<int>(items.size())) {
    items[itemIndex].quantity = newQuantity;
  } else {
    std::cout << "Item does not exist\n";
  }
}

void Inventory::setPrice(int itemIndex, float newPrice) {
  if (itemIndex >= 0 && itemIndex < static_cast<int>(items.size())) {
    items[itemIndex].price = newPrice;
  } else {
    std::cout << "Item does not exist\n";
  }
}

std::string Inventory::getItemName(int itemIndex) const {
  if (itemIndex >= 0 && itemIndex < static_cast<int>(items.size())) {
    return items[itemIndex].name;
  } else {
    std::cout << "Item does not exist\n";
  }
  return "";
}

std::string Inventory::getItemDetails(int itemIndex) const {
  if (itemIndex >= 0 && itemIndex < static_cast<int>(items.size())) {
    return items[itemIndex].details;
  } else {
    std::cout << "Item does not exist\n";
  }
  return "";
}

int Inventory::getQuantity(int itemIndex) const {
  if (itemIndex >= 0 && itemIndex < static_cast<int>(items.size())) {
    return items[itemIndex].quantity;
  } else {
    std::cout << "Item does not exist\n";
  }
  return -1;
}

float Inventory::getPrice(int itemIndex) const {
  if (itemIndex >= 0 && itemIndex < static_cast<int>(items.size())) {
    return items[itemIndex].price;
  } else {
    std::cout << "Item does not exist\n";
  }
  return -1.0f;
}

void Inventory::addItem(Item item) { this->items.push_back(item); }
void Inventory::deleteItem(int itemIndex) {
  if (itemIndex < 0 || itemIndex >= static_cast<int>(this->items.size())) {
    std::cout << "Invalid index for item deletion\n";
    return;
  } else {
    std::cout << "Item does not exist\n";
  }
  this->items.erase(items.begin() + itemIndex);
}

Item Inventory::getItem(int itemIndex) { return this->items[itemIndex]; }

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
std::vector<Item> Inventory::searchItemName(std::string name) {  
  return Inventory::search([&](Item& item) { return item.name == name; });
}  
// returns an array of Items matching the quantity range
std::vector<Item> Inventory::searchQuantity(int min, int max) {
  return Inventory::search(
      [&](Item& item) { return min < item.quantity && item.quantity < max; });
}  
// returns an array of Items matching the price range
std::vector<Item> Inventory::searchPrice(float min, float max) {
  return Inventory::search(
      [&](Item& item) { return min < item.price && item.price < max; });
}

