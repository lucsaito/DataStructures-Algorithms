//
// Created by Lucas on 09/04/21.
//
// A simple heap template class
// It has the following methods:

// MakeHeap     -> Creates a heap from an unordered array.
// Insert       -> Inserts an element into the heap.
// RemoveMin    -> Removes the minimum element of the heap and returns it.
// GetMin       -> Returns the minimum element of the heap.
// GetLeftChild     -> Returns the left child element.
// GetRightChild    -> Returns the left child element.
// GetParent        -> Returns the parent of the element.
// HasLeftChild     -> Returns bool value.
// HasRightChild    -> Returns bool value.


#include <iostream>
#include <map>
#include <vector>

template <typename ElementType, typename Compare = std::less<ElementType>>
class Heap {
public:
    explicit Heap(Compare comp = Compare()) : comp_{comp} {
    }

    void MakeHeap(const std::vector<ElementType>& array) {
        heap_ = array;
        for (ssize_t i = (array.size() - 1) / 2; i >= 0; i--) {
            SiftDown(static_cast<size_t>(i));
        }
    }

    void Insert(const ElementType& element) {
        heap_.push_back(element);
        if (!heap_.empty()) {
            SiftUp(heap_.size() - 1);
        }
    }

    ElementType RemoveMin() {
        ElementType min = heap_[0];
        heap_[0] = heap_[heap_.size() - 1];
        heap_.pop_back();
        SiftDown(0);
        return min;
    }

    const ElementType& GetMin() const {
        return heap_[0];
    }

private:
    void SiftUp(size_t index) {
        while (comp_(heap_[index], heap_[((int)index - 1) / 2])) {
            std::swap(heap_[index], heap_[(index - 1) / 2]);
            if (index > 1) {
                index = (index - 1) / 2;
            } else {
                index = 0;
            }
        }
    }

    void SiftDown(size_t index) {
        while (2 * index + 1 < heap_.size()) {
            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;
            size_t j = left;
            if (right < heap_.size() && comp_(heap_[right], heap_[left])) {
                j = right;
            }
            if (comp_(heap_[index], heap_[j])) {
                break;
            }
            std::swap(heap_[index], heap_[j]);
            index = j;
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

    bool HasLeftChild(size_t index) const {
        return 2 * index + 1 < heap_.size();
    }

    bool HasRightChild(size_t index) const {
        return 2 * index + 2 < heap_.size();
    }

private:
    std::vector<ElementType> heap_;
    Compare comp_;
};

int main() {
    return 0;
}
