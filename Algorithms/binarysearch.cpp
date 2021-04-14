//
// Created by Lucas on 14/04/21.
//
// A binary search template function. It accepts an std::vector<T>, its size,
// and the element to search in the array, if not found, returns -1

#include <iostream>
#include <vector>

template <typename T>
size_t BinarySearch(const std::vector<T>& arr, size_t n, T element) {
    size_t left = 0;
    size_t right = n;

    while (left <= right) {
        size_t m = ((left + right) / 2);
        if (arr[m] < element) {
            left = m + 1;
        } else if (arr[m] > element) {
            right = m - 1;
        } else {
            return m;
        }
    }
    return -1;
}

int main() {
    // Test
    std::vector<int> arr = {234, 543, 123, 39, 50, 33, 89, 88, 54, 64, 10, 18, 25, 38, 104, 99, 51, 74};
    std::sort(arr.begin(), arr.end());
    for (auto &item : arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::cout << BinarySearch(arr, arr.size() - 1, 54) << std::endl;

    return 0;
}
