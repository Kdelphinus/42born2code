# C++ Module 00

## 개념

- `Namespaces` : 어떤 정의된 객체에 대해 어디 소속인지 지정해주는 것
  - 같은 이름의 함수라도 어느 이름 공간에 위치하냐에 따라 기능이 다름
- `classes` : 객체의 설계도
- `member functions` : 클래스 상에 들어있는 함수들
- `stdio streams` : 표준 스트림은 유닉스와 그 계열에서 컴퓨터와 환경 사이에 미리 연결된 입출력 통로
  - STDIN, STDOUT, STDERR
- `initialization lists` : 생성자 호출과 동시에 멤버 변수들을 초기화해주는 방식
  - 좀 더 효율적(선언 후, 대입하는 것보다 선언하면서 대입하는게 동작이 적음)
  - 레퍼런스와 상수는 모두 생성과 동시에 초기화가 되어야 하기에 초기화 리스트가 필수
- `static`
  - 클래스 안에서 static 멤버 변수는 프로그램이 종료될 때 소멸
  - 클래스의 모든 객체들이 공유
- `const`
  - 함수 앞에 선언되면 이 함수는 객체들의 읽기만 수행됨을 의미
  - 변수 앞에 선언되면 이 변수는 읽기만 수행되며 바뀌지 않음


## 참고 문헌
- [42seoul, C++ Module 00](https://cdn.intra.42.fr/pdf/pdf/82228/en.subject.pdf)
- [위키백과, 표준 스트림](https://ko.wikipedia.org/wiki/%ED%91%9C%EC%A4%80_%EC%8A%A4%ED%8A%B8%EB%A6%BC)