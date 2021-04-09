#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Queue {
    private:
        T *queue; //Array.
        int capacity; //Array Size.
        int front; //Behind one of First Element(Counterclockwise).
        int rear; //Postion of Last Element.
    
    public:
        Queue(int stackCapacity = 10);
        bool IsEmpty();
        T& Front();
        T& Rear();
        void Push(const T& item);
        void Pop();
};

//Constructor.
template <typename T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity) {
    if (capacity < 1) throw "Stak capacity must me > 0";
    queue = new T[capacity];
    front = rear = 0; //Empty Stack.
}

//Method.
template <typename T>
inline bool Queue<T>::IsEmpty() {
    return front == rear;
}

template <typename T>
inline T& Queue<T>::Front() {
    if (IsEmpty()) throw "Queue is empty. No front element.";
    
    return queue[(front + 1)%capacity];
}

template <typename T>
inline T& Queue<T>::Rear() {
    if (IsEmpty()) throw "Queue is empty. No rear element.";
        
    return queue[rear];
}

template <typename T>
void Queue<T>::Push(const T& item) {
    if ((rear + 1) % capacity == front) {
        T* newQueue = new T[2 * capacity];
        int start = (front + 1) % capacity;
        
        if (start < 2) {
            copy(queue+start, queue+start+capacity-1, newQueue);
        } else {
            copy(queue+start, queue+capacity, newQueue);
            copy(queue, queue+rear+1, newQueue+capacity-start);
        }
        front = 2 * capacity - 1;
        rear = capacity - 2;
        capacity *= 2;
        delete[]queue;
        queue = newQueue;
    }
    rear = (rear + 1) % capacity;
    queue[rear] = item;
}

template <typename T>
void Queue<T>::Pop() {
    if (IsEmpty()) throw "Queue is empty. Can not delete.";
    front = (front + 1) % capacity;
    queue[front].~T();
}
