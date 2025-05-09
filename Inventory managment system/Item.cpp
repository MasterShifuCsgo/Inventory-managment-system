#include <string>
#include "Item.h"


Item::Item(float price, int quantity, std::string itemName,
           std::string details) { 
  this->id = id++;
  this->price = price;
  this->quantity = quantity;
  this->name = itemName;
  this->details = details;  
}

Item::Item() : Item(0, 0, "no name", "no details") {}



