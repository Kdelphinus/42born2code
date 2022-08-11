# **ft_printf**

## 0. [개념](#0-개념)
- 0.1 [가변인자](#01-가변인자)  
	- 0.1.1 [가변인자 처리 매크로](#011-가변인자-처리-매크로)
		- 0.1.1.1 [va_list](#0111-va_list)  
		- 0.1.1.2 [va_start](#0112-va_start)  
		- 0.1.1.3 [va_end](#0113-va_end)  
		- 0.1.1.4 [va_arg](#0114-va_arg)  
- 0.2 [라이브러리 추가](#02-라이브러리-추가)  
	- 0.2.1 [-L](#021--L)  
	- 0.2.2 [-l](#022--l)  
	- 0.2.3 [응용](#023-응용)  
- 0.3 [printf](#03-printf)  
	- 0.3.1 [변수 출력 형식(mandatory part)](#031-변수-출력-형식mandatory-part)   
	- 0.3.2 [d와 i의 차이](#032-d와-i의-차이)  
## 1. [파일](#1-파일)  
- 1.0 [libft](#10-libft)  
- 1.1 [includes](#11-includes)  
- 1.2 [lib](#12-lib)  
- 1.3 [srcs](#13-srcs)  
	- 1.3.1 [ft_printf.c](#131-ft_printf.c)  
		- 1.3.1.1 [ft_printf](#1311-ft_printf)  
		- 1.3.1.2 [format_print](#1312-format_print)  
	- 1.3.2 [ft_printf_write.c](#132-ft_printf_write.c)  
		- 1.3.2.1 [write_c](#1321-write_c)  
		- 1.3.2.2 [write_s](#1322-write_s)  
		- 1.3.2.3 [write_d](#1323-write_d)  
		- 1.3.2.4 [write_per](#1324-write_per)  
	- 1.3.3 [ft_printf_write_2.c](#133-ft_printf_write_2.c)  
		- 1.3.3.1 [write_x](#1331-write_x)  
		- 1.3.3.2 [write_u](#1332-write_u)  
		- 1.3.3.3 [write_p](#1333-write_p)  
	- 1.3.4 [ft_printf_utils.c](#134-ft_printf_utils.c)  
		- 1.3.4.1 [ft_nbr_count](#1341-ft_nbr_count)  
		- 1.3.4.2 [cal_idx](#1342-cal_idx)  
		- 1.3.4.3 [cal_minus](#1343-cal_minus)  
		- 1.3.4.4 [ft_convert_base](#1344-ft_convert_base)  
	- 1.3.5 [ft_printf_utils_2.c](#135-ft_printf_utils_2.c)  
		- 1.3.5.1 [ft_putunnbr](#1351-ft_putunnbr)  
		- 1.3.5.2 [ft_putptr_2](#1352-ft_putptr_2)  
		- 1.3.5.3 [ft_putptr](#1353-ft_putptr)  

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

```
# 실제 테스트 할 때 사용한 쉘 스크립트
make re
gcc -Wall -Wextra -Werror main.c -L. -lftprintf
./a.out
read next
make fclean
rm a.out
```

## 0.3 printf
```
int	printf(const char *format, ...)
```

printf는 여러 자료형을 출력하는 함수이다. 반환값으로 출력한 자료형의 길이를 반환하며 ```stdio.h```에 정의되어 있다. 

### 0.3.1 변수 출력 형식(mandatory part)
- %c: 문자(정수 역시 문자로 해석)
- %s: 문자열(정수 역시 문자열로 해석)
- %p: 포인터가 참조하고 있는 메모리의 주소값(8자리 16진수)
- %d: 부호가 있는 10진 정수
- %i: 부호가 있는 10진 정수
- %u: 부호없는 10진 진수로 해석
- %x: 소문자를 사용하여 부호없는 16진 진수로 해석
- %X: 대문자를 사용하여 부호없는 16진 진수로 해석
- %%: %를 출력

그 외 옵션들은 참고자료를 참고

### 0.3.2 d와 i의 차이
d와 i 모두 부호가 있는 10진 진수로 해석한다. 그렇기에 두 옵션에 대해 출력에선 차이가 없다. 그렇기에 va_arg를 int형으로 불러온다면 i에 8진수가 들어오든 16진수가 들어오든 10진수로 변환되어 변수에 저장된다. 

따라서 현 프로젝트인 printf에선 두 개를 출력하는 함수의 차이가 없고 scanf 등 입력을 받는 프로젝트를 진행하게 된다면 i에 기능을 추가해야 할 것이다.

# 1. 파일
## 1.0 libft
이전 과제에서 작성한 libft를 가져와 헤더는 ```includes```, 파일들을 ```lib```폴더에 저장하고 사용하였다.

## 1.1 includes
libft.h와 ft_printf.h 헤더 파일이 들어있다. 

```write```함수를 위한 ```unistd.h```와 가변인자를 위한 ```stdarg.h```가 선언되어 있으며 그 외에도 각 파일마다 사용하는 함수들의 프로토타입이 정의되어 있다.

## 1.2 lib
이전 과제에서 만든 libft의 파일들이 있다. 기존의 파일을 그대로 사용한다.

## 1.3 srcs
ft_printf를 실제로 동작시키기 위해 필요한 파일들이 들어있다.

### 1.3.1 ft_printf.c
중심이 되는 함수들이 들어있으며 ft_printf의 옵션을 구분하여 출력하거나 옵션별 동작으로 넘기는 과정을 수행한다.

#### 1.3.1.1 ft_printf
```int	ft_printf(const char *format, ...)```

가장 먼저 동작하는 함수로 ```format```과 가변인자를 받는 함수다. ```format```이 끝날 때까지 문자를 탐색하며 옵션이 들어올 때, ```format_print``` 함수를 호출하여 처리하고 그 외에은 ```write```함수로 출력한다. 

이때 잘못된 옵션이 들어올 경우 음수를 반환하여 사용자에게 잘못됨을 인지시켰다.

#### 1.3.1.2 format_print
```static int	format_print(const char **format, va_list ap)```

format에서 %를 인식하면 이 함수로 들어오게 된다. % 다음에 오는 옵션에 따라서 각각의 출력을 위한 함수를 호출하여 출력한 길이를 받고 이를 반환한다. 

### 1.3.2 ft_printf_write.c

c, s, d, %에 대한 옵션을 수행하는 함수가 정의되어 있다. 

#### 1.3.2.1 write_c
```int	write_c(va_list ap)```

c옵션을 처리하는 함수다. va_arg는 메뉴얼을 보면 ```char```형태로 받을 수 없다. 그렇기에 int로 받아 아스키 코드를 저장하고 이를 출력한다.

이때, 출력하는 길이는 항상 1이기에 길이를 따로 구하지 않고 1를 반환한다.

#### 1.3.2.2 write_s
```int	write_s(va_list ap)```

s옵션을 처리하는 함수다. va_arg를 이용하여 ```char *```자료형으로 받아온다. 만약 받은 변수가 ```NULL```이라면 ```printf```가 그러하듯 "(null)"을 출력한다. 이외의 상황에선 write를 활용하여 출력 후, 길이를 반환한다. 

#### 1.3.2.3 write_d
```int	write_d(va_list ap)```
d와 i옵션을 처리하는 함수다. va_arg를 이용하여 ```int```자료형을 받아온 후, libft에 있는 ```ft_putnbr_fd```함수로 출력한다. 

길이는 후에 ```ft_printf_utils.c```에 정의되어 있는 ```ft_nbr_count```함수를 이용하여 구한 뒤, 반환한다.

#### 1.3.2.4 write_per
```int	write_per(void)```
%옵션을 처리하는 함수다. 바로 %를 하나 출력하고 1을 반환한다.

### 1.3.3 ft_printf_write_2.c
x, X, u, p에 대한 옵션을 수행하는 함수가 정의되어 있다.

#### 1.3.3.1 write_x
```int	write_x(char fm, va_list ap)```

x와 X에 대한 옵션을 처리하는 함수다. ```int```형으로 가변인자를 받고 ```ft_printf_utils.c```에 정의된 ```ft_convert_base```를 통해 16진수로 출력한다. 이때 x면 소문자, X면 대문자로 출력한다.

#### 1.3.3.2 write_u
```int	write_u(va_list ap)```

u에 대한 옵션을 처리하는 함수다. ```unsigned int```형으로 받아 ```ft_printf_utile_2.c```에 정의된 ```ft_putunnbr```함수로 출력했다. 길이는 d옵션과 마찬가지로 ```ft_nbr_count```함수를 이용해 반환했다.

#### 1.3.3.3 write_p
```int	write_p(va_list ap)```

p에 대한 옵션을 처리하는 함수다. 먼저 16진수로 표현되기에 앞에 0x를 먼저 출력하고 출력한 길이에 추가한다. 그 뒤, ```ft_printf_utile_2.c```에 정의된 ```ft_putptr```함수로 주소를 출력했다. 이때 주소가 얼마나 클지 모르고, 항상 양수임을 감안해서 ```unsigned long long```으로 형변환하여 입력했다.

### 1.3.4 ft_printf_utils.c
숫자의 길이를 세는 함수와 16진수로 변환하는 동작에 대한 함수가 정의되어 있다. 

#### 1.3.4.1 ft_nbr_count
```int	ft_nbr_count(long long num)```
숫자의 길이를 계산하여 반환하는 함수다. 음수인 경우 -부호를 출력해야 하기에 길이를 하나 더 추가했다.

#### 1.3.4.2 cal_idx
```static int	cal_idx(long long num, int flag)```

```ft_convert_base```함수의 동작 중에서 현재 출력해야 하는 인덱스를 구하는 함수다. 양수인 경우 주어진 인덱스를 그대로 반환하나 음수인 경우 보수를 출력해야 하기 때문에 반전시켜서 반환한다.

#### 1.3.4.3 cal_minus
```static int	cal_minus(int **nbr_p, int idx)```

음수인 경우 보수를 구하여 그 수의 1을 더한 값을 반환하는 것이 컴퓨터의 동작이다. 그렇기에 ```cal_idx```에서 보수를 구하여도 거기에 1을 더해야 한다. 

우선 첫번째 반복문은 만약 앞자리가 남았다면 0의 보수인 15번째 수를 채우는 과정이다. 

다음 반복문은 끝자리에 1을 더해 인덱스를 늘리고 그에 따른 올림을 처리하는 과정이다. 

#### 1.3.4.4 ft_convert_base
```int	ft_convert_base(long long lnum, const char *base, int flag)```

주어진 수와 base를 이용하여 16진수를 출력하는 함수다. ```calloc```을 사용해 8자리의 칸을 먼저 만든 후, 계산하는 방식이다. 이때 ```flag```가 1이면 음수이기에 음수를 따로 처리한다.

### 1.3.5 ft_printf_utils_2.c
unsigned int를 출력하는 함수나 주소를 출력하는 함수가 정의되어 있다.

#### 1.3.5.1 ft_putunnbr
```void	ft_putunnbr(unsigned int num)```

unsigned int형을 출력하는 함수다.

#### 1.3.5.2 ft_putptr_2
```static void	ft_putptr_2(unsigned long long ptr, int *cnt, char *base)```

재귀를 돌며 주소를 출력하기 위해 작성된 함수다. 재귀의 특성상 출력된 길이를 저장하며 가져가긴 어렵기에 ```cnt```의 주소값을 입력하여 반환이 필요없도록 작성했다.

#### 1.3.5.3 ft_putptr
```int	ft_putptr(unsigned long long ptr)```

주소를 출력하는 함수다. ```ft_putptr_2```로 주소를 출력한 뒤, cnt에 저장된 값을 반환한다. 

# 참고 자료
- [팔만코딩경, ft_printf](https://80000coding.oopy.io/10c13274-8701-4395-9f39-d5c349735c94)
- [팔만코딩경, [C] 가변인자 뜯어보기](https://80000coding.oopy.io/b1bc0184-9612-49f2-813b-ffeaf830f4fe)
- [팔만코딩경, [make] Makefile 개념 및 사용법 정리](https://80000coding.oopy.io/e836636a-c302-4f8f-9b7c-cc71c5d62fff)
- [코딩 도장, 66 함수에서 가변 인자 사용하기](https://dojang.io/mod/page/view.php?id=577)
- [IBM, 가변 인수 리스트 처리](https://www.ibm.com/docs/ko/i/7.3?topic=lf-va-arg-va-copy-va-end-va-start-handle-variable-argument-list)
- [gcc, 3.7.2 Common Predifined Macros](https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html)
- [양햄찌가 만드는 세상, 가변인자 함수의 사용](https://jhnyang.tistory.com/293)
- [mtak0235, 라이브러리](https://velog.io/@mtak0235/%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)
