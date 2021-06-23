#include <iostream>
using namespace std;

class String {
    private:
        char *buffer; //Array.
        int size; //Array Length.
        int length; //Count.
    
    public:
        //Constructor.
        String();
        String(int m);
        String(String&); //Copy Constructor.
        String(char *init, int m);
        
        //Destructor.
        ~String();
    
        //Operation.
        bool operator==(String t);
        bool operator!();
        String& operator=(const String&);
    
        //Method.
        String Concat(String t);
        String Substr(int i, int j);
        int Length();
        int Find(String pat);
        void println();
};

//Constructor.
String::String() : String(10) {}

String::String(int m) {
    size = m;
    buffer = new char[m];
    length = 0;
}

String::String(String& s) : String(s.length + 1) {
    for (int i=0; i<s.length; i++)
        buffer[i] = s.buffer[i];
    buffer[s.length] = '\0';
    length = s.length;
}

String::String(char *init, int m) : String(m + 1) {
    for (int i=0; i<m; i++)
        buffer[i] = init[i];
    buffer[m] = '\0';
    length = m;
}

//Destructor.
String::~String() {
    delete [] buffer;
}

//Operator.
bool String::operator==(String t) {
    for (int i=0; i<length; i++) {
        if (buffer[i] != t.buffer[i])
            return false;
    }
    return true;
}

bool String::operator!() {
    if (length == 0)
        return true;
    else
        return false;
}

String& String::operator=(const String& s) {
    delete [] buffer;
    buffer = new char[s.length + 1];
    for (int i = 0; i < s.length; i++)
        buffer[i] = s.buffer[i];
    buffer[s.length] = '\0';
    length = s.length;

    return *this;
}

//Method.
String String::Concat(String t) {
    String result(length + t.length + 1);
    
    for (int i=0; i<length; i++)
        result.buffer[i] = buffer[i];
    for (int j=0; j<t.length; j++)
        result.buffer[length + j] = t.buffer[j];
    result.buffer[length + t.length] = '\0';
    result.length = length + t.length;
    
    return result;
}

String String::Substr(int i, int j) {
    String search(j - i + 2);
    search.length = j - i + 1;
    
    for (int k=0; k<search.length; k++)
        search.buffer[k] = buffer[k + i];
    search.buffer[search.length] = '\0';
    
    return search;
}

int String::Length() {
    return length;
}

int String::Find(String pat) {
    for (int i=0; i<length-pat.length+1; i++) {
        for (int j=0; j<pat.length; j++) {
            if ((buffer[i + j] == pat.buffer[j]) && (j == pat.length - 1)) {
                return i;
            }
        }
    }
    return -1;
}

void String::println() {
    for (int i=0; i<length; i++)
        cout << buffer[i];
    cout << endl;
}
