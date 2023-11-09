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

- `reinterpret_cast`는 `reinterpret_cast` 로 변환된 것을 다시 캐스팅하는 것 이외의 다른 용도로는 안전하게 사용할 수 없다.
- `reinterpret_cast`는 실제 사용은 아래와 같이 두 개의 고유 값이 비슷하지 않은 인덱스로 끝나지 않도록 인덱스를 매핑하는 해시 함수에서 사용된다.

> 무슨 코드인지 나도 이해 아직 못 함

```c++
#include <iostream>
using namespace std;

// Returns a hash code based on an address
unsigned short Hash( void *p ) {
   unsigned int val = reinterpret_cast<unsigned int>( p );
   return ( unsigned short )( val ^ (val >> 16));
}

using namespace std;
int main() {
   int a[20];
   for ( int i = 0; i < 20; i++ )
      cout << Hash( a + i ) << endl;
}
```

```shell
64641
64645
64889
64893
64881
64885
64873
64877
64865
64869
64857
64861
64849
64853
64841
64845
64833
64837
64825
64829
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

허나 이때, 초기화 과정이 필요하다.

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

## std::numeric_limits

`std::numeric_limits`는 템플릿 클래스로서, 특정 타입의 수치적 특성을 제공하는 클래스 템플릿으로 `<limits>` 헤더에 정의되어 있다.

```c++
template <class T> class numeric_limits;
```

클래스는 위와 같이 정의 되어 있으며 안에는 다양한 멤버 변수가 정의되어 있다.

여기선 `min()`, `max()`를 사용해서 각 자료형의 범위를 확인했는데 각 타입당 반환값은 다음과 같다.

| type   | min()        | max()        |
|:-------|:-------------|:-------------|
| char   | -128         | 127          |
| int    | -2147483648  | 2147483647   |
| float  | 1.17549e-38  | 3.40282e+38  |
| double | 2.22507e-308 | 1.79769e+308 |

이때, `float`과 `double` 자료형의 `min()`함수가 우리가 생각하는 최솟값이 아니라 `denormalized number`이다.

> ### denormalized number
>
> 비정규화 값은 가장 작은 일반 숫자보다 더 작은 0이 아닌 값, 즉 표현할 수 있는 0과 가장 가까운 값을 말한다.
> 비정규화 값은 부동소수점 연산에서 0 주위의 언더플로 차이를 채워준다.

따라서 범위로 사용하기엔 부적절하다. 또한 우리가 생각하는 최솟값을 `lowest()`라는 함수로 구할 수 있으나 `c++11`에 도입되었다.
그렇기에 `float`과 `double`은 `max()` 값에 -를 붙여서 사용하였다.

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

## 테스트 전 확인할 것

### 공통

- `static class` 에 대한 정의는 평가표에 의하면 모든 멤버가 `static` 인 클래스를 의미한다.

### ex00

- 나는 인식한 타입을 먼저 바꾸고 그 타입이 변환 불가하면 다 impossible로 출력했다.

> You have to first detect the type of the literal passed as parameter, convert it from string to its actual type, then
> convert it explicitly to the three other data types. Lastly, display the results as shown below.
> If a conversion does not make any sense or overflows, display a message to inform the user that the type conversion is
> impossible. Include any header you need in order to handle numeric limits and special values.

- float과 double에 `std::fixed` 를 사용하여 소수점을 고정했다. 이에 따라 값이 매우 부정확하다.
- float의 경우 int 범위를 간신히 넘어갔을 때, 구분하지 못하는 경우가 많다.
- 하지만 위 규칙은 인식된 타입을 변환할 때만 적용하고 그 외 세가지 타입 변환 시에는 `static_cast` 로 명시적 변환

- float과 double의 경우, 범위를 벗어나면 atof 상에서 inf로 변환된다.

### ex02

- seed를 설정하는 `std::srand(std::time(0))` 를 한 번만 선언해주어야 한다. 함수를 호출할 때마다 선언하면 같은 값만 출력된다.

## 참고 문헌

- [42Seoul, C++ Module 06](en.subject.pdf)
- [cplusplus.com](https://cplusplus.com/doc/oldtutorial/typecasting/)
- [즐거운인생 (미련없이 하자), 9. type casting](https://doitnow-man.tistory.com/entry/C-%EA%B0%9C%EB%B0%9C%EC%9E%90%EB%90%98%EA%B8%B0-8-type-casting-cast-operator)
- [개발자 지망생, [C++] static_cast(타입캐스트 연산자)](https://blockdmask.tistory.com/236)
- [개발자 지망생, [C++] reinterpret_cast(타입캐스트 연산자)](https://blockdmask.tistory.com/242)
- [개발자 지망생, [C++] dynamic_cast(타입캐스트 연산자)](https://blockdmask.tistory.com/241)
- [HardCore in Programming, [C++] static 키워드 완벽 가이드](https://kukuta.tistory.com/434)
- [위키백과, 직렬화](https://ko.wikipedia.org/wiki/%EC%A7%81%EB%A0%AC%ED%99%94)
- [해피쿠 블로그, [Java] 직렬화(Serialization)에 대해 알아보자](https://www.happykoo.net/@happykoo/posts/257)
- [우아한 기술블로그, 자바 직렬화, 그것이 알고싶다. 훑어보기편](https://techblog.woowahan.com/2550/)
- [위키백과, 비정규 값](https://ko.wikipedia.org/wiki/비정규_값)
- [cppreference, std::numeric_limits](https://en.cppreference.com/w/cpp/types/numeric_limits)
- [Microsoft, reinterpret_cast 연산자](https://learn.microsoft.com/ko-kr/cpp/cpp/reinterpret-cast-operator?view=msvc-170)
