#include "Inventory.h"
#include "Item.h"
#include "InventoryDisplay.h"
#include "UserInput.h"
#include <sstream>
#include <string>
  

  InventoryDisplay::InventoryDisplay(Inventory& inventory) : inv(inventory) {}

  void InventoryDisplay::welcome() {
    std::cout << "\n===== Inventory Management System =====\n";
    std::cout << "0. Set Item Name\n";
    std::cout << "1. Set Item Details\n";
    std::cout << "2. Set Item Quantity\n";
    std::cout << "3. Set Item Price\n";
    std::cout << "4. Get Item Name\n";
    std::cout << "5. Get Item Details\n";
    std::cout << "6. Get Item Quantity\n";
    std::cout << "7. Get Item Price\n";
    std::cout << "8. Add New Item\n";
    std::cout << "9. Delete Item\n";
    std::cout << "10. Search Item by Name\n";
    std::cout << "11. Search Item by Quantity Range\n";
    std::cout << "12. Search Item by Price Range\n";
    std::cout << "99. Exit\n";
    std::cout << "=======================================\n";
  }

  std::string InventoryDisplay::displayData(const std::string& type,
                                            const int data) {
    return "Item " + type + ": " + std::to_string(data) + '\n';
  }

  std::string InventoryDisplay::displayData(const std::string& type,
                                            const float data) {
    return "Item " + type + ": " + std::to_string(data) + '\n';
  }

  std::string InventoryDisplay::displayData(const std::string& type,
                                            const std::string& data) {
    return "Item " + type + ": " + data + '\n';
  } 

  std::string InventoryDisplay::displayData(Item& item) {
    std::stringstream ss;

    ss << displayData("Name", item.name) << '\n';
    ss << displayData("Price", item.price) << '\n';
    ss << displayData("Quantity", item.quantity) << '\n';
    ss << displayData("Details", item.details) << '\n';

    return ss.str();
  }

  void InventoryDisplay::displayData(std::vector<Item>& items) {
    std::stringstream ss;
    ss << "========================\n";
    for (int i = 0; i < items.size(); i++) {
      ss << "Item index" << i << '\n';
      ss << displayData(items[i]);
      ss << "========================\n";
    }
    std::cout << ss.str();
  }

  void InventoryDisplay::UIsetItemName() {
    std::cout << "UI: Set Item Name\n\n"
              << "What you have to enter:\n"
              << "- item index\n"
              << "- new item name\n\n";

    std::cout << "Enter item index: ";
    int itemIndex = getUserInput<int>();
    if (itemIndex == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    if (itemIndex < 0 || itemIndex >= this->inv.items.size()) {
      std::cout << "Invalid Item Index" << std::endl;
      return;
    }
    std::cout << "Current Item Name: " << inv.getItemName(itemIndex)
              << std::endl;
    std::cout << "Enter new item name: ";
    std::string itemName = getUserInput<std::string>();
    if (itemName == "99") {
      std::cout << "Returning to main menu.\n";
      return;
    }

    this->inv.setItemName(itemIndex, itemName);
    std::cout << "Operation Complete: Item name updated.\n";
  }

  void InventoryDisplay::UIsetItemDetails() {
    std::cout << "UI: Set Item Details\n\n"
              << "What you have to enter:\n"
              << "- item index\n"
              << "- new item details\n\n";

    std::cout << "Enter item index: ";
    int itemIndex = getUserInput<int>();
    if (itemIndex == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    if (itemIndex < 0 || itemIndex >= this->inv.items.size()) {
      std::cout << "Invalid Item Index" << std::endl;
      return;
    }
    std::cout << "Current Item Details: " << inv.getItemDetails(itemIndex)
              << std::endl;
    std::cout << "Enter new item details: ";
    std::string itemDetails = getUserInput<std::string>();
    if (itemDetails == "99") {
      std::cout << "Returning to main menu.\n";
      return;
    }

    this->inv.setItemDetails(itemIndex, itemDetails);
    std::cout << "Operation Complete: Item details updated.\n";
  }

  void InventoryDisplay::UIsetQuantity() {
    std::cout << "UI: Set Item Quantity\n\n"
              << "What you have to enter:\n"
              << "- item index\n"
              << "- new item quantity\n\n";

    std::cout << "Enter item index: ";
    int itemIndex = getUserInput<int>();
    if (itemIndex == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    if (itemIndex < 0 || itemIndex >= this->inv.items.size()) {
      std::cout << "Invalid Item Index" << std::endl;
      return;
    }
    std::cout << "Current Item Quantity: " << inv.getQuantity(itemIndex)
              << std::endl;
    std::cout << "Enter new item quantity: ";
    int newQuantity = getUserInput<int>();
    if (newQuantity == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    this->inv.setQuantity(itemIndex, newQuantity);
    std::cout << "Operation Complete: Item quantity updated.\n";
  }

  void InventoryDisplay::UIsetPrice() {
    std::cout << "UI: Set Item Price\n\n"
              << "What you have to enter:\n"
              << "- item index\n"
              << "- new item price\n\n";

    std::cout << "Enter item index: ";
    int itemIndex = getUserInput<int>();
    if (itemIndex == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    if (itemIndex < 0 || itemIndex >= this->inv.items.size()) {
      std::cout << "Invalid Item Index" << std::endl;
      return;
    }
    std::cout << "Current Item Price: " << inv.getPrice(itemIndex) << std::endl;
    std::cout << "Enter new item price: ";
    float newPrice = getUserInput<float>();
    if (newPrice == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    this->inv.setPrice(itemIndex, newPrice);
    std::cout << "Operation Complete: Item price updated.\n";
  }

  void InventoryDisplay::UIgetItemName() {
    std::cout << "UI: Get Item Name\n\nEnter item index: ";
    int itemIndex = getUserInput<int>();
    if (itemIndex == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    if (itemIndex < 0 || itemIndex >= this->inv.items.size()) {
      std::cout << "Invalid Item Index" << std::endl;
      return;
    }
    std::cout << "Item Name: " << inv.getItemName(itemIndex) << std::endl;
    std::cout << "Operation Complete.\n";
  }

  void InventoryDisplay::UIgetItemDetails() {
    std::cout << "UI: Get Item Details\n\nEnter item index: ";
    int itemIndex = getUserInput<int>();
    if (itemIndex == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    if (itemIndex < 0 || itemIndex >= this->inv.items.size()) {
      std::cout << "Invalid Item Index" << std::endl;
      return;
    }
    std::cout << "Item Details: " << inv.getItemDetails(itemIndex) << std::endl;
    std::cout << "Operation Complete.\n";
  }

  void InventoryDisplay::UIgetQuantity() {
    std::cout << "UI: Get Item Quantity\n\nEnter item index: ";
    int itemIndex = getUserInput<int>();
    if (itemIndex == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    if (itemIndex < 0 || itemIndex >= this->inv.items.size()) {
      std::cout << "Invalid Item Index" << std::endl;
      return;
    }
    int quantity = inv.getQuantity(itemIndex);
    if (quantity != -1) {
      std::cout << "Item Quantity: " << quantity << std::endl;
    }
    std::cout << "Operation Complete.\n";
  }

  void InventoryDisplay::UIgetPrice() {
    std::cout << "UI: Get Item Price\n\nEnter item index: ";
    int itemIndex = getUserInput<int>();
    if (itemIndex == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    if (itemIndex < 0 || itemIndex >= this->inv.items.size()) {
      std::cout << "Invalid Item Index" << std::endl;
      return;
    }
    float price = inv.getPrice(itemIndex);
    if (price != -1.0f) {
      std::cout << "Item Price: " << price << std::endl;
    }
    std::cout << "Operation Complete.\n";
  }

  void InventoryDisplay::UIaddItem() {
    std::cout << "UI: Add New Item\n\nEnter item details:\n";
    std::cout << "Enter item name: ";
    std::string name = getUserInput<std::string>();
    if (name == "99") {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::cout << "Enter item details: ";
    std::string details = getUserInput<std::string>();
    if (details == "99") {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::cout << "Enter item quantity: ";
    int quantity = getUserInput<int>();
    if (quantity == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::cout << "Enter item price: ";
    float price = getUserInput<float>();
    if (price == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    
    Item item(price, quantity, name, details);

    inv.addItem(item);
    std::cout << "Operation Complete: Item added.\n";
  }

  void InventoryDisplay::UIdeleteItem() {
    std::cout << "UI: Delete Item\n\nEnter the index of the item to delete: ";
    int itemIndex = getUserInput<int>();
    if (itemIndex == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    if (itemIndex < 0 || itemIndex >= this->inv.items.size()) {
      std::cout << "Invalid Item Index" << std::endl;
      return;
    }
    std::cout << "Deleting Item: " << inv.getItemName(itemIndex) << std::endl;
    inv.deleteItem(itemIndex);
    std::cout << "Operation Complete: Item deleted.\n";
  }

  void InventoryDisplay::UISearchItemName() {
    std::cout << "UI: Search Item by Name\n\nEnter the name to search for: ";
    std::cout << "\nEnter item name: ";
    std::string searchName = getUserInput<std::string>();
    if (searchName == "99") {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::vector<Item> results = inv.searchItemName(searchName);
    displaySearchResults(results, "Name");
  }

  void InventoryDisplay::UISearchQuantity() {
    std::cout
        << "UI: Search Item by Quantity Range\n\nEnter the quantity range:\n";
    std::cout << "Enter minimum quantity: ";
    int minQuantity = getUserInput<int>();
    if (minQuantity == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::cout << "Enter maximum quantity: ";
    int maxQuantity = getUserInput<int>();
    if (maxQuantity == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::vector<Item> results = inv.searchQuantity(minQuantity, maxQuantity);
    displaySearchResults(results, "Quantity");
  }

  void InventoryDisplay::UISearchPrice() {
    std::cout << "UI: Search Item by Price Range\n\nEnter the price range:\n";
    std::cout << "Enter minimum price: ";
    float minPrice = getUserInput<float>();
    if (minPrice == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::cout << "Enter maximum price: ";
    float maxPrice = getUserInput<float>();
    if (maxPrice == 99) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::vector<Item> results = inv.searchPrice(minPrice, maxPrice);
    displaySearchResults(results, "Price");
  }

  void InventoryDisplay::displaySearchResults(const std::vector<Item>& results,
                            const std::string& searchType) {
    if (results.empty()) {
      std::cout << "No items found matching the " << searchType
                << " criteria.\n";
    } else {
      std::cout << "\n--- Search Results (by " << searchType << ") ---\n";
      for (size_t i = 0; i < results.size(); ++i) {
        std::cout << "Item " << i << ": " << results[i].name
                  << " (Qty: " << results[i].quantity
                  << ", Price: " << results[i].price << ")\n";
      }
      std::cout << "---------------------------------------\n";
    }
    std::cout << "Operation Complete.\n";
  }
