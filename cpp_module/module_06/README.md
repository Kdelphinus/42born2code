# C++ Module 06

## C++ casts

### 묵시적 형 변환(Implicit conversion)
- 지원 범위: C, C++
- 컴파일 시, 묵시적으로 왼쪽 변수의 type으로 형 변환

```c++
double a = 3.14f;
int b;

b = a; // 묵시적 형 변환
std::cout << b << std::endl;
```

```shell
# 실행 결과
3
```

### 명시적 형 변환(Explicit conversion)
- 지원 범위: C, C++
- 개발자가 변환한 type으로 형 변환
- 함수의 인자와 매개변수의 type이 다를 때 사용
- void pointer를 사용해 인자를 넘긴 후, 다른 type으로 casting하여 사용

```c++
double a = 3.14f;
int b;

b = (int)a; // 명시적 형 변환
b = int(a); // 명시적 형 변환
std::cout << b << std::endl;
```

```shell
# 실행 결과
3
```

### dynamic_cast
- 지원 범위: C++
- 상속 관계에 있는 class 간의 형 변환
- 포인터나 레퍼런스 객체에만 사용 가능
- 관련되지 않은 클래스에 대한 포인터 사이에서도 NULL 포인터 캐스팅은 가능
- 모든 유형의 포인터를 void 포인터로 캐스팅할 수 있음

```c++
class Base {};
class Derived : public Base {};

Base base; Base p_base;
Derived derive; Derived p_derive;

p_base = dynamic_cast<Base*>(&base); // OK
p_derive = dynamic_cast<Derived*>(&derive); // OK
p_base = dynamic_cast<Base*>(&derive); // OK: derived to base
p_derive = dynamic_cast<Derived*>(&base); // Error: base to derived
```

- 단, 가상 함수가 있다면 Error 케이스 상황도 가능

### static_cast
- 지원: C++
- 

### const_cast
### reinterpret_cast

## 참고 문헌
- [42Seoul, C++ Module 06](https://cdn.intra.42.fr/pdf/pdf/100866/en.subject.pdf)
- [cplusplus.com](https://cplusplus.com/doc/oldtutorial/typecasting/)
- [즐거운인생 (미련없이 하자), 9. type casting](https://doitnow-man.tistory.com/entry/C-%EA%B0%9C%EB%B0%9C%EC%9E%90%EB%90%98%EA%B8%B0-8-type-casting-cast-operator)
- [C++ 캐스트 연산자](https://modoocode.com/224)
