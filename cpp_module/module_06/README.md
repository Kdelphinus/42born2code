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
- 단, 기반 클래스에 virtual 함수가 정상 동작해야 함

```c++
class Base {};
class Derived : public Base {};

Base b; Base pb;
Derived d; Derived pd;

pb = dynamic_cast<Base*>(&b); // OK
pd = dynamic_cast<Derived*>(&d); // OK
pb = dynamic_cast<Base*>(&d); // OK: derived to base
pd = dynamic_cast<Derived*>(&b); // Error: base to derived
```



### static_cast
### const_cast
### reinterpret_cast

## 참고 문헌
- [42Seoul, C++ Module 06](https://cdn.intra.42.fr/pdf/pdf/100866/en.subject.pdf)
- [cplusplus.com](https://cplusplus.com/doc/oldtutorial/typecasting/)
- [즐거운인생 (미련없이 하자), 9. type casting](https://doitnow-man.tistory.com/entry/C-%EA%B0%9C%EB%B0%9C%EC%9E%90%EB%90%98%EA%B8%B0-8-type-casting-cast-operator)
- [C++ 캐스트 연산자](https://modoocode.com/224)
