#include <iostream>
#include "String.h"
using namespace std;

int main(void) {
    int find;
    bool tf;
    String str1((char*)"Hello", 5);
    String str2((char*)"world!", 6);
    String str3;
    String str4;
    
    //Print String.
    cout << "Print String." << endl;
    cout << "str1: ";
    str1.println();
    cout << "str2: ";
    str2.println();
    
    //'=' Operation.
    cout << "\n" << "'=' Operation." << endl;
    tf = (str1 == str2);
    cout << "str1 == str2: "<< tf << endl;
    
    //'!' Operation.
    cout << "\n" << "'!' Operation." << endl;
    tf = (! str1);
    cout << "! str1: " << tf << endl;
    tf = (! str3);
    cout << "! str3: " << tf << endl;
    
    //Concat() Method.
    cout << "\n" << "Concat() Method." << endl;
    cout << "str3: ";
    str3 = str1.Concat(str2);
    str3.println();
    
    //Substr() Method.
    cout << "\n" << "Substr() Method." << endl;
    cout << "str4: ";
    str4 = str3.Substr(3, 7);
    str4.println();
    
    //Find() Method.
    cout << "\n" << "Find() Method." << endl;
    find = str3.Find(str1);
    cout << "Index(str1 in str3): " << find << endl;
    find = str3.Find(str2);
    cout << "Index(str2 in str3): " << find << endl;
    
    return 0;
}
