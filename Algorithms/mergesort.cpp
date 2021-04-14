//
// Created by Lucas on 14/04/21.
//
// Template function of Merge Sort algorithm, it accepts an std::vector as input.
//
// 1. The console reads the number of elements of the array to be sorted.
// 2. The console reads all the numbers of the array separated by space.
// 3. The console outputs the sorted array.

#include <iostream>
#include <vector>

std::vector<int> ReadInput() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);

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

template <typename T>
struct CustomComparator {
    bool operator()(const T& lhs, const T& rhs) {
        return (lhs < rhs);
    }
};

template <typename T, typename Compare = CustomComparator<T>>
void Merge(std::vector<T>& array, size_t first_begin, size_t first_end, size_t second_begin,
           size_t second_end, Compare comp = Compare()) {
    size_t array1_size = first_end - first_begin;
    size_t array2_size = second_end - first_end;

    std::vector<int> first_array(array1_size);
    std::vector<int> second_array(array2_size);

    std::copy(array.begin() + first_begin, array.end() - (array.size() - first_end),
              first_array.begin());
    std::copy(array.begin() + second_begin, array.end() - (array.size() - second_end),
              second_array.begin());

    size_t i = 0;
    size_t j = 0;
    size_t merge_array_index = first_begin;

    while (i < array1_size && j < array2_size) {
        if (first_array[i] <= second_array[j]) {
            array[merge_array_index] = first_array[i];
            i++;
        } else {
            array[merge_array_index] = second_array[j];
            j++;
        }
        merge_array_index++;
    }
    while (i < array1_size) {
        array[merge_array_index] = first_array[i];
        i++;
        merge_array_index++;
    }
    while (j < array2_size) {
        array[merge_array_index] = second_array[j];
        j++;
        merge_array_index++;
    }
}

template <typename T, typename Compare = CustomComparator<T>>
void MergeSort(std::vector<T>& array, size_t begin, size_t end, Compare comp = Compare()) {
    if (begin + 1 < end) {
        size_t m = (begin + end) / 2;
        MergeSort(array, begin, m);
        MergeSort(array, m, end);
        Merge(array, begin, m, m, end);
    }
}

template <typename T, typename Compare = CustomComparator<T>>
void Sort(std::vector<T>& array) {
    MergeSort(array, 0, array.size());
}

int main() {
    std::vector<int> arr = ReadInput();
    Sort(arr);
    PrintArray(arr);
    return 0;
}
