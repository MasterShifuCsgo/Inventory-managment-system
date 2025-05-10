#pragma once
#include <vector>
#include <iostream>
#include "Inventory.h"
#include "Item.h"

class InventoryDisplay {
 public:

   //used for operations in the Inventory class
   Inventory inv;

  InventoryDisplay(Inventory& inventory);  

  void welcome();
  
  void displayData(std::vector<Item>& items);
  std::string displayData(Item& item);
  std::string displayData(const std::string& type, const int data);
  std::string displayData(const std::string& type, const float data);
  std::string displayData(const std::string& type, const std::string& data);
  
  void UIsetItemName();

  void UIsetItemDetails();

  void UIsetQuantity();

  void UIsetPrice();

  void UIgetItemName() const;

  void UIgetItemDetails() const;

  void UIgetQuantity() const;

  void UIgetPrice() const;

  void UIaddItem();

  void UIdeleteItem();

  void UISearchItemName();

  void UISearchQuantity();

  void UISearchPrice();

  void UISearchDetails();

  void displaySearchResults(const std::vector<Item>& results,
                            const std::string& searchType);
};


