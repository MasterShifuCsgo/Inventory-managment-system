#include <iostream>
#include <vector>
#include <functional>
#include <array>
#include <string>
#include "Inventory.h"
#include "InventoryDisplay.h"
#include "UserInput.h"
#include "ItemCsvFileManager.h"

int main(int argc, char* argv[]) {
  system("cls");  // unfortunately only works on windows
  std::cout << "Project: Simple Inventory Management System\n";
  ItemCsvFileManager fileManager;

  if (argc == 2) {          
     //read the content of the csv and return a vector if items to insert to Inventory, no searching through the file, only through memory.     
     fileManager.open(argv[1]);
     

  }
  
  
  Inventory inventory(fileManager.getItems());
  InventoryDisplay display(inventory);
      
    // maybe create a vairable for the lambda that is used to describe the function? this way the welcome page and this vector are not seperated.
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

      // save data to the new or already used CSV


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
