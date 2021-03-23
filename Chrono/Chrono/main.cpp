#include <chrono>
#include <iostream>
#include <cmath>
using namespace std;
using namespace chrono;

int main(void) {
    int sum = 0;
    system_clock::time_point start = system_clock::now();
    
    /*There are codes to measure time.*/
    for (int i=0; i<3000; i++)
        sum += i;
    
    system_clock::time_point end = system_clock::now();
    
    duration<double> default_time = end - start;
    nanoseconds nano = end - start;
    microseconds micro = duration_cast<microseconds>(end - start);
    milliseconds milli = duration_cast<milliseconds>(end - start);
    seconds sec = duration_cast<seconds>(end - start);
    minutes min = duration_cast<minutes>(end - start);
    hours hour = duration_cast<hours>(end - start);
    
    cout << default_time.count() << " Default" << endl;
    cout << nano.count() << " Nano" << endl;
    cout << micro.count() << " Micro" << endl;
    cout << milli.count() << " Milli" << endl;
    cout << sec.count() << " Sec" << endl;
    cout << min.count() << " Min" << endl;
    cout << hour.count() << " Hour" << endl;

    return 0;
}
