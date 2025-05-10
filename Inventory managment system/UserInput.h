#pragma once
#include <iostream>
#include <limits>
#include <string>
#include <type_traits>
#include <optional>
//exit codes for getUserInput
//  Integral types
template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type isDefault(
    const T& value) {
  return value == 99;
}

// Floating-point types
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type isDefault(
    const T& value) {
  return value == 99.0;
}

// String (handled via overload, not specialization)
bool isDefault(const std::string& value);

// Unknown types fallback
template <typename T>
typename std::enable_if<!std::is_integral<T>::value &&
                            !std::is_floating_point<T>::value &&
                            !std::is_same<T, std::string>::value,
                        bool>::type
isDefault(const T&) {
  std::cerr << "Default value for type unknown\n";
  return false;
}

  template<typename T>
  T getUserInput() {      
    T reciver;
    while (true) {
      std::cin >> reciver;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please try again";
      } else {               
        if (isDefault(reciver)) {
          return reciver;  
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return reciver;
      }
    }
  } 

template <typename T>
  std::optional<T> getField(const std::string& prompt) {
    std::cout << prompt;
    T value = getUserInput<T>();

    if constexpr (std::is_same_v<T, std::string>) {
      if (value == "99") {
        std::cout << "Returning to main menu.\n";
        return std::nullopt;
      }
    } else { // For numeric types
      if (value == 99) {
        std::cout << "Returning to main menu.\n";
        return std::nullopt;
      }
    }
    return value;
  }