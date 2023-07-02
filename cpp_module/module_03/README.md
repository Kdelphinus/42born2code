# C++ Module 03

## 개념
- `Inheritance` :  상속

## 문제

### ex00

- `ClapTrap` 클래스 구현

### ex01

- `ScavTrap` 클래스 구현
- 이때, `ClapTrap` 클래스를 상속 받음
- 이에 따라 `ClapTrap` 클래스의 `private` 변수들을 `protected` 변수들로 수정

### ex02

- `FragTrap` 클래스 구현
- 역시 `ClapTrap` 클래스 상속 받음

### ex03

- `DiamondTrap` 클래스 구현
- 상속받는 순서대로 생성자 호출
  - 따라서 여기선 `ClapTrap` -> `FragTrap` -> `ScavTrap` 순서
- 그렇기에 마지막 상속 클래스인 `ScavTrap` 속성으로 초기화되어있다.
- 과제에 따라 `FragTrap` 으로 변경할 것만 변경
- 또한 이는 다중 상속에 관한 문제에 대해 살펴본다. 
  - `FragTrap` 과 `ScavTrap` 이 모두 `ClapTrap`을 상속받기에 `DiamondTrap`이 충돌나지 않고 다중상속하기 위해선 각 클래스가 `ClapTrap`을 virtual로 상속받아야 한다.
  - 왜냐하면 각각의 클래스에서 자신의 기반 클래스를 상속받기에 `DiamondTrpa` 입장에선 어떤 `CrapTrap`을 상속받아야 할지 모르는 상황이 생기기 때문

## 참고 문헌
- [42seoul, C++ Module 03](https://cdn.intra.42.fr/pdf/pdf/82240/en.subject.pdf)
