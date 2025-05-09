#include <string>
#include "Item.h";
#include "Collection.h"


Item::Item(int price, int quantity, std::string itemName,
           std::string details) { 
  this->id = id++;
  this->price = price;
  this->quantity = quantity;
  this->itemName = itemName;
  this->details = details;  
}





