# C++ Module 07

## Index

- [Subject](#subject)
- [C++ templates](#c-templates)
	- [함수 템플릿(Function Template)](#함수-템플릿function-template)
	- [함수 템플릿 특수화(Function Template Specialization)](#함수-템플릿-특수화function-template-specialization)
	- [클래스 템플릿(Class Template)](#클래스-템플릿class-template)
	- [클래스 템플릿 특수화(Class Template Specialization)](#클래스-템플릿-특수화class-template-specialization)
		- [암시적 특수화(Implicit Specialization)](#암시적-특수화implicit-specialization)
		- [명시적 특수화(Explicit Specialization)](#명시적-특수화explicit-specialization)
		- [부분 특수화(Partial Specialization)](#부분-특수화partial-specialization)
		- [중첩 클래스 템플릿(Nested Class Template)](#중첩-클래스-템플릿nested-class-template)
	- [typedef](#typedef)
- [참고 문헌](#참고-문헌)

## Subject

### ex00

- Files: Makefile, main.cpp, whatever.{h, hpp}
- 아래와 같은 함수 템플릿을 구현하기
	- `swap` : 주어진 두 인수의 값을 바꾼다. 아무것도 반환하지 않는다.
	- `min` : 주어진 두 인수 중 작은 값을 반환한다. 두 값이 같으면 두 번째 값을 반환한다.
	- `max` : 주어진 두 인수 중 큰 값을 반환한다. 두 값이 같으면 두 번째 값을 반환한다.
- 이 함수들은 어떤 형식의 인수 T와도 함께 호출될 수 있다.
- 유일한 조건은 두 인수가 동일한 타입을 가져야 하고 모든 비교 연산자를 지원해야 한다는 것이다.

> 템플릿은 반드시 헤더 파일에 정의되어 있어야 한다.

```c++
int main() {
  int a = 2;
  int b = 3;
  
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
  std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
  
  std::string c = "chaine1";
  std::string d = "chaine2";
  
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
  std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
  
  return 0;
}
```

```shell
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

### ex01

- Files: Makefile, iter.{h, cpp}, main.cpp
- 3개의 매개변수를 사용하고 아무것도 반환하지 않는 함수 템플릿 `iter`를 구현하기
	- 첫 번째 매개변수는 배열의 주소이다.
	- 두 번째 매개변수는 배열의 길이이다.
	- 세 번째 매개변수는 배열의 모든 요소를 호출하는 함수이다.
- 테스트가 포함된 main.cpp 파일을 제출하고 테스트를 실행할 수 있는 충분한 코드를 제공해야 한다.
- `iter` 함수 템플릿은 배열 형식에 관계없이 작동해야 한다.
- 세 번째 매개변수는 인스턴스화 함수 템플릿이 될 수 있다.

### ex02

- Files: Makefile, Array.{h, cpp}, main.cpp (+ Array.tpp)
- T 타입의 요소를 포함하고 다음 동작과 함수가 있는 클래스 템플릿 `Array`를 구현한다.
	- 매개변수가 없을 때: 빈 배열을 만든다.
	- `unsigned int n`를 매개변수로 할 때: 초기화된 n개 요소의 배열을 만든다.
  > TIP: `int * a = new int();` 를 컴파일하고 `*a`를 확인해볼 것
	- 복사 및 할당 연산자: deepcopy(모두 복사 후, 원래 배열과 복사된 배열 중 하나를 수정해도 다른 배열에 영향을 미치지 않음)
	- 메모리를 할당하려면 `new[]` 연산자를 사용해야 한다. 미리 메모리를 할당하는 것은 금지된다. 또한 할당되지 않은 메모리에 접근하면 안 된다.
	- 요소들은 `[]` 연산자를 사용해 접근할 수 있어야 한다.
	- `[]` 연산자로 접근할 때, 인덱스를 벗어나면 `std::exception`을 `throw` 한다.
	- 멤버 함수 `size()`는 배열의 요소 개수를 반환한다. 이 멤버 함수는 파라미터가 필요없고 현재 인스턴스를 수정해선 안 된다.
- 테스트가 포함된 main.cpp로 테스트하고 함께 제출한다.

## C++ templates

- `template`은 함수나 클래스를 개별적으로 다시 작성하지 않아도, 여러 자료 형으로 사용할 수 있도록 만들어 놓은 틀이다.
- 크게 함수 템플릿과 클래스 템플릿으로 나뉜다.

### 함수 템플릿(Function Template)

- 함수의 기능은 명확하지만, 자료형을 모호하게 두는 것

#### 예시1) sum 함수

- C++은 오버로딩에 의해 함수 이름이 같아도 된다.
- 그렇기에 만약 템플릿이 없다면 `int`와 `double` 자료형을 각각 받는 함수를 만들어야 한다.

```c++
int sum(int a, int b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}
```

- 하지만 템플릿을 사용하면 아래와 같이 하나의 함수로 표현할 수 있다.

```c++
template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {
    std::cout << sum<int>(1, 2) << std::endl;
    std::cout << sum<double>(1.1, 2.2) << std::endl;
}
```

#### 예시2) 타입이 다른 두 개의 인자를 받는 경우

```c++
// template <class T1, class T2> 모두 가능
template <typenam T1, typename T2>
void print(T1 a, T2 b) {
std::cout << a << ", " << b << std::endl;
}

int main() {
print("ok", 1);
print(1, 2.2);
print(1.1, 2);
}
```

- 템플릿이 사용하는 변수가 2개 이상일 땐, 함수이름 뒤에 <>을 사용하지 않고 컴파일러가 스스로 자료형을 판단한다.

### 함수 템플릿 특수화(Function Template Specialization)

- 템플릿 사용 중, 특수한 자료형에 대해서 다른 처리를 하고 싶을 때 사용한다.
- 아래와 같이 템플릿이 정의되어 있을 때, 재정의하고 싶은 데이터 타입에 대해서만 특수화를 해주면 된다.

```c++
template <typename T>
T sum(T a, T b) {
	return a + b;
}

template <>
char* sum(char* a, char* b) {
	char* result = "[char*] 문자열은 더할 수 없습니다.";
	return result;
}

template <>
const char* sum(const char* a, const char* b) {
	const char* result = "[const char*] 문자열은 더할 수 없습니다.";
	return result;
}
``` 

### 클래스 템플릿(Class Template)

- 클래스 템플릿은 클래스의 일반화된 선언을 의미한다.
- 즉, 클래스 템플릿에 전달되는 템플릿 인수에 따라 별도의 클래스를 만들 수 있다.
- 예시

<details>
<summary>예시 코드</summary>

```c++
#include <iostream>

tmplate <typename T>
class Data {
	private:
		T _data;
	public:
		Data(T dt);
		T get_data();
}

template <typename T>
Data<T>::Data(T dt) {
	_data = dt;
}

template <typename T>
T Data<T>::get_data() {
	return _data;
}

int main() {
	Data<string> str_data("클래스 템플릿");
    Data<int> int_data(12);
    
    std::cout << "str_data : " << str_data.get_data() << std::endl;
    std::cout << "int_data : " << int_data.get_data() << std::endl;
    return 0;
}
```

```shell
str_data : 클래스 템플릿
int_data : 12
```

</details>

#### 특징

- 하나 이상의 템플릿 인자를 가지는 클래스 템플릿을 선언할 수 있다.

```c++
template <typename T1, int i>
class X {
	...  
};
```

- 클래스 템플릿에 디폴트 템플릿 인수를 명시할 수 있다.

```c++
template <typename T1 = int, typename T2 = double>
class X {
	...  
};
```

- 클래스 템플릿을 기반 클래스로 하여 상속할 수 있다.

```c++
template <typename T>
class Y : public X<T> {
	...  
};
```

### 클래스 템플릿 특수화(Class Template Specialization)

#### 암시적 특수화(Implicit Specialization)

- 클래스 템플릿이 각각의 타입에 대해 처음으로 호출될 때, 컴파일러는 해당 타입의 인스턴스를 생성하고 이는 해당 타입에 대한 특수화된 템플릿 함수이다.
- 따라서 해당 인스턴스는 함수 템플릿에 해당 타입이 사용될 때마다 호출된다.

#### 명시적 특수화(Explicit Specialization)

- 특정 타입이나 값의 템플릿 인수에 대해 특수화하는 것이다.
- 특수화를 명시하면 해당 타입에 대한 특별한 동작을 정의할 수 있다.
- 컴파일러가 전달된 인수와 정확히 대응하는 특수화된 정의를 발견하면, 더는 다른 템플릿을 찾지 않고 해당 정의를 사용한다.

- 예시: double 형에 대한 특수화를 추가

<details>
<summary>예시 코드</summary>

```c++
#include <iostream>

tmplate <typename T>
class Data {
	private:
		T _data;
	public:
		Data(T dt);
		T get_data();
}

template <>
class Data<double> {
	private:
		double _data;
	public:
		Data(double dt);
		double get_data(); {
		  std::cout << "double 타입의 특수화" << std::endl;
		  return _data;
		}
}

template <typename T>
Data<T>::Data(T dt) {
	_data = dt;
}

template <typename T>
T Data<T>::get_data() {
	return _data;
}

int main() {
	Data<string> str_data("클래스 템플릿");
    Data<double> double_data(12.3);
    
    std::cout << "str_data : " << str_data.get_data() << std::endl;
    std::cout << "double_data : " << double_data.get_data() << std::endl;
    return 0;
}
```

```shell
str_data : 클래스 템플릿
double 타입의 특수화
double_data : 12.3
```

</details>

#### 부분 특수화(Partial Specialization)

- 템플릿 인수가 2개 이상이면서, 그 중 일부만 특수화를 해야할 때는 부분 특수화를 사용한다.
- 예시)

```c++
template <typename T1, typename T2>
class X {...};
```

- 템플릿 인수가 2개인 위의 템플릿 클래스 X를 double형에 대해 부분 특수화를 하면 다음과 같다.

```c++
template <typename T1>
class X<T1, double> {...};
```

- 모든 템플릿 인수를 특수화하게 되면, 명시적 특수화가 된다.

```c++
template <>
class X<int, double> {...};
```

#### 중첩 클래스 템플릿(Nested Class Template)

- 클래스 템플릿 내부에 클래스 템플릿을 정의할 수 있으며 이를 멤버 템플릿이라고 한다.
- 그리고 멤버 템플릿 중 클래스 템플릿을 중첩 클래스 템플릿이라고 한다.
- 중첩 클래스 템플릿은 바깥쪽 클래스 범위 내에서 클래스 템플릿으로 선언되며, 정의는 바깥쪽 클래스의 범위 내에서 뿐만 아니라 범위 밖에서도 가능하다.
- 예시)

```c++
template <typename T>
class X {
  template <typename U>
  class Y {
	...
  };
  ...
};

template <typename T>
template <typename U>
X<T>::Y<U>::Y() {...}
```

- 위와 같이 바깥쪽 클래스인 `X` 외부에 중첩 클래스 템플릿 `Y`를 정의하면, 클래스 템플릿 인수와 멤버 템플릿의 템플릿 인수 모두 앞에 명시되어야 한다.

### typedef

C++11부터는 `typedef` 키워드를 사용해 템플릿 특수화를 위한 새로운 이름을 선언할 수 있다.

```c++
typedef X<double, 3.14> DoubleX;
DoubleX x;
```

## 참고 문헌

- [blockdmask, [C++] 템플릿에 관하여 1 (템플릿이란, 함수 템플릿)](https://blockdmask.tistory.com/43)
- [octo__, [C++] 클래스 템플릿(class template)](https://velog.io/@octo__/C-클래스-템플릿class-template)