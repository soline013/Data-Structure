#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(int argc, const char * argv[]) {
    //Chain.
    Chain<int> c1;
    Chain<int> c2;
    
    //InsertBack().
    for (int i=0; i<5; i++) {
        c1.InsertBack(i + 1);
        c2.InsertBack(i + 6);
    }
    c1.Print();
    c2.Print();
    
    //Concatencate();
    c1.Concatencate(c2);
    c1.Print();
    
    //Reverse();
    c1.Reverse();
    c1.Print();
    
    return 0;
}
