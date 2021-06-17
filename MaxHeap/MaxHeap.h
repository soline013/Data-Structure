#include <iostream>
using namespace std;

//ADT 5.2:A max priority queue
template <class T>
class MaxHeap {
    private:
        T *heap;        // element array
        int heapSize;   // number of elements in heap
        int capacity;   // size of the array heap
    
    public:
        MaxHeap(int theCapacity = 10);
        ~MaxHeap() {}           // destructor
        bool IsEmpty() const;   // return true iff the priority queue is empty
        const T& Top() const;   // return reference to max element
        void Push(const T&);    // add an element to the priority queue
        void Pop();             // delete element with max priority
        void ChangeSize1D(T*& a, const int oldSize, const int newSize);
};

template<class T>
bool MaxHeap<T>::IsEmpty() const {
    return heapSize == 0;
}

template<class T>
const T& MaxHeap<T>::Top() const {
    return heap[heapSize];
}

//Program 5.15:Max heap constructor
template <class T>
MaxHeap<T>::MaxHeap (int theCapacity) {
    if (theCapacity < 1) throw "Capacity must be >= 1.";
    capacity = theCapacity;
    heapSize = 0;
    heap = new T[capacity + 1]; // heap[0] is not used
}

//Program 5.16:Insertion into a max heap
template <class T>
void MaxHeap<T>::Push(const T& e) { // Insert e into the max heap.
    if (heapSize == capacity) {     // double the capacity
        ChangeSize1D(heap, capacity, 2 * capacity);
        capacity *=2;
    }
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < e) { // bubble up
        heap[currentNode] = heap[currentNode/2];            // move parent down
        currentNode /= 2;                                   // move to parent
    }
    heap[currentNode] = e;
}

//Program 5.17:Deletion from a max heap
template <class T>
void MaxHeap<T>::Pop() {    // Delete max element.
    if (IsEmpty()) throw "Heap is empty. Cannot delete.";
    heap[1].~T();   // delete max element
    
    // remove last element from heap
    T lastE = heap[heapSize--];
  
    // trickle down
    int currentNode = 1;    // root
    int child =2;           // a child of currentNode
    while (child <= heapSize) {
        // set child to larger child of currentNode
        if (child < heapSize && heap[child] < heap[child+1]) child++;
        
        // can we put lastE in currentNode?
        if (lastE >= heap[child]) break;   // yes
    
        // no
        heap[currentNode] = heap[child];    // move child up
        currentNode = child; child *= 2;    // move down a level
    }
    heap[currentNode] = lastE;
}

template<class T>
void MaxHeap<T>::ChangeSize1D(T*& a, const int oldSize, const int newSize) {
    if (newSize < 0) throw "New length must be >= 0";
    T* temp = new T[newSize];
    int number = min(oldSize, newSize);
    copy(a, a+number, temp);
    delete[] a;
    a = temp;
}
