#include <vector>

class Sort {
    public:
        static void insertionSort(std::vector<int> &vect);
    private:
        static void visualizeArray(const std::vector<int>& vect, int highlightIndex = -1, int compareIndex = -1);
        static void clearScreen();
};