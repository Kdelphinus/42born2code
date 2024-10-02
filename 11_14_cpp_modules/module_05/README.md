# C++ Module 05

## 개념

- `Repetition` : 반복문을 사용하여 특정 코드를 여러번 실행하는 것
    - `for`, `while`, `do-while`
    - `do-while` 은 일단 코드를 실행한 후에 조건을 확인하며 반복할 지 확인
    - 즉, `do-while` 은 조건과 관계없이 한 번은 코드가 실행된다는 특징이 있다.
    - ```c++
      do {
          // 반복 실행될 코드
      }  while (조건식);
      ```
- `Exceptions` : 예기치 않은 상황이나 오류를 처리하는 메커니즘
    - `try`, `catch`, `throw`
    - 예외를 발생시키는 코드 블록이 던져지면, 해당 예외를 처리하는 코드 블록에서 캐치된다.
    - 발생한 예외와 일치하는 `catch` 블록이 없으면 상위 블록으로 예외가 전달된다.
    - ```c++
      try {
          // 예외가 발생할 수 있는 코드
          if (조건) {
              throw 예외; // 예외 발생
          }
      }  catch (예외 타입) {
          // 예외를 처리하는 코드
      }  catch (다른 예외 타입) {
          // 다른 예외를 처리하는 코드
      }
      ```
- `Custom Exception`
    - ```c++
      class CustomException : public std::exception {
      public:
        virtual const char* what() const throw() {
            return "CustomException";
        }
      };
      ```
    - `std::exception` 을 상속받아 `what()` 함수를 오버라이딩하여 에러를 직접 정의할 수 있다.
    - 이때, `CustomException`들은 모두 `std::exception` 을 상속받으므로 `catch`에 `std::exception` 을 사용하면 모든 `CustomException` 을 처리할 수
      있다.
- `Unwind`
  - 예외가 발생하면, 해당 예외를 처리하는 코드 블록을 찾을 때까지 스택을 거슬러 올라가며 호출된 함수들을 모두 종료시킨다.
  - 이때, 수명이 끝난 객체들은 모두 소멸자가 호출된다.

## 주의 사항

### 기본 생성자

`Bureacrat` 클래스에서 기본 생성자는 나중에 이름을 바꿀 수 없기에 의미가 없다. 그렇지만 OCF 때문에 기본 생성자를 만들긴 해야 한다.
그래서 선언 후, private에 선언하는 방식이 조금 더 좋지 않을까 싶다.

### 내부 클래스

`Bureacrat`의 내부 클래스인 `GradeTooHighException`과 `GradeTooLowException`은 `Bureacrat`의 소멸자가 호출될 때 소멸되는 것이 맞다.
하지만 unwind 과정으로 처리될 때, 예외가 던져진 순간의 스택 상태로 돌아가기에 해당 예외 처리하는데 필요한 정보가 보존된다.

즉, 예외 처리 과정에선 별도의 매커니즘으로 인해 `Bureacrat`와 `GradeTooHighException`, `GradeTooLowException` 클래스는 독립적으로 소멸된다.

### ofstream

`ofstream` 생성자가 받는 변수 중 `const char *`를 제외한 나머지는 모두 C++98이 아니다.
`std::string`은 C++11이다.

## 참고 자료

- [42seoul, C++ Module 05](https://cdn.intra.42.fr/pdf/pdf/81249/en.subject.pdf)
- [Jseo Doodle, CPP Module 05](https://bigpel66.oopy.io/library/42/inner-circle/16)
- [cppreference, std::basic_ofstream<CharT,Traits>::basic_ofstream](https://en.cppreference.com/w/cpp/io/basic_ofstream/basic_ofstream)