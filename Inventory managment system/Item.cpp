#include <string>
#include <iostream>
#include "Item.h"

int Item::nextId = 0;


Item::Item(float price, int quantity, std::string itemName, std::string details)
    : price(price),
      quantity(quantity),
      name(itemName),
      details(details),
      id(nextId++) {}



Item::Item() : Item(0, 0, "no name", "no details") {}

int Item::getId() const { return this->id - 1; }


