## C에서 Node + Linked List의 구현.

```c
//first → (123) → (456) → (789) → 0(NULL)
//first의 data에 값이 없다.

struct node {
	int data;
	struct node* link;
};

struct node first;
struct node _2nd;
struct node _3th;
struct node _4th;

first.link = &_2nd;

_2nd.data = 123;
_2nd.link = &_3th;

_3th.data = 456;
_3th.link = &_4th;

_4th.data = 789;
_4th.link = NULL;
```

```c
//first(123) → second(456) → 0(NULL)
//first의 data에 값이 있다.

struct node {
	int data;
	struct node* link;
};

struct node first;
struct node second;

first.data = 123;
first.link = &second;

second.data = 456;
second.link = NULL;

printf("%d", first.link->data); //456
```

- `(*first.link).data`와 `first.link->data`는 같다.
- 밑의 코드는 논리적 개념을 충실히 따르지는 않는다.
- C에서는 `*first`를 사용하면 함수 구현 등에서 오류가 발생할 수 있고 어렵기 때문에 사용하지 않는다.

## C++에서 Node의 구현.

```cpp
class ThreeLetterNode {
	private:
		char data[3];
		ThreeLetterNode *link;
};
```

```cpp
class NodeA {
	private:
		int data1;
		char data2;
		float data3;
		NodeA *linka;
		NodeB *linkb;
};

class NodeB {
	private:
		int data;
		NodeB *link;
```

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4c2e8b1a-b95c-45bf-81fe-af6ecb5157d3/_2021-04-17_16.07.22.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4c2e8b1a-b95c-45bf-81fe-af6ecb5157d3/_2021-04-17_16.07.22.png)

- NodeA와 NodeB를 만들어 복잡한 구현도 가능하나, 많이 사용하는 방식은 아니다.
- C++에서는 `*first`를 사용해도 문제가 없기 때문에 잘 사용한다.

## C++에서 체인 클래스 설계.

```cpp
class ThreeLetterNode {
	private:
		char data[3];
		ThreeLetterNode *link;
	
	//Node 접근 방법 1. Public한 Method 만들기.
	//public:
	//	 getData, setData, getLink, setLink
	
	//Node 접근 방법 2. Friend로 선언하기. 가장 많이 사용하는 방법.
	//friend class LinkedList;
};

class LinkedList {
	private:

		//Node 접근 방법 3. 중첩 클래스로 두기. Class 안에 넣으면 된다.
		//class ThreeLetterNode {
		//	public:
		//		char data[3];
		//		ThreeLetterNode *link;
		//};

		ThreeLetterNode *first; //ThreeLetterNode first;
};
```

- Node가 모여서 표현되는 것을 Chain, Linked List라고 부른다.
- Linked List HAS-A Node. HAS-A 관계는 부속 클래스로 같이 생성되고 소멸한다.

1. `ThreeLetterNode *first;`과 `ThreeLetterNode first;`의 차이.
    1. 논리적 개념으로는 First가 첫 번째 노드를 가리키는 포인터이다.
    2. 따라서 `ThreeLetterNode *first;`가 논리적 개념을 확실히 따르는 것이다.
    3. `ThreeLetterNode first;`를 사용할 경우, Data 부분을 사용하지 않는다.

2. Linked List에서 Node에 접근하기.
    1. 함수 만들기. 잘못 접근하여 변경될 가능성이 있다.
    2. Linked List HAS-A Node. HAS-A 관계 만들기.
        1. Friend로 선언하기. 가장 많이 사용하는 방법.
        2. 중첩 클래스로 두기. Class 안에 넣으면 된다.

## C++에서 포인트 조작.

자료 구조 연결 리스트 강의 자료 참고.

추후 정리.

## 체인 조작 연산 (1).

자료 구조 연결 리스트 강의 자료 참고.

추후 정리.

## 체인 조작 연산 (2).

자료 구조 연결 리스트 강의 자료 참고.

추후 정리.

## 체인 반복자 (1).

```cpp
//1. 첫 번째 Node부터 마지막 Node까지.
//Node 생성, 추가에 사용한다.
for (end=first; end->link!=NULL; end=end->link);

//2. 첫 번째 Node부터 NULL까지.
//Node의 Data를 탐색할 때 사용한다.
//Node 추가에 사용하면 오류가 난다.
for (end=first; end!=NULL; end=end->link);
```

컨테이너 클래스 C: 스택, 큐, 리스트 등 자료를 포함하는 클래스.

## 체인 반복자 (2).

1. 보통 템플릿 클래스를 사용하는데, Sum과 같은 기능은 String 등에서 사용할 수 없다.
2. 따라서 Class에 들어가 있는 것이 아니라 Main 같은 곳에서 사용하는 것이 좋다.
3. 그러나 Main에서는 속성에 접근하기 어렵다.
4. 결국 반복자라는 객체를 사용하여 해결할 수 있다.

## C++ 반복자 (1).

```cpp
for (Iterator i=start; i!=end; i++);
```

## C++ 반복자 (2).

P. 169.

- 입력: 입력을 지원하는 반복자.
- 출력: 출력을 지원하는 반복자.
- 전방: 전진할 수 있는 반복자.
- 양방: 전진, 후퇴할 수 있는 반복자.
- 임의접근: 원하는 위치로 갈 수 있는 반복자.

!=에 대한 연산자 오버로딩 추가 필요.

## 체인 연산.

다른 컨테이너 클래스 C에서 구현하고 사용되는 것과 비슷하다.
