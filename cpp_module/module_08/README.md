# C++ Module 08

## Index

- [Subject](#Subject)
- [STL Containers](#stl-containers)
- [Algorithm](#algorithm)
- [Iterator](#iterator)
- [References](#references)

## Subject

### Module-specific rules

이 모듈은 표준 컨테이너와 표준 알고리즘 없이도 구현할 수 있다.

하지만 이를 정확히 사용하는 것이 모듈의 목표이다.
여기선 **Containers** (vector/list/map 등)와 **Algorithms** (<algorithm> 헤더에 정의된)을 사용할 수 있다.
적절한 곳에 적용할 수 있어야 한다.

또한 헤더 파일에 템플릿을 정의할 수 있다.

### ex00

- files: Makefile, main.cpp, easyfind.{h, hpp} (+ easyfind.tpp)
- 함수 템플릿 `easyfind`를 작성해야 한다. 이때 차례대로 타입 `T`와 `int`를 매개변수로 받는다.
- 타입 `T`가 정수의 컨테이너인 것으로 가정하면, 이 함수는 첫 번째 매개변수에서 두 번째 매개변수의 첫 번째 발생을 찾아야 한다.
- 만약 발견되지 않았다면, 예외를 던지거나 사용자 지정 오류 값을 반환할 수 있다. 참고로 표준 컨테이너의 동작 방식을 분석하여 영감을 얻을 수 있다.
- 물론, 함수가 예상대로 작동하는지 확인하기 위해 자체 테스트를 작성하고 세출해야 한다.

> 연관성이 있는 컨테이너(associative container)에 대한 처리는 하지 않아도 된다.

### ex01

- files: Makefile, main.cpp, Span.{h, hpp} (+ Span.tpp)
- 최대 N개의 정수를 저장할 수 있는 `Span` 클래스를 개발한다. 이때 N은 `unsigned int`이며 생성자에게 전달되는 유일한 매개변수이다.
- `Span` 클래스는 다음과 같은 메서드를 제공해야 한다.
  - `addNumber`: 정수를 추가한다. 이때 추가된 정수는 `Span` 클래스에 저장된다. 만약 같은 정수가 있거나 추가할 수 없다면, 예외를 던진다.
    - `shortestSpan`: `Span` 클래스에 저장된 정수 중 두 개의 정수 사이의 가장 짧은 거리를 반환한다. 만약 정수가 하나 뿐이라면, 예외를 던진다.
    - `longestSpan`: `Span` 클래스에 저장된 정수 중 두 개의 정수 사이의 가장 긴 거리를 반환한다. 만약 정수가 하나 뿐이라면, 예외를 던진다.
- 테스트를 작성하고 아래의 테스트들보다 더 철저해야 한다. 적어도 만 개 이상의 숫자로 테스트해야 한다.

<details>
<summary>테스트 코드</summary>

```cpp
#include "Span.hpp"

int main() {
  Span sp = Span(5);
  
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  
  return 0;
}
```

```shell
2
14
```

</details>

- `iterator` 범위를 사용해서 `Span`을 채우는 기능을 구현해라. 이떄 한 번 호출해서 `Span`에 많은 숫자를 추가하는 멤버 함수를 구현해야 한다.

> 일부 멤버 함수는 컨테이너 요소의 순서를 추가하기 위해 iterator의 범위를 택한다.

### ex02

- files: Makefile, main.cpp, MutantStack.{h, hpp} (+ MutantStack.tpp)
- `std::stack` 컨테이너는 컨테이너 중에서 유일하게 반복 기능이 없는 컨테이너이다.
- 이를 해결하기 위해, `MutantStack` 클래스를 개발한다. 이때 `MutantStack`은 `std::stack`을 상속받아야 한다.
- 그리고 `iterator` 기능을 추가로 제공할 것이다.
- 이를 확인하기 위해 테스트를 작성하고 제출해야 한다.

<details>
<summary>테스트 코드</summary>

```cpp
#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;
  
  mstack.push(5);
  mstack.push(17);
  
  std::cout << mstack.top() << std::endl;
  
  mstack.pop();
  
  std::cout << mstack.size() << std::endl;
  
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  return 0;
}
```

</details>

- `MutantStack`을 사용하여 첫 번째 실행하고, 두 번째 실행에서 `MutantStack` 대신 예를 들어 `std::list`로 대체하면 두 출력 결과가 동일해야 한다.
- 물론, 다른 컨테이너를 테스트할 때는 아래의 코드를 해당 멤버 함수로 업데이트해야 한다(예: push()를 push_back()으로).

## STL Containers

**컨테이너**는 다른 객체들을 보관하는 하나의 커다란 보관소라고 할 수 있다.
특히, STL 컨테이너는 클래스 템플릿의 형태로 구현되어 있기 때문에 임의의 타입 원소들을 위한 컨테이너를 만들 수 있다.
물론 한 컨테이너에는 한 가지 종류의 객체들만 보관할 수 있다.

컨테이너는 자신이 보관하는 원소들의 메모리를 관리하여, 각각의 원소에 접근할 수 있는 멤버 함수를 제공한다.
접근할 때는 **직접 함수를 호출**하거나 **반복자(iterator)**를 사용한다.

한 가지 유의할 사항은 `stack`, `queue`, `priority_queue`는 **컨테이너 어댑터(container adaptor)**라는 점이다.
이들은 다른 컨테이너 클래스를 상속 받아서 다른 컨테이너 클래스 객체에 특정한 인터페이스를 제공한다.

- 순차 컨테이너(sequential container)
    - `vector`
    - `list`
    - `deque(double ended queue)`
- 연관 컨테이너(associative container)
    - `set`
    - `multiset` : 여러 키를 가지는 `set`
    - `map`
    - `multimap` : 여러 키를 가지는 `map`
- 컨테이너 어댑터(container adaptor)
    - `stack`
    - `queue`
    - `priority_queue`

## Algorithm

**알고리즘(algorithm)** 라이브러리는 컨테이너에 반복자들을 가지고 정렬, 검색 등의 작업을 쉽게 수행할 수 있도록 도와주는 라이브러리이다.

알고리즘의 정의된 함수들은 크게 아래와 같은 두 가지 형태를 따르고 있다.

```c++
template <typename Iter>
void doSomething(Iter begin, Iter end);

template <typename Iter, typename Pred>
void doSomething(Iter begin, Iter end, Pred pred);
```

이때 **서술자(Predict)** 라고 하는 특정한 조건을 받는 함수들이 있다.
서술자에는 일반적으로 `bool` 을 반환하는 함수 객체를 전달하게 된다.

### 정렬

알고리즘 라이브러리가 지원하는 정렬은 3가지이다.

- `sort`: 컨테이너의 원소들을 정렬한다.
- `stable_sort`: `sort`와 동일하게 동작하지만, 원소들의 순서가 같은 경우에는 원래의 순서를 유지한다.
- `partial_sort`: 컨테이너의 원소들 중 일부만 정렬한다.

이때 `sort`에 들어가는 반복자의 경우, 반드시 임의접근 반복자(RandomAccessIterator) 타입을 가져야 한다.
그렇기에 `vector`, `deque` 등의 컨테이너만 사용할 수 있다.

또한 정렬은 기본적으로 오름차순으로 정렬된다. 이를 바꿔주기 위해선 서술자에 함수를 넣어주어야 한다.
타입에 국한받지 않도록 `template`을 사용하여 구현하면 편하다.

```c++
template <typename T>
struct greater_comp {
  bool operator()(const T& a, const T& b) const {
    return a > b;
  }
};
```

또한 `functional` 헤더에는 `greater` 라는 템플릿 클래스가 정의되어 있기에 아래와 같이 사용할 수 있다.

```c++
std::sort(v.begin(), v.end(), std::greater<int>());
```

물론 `>` 연산자가 존재하는 타입들만 가능하다.

#### Partial Sort

`partial_sort` 함수는 아래와 같이 세 개의 인자를 갖는다.

```c++
std::partial(start, middle, end)
```

`[start, middle)` 개수의 원소들만 정렬하고 나머지 위치는 정렬되지 않은 상태로 남아있다.

만약 전체 원소의 개수가 `N` 개이고, 정렬하려는 원소의 개수가 `M` 개라고 할 때, 시간복잡도는 `O(NlogM)` 이다.
그렇기에 예를 들어 100명 중, 상위 10명의 학생만 성적순으로 보고 싶다면 `partial_sort` 를 사용하는 것이 효율적이다.

#### stable_sort

값이 같을 때, 기존의 자리를 보장해주는 정렬법이다.
그렇기에 `sort` 보다는 느리다.

`sort` 가 최악의 경우에도 `O(n log n)` 이 보장된다면, `stable_sort` 는 최악의 경우 `O(n (log n)^2)` 로 더 느리다.

그 외에도 아래와 같은 다양한 함수들이 정의되어 있다.

- `count` : 특정 원소의 개수를 구한다.
- `find` : 특정 원소의 처음 위치를 반환한다.
- `reverse` : 컨테이너의 원소들을 뒤집는다.
- `max_element, min_element` : 컨테이너의 최대, 최소 원소를 반환한다.
- `minmax_element` : 컨테이너의 최대, 최소 원소를 pair 형태로 반환한다.
- `swap, swap_range` : 해당 변수 값을 서로 바꿔준다. (swap_range는 특정 범위의 값들은 다른 연속된 메모리 공간의 값들과 바꿀 수 있다.)
- `iter_swap` : 특정 반복자의 값을 서로 바꿔준다.
- `copy` : 특정 범위의 값을 다른 곳에 복사한다.
- `unique` : 중복된 값을 뒤로 보내며 함수를 재정렬한다. erase와 같이 사용하면 중복된 원소들을 제거할 수 있다. 반환은 밀려난 원소의 시작점이다.
- `lower_bound, upper_bound` : 특정 값의 위치를 반환한다. (lower_bound는 특정 값 이상, upper_bound는 특정 값 초과)
- `equal_range` : 특정 값의 위치를 pair 형태로 반환한다. (lower_bound, upper_bound의 pair 형태)
- `remove` : 특정 값을 모두 지운다.
- `remove_if` : 특정 조건을 만족하는 값들을 지운다.

## Iterator

**반복자(Iterator)** 는 C++ 프로그램이 서로 다른 데이터 구조들이 균일한 방식으로 작업할 수 있도록 도와주는 포인터의 일반화이다.
또한 컨테이너와 알고리즘이 하나로 동작하게 묶어주는 인터페이스 역할을 한다.
알고리즘마다 다른 방식으로 컨테이너를 순회할 수 있기에 반복자에도 여러 종류가 있다.

- 반복자는 컨테이너 내부의 원소(객체)를 가리키고 접근할 수 있어야 한다.
- 반복자는 다음 원소로 이동하고 컨테이너의 모든 원소를 순회할 수 있어야 한다.

```cpp
contanier<T>::iterator it;
```

선언은 위와 같이 하며 순회를 위해 `begin()`과 `end()`는 모든 컨테이너가 가지고 있다.

- `begin()`: 첫 번째 원소를 가리키는 반복자를 반환
- `end()`: 마지막 원소의 다음을 가리키는 반복자를 반환

따라서 원소를 순회할 때와 비어있는지 확인할 때는 다음과 같이 구현할 수 있다.

```c++
for (it = container.begin(); it != container.end(); ++it) {
  // ...
}

bool empty = container.begin() == container.end();
bool empty = container.empty();
```

> 반복문에서 반복자를 증가시킬 때 후위 연산자보단 전위 연산자를 사용한다.
> 후위 연산자를 사용하면 반복자의 이전 값을 반환하기에 임시로 객체가 생겨 성능이 늦어진다.

### Iterator Categories

- 입력 반복자(input iterator)
  - 현 위치의 원소를 한 번만 읽을 수 있는 반복자(istream)
- 출력 반복자(output iterator)
  - 현 위치의 원소를 한 번만 쓸 수 있는 반복자(ostream)
- 순방향 반복자(forward iterator)
  - 입력, 출력 반복자 기능에 순방향으로 이동(++) 가능한 재할당될 수 있는 반복자
- 양방향 반복자(bidirectional iterator)
  - 순방향 반복자 기능에 역방향으로 이동(--) 가능한 반복자
  - `!=`, `==`, `++`, `--` 연산자를 사용할 수 있다.
  - `list`, `set`, `map` 등
- 임의 접근 반복자(random access iterator)
  - 양방향 반복자 기능에 임의 접근(`+`, `-`, `+=`, `-=`, `[]`, `<`, `>`, `<=`, `>=`, `==`, `!=`) 가능한 반복자
  - `vector`, `deque` 등

모든 컨테이너는 양방향 반복자 이상을 제공하며 배열 기반 컨테이너인 `vector`, `deque`는 임의 접근 반복자를 제공한다.

## References
- [42Seoul, C++ Module 08](https://cdn.intra.42.fr/pdf/pdf/102839/en.subject.pdf)
- [모두의 코드, C++ 레퍼런스 - STL 컨테이너](https://modoocode.com/174)
- [영화같이, [C++] Iterator에 대해서](https://cho001.tistory.com/193)
- [Microsoft Learn, C++ <Iterator>](https://learn.microsoft.com/ko-kr/cpp/standard-library/iterator?view=msvc-170)
- [모두의 코드, C++ <10 - 3. C++ STL - 알고리즘(algorithm)>](https://modoocode.com/225)
- [kth811, 6. c++ STL algorithm](https://velog.io/@kth811/6.-c-STL-algorithm)
