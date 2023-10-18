# C++ Module 06

## Index

- [C++ casts](#c-casts)
  - [dynamic_cast](#dynamiccast)
  - [static_cast](#staticcast)
  - [reinterpret_cast](#reinterpretcast)
  - [const_cast](#constcast)
- [static member variable](#static-member-variable)
- [Serialization](#serialization)
- [Pseudo Literals](#pseudo-literals)
- [Subject](#subject)
  - [ex00](#ex00)
  - [ex01](#ex01)
  - [ex02](#ex02)
- [참고 문헌](#참고-문헌)

## C++ casts

### dynamic_cast

- 지원 범위: C++
- 안전한 다운캐스팅에 사용
- 쉽게 말해 부모 클래스 포인터 -> 자식 클래스 포인터로 캐스팅(이때, 부모 클래스 포인터가 실제 무엇을 가리키고 있는 지가 중요)
- 반환값
    - 성공: new_type의 value
    - 실패
        - type이 pointer: nullptr
        - type이 reference: bad_cast(exception으로 처리)

#### 예시 1) 다운 캐스팅 오류

```c++
#include <iostream>
using namespace std;
class Blog
{
public:
    Blog() { cout << "Blog()\n"; };
    virtual ~Blog() { cout << "~Blog()\n"; };
 
    void Show()
    {
        cout << "This is Blog Class\n";
    }
};
 
class Tistory : public Blog
{
public:
    Tistory() { cout << "Tistory()\n"; };
    virtual ~Tistory() { cout << "~Tistory()\n"; };
 
    void Show()
    {
        cout << "This is Tistory Class\n";
    }
};
 
int main(void)
{
    Blog* pBlog = new Blog();
 
    //출력됩니다.
    pBlog->Show();
 
    Tistory* pTistory = dynamic_cast<Tistory*>(pBlog);
    if (pTistory == nullptr)
    {
        //티스토리 클래스의 포인터가 nullptr이 나올떄.
        cout << "Runtime Error\n";
    }
    else
    {
        pTistory->Show();
    }
    
    delete pBlog;
    system("pause");
    return 0;
}
```

```shell
# 실행 결과
Blog()
This is Blog Class
Runtime Error
~Blog()
```

`new Blog()`를 통해서 생성되었기에 `Tistory` 생성자는 호출되지 않았다. 그렇기에 캐스팅이 불가하다.

#### 예제 2) 다운 캐스팅 성공

```c++
#include <iostream>
using namespace std;
class Blog
{
public:
    Blog() { cout << "Blog()\n"; };
    virtual ~Blog() { cout << "~Blog()\n"; };
 
    void Show()
    {
        cout << "This is Blog Class\n";
    }
};
 
class Tistory : public Blog
{
public:
    Tistory() { cout << "Tistory()\n"; };
    virtual ~Tistory() { cout << "~Tistory()\n"; };
 
    void Show()
    {
        cout << "This is Tistory Class\n";
    }
};
 
int main(void)
{
    Blog* pBlog = new Tistory();
 
    //출력됩니다.
    pBlog->Show();
 
    Tistory* pTistory = dynamic_cast<Tistory*>(pBlog);
    if (pTistory == nullptr)
    {
        //티스토리 클래스의 포인터가 nullptr이 나올떄.
        cout << "Runtime Error\n";
    }
    else
    {
        pTistory->Show();
    }
    
    delete pBlog;
    system("pause");
    return 0;
}
```

```shell
# 실행 결과
Blog()
Tistory()
This is Blog Class
This is Tistory Class
~Tistory()
~Blog()
```

- 예제 1과 바뀐 거는 `Blog* pBlog = new Tistory()` 하나 뿐이다.
- `pBlog->Show()`에서 `pBlog`는 `Tistory`를 가리키고 있지만, `virtual`로 선언되지 않았기에 `Blog`의 `Show()`를 호출한다.

#### 예제 3) 업 캐스팅

```c++
#include <iostream>
using namespace std;
class Blog
{
public:
    Blog() { cout << "Blog()\n"; };
    virtual ~Blog() { cout << "~Blog()\n"; };
 
    void Show()
    {
        cout << "This is Blog Class\n";
    }
};
 
class Tistory : public Blog
{
public:
    Tistory() { cout << "Tistory()\n"; };
    virtual ~Tistory() { cout << "~Tistory()\n"; };
 
    void Show()
    {
        cout << "This is Tistory Class\n";
    }
};
 
int main(void)
{
    Tistory* pTistory = new Tistory();
 
    //출력됩니다.
    pTistory->Show();
 
    Blog* pBlog = static_cast<Blog*>(pTistory);
   pBlog->Show();
    
    delete pTistory;
    system("pause");
    return 0;
}
```

```shell
# 실행 결과
Blog()
Tistory()
This is Tistory Class
This is Blog Class
~Tistory()
~Blog()
```

- 부모로 업 캐스팅을 할 때는 `static_cast`를 사용한다.

### static_cast

- 지원: C++
- 논리적으로 변환 가능한 타입을 변환한다.
- compile 타임에 형변환에 대한 타입 오류를 잡아준다.
- 실수와 정수, 열거형과 정수형, 실수와 실수 사이의 변환 등을 허용한다.
- 포인터 타입을 다른 것으로 변환 하는 것은 허용되지 않는다. (compile error)
- 하지만 상속 관계에 있는 포인터끼리 변환은 가능하다.
    - static_cast<Derived*>(base_ptr) (downcast) 시에는 unsafe하게 동작한다. (safe하게 사용하려면 dynamic_cast 사용)

### reinterpret_cast

- 지원 범위: C++
- 임의의 포인터 타입끼리 변환
- 정수형을 포인터로 바꿀 수도 있음(이때 정수값이 포인터의 절대 주소로 들어가게 된다)
- `reinterpret_cast<type>(expression)` 형태에서 expression을 type의 비트 단위로 바꾸는 것이다.
- 하지만 const 변수들은 사용 불가

```c++
#include<iostream>
#include<cstdio>
using namespace std;
 
struct Cube{
    int a;
};
 
int main(void){
    int a = 71234561;
 
    //1. int -> int * 로 타입캐스팅
    //변수 a의 값을 절대주소로 받는 포인터 ptr1
    //이 경우에는 주소 111번지를 가리키고 있는 poiner가 됩니다.
    //111번지가 어느곳을 가리킬지 모르기 때문에 위험합니다.
    int *ptr1;
    ptr1 = reinterpret_cast<int *>(a);
 
    
    //2. int * -> char * 로 타입캐스팅
    //컴파일러에 따라 다르게 나옵니다.
    int *ptr2 = &a;
    char * c;
    c = reinterpret_cast<char *>(ptr2);
    cout << "2. int* -> char * (cout) : " << *c << endl;
    printf("2. int* -> char * (printf int type) : %d\n", *c);
 
    
    //3. struct 내의 첫번째 int -> int *
    //struct cube에는 int 형 변수 하나만 존재 하므로,
    //ptr3은 int a변수의 시작점을 잘 가리키고 있습니다
    Cube cb;
    cb.a = 20;
    int * ptr3;
    ptr3 = reinterpret_cast<int *>(&cb);
    cout << "3. struct -> int * : " << *ptr3 << endl;
 
    return 0;
}
```

```shell
# 실행 결과
2. int* -> char * (cout) : 
2. int* -> char * (printf int type) : 1
3. struct -> int * : 20
```

### const_cast

- 지원 범위: C++
- 포인터나 레퍼런스의 const를 잠깐 제거해주는데 사용
- 또한 [volatile 속성](https://4369.tistory.com/entry/volatile)을 잠깐 제거해주는데도 사용
- 함수 포인터에는 사용 불가

```c++
#include<iostream>
using namespace std;
 
int main(void){
    char str[] = "BlockDMask";
    const char * ptr = str;
    cout << "before : " << str << endl;
 
    //ptr[0] = 'Q'; ==> error
 
    char * c = const_cast<char *>(ptr);
    c[0] = 'Q';
    cout << "after : " << str << endl;
 
    return 0;
}
```

```shell
# 실행 결과
before : BlockDMask
after : QlockDMask
```

## static member variable

static 멤버 변수는 클래스의 모든 객체가 공유하는 변수이다.
그렇기에 static 멤버 변수는 클래스 자체에 속하고 객체를 생성하지 않아도 사용할 수 있다.

```c++
MyClass::static_member_variable = 42;
```

위와 같이 클래스 이름을 사용하여 접근할 수 있으며 클래스 내부에선 멤버 변수처럼 접근할 수 있다.

허나 이때, 초기화 과정이 필요한데 `main.cpp` 에 초기화 해줘야 한다. (꼭 여기에다 해야 한다는 근거는 없으나 경험이 있음)

```c++
#include <iostream>

class MyClass {
	public:
      static int static_member_variable;
};

int MyClass::static_member_variable = 42;

int main() {
	std::cout << MyClass::static_member_variable << std::endl;
	
	MyClass::static_member_variable = 21;
	std::cout << MyClass::static_member_variable << std::endl;
    return 0;
}
```

## Serialization

`Serialization(직렬화)`은 데이터 구조나 오브젝트 상태를 동일하거나 다른 컴퓨터 환경에 저장하고 나중에 재구성할 수 있는 포맷으로 변환하는 과정이다.
즉, **현재 데이터의 상태를 영속적으로 저장하거나 다른 환경으로 전달하기 위해 어떠한 정해진 포맷으로 변환하는 과정**을 말한다.

그리고 변환된 데이터를 다시 원래 데이터로 변환시키는 과정을 `Deserialization(역직렬화)`라고 한다.

대체로 바이트 형태로 데이터 변환(직렬화)와 그것을 다시 객체로 변환(역직렬화)하는 방법을 많이 사용한다.

## Pseudo Literals

- `inf` : 양의 무한대, 연산 결과가 무한대로 수렴하는 경우 이 값이 나타난다.
- `+inf` : 양의 무한대
- `-inf` : 음의 무한대
- `inff` : float형 양의 무한대
- `+inff` : float형 양의 무한대
- `-inff` : float형 음의 무한대
- `nan` : Not a Number, 연산 결과가 정의되지 않거나 부정확한 경우, 일반적으로 오류이다.
- `+nan` : 부호가 양수인 Not a Number
- `-nan` : 부호가 음수인 Not a Number
- `nanf` : float형인 Not a Number
- `+nanf` : 부호가 양수이고 float형인 Not a Number
- `-nanf` : 부호가 음수이고 float형인 Not a Number

> 이때, nan의 부호는 부동 소수점 숫자 부호에 따라 결정되며 부호 정보를 강조하고 싶을 때 사용된다.

## Subject

### ex00

- static class `ScalarConverter`를 만들어라.
    - `ScalarConverter`는 `char`, `int`, `float`, `double` 타입을 변환할 수 있다.
    - 일반적인 형식의 literal string을 매개변수로 받는 `convert` 메소드를 가지고 있어야 한다.
- 문자 매개변수를 제외하면 십진수 표기만 사용해야 한다.
- char 리터럴의 예: 'c', 'a', ...
    - 표시할 수 없는 문자를 입력값으로 사용할 수 없다.
    - 문자열로 변환할 때 표시할 수 없는 경우 정보 메세지를 출력한다.
- int 리터럴의 예: 42, 0, -9, ...
- float 리터럴의 예: 42.0f, 0.0f, -9.0f, ...
- double 리터럴의 예: 42.0, 0.0, -9.0, ...
- 의사 리터럴의 예: -inff, +inff, nanf, -inf, +inf, nan

- 클래스를 테스트 할 프로그램을 작성해야 한다.
    - 매개변수로 전달된 리터럴의 유형을 감지하고 실제 유형으로 변환한다.
    - 그리고 다른 세 가지 타입 유형으로 명시적이게 변한해야 한다.
    - 변환이 의미없거나 오버플로우가 발생하면 사용자에게 "impossible"을 출력한다.
    - 숫자 범위나 특별한 변수들을 처리하기 위해 필요한 헤더를 추가해야 한다.

```shell
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf   
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

### ex01

- 아래의 메소드들을 가지는 static class `Serializer`를 구성
  - `uintptr_t serialize(Data* ptr);` : pointer -> `uintptr_t`
  - `Data* deserialize(uintptr_t raw);` : `uintptr_t` -> pointer
- 멤버를 가지고 있는 `Data` 구조체를 생성
- `serialize`와 `deserialize` 함수를 이용해 `Data *` 를 `uintptr_t`로 변경했다가 복구하는 테스트를 작성

### ex02
- virtual 소멸자만 가지는 `Base` 클래스 생성
- `Base`를 public하게 상속받고 비어있는 `A`, `B`, `C` 클래스 생성
> 이때, 네 개의 클래스는 OCF를 지키지 않아도 된다.
- 아래 함수들을 구성
  - `Base *generate(void)`: `A`, `B`, `C` 중 하나를 `Base *` 타입으로 무작위 반환하는 함수
  - `void identify(Base* p)`: 입력 받은 클래스가 실제로 `A`, `B`, `C` 중 어떤 것인지 출력하는 함수
  - `void identify(Base& p)`
    - 입력 받은 클래스가 실제로 `A`, `B`, `C` 중 어떤 것인지 출력하는 함수
    - 이때, 이 함수 내에서 포인터 사용은 금지
- `typeinfo` 헤더는 금지

## 참고 문헌

- [42Seoul, C++ Module 06](en.subject.pdf)
- [cplusplus.com](https://cplusplus.com/doc/oldtutorial/typecasting/)
- [즐거운인생 (미련없이 하자), 9. type casting](https://doitnow-man.tistory.com/entry/C-%EA%B0%9C%EB%B0%9C%EC%9E%90%EB%90%98%EA%B8%B0-8-type-casting-cast-operator)
- [개발자 지망생, [C++] static_cast(타입캐스트 연산자)](https://blockdmask.tistory.com/236)
- [개발자 지망생, [C++] reinterpret_cast(타입캐스트 연산자)](https://blockdmask.tistory.com/242)
- [개발자 지망생, [C++] dynamic_cast(타입캐스트 연산자)](https://blockdmask.tistory.com/241)
- [HardCore in Programming, [C++] static 키워드 완벽 가이드](https://kukuta.tistory.com/434)
- [위키피디아, 직렬화](https://ko.wikipedia.org/wiki/%EC%A7%81%EB%A0%AC%ED%99%94)
- [해피쿠 블로그, [Java] 직렬화(Serialization)에 대해 알아보자](https://www.happykoo.net/@happykoo/posts/257)
- [우아한 기술블로그, 자바 직렬화, 그것이 알고싶다. 훑어보기편](https://techblog.woowahan.com/2550/)
