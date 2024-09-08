#include <sort.hpp>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>

#define SLEEP_PERIOD_MS 30

void Sort::visualizeArray(const std::vector<int>& vect, int highlightIndex, int compareIndex) {
    clearScreen();
    int maxElement = *std::max_element(vect.begin(), vect.end());

    for (int height = maxElement; height > 0; height--) {
        for (size_t i = 0; i < vect.size(); i++) {
            if (vect[i] >= height) {
                if (static_cast<int>(i) == highlightIndex)
                    std::cout << "\033[1;31m-\033[0m"; // Red for current element
                else if (static_cast<int>(i) == compareIndex)
                    std::cout << "\033[1;32m-\033[0m"; // Green for compare element
                else
                    std::cout << "-";
            } else {
                std::cout << " ";
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    for (size_t i = 0; i < vect.size(); i++) {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

void Sort::clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}


void Sort::insertionSort(std::vector<int> &vect) {
    for (size_t i = 1; i < vect.size(); i++)
    {
        for (size_t j = i; j > 0 && vect[j-1] > vect[j]; j--)
        {
            visualizeArray(vect, i, j);
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_PERIOD_MS));

            int temp = vect[j];
            vect[j] = vect[j-1];
            vect[j-1] = temp;
        }
    }
    visualizeArray(vect);
}