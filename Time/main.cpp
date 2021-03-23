#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t start, end;
    double duration;
    int times = 0;
    
    start = time(NULL);
    
    /*There are codes to measure time.*/
    for (int i=0; i<202103; i++)
        times = i * i;
        
    end = time(NULL);
    
    duration = (double)(end - start);
    cout << duration << "s" << endl;
    
    return 0;
}
