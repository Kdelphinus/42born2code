# CPP Module 09

## Index

- [Subject](#subject)
	- [Module-specific rules](#module-specific-rules)
	- [ex00](#ex00)
	- [ex01](#ex01)
	- [ex02](#ex02)
- [주의할 점](#주의할-점)
- [References](#references)

## Subject

### Module-specific rules

- 이 모듈에선 반드시 표준 컨테이너를 사용해야 한다.
- 한 번 사용한 컨테이너는 다른 문제에서 사용할 수 없다.

> 문제를 풀기 전에 subject 전체를 읽는 것이 좋다.

> 두 개의 컨테이너를 사용해야 하는 ex02를 제외하고 각 문제마다 적어도 한 개의 컨테이너를 사용해야 한다.

- 소스 파일을 컴파일 할 때, `-Wall -Wextra -Werror` 플래그를 사용해야 한다.
- 반드시 `c++` 을 사용해야 하며 relink 되어서는 안 된다.
- Makefile에는 적어도 $(NAME), all, clean, fclean, re 규칙이 있어야 한다.

### ex00

- files: Makefile, main.cpp, BitcoinExchange.{cpp, hpp}

- 특정 날짜에 특정 비트코인의 가치를 출력하는 프로그램 만들기
- 이 프로그램은 csv 형식의 데이터베이스를 사용해야 하며, 데이터베이스는 subject와 함께 제공된다.
- 이 프로그램은 평가할 가격/날짜가 저장된 또 다른 데이터베이스를 받는다.
- 이 프로그램은 아래와 같은 규칙을 지켜야 한다.
  - 이 프로그램 이름은 `btc` 이다.
  - 이 프로그램은 반드시 파일을 인자로 받아야 한다.
  - 인자로 받는 파일의 각 줄은 반드시 **data | value** 형태로 되어있어야 한다.
  - 날짜는 **Year-Month-Day** 형태로 되어있어야 한다.
  - 유효한 값은 0과 1000 사이에 소수와 양의 정수이다.

> 이 연습문제의 유효성을 확인하려면 코드에 하나 이상의 컨테이너를 사용해야 한다.
> 또한 가능한 오류를 적절한 오류 메세지로 처리해야 한다.

- 아래는 `input.txt` 파일의 예시이다.

```txt
data | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
```

- 이 프로그램은 input 파일 안에 있는 값을 사용해야 한다.
- 표준 출력에는 데이터베이스에 표시된 날짜에 따라 값에 환율을 곱한 결과가 표시되어야 한다.

> input 에 사용된 날짜가 데이터베이스에 존재하지 않는 경우, 데이터베이스에 포함된 가장 가까운 날짜를 사용해야 한다.
> 미래가 아니라 과거 날짜를 사용해야 한다. 

- 아래는 프로그램 출력 예시이다.

```shell
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
```

> **경고** : 이 연습은 검증하는 데 사용하는 컨테이너는 이 모듈의 나머지 부분에서는 더 이상 사용할 수 없다.

### ex01

- files: Makefile, main.cpp, RPN.{cpp, hpp}

- 이 프로그램은 아래와 같은 조건을 만족해야 한다.
  - 이 프로그램 이름은 `RPN` 이다.
  - 이 프로그램은 폴란드어 수학식을 인수로 사용해야 한다.
  - 이 연산에서 사용되고 인수로 전달되는 숫자는 항상 10보다 작다. 물론 계산 중 값과 결과는 이 규칙을 고려하지 않는다.
  - 프로그램에서 이 식을 처리하고 표준 출력에 정확한 결과를 출력해야 한다.
  - 프로그램을 실행하는 동안 오류가 발생하면 표준 출력에 오류 메세지가 표시되어야 한다.
  - 프로그램에서 "+-/*" 토큰으로 작업을 처리할 수 있어야 한다.

> 이 연습의 유효성을 확인하려면 코드에 하나 이상의 컨테이너를 사용해야 한다.

> 대괄호나 십진수를 관리할 필요는 없다.

- 아래는 프로그램 출력 예시이다.

```shell
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
```

> **경고** : 

### ex02

## 주의할 점

## References

- [42Seoul, cpp module 09](./en.subject.pdf)