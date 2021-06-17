#include <iostream>
#include "MaxHeap.h"
using namespace std;

int main(int argc, const char * argv[]) {
    try {
        MaxHeap<int> maxHeap(10);
        
        //Push(), Top().
        for (int i=0; i<15; ++i) {
            maxHeap.Push(i);
            cout << maxHeap.Top() << " ";
        }
        cout << endl;
        
        //Pop(), Top().
        for (int i=0; i<15; ++i) {
            maxHeap.Pop();
            cout << maxHeap.Top() << " ";
        }
        cout << endl;
        
        //Two Exceptions.
        //MaxHeap<int> maxHeap_(0);
        maxHeap.Pop();
    } catch (const char* err) {
        cout << err << endl;
    }
    return 0;
}
