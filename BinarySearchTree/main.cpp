#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main(int argc, const char * argv[]) {
    BST<int, int> test, small, big;
    pair<int, int> *mid;
    
    //IsEmpty().
    cout << "test.IsEmpty(): " << test.IsEmpty() << endl;
    
    //Insert().
    cout << "Run test.Insert() Method." << endl;
    test.Insert(make_pair(3, 12));
    test.Insert(make_pair(4, 10));
    test.Insert(make_pair(5, 15));
    test.Insert(make_pair(6, 14));
    test.Insert(make_pair(7, 11));
    
    //Get().
    if (test.Get(2)) {
        cout << "Run test.Get(2) Method." << endl;
    } else if (test.Get(3)) {
        cout << "Run test.Get(3) Method, not Get(2)" << endl;
    }
    
    //RankGet().
    for (int i=0; i<10; i++)
        if (test.RankGet(i))
            cout << "Run test.RankGet(" << i << ") Method." << endl;
    
    //Split().
    cout << "Run test.Split() Method." << endl;
    test.Split(5, small, mid, big);
    
    //Start small.
    //IsEmpty().
    cout << endl;
    cout << "small.IsEmpty(): " << small.IsEmpty() << endl;
    
    //Delete().
    cout << "Run small.Delete()." << endl;
    small.Delete(3);
    small.Delete(4);
    
    //IsEmpty().
    cout << "small.IsEmpty(): " << small.IsEmpty() << endl;
    cout << endl;
    //End small.
    
    //Delete().
    cout << "Run test.Delete()." << endl;
    test.Delete(3);
    test.Delete(4);
    test.Delete(5);
    test.Delete(6);
    
    //IsEmpty().
    cout << "test.IsEmpty(): " << test.IsEmpty() << endl;
    
    return 0;
}
