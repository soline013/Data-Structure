# timeGetTime.

Windows가 시작되어 흐른 시간을 ms 단위로 DWORD형을 리턴한다.

멀티미디어 라이브러리를 이용한다.

멀티미디어 타이머에 영향을 받는다. (최소 정밀도: 5ms 이상.)

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
		int mean = 0;
		DWORD start = timeGetTime();
		
		/*There are codes to measure time.*/
		for (int i=1; i<=3000; i++)
			mean += i;
		mean /= 3000;
		cout << mean << endl;
		
		DWORD end = timeGetTime();
		
		cout << end - start << "ms" << endl;
		
		return 0;
}
```