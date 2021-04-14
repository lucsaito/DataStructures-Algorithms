//
// Created by Lucas on 09/04/21.
//
// Simple Bubble Sort algorithm, it accepts
// an std::vector of integers as parameter.
//
// 1. The console reads the number of elements of the array to be sorted.
// 2. The console reads all the numbers of the array separated by space.
// 3. The console outputs the sorted array.

#include <iostream>
#include <vector>

template <typename T, typename Compare = std::greater<T>>
class HeapSort {
public:
    explicit HeapSort(Compare comp = Compare()) : comp_{comp} {
    }

    void operator()(std::vector<T>& array) {
        MakeHeap(array);
        for (size_t i = array.size() - 1; i > 0; i--) {
            std::swap(array[0], array[i]);
            SiftDown(array, 0, i);
        }
    }

private:
    void MakeHeap(std::vector<T>& array) {
        for (ssize_t i = array.size() - 1; i >= 0; i--) {
            SiftDown(array, i, array.size());
        }
    }

    void SiftDown(std::vector<T>& array, size_t index, size_t heap_size) {
        while (2 * index + 1 < heap_size) {
            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;
            size_t j = left;
            if (right < heap_size && comp_(array[right], array[left])) {
                j = right;
            }
            if (comp_(array[index], array[j])) {
                break;
            }
            std::swap(array[j], array[index]);
            index = j;
        }
    }

    void SiftUp(std::vector<T>& array, size_t index, size_t heap_size) {
        while (comp_(array[index], array[((int)index - 1) / 2])) {
            std::swap(array[index], array[(index - 1) / 2]);
            if (index > 1) {
                index = (index - 1) / 2;
            } else {
                index = 0;
            }
        }
    }

    size_t GetLeftChild(size_t index) const {
        return 2 * index + 1;
    }

    size_t GetRightChild(size_t index) const {
        return 2 * index + 2;
    }

    size_t GetParent(size_t index) const {
        return (index + 1) / 2 - 1;
    }

    bool HasLeftChild(size_t index, size_t heap_size) const {
        return 2 * index + 1 < heap_size;
    }

    bool HasRightChild(size_t index, size_t heap_size) const {
        return 2 * index + 2 < heap_size;
    }

private:
    Compare comp_;
};

std::vector<int> ReadInput() {
    size_t n;
    std::cin >> n;
    std::vector<int> temp_arr(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> temp_arr[i];
    }
    return temp_arr;
}

template <typename T>
void SortArray(std::vector<T>& array) {
    HeapSort<T> heap;
    heap(array);
}

template <typename T>
void PrintArray(const std::vector<T>& array) {
    for (size_t i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
}

int main() {
    std::vector<int> array = ReadInput();
    SortArray(array);
    PrintArray(array);
    return 0;
}
