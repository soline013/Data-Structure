#include <iostream>
using namespace std;

class HeapEmpty {};
class HeapFull {};

template<typename T>
class MaxHeap {
public:
	MaxHeap(int maxSize = 100) : heapSize(0), capacity(maxSize), heap(new T(maxSize)) {}
	~MaxHeap() { delete heap; }
	void Push(const T& data);
	void Pop();
	T& Top() const;
	int Size() const;
	bool IsEmpty() const;

private:
	T* heap;
	int heapSize;
	int capacity;
};

template<typename T>
void MaxHeap<T>::Push(const T& data) {
	try {
		if (Size() == capacity) throw HeapFull();
		heap[heapSize] = data;
		int parent = (heapSize - 1) / 2;
		int child = heapSize;
		
		while ((parent >= 0) && (heap[parent] < heap[child])) {
			T tmp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		++heapSize;
	}
	catch (HeapFull e) {
		cout << "Heap is full\n";
		exit(2);
	}
}

template<typename T>
void MaxHeap<T>::Pop() {
	try {
		if (IsEmpty()) throw HeapEmpty();
		heap[0] = heap[--heapSize];
		int parent = 0;
		int child = parent * 2 + 1;
		bool placed = false;
		
		while ((!placed) && (child < heapSize)) {
			if ((child < heapSize - 1) && (heap[child] < heap[child + 1]))
				child += 1;
			
			if (heap[parent] >= heap[child]) {
				placed = true;
			} else {
				T tmp = heap[parent];
				heap[parent] = heap[child];
				heap[child] = tmp;
			}
			
			parent = child;
			child = parent * 2 + 1;
		}
	}
	catch (HeapEmpty e) {
		cout << "Heap is empty\n";
		exit(2);
	}
}

template<typename T>
T& MaxHeap<T>::Top() const {
	try {
		if (IsEmpty()) throw HeapEmpty();
		return heap[0];
	}
	catch (HeapEmpty e) {
		cout << "Heap is empty\n";
		exit(2);
	}
}

template<typename T>
int MaxHeap<T>::Size() const {
	return heapSize;
}

template<typename T>
bool MaxHeap<T>::IsEmpty() const {
	return (heapSize == 0);
}