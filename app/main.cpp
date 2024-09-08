#include "sort.hpp"
#include <iostream>
#include <random>
#include <vector>

#define RANDOM_MIN 1
#define RANDOM_MAX 40

// Function to print a vector
void printVector(const std::vector<int> &vect) {
  for (const auto &num : vect) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(RANDOM_MIN, RANDOM_MAX);

  while (true) {
    int size;
    std::cout << "\nEnter the size of the vector (0 to exit): ";
    std::cin >> size;

    if (size == 0) {
      std::cout << "Exiting program. Goodbye!\n";
      break;
    }

    if (size < 0) {
      std::cout << "Please enter a positive number.\n";
      continue;
    }

    // Create a vector of the specified size
    std::vector<int> vect(size);

    // Fill the vector with random numbers
    for (int &num : vect) {
      num = dis(gen);
    }

    std::cout << "Original vector: ";
    printVector(vect);

    // Call insertionSort (passing the vector by reference)
    Sort::insertionSort(vect);

    std::cout << "Sorted vector: ";
    printVector(vect);

    // Clear the input buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return 0;
}