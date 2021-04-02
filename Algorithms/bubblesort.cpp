//
// Created by Lucas on 12/03/21.
//
// Simple Bubble Sort algorithm, it accepts
// an std::vector of integers as parameter.
//
// 1. The console reads the number of elements of the array to be sorted.
// 2. The console reads all the numbers of the array separated by space.
// 3. The console outputs the sorted array.

#include <iostream>
#include <vector>

void BubbleSort (std::vector<int>& array, std::size_t n) {
    for (size_t i = 0; i < n; i++) {
        bool swapped = false;

        for (size_t j = 1; j < n; j++) {
            if (array[j - 1] > array[j]) {
                std::swap(array[j - 1], array[j]);
                swapped = true;
            }
        }
        // If no swap occur, then the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

std::vector<int> ReadInput() {
    std::size_t n;
    std::cin >> n;
    std::vector<int> array(n)
    for (size_t i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    return array;
}

void PrintArray(const std::vector<int>& array) {
    for (size_t i = 0; i < array.size(); i++) {
        std::cout << array[i] << ' ';
    }
}

int main() {
    std::vector<int> array = ReadInput();
    BubbleSort(array);
    PrintArray(array);

    return 0;
}
