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
    std::cout << "3. Set Item Price\n\n";
    std::cout << "4. Get Item Name\n";
    std::cout << "5. Get Item Details\n";
    std::cout << "6. Get Item Quantity\n";
    std::cout << "7. Get Item Price\n\n";
    std::cout << "8. Add New Item\n";
    std::cout << "9. Delete Item\n\n";
    std::cout << "10. Search Item by Name\n";
    std::cout << "11. Search Item by Quantity Range\n";
    std::cout << "12. Search Item by Price Range\n";
    std::cout << "13. Search Item by Details\n";
    std::cout << "-1. Exit\n";
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

// UI Functions (Refactored with improved input handling)
  void InventoryDisplay::UIsetItemName() {
    std::cout << "UI: Set Item Name\n\n"
              << "What you have to enter:\n"
              << "- item id\n"
              << "- new item name\n\n";

    auto itemId = getField<int>("Enter item id: ");
    if (!itemId.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    std::cout << "Current Item Name: " << inv.getItemName(itemId.value())
              << std::endl;

    auto itemName = getField<std::string>("Enter new item name: ");
    if (!itemName.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    inv.setItemName(itemId.value(), itemName.value());
    std::cout << "Operation Complete: Item name update.\n";
  }

  void InventoryDisplay::UIsetItemDetails() {
    std::cout << "UI: Set Item Details\n\n"
              << "What you have to enter:\n"
              << "- item id\n"
              << "- new item details\n\n";

    auto itemId = getField<int>("Enter item id: ");
    if (!itemId.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    std::cout << "Current Item Details: " << inv.getItemDetails(itemId.value())
              << std::endl;

    auto itemDetails = getField<std::string>("Enter new item details: ");
    if (!itemDetails.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    this->inv.setItemDetails(itemId.value(), itemDetails.value());
    std::cout << "Operation Complete: Item details update.\n";
  }

  void InventoryDisplay::UIsetQuantity() {
    std::cout << "UI: Set Item Quantity\n\n"
              << "What you have to enter:\n"
              << "- item id\n"
              << "- new item quantity\n\n";

    auto itemId = getField<int>("Enter item id: ");
    if (!itemId.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    std::cout << "Current Item Quantity: " << inv.getQuantity(itemId.value())
              << std::endl;

    auto newQuantity = getField<int>("Enter new item quantity: ");
    if (!newQuantity.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    this->inv.setQuantity(itemId.value(), newQuantity.value());
    std::cout << "Operation Complete: Item quantity update.\n";
  }

  void InventoryDisplay::UIsetPrice() {
    std::cout << "UI: Set Item Price\n\n"
              << "What you have to enter:\n"
              << "- item id\n"
              << "- new item price\n\n";

    auto itemId = getField<int>("Enter item id: ");
    if (!itemId.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    std::cout << "Current Item Price: " << inv.getPrice(itemId.value())
              << std::endl;

    auto newPrice = getField<float>("Enter new item price: ");
    if (!newPrice.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    this->inv.setPrice(itemId.value(), newPrice.value());
    std::cout << "Operation Complete: Item price update.\n";
  }

  void InventoryDisplay::UIgetItemName() const {
    std::cout << "UI: Get Item Name\n\nEnter item id: ";
    auto itemId = getField<int>("Enter item id: ");
    if (!itemId.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::cout << "Item Name: " << inv.getItemName(itemId.value()) << std::endl;
    std::cout << "Operation Complete.\n";
  }

  void InventoryDisplay::UIgetItemDetails() const {
    std::cout << "UI: Get Item Details\n\nEnter item id: ";
    auto itemId = getField<int>("Enter item id: ");
    if (!itemId.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::cout << "Item Details: " << inv.getItemDetails(itemId.value())
              << std::endl;
    std::cout << "Operation Complete.\n";
  }

  void InventoryDisplay::UIgetQuantity() const {
    std::cout << "UI: Get Item Quantity\n\nEnter item id: ";
    auto itemId = getField<int>("Enter item id: ");
    if (!itemId.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    int quantity = inv.getQuantity(itemId.value());
    if (quantity != -1) {
      std::cout << "Item Quantity: " << quantity << std::endl;
    }
    std::cout << "Operation Complete.\n";
  }

  void InventoryDisplay::UIgetPrice() const {
    std::cout << "UI: Get Item Price\n\nEnter item id: ";
    auto itemId = getField<int>("Enter item id: ");
    if (!itemId.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    float price = inv.getPrice(itemId.value());
    if (price != -1.0f) {
      std::cout << "Item Price: " << price << std::endl;
    }
    std::cout << "Operation Complete.\n";
  }

  void InventoryDisplay::UIaddItem() {
    std::cout << "UI: Add New Item\n\n";

    auto name = getField<std::string>("Enter item name: ");
    if (!name.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    auto quantity = getField<int>("Enter item quantity: ");
    if (!quantity.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    auto price = getField<float>("Enter item price: ");
    if (!price.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    auto details = getField<std::string>("Enter item details: ");
    if (!details.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }

    Item item(price.value(), quantity.value(), name.value(),
              details.value());  // Use .value()
    inv.addItem(item);
    std::cout << "Operation Complete: Item addition.\nItem id: "
              << inv.getItems().back().getId() << std::endl;
  }

  void InventoryDisplay::UIdeleteItem() {
    std::cout << "UI: Delete Item\n\n";
    auto itemIdToDelete = getField<int>("Enter the id of the item to delete: ");
    if (!itemIdToDelete.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    inv.deleteItem(itemIdToDelete.value());
    std::cout << "Operation Complete: Item Deletion.\n";
  }

  void InventoryDisplay::UISearchItemName() {
    std::cout << "UI: Search Item by Name\n\nEnter the name to search for:\n";
    auto searchName = getField<std::string>("Enter item name: ");
    if (!searchName.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::vector<Item> results = inv.searchItemName(searchName.value());
    displaySearchResults(results, "Name");
  }

  void InventoryDisplay::UISearchQuantity() {
    std::cout
        << "UI: Search Item by Quantity Range\n\nEnter the quantity range:\n";
    auto minQuantity = getField<int>("Enter minimum quantity: ");
    if (!minQuantity.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    auto maxQuantity = getField<int>("Enter maximum quantity: ");
    if (!maxQuantity.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::vector<Item> results =
        inv.searchQuantity(minQuantity.value(), maxQuantity.value());
    displaySearchResults(results, "Quantity");
  }

  void InventoryDisplay::UISearchPrice() {
    std::cout << "UI: Search Item by Price Range\n\nEnter the price range:\n";
    auto minPrice = getField<float>("Enter minimum price: ");
    if (!minPrice.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    auto maxPrice = getField<float>("Enter maximum price: ");
    if (!maxPrice.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::vector<Item> results =
        inv.searchPrice(minPrice.value(), maxPrice.value());
    displaySearchResults(results, "Price");
  }

  void InventoryDisplay::UISearchDetails() {
    std::cout << "UI: Search Item by Details\n\nEnter a word to search for:\n";
    auto searchName = getField<std::string>("Enter word: ");
    if (!searchName.has_value()) {
      std::cout << "Returning to main menu.\n";
      return;
    }
    std::vector<Item> results = inv.searchDetails(searchName.value());
    displaySearchResults(results, "Details");
  }

  void InventoryDisplay::displaySearchResults(const std::vector<Item>& results,
                            const std::string& searchType) {
    if (results.empty()) {
      std::cout << "No items found matching the " << searchType
                << " criteria.\n";
    } else {
      std::cout << "\n--- Search Results (by " << searchType << ") ---\n";
      for (size_t i = 0; i < results.size(); ++i) {
        std::cout << ">->->->->-> Item index: " << i
                  << " >->->->->->\n" 
                  << "Id: " << results[i].getId() << '\n'                  
                  << "Name: " << results[i].name << '\n'
                  << "Qty: " << results[i].quantity << '\n'
                  << "Price: " << results[i].price << "\n"
                  << "Details: " << results[i].details << "\n"
                  << std::endl;
      }
      std::cout << "---------------------------------------\n";
    }
    std::cout << "Operation Complete.\n";
  }


