# 랭작을 해봅시다.

## STL 기초 자료구조
> 이곳 바탕으로 만듬
> 
> https://ssinyoung.tistory.com/46
>
> *list vector 양이 많아서 도중에 이거 기초로 만듬*
>
> https://baactree.tistory.com/29
> 
> **공부를 위해 아예 전적으로 베꼈으니 윗글 참고하시는게 도움 더 됩니다.**
---
## 1. List

+ 양방향 연결리스트(노드 기반 메모리), 어느 위치 에서든 상수 시간 안에 추가 삭제 가능
+ 별도의 iterator 로 접근 가능하고, erase로 삭제 접근이 가능
+ remove 멤버 함수로 값으로 접근하여 삭제 가능
+ for each 문으로도 접근 가능, 이때 auto 형이 아니라 엄밀히 하기 위해선 list<int>::iterator 사용
+ 추가적으로 덧붙이자면 잘 안쓸것 같아 예제 코드는 올리지 않음.

```cpp
```

## 2. Vector

+ 배열 기반 동적 할당 배열 (연속된 메모리), 빠른 데이터 참조에 유리하다.
+ 뒤에서 원소 추가하는 연산은 O(1)을 보장한다.

+ [] 연산자가 오버로딩 되어 있어 사용이 직관적이다.
+ 배열의 원소 개수가 변할 수 있다.
+ 다만, 이때 자리가 부족할 경우 2배만큼 할당을 받기 때문에 공간복잡도에서 신중하게 결정해야한다.
+ 따라서 가능한 한 vector가 메모리 재할당을 하지 않도록 조작하는 것이 중요하다.
+ vector.reverse(capacity) 를 통해 처음 할당할 때 크기를 정해줄 수 있다.
+ 이는 생성자의 인수로도 할당 가능하다.

```cpp
#include<vector>

vector<int> vt(5, 1); // 값이 1인 int 자료를 5개를 담는 배열로 초기화
vt.push_back(1); // vt 배열 맨 뒤에 1을 추가
vt.pop_back();
vt.resize(n); // 크기를 n으로 설정한다.
vt.begin();
vt.end(); // 보통 sort할때 기준점으로 사용된다.

vector<vector<int>> sec(n, vector<int>(m, 0));
// arr[n][m] 을 0으로 초기화한 2차원 동적배열과 같다.
```

## 3. Stack

모두가 아는 그것. LIFO(후입 선출) 을 만족하는 선형 자료구조이다.

```cpp
#include<stack>

stack<int> st;
st.push(int);
st.pop(); // 이때 원소값 출력
st.top();
st.empty();
st.size();
```
## 4. Queue

모두가 아는 그것 2. FIFO(선입 선출) 을 만족하는 선형 자료구조이다.

```cpp
#include<queue>

queue<int> q;
q.push(4);
q.pop(); // 이때 원소값 출력
q.front();
q.back();
q.empty();
q.size();
```

## 5. Deque

덱 이라고 부르던데 데큐라고도 부르더라. 앞 뒤 모든 곳에서 삽입 삭제가 가능한 선형 자료구조.  
사용 하는 이유는 앞뒤에서 작업할 때 속도가 O(1)을 보장하기 때문.

```cpp
#include<deque>

deque<int> dq;
dq.push_back(2);
dq.push_front(1);
dq.front();
dq.back();
```

## 6. Set

밸런스트리, 레드블랙 트리로 만들어져있다. 따라서 검색 및 삽입 삭제 모두 O(logN) 을 보장한다.  
당연히 Set(집합) 이므로 중복을 허용하지 않는다.  
레드 블랙 트리는 구현해볼만하니 시간되면 구현해보자.

```cpp
#include<set>

set<int> s;
s.insert(5); // 원소 5 삽입
if(s.find(6) != s.end()) // 원소 검색방법
    cout<<"6이 존재합니다.\n";
s.size(); // 저장된 원소의 수 s.insert(5); 3번했다고 3이 되는게 아님
s.clear(); // 모든 원소 삭제
s.erase(++s.begin()); // 2번째 원소 삭제
```

## 7. Map
파이썬의 딕셔너리, 자바스크립트의 객체와 비슷하다.  
set에 key와 value가 추가된 버전이라고 생각하면 된다.  
따라서 삽입 삭제 탐색 모두 O(log N)
```cpp
#include<map>

map<int, int> m; // key가 int고 value가 int 인 map
m.insert(make_pair(4, 5)); // 삽입 시 pair 자료형이 들어간다.
m[4]; // 5, 인덱싱할 때 key가 스트링이면 스트링으로도 인덱싱이 가능!
cout<<m.find(4)->second; // find 함수는 pair 포인터를 반환한다.
cout<<m.count(4); // key와 관련된 원소의 갯수를 리턴한다.
m.size();
m.clear();
```

## 8. Pair
2개의 데이터를 쌍으로 묶어 저장할 수 있는 자료형  
비교 연산 시 first -> second 순으로 비교하게된다.  
```cpp
#include<utility>
// pair 가 아니라 utility 인거 조심
pair<int, int> pii_;
// 보통 개인 정의형 자료형으로 많이 정의시켜서 쓴다.
typedef pair<int, int> pii;
typedef pair<float, int> pfi;
typedef pair<vector<int>, int> pvi; // 등등..

pii_ = make_pair(4, 5); // pair 형으로 바로 전환해줌

```

## 9. algorithm

자료형보단 알고리즘모음에 가깝다. sort 등의 유용한 알고리즘을 편하게쓰자~  

```cpp
#include<algorithm>

bool cmp (const int a, const int b) {
    return a>b; // 역순으로 정렬할 수 있도록 하는 개인 정렬함수를 정의하여 sorting 가능
}

int main(){
    vector<int> arr(1000);
    int narr[1000];
    
    sort(narr, narr + n); // arr의 N-1번째 원소(arr[n-1]까지 정렬
    sort(arr.begin(), arr.end()); // vector는 편하게 정렬가능
    sort(narr, narr+n, cmp);

    stable_sort(narr, narr+n); // 사용법은 같으나 안정적으로 sort한다. 
    // 둘의 차이점은 우선순위가 같은 여러 원소들 사이의 기존 위치가 바뀌지 않는다는 점.
    // 예 ) (3, d), (2, c), (2, d), (1, f)
    // 정렬 후 (2,c) 와 (2, d)의 순서는 바뀌지 않는다.

    // max, min 값 반환, 원소의 "주소"를 반환하니 주의할것
    *max_element(narr, narr+n);
    *min_element(narr, narr+n);
    
}
```
---
## 기초 알고리즘
> 기초적인 알고리즘들을 정리해놓았습니다.  
> 알고리즘들의 아이디어들은 plzrun 님의 강의글을 참고하였습니다.  
> 순서는 난이도순이 아니니 주의할 것
---

## 0. 정렬

### 버블정렬/선택정렬/삽입정렬
응애 수준 정렬들이고 O(N^2) 라서 엄청 비효율적이지만,  
알고의 기초가 된다고 생각되어 넣어봤습니다.
```cpp
```
### 합병정렬/퀵정렬
이제 옹알이 정도면 알아두어야할 것  
둘다 O(NlogN) 이라 쓸만하다.
```cpp
```


## 1. Dynamic Programing

---

## 2. Graph 이론

### DFS, BFS

### Dijkstra, Floyd, 벨만-포드

---
## 3. 이분 탐색

### 삼분 탐색
---
## 4. 분할 정복

## 5. 그리디 알고리즘

## 6. 완전탐색







## 문제 푸는 법

> 내 수준에 맞춰서  

나같은 경우는 백준 골드보다 못한 실딱 벌레라고 생각하기 때문에  
실버 문제부터 많은 사람들이 푼 문제 순으로 본다. 

아래에 들어가면 각자가 정한 문제 정렬 방식 옵션을 저장할 수 있는데,  
여기 가서 자기 수준에 맞게 난이도를 고쳐서 저장해두면 좋다.  
진짜 솔브드가 이제 지원되서 좋은 점인거 같음.  

- https://www.acmicpc.net/problemset/options

- https://www.acmicpc.net/problemset?sort=ac_desc&submit=fa%2Cus&tier=6%2C7%2C8%2C9%2C10%2C11%2C12%2C13%2C14%2C15&style=cs&style_if=nand

### 군돌이들 팁

**VPS** 로 코드서버 파서 사드세요 그냥.. 답없어요   