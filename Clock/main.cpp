#include <iostream>
#include <ctime>
using namespace std;

int main(void) {
    clock_t start, end;
    double duration;
    int sum = 0;
    
    start = clock();
    
    /*There are codes to measure time.*/
    for (int i=0; i<100; i++)
        sum += i;
 
    end = clock();
 
    duration = (double)(end - start);
    cout << duration << " ms" << endl;
 
    return 0;
}
