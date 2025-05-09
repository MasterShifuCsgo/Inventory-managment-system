#include <iostream>
#include <vector>
#include <functional>
#include <array>
#include "Inventory.h"
#include "InventoryDisplay.h"
#include "UserInput.h"








int main()
{
  system("cls"); // unfortunately only works on windows  
    
  std::cout << "Project: Simple Inventory Management System\n";        

  std::vector<Item> items = {};  

  for (int i = 0; i < 100; i++) {
    Item item;
    items.push_back(item);
  }

  Inventory inventory(items);
  InventoryDisplay display(inventory);

  const std::vector<std::function<void(void)>> 
    UIfunctions = {[&]() { display.UIsetItemName(); },
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
     [&]() { display.UISearchPrice(); }};

  //UI
  while (true) {
    display.welcome();
    std::cout << "Please select an option above: ";
    int selection = getUserInput<int>();

    if (selection == 0 || selection < UIfunctions.size()) {
      system("cls");
      UIfunctions[selection]();
    } else if(selection == 99) {
      std::cout << "Exiting program.\n";
      return 0;
    } else {
      system("cls");
      std::cout << "Invalid Selection.\n";
    }     
  }    
}
