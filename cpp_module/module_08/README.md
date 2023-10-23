# C++ Module 08

## Index

- [Subject](#Subject)
- [STL Containers](#stl-containers)
- [Iterators](#iterators)
- [Algorithms](#algorithms)
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
    - `addNumber`: 정수를 추가한다. 이때 추가된 정수는 `Span` 클래스에 저장된다. 만약 정수를 추가할 수 없다면, 예외를 던진다.
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

## Iterators


## Algorithms

## References
- [42Seoul, C++ Module 08](https://cdn.intra.42.fr/pdf/pdf/102839/en.subject.pdf)
- [모두의 코드, C++ 레퍼런스 - STL 컨테이너](https://modoocode.com/174)
- 
