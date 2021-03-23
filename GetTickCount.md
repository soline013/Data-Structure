# GetTickCount.

OS 부팅부터 지난 시간을 ms 단위로 리턴한다.

Windows는 1초에 1000 Clock Ticks이 증가한다.

카운트는 32 Bit로 최대 49.7일까지 유지할 수 있었으나, GetTickCount64 함수로 카운트가 64 Bit까지 늘어나 약 5억 8천년까지 유지할 수 있다.

시스템 타이머 정밀도에 영향을 받는다. (최소 정밀도: 10~16ms.)

windows.h와 winmm.lib가 필요하다.

## winmm.lib 링크 방법.
1.	Visual Studio – 프로젝트 – 속성 – 구성속성 – 링커 – 입력 – 추가종속성 추가.
2.	#pargma comment(lib, “winmm.lib”).

## Code.
```CPP
#include <windows.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")
using namespace std;

int main(void) {
		int double_sum = 0;
		DWORD start = GetTickCount();
		
		/*There are codes to measure time.*/
		for (int i=0; i<3000; i++)
			double_sum += i * 2;
		cout << double_sum << endl;
		
		DWORD end = GetTickCount ();
		
		cout << end - start << "ms" << endl;
		
		return 0;
}
```