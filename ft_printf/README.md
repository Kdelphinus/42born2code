# **ft_printf**

# 0. 개념

## 0.1 가변인자

가변인자란 인자들의 개수와 자료형이 미리 정해져 있지 않은 인자들을 의미한다. 
자주 사용하는 printf 함수 역시 가변인자를 사용하는데 printf의 프로토타입은 다음과 같다.

```int   printf(const char *format, ...)```

여기서 ```...```이 인수의 개수와 자료형을 점검하지 않도록 만들어 가변 인수를 사용하게 만든다. 이때 ```...``` 뒤에 다른 매개변수를 지정할 수는 없다.  
  
### 0.1.1 가변인자 처리 매크로
가변인자들을 처리하는 va_list, va_start, va_arg, va_end, va_copy 등의 자료형과 매크로는 ```stdarg.h``` 헤더 파일에 정의되어 있다.

간단하게 살펴보면 다음과 같다. 
- va_list: 가변 인자 목록으로 가번 인자의 메모리 주소를 저장하는 포인터
- va_start: 가변 인자를 가져올 수 있도록 포인터를 설정
- va_arg: 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옴
- va_end: 가변 인자 처리가 끝났을 때, 포인터를 NULL로 초기화
- va_copy: 가변 인자의 포인터를 특정 가변 인자의 포인터로 복사

#### 0.1.1.1 va_list
```
#if defined __GNUC__ && __GNUC__ >= 3
typedef __builtin_va_list va_list;
#else
typedef char* va_list;
#endif
```
va_list는 가변 인수들에 대한 정보를 hold하기 위한 타입이다. 1바이트 단위로 이동하기 위해서 va_list의 실제 타입은 char *로 사용되며 이는 va_arg의 포인터 연산에서 사용된다. 

GNUC가 정의되어 있고 main 버전이 3이상이라면 gcc컴파일러 내부에 정의된 자체 va_list를 사용하며 그렇지 않는 경우는 char *를 사용한다.

>__GNUC__는 GNU 컴파일러의 main 버전을 의미하며 우리가 사용하는 mac 상에선 4로 정의되어 있다. 이 외에도 __GNUC__MINOR__와 __GNUC__PATCHLEVEL__ 등, minor 버전과 패치 수준 역시 상수로 정의되어 있다. 
  
> 흔히 해당 자료형의 변수명을 ```ap``` 로 많이 사용하는데 이는 **arguments pointer** 를 의미한다.

#### 0.1.1.2 va_start
```
// GNU_C >= 3
#define va_start(ap, pN)	\
	((ap) = ((va_list) __builtin_next_arg(pN)))

// ! (GNUC >= 3)
#define va_start(ap, pN)	\
	((ap) = ((va_list) (&pN) + __va_argsiz(pN)))
```
va_start는 va_list의 값을 가변인자의 첫 번째 매개변수의 값으로 초기화시킨다. 
  
매크로 함수의 인자로 들어오는 pN은 함수의 가변 인자 이전에 들어온 마지막 인자이다. 즉 ```...``` 직전의 인자이다. 이를 이용해 첫번째 인자를 가리키도록 만들어준다. 

구체적으로 본다면 va_start는 가변 인자 직전 마지막에 들어온 인자의 위치에서 그 인자의 자료형 크기만큼 더한 위치로 ap를 초기화하는 것이다. 

#### 0.1.1.3 va_end
```
#define va_end(ap)	((void)0)
```
va_end는 가변 인자를 모두 사용하고 난 후, ap의 값을 NULL로 초기화한다.

#### 0.1.1.4 va_arg
```
#define va_arg(ap, t)					\
	 (((ap) = (ap) + __va_argsiz(t)),		\ // 먼저 ap 값을 밀어줌
	  *((t*) (void*) ((ap) - __va_argsiz(t)))) // 반환값으로 밀어주기 전의 주소에서 캐스팅 값
```
va_arg는 va_list에 저장된 값을 바탕으로 현재 매개인자를 반환하고 va_list의 주소를 다음으로 이동시킨다. 위 매크로 함수의 동작으로 살펴보면 다음과 같다.
- ap의 값을 t만큼 이동한다.
- 기존에 가리키고 있던 값의 타입으로 캐스팅하여 반환한다.


## 0.2 라이브러리 추가

### 0.2.1 -L
-L은 사용할 라이브러리의 위치를 지정하는 옵션이다. ```-L<디렉토리명>```으로 사용한다.

### 0.2.2 -l

-l은 링크할 정적 라이브러리를 명시할 때 사용하는 옵션이다. 이때 대상 라이브러리의 이름에서 ```lib```과  ```.a```를 제외한 나머지 이름만 적는다. 

예를 들어 libft.a를 링크시키려면 ```-lft```를 옵션으로 주면 된다.

### 0.2.3 응용
예를 들어 ```\lib\libft```에 ```libft.a```라는 라이브러리를 사용하고 싶다면 옵션을 다음과 같이 주면 된다.

```
-L./lib/libft -lft
```


# 참고 자료
- [팔만코딩경, [C] 가변인자 뜯어보기](https://80000coding.oopy.io/b1bc0184-9612-49f2-813b-ffeaf830f4fe)
- [코딩 도장, 66 함수에서 가변 인자 사용하기](https://dojang.io/mod/page/view.php?id=577)
- [IBM, 가변 인수 리스트 처리](https://www.ibm.com/docs/ko/i/7.3?topic=lf-va-arg-va-copy-va-end-va-start-handle-variable-argument-list)
- [gcc, 3.7.2 Common Predifined Macros](https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html)
- [양햄찌가 만드는 세상, 가변인자 함수의 사용](https://jhnyang.tistory.com/293)
- [mtak0235, 라이브러리](https://velog.io/@mtak0235/%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)
