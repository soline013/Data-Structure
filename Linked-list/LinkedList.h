#include <iostream>
using namespace std;

//Program 4.6: Template definition of chains.
template <class T> class Chain; // forward declaration

template <class T>
class ChainNode {
    friend class Chain<T>;
    public:
        ChainNode<T>(T e) {
            data = e;
        }
    
    private:
        T data;
        ChainNode<T> *link;
};

template <class T>
class Chain {
    public:
        Chain() {first = 0;};   // constructor initializing first to 0
                                // Chain manipulation operations
        void InsertBack(const T& e);
        void Concatencate(Chain<T>& b);
        void Reverse();
        void Print();
    
    private:
        ChainNode<T> *first;
        ChainNode<T> *last;
};

//Program 4.11: Inserting at the back of a list.
template <class T>
void Chain<T>::InsertBack(const T& e) {
    if (first) { // nonempty chain
        last->link = new ChainNode<T>(e);
        last = last->link;
    } else first = last = new ChainNode<T>(e);
}

//Program 4.12: Concatenating two chains.
template <class T>
void Chain<T>::Concatencate(Chain<T>& b) { // b is concatenated to the end of *this.
    if (first) {
        last->link = b.first;
        last = b.last;
    } else {
        first = b.first;
        last = b.last;
    }
    b.first = b.last = 0;
}

//Program 4.13: Reverse a list.
template <class T>
void Chain<T>::Reverse() { // A chain is reversed so that (a sub 1, ..., a sub n) becomes (a sub n, ..., a sub 1).
    ChainNode<T> *current = first, *previous = 0; // previout trails current
    while (current) {
        ChainNode<T> *r = previous;
        previous = current;         // r trails previous
        current = current->link;    // current moves to next node
        previous->link = r;         // link previous to preceding node
    }
    first = previous;
}

template <class T>
void Chain<T>::Print() {
    ChainNode<T> *temp = first;
    
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}
