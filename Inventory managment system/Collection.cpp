#include "Collection.h"
#include "Item.h"

Collection::Collection(std::vector<Item> items) {}
Collection::Collection() {}

void Collection::setItemName(Item* item, std::string newName) {
  item->itemName = newName;
}

void Collection::setItemDetails(Item* item, std::string newDetails) {
  item->details = newDetails;
}

void Collection::setQuantity(Item* item, int newQuantity) {
  item->quantity = newQuantity;
}

void Collection::setPrice(Item* item, int newPrice) { item->price = newPrice; }

std::string Collection::getItemName(Item* item) const { return item->itemName; }

std::string Collection::getItemDetails(Item* item) const {
  return item->details;
}

int Collection::getQuantity(Item* item) const { return item->quantity; }

int Collection::getPrice(Item* item) const { return item->price; }