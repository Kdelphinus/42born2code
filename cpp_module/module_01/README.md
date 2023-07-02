# C++ Module 01

## 개념
- `Memory allocation` : 메모리 할당, c++은 new
- `pointers to members` : 포인터인 멤버(by jaekkang)
- `refernce` : 참조
- `switch statement` : switch 써 봐

## 문제

### ex00

- 할당한 객체는 `delete` 로 해제해야 한다.
- 기본 생성자는 생성된 함수가 종료될 때, 자동적으로 소멸자를 호출한다.

### ex01

- 할당한 것은 함수가 종료되도 소멸자가 호출되지 않는다.
- 그렇기에 delete를 해야만 한다.

### ex02

- 포인터와 레퍼런스의 차이
- 레퍼런스는 사실상 그 대상과 동일하다.
- 대상을 나타내는 또 다른 별명느낌
- 컴파일 과정에서 원본 데이터로 치환되서 사용됨

### ex03

- 포인터와 레퍼런스의 차이 2
- 클래스가 레퍼런스를 가지고 있다면 반드시 생성과 동시에 초기화를 해주어야 한다.
- 그렇기에 `HumanA` 클래스는 반드시 `Weapon` 클래스를 입력받아 동시에 생성되어야 한다.

### ex04

- sed 만들기
- string.substr(pos, count): pos 위치부터 count만큼의 문자열 반환

### ex05

- 멤버 함수들의 포인터로 complain 구현
- if/else 를 사용하면 안 되기에 if만 사용
- 멤버 함수들의 포인터로 실행

### ex06

- switch 문에서 `fallthrough` 문제
  - 조건에 맞는 동작 진행 후, return이나 break를 하지 않으면 그 후 조건들도 모두 수행하는 현상
- 이를 일부러 수행하기 위해선 fallthrough를 명시적으로 선언해야 함
- c++98에서 가능한 방법은 gcc에 플래그를 주거나(-Wno-implicit-fallthrough) `__attribute((fallthrough))` 를 명시적으로 선언하는 것이다.
- c++17부터는 `[[fallthrough]]` 를 사용할 수 있다.

## 참고 문헌
- [42seoul, C++ Module 01](https://cdn.intra.42.fr/pdf/pdf/82232/en.subject.pdf)
- [팔만코딩경, switch case에서의 명시적 fallthrough](https://80000coding.oopy.io/e570df15-29ef-4642-9045-4f72795785e9)