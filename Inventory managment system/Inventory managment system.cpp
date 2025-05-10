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

  while (true) {
    display.welcome();
    std::cout << "Please select an option above: ";
    int selection = getUserInput<int>();
    
    if (selection >= 0 && selection < InteractableFunctions.size()) {
      system("cls");
      InteractableFunctions[selection]();
    } else if(selection == 99) {
      std::cout << "Exiting program.\n";
      return 0;
    } else {
      system("cls");
      std::cout << "Invalid Selection.\n";
    }     
  }    
}
