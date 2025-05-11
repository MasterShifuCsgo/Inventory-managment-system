#pragma once
#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <optional>


  template <typename T, std::enable_if_t< std::is_arithmetic_v<T>, int> = 0>  
  T getUserInput() {      
    T reciver;
    while (true) {
      std::cin >> reciver;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please try again: ";
      } else {               
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return reciver;
      }
    }
  } 

  template <typename T, std::enable_if_t<std::is_same_v<T, std::string>, int> = 0>
  T getUserInput() {
    T reciver;
    while (true) {
      std::getline(std::cin, reciver);
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Input Error. Please try again: ";
      } else {        
        return reciver;
      }
    }
  }

template <typename T>
  std::optional<T> getField(const std::string& prompt) {
    std::cout << prompt;
    T value = getUserInput<T>();

    if constexpr (std::is_same_v<T, std::string>) {
      if (value == "-1") {        
        return std::nullopt;
      }
    } else { // For numeric types
      if (value == -1) {        
        return std::nullopt;
      }
    }
    return value;
  }
