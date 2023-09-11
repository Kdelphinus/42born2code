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
- 안전한 다운캐스팅에 사용
- 쉽게 말해 부모 클래스 포인터 -> 자식 클래스 포인터로 캐스팅(이때, 부모 클래스 포인터가 실제 무엇을 가리키고 있는 지가 중요)
- 반환값
  - 성공: new_type의 value
  - 실패
    - type이 pointer: nullptr
    - type이 reference: bad_cast(exception으로 처리)

- 예시 1) 다운 캐스팅 오류
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

- 예제 2) 다운 캐스팅 성공
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

- 예제 3) 업 캐스팅
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

## 참고 문헌
- [42Seoul, C++ Module 06](en.subject.pdf)
- [cplusplus.com](https://cplusplus.com/doc/oldtutorial/typecasting/)
- [즐거운인생 (미련없이 하자), 9. type casting](https://doitnow-man.tistory.com/entry/C-%EA%B0%9C%EB%B0%9C%EC%9E%90%EB%90%98%EA%B8%B0-8-type-casting-cast-operator)
- [개발자 지망생, [C++] static_cast(타입캐스트 연산자)](https://blockdmask.tistory.com/236)
- [개발자 지망생, [C++] reinterpret_cast(타입캐스트 연산자)](https://blockdmask.tistory.com/242)
- [개발자 지망생, [C++] dynamic_cast(타입캐스트 연산자)](https://blockdmask.tistory.com/241)
