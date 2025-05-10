#include <iostream>
#include <vector>
#include <functional>
#include <array>
#include "Inventory.h"
#include "InventoryDisplay.h"
#include "UserInput.h"

int main() {
  system("cls");  // unfortunately only works on windows

  std::cout << "Project: Simple Inventory Management System\n";

  std::vector<Item> items = {};

  float price = 0;
  int quantity = 0;
  std::string itemName = "item";
  std::string details = "item";

  for (int i = 0; i < 100; i++) {
    Item item(price, quantity, itemName, details);
    items.push_back(item);
    price += 1;
    quantity += 1;    
    details += "item";

  }

  Inventory inventory(items);
  InventoryDisplay display(inventory);

    const std::vector<std::function<void(void)>> InteractableFunctions = {
        [&]() { display.UIsetItemName(); },
        [&]() { display.UIsetItemDetails(); },
        [&]() { display.UIsetQuantity(); }, 
        [&]() { display.UIsetPrice(); },
        [&]() { display.UIgetItemName(); },
        [&]() { display.UIgetItemDetails(); },
        [&]() { display.UIgetQuantity(); }, 
        [&]() { display.UIgetPrice(); },
        [&]() { display.UIaddItem(); }, 
        [&]() { display.UIdeleteItem(); },
        [&]() { display.UISearchItemName(); },
        [&]() { display.UISearchQuantity(); },
        [&]() { display.UISearchPrice(); },
        [&]() { display.UISearchDetails(); }};

  // UI
  while (true) {
    display.welcome();
    auto selection = getField<int>("Please select an option above: ");    

    if (!selection.has_value()) {
      std::cout << "Exiting program.\n";
      break;
    }

    if (*selection >= 0 && *selection < InteractableFunctions.size()) {
      system("cls");
      InteractableFunctions[*selection]();
    } else {
      system("cls");
      std::cout << "Invalid Selection.\n";
    }     
  }    

  return 0;
}
