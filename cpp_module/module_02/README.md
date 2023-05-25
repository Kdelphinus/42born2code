# C++ Module 02

## 개념
- `Ad-hoc polymorphism` : 애드혹 다형성(임시 다형성)
  - 같은 이름의 함수를 매개 변수의 개수 또는 타입을 변경하여 여러 개의 함수가 서로 다르게 행동할 수 있도록 하는 성질
- `operator overloading` : 연산자 오버로딩
  - 사용하는 인자의 자료형에 따라 기존에 정의된 연산자가 아닌 새로 정의한 연산자를 사용하는 방법
- `Orthodox Canonical class form`
  - 사용하지 않더라도 아래의 4가지 규칙을 적용하여 규정대로 클래스를 작성하는 것
    - 디폴트 생성자(default constructor) : 지금까지 사용한 생성자
    - 복사 생성자(copy constructor) : 다른 객체의 값을 복사하여 초기화하는데 사용하는 생성자
    - 복사 대입 연산자(copy assignment operator) : 이미 생성된 같은 타입의 객체에 값을 복사할 때 사용
      - 따로 정의되지 않은 기본 복사 대입 연산자는 얕은 복사를 실행
    - 소멸자(destructor) : 소멸할 때, 호출되는 소멸자

## 참고 문헌
- [42seoul, C++ Module 02](https://cdn.intra.42.fr/pdf/pdf/82236/en.subject.pdf)
