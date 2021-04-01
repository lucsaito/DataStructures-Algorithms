//
// Created by Lucas on 25/03/21.
// This is an insertion sort algorithm using std::vector as argument
//

#include <iostream>
#include <vector>

std::vector<int> ReadInput() {
    size_t n;
    std::vector<int> array;
    std::cin >> n;
    array.resize(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    return array;
}

void InsertionSort(std::vector<int>& array) {
    for (size_t j = 1; j < array.size(); j++) {
        int key = array[j];
        size_t i = j - 1;

        while (i >= 0 && (array[i] > key)) {
            array[i + 1] = array[i];
            i -= 1;
        }
        array[i + 1] = key;
    }
}

void PrintArray(const std::vector<int>& array) {
    for (size_t i = 0; i < array.size(); i++) {
        std::cout << array[i] << ' ';
    }
}

int main() {
    std::vector<int> array = ReadInput();
    InsertionSort(array);
    PrintArray(array);

    return 0;
}
