[0. 개념](#0.-개념)  
[1. Part1 문제](#1.-part1-문제)  
[4. Test result](#4.-test-result)


# 0. 개념

## 0.1 void pointer

**void pointer**는 자료형이 정해져 있지 않기 떄문에 임의의 자료형 포인터도 받을 수 있다. 이는 다시 말해 가져올 값이나 저장할 값의 크기도 모른다는 의미다. 그렇기에 void pointer는 역참조가 불가하다. 그렇기에 void pointer를 받는 함수에 값을 넣기 위해선 형변환을 거쳐서 값을 대입해야 한다.

```
void	*b;  
char	c;  
   
*(char *)(b) = c;  
```  

## 0.2 size_t

**size_t**는 기본적으론 unsigned int와 같이 부호가 없는 양수의 수를 의미한다. 그러나 size_t는 운영체제에 따라 64bit에선 부호 없는 64bit의 정수, 32bit에선 부호 없는 32bit의 정수임에 반해 unsigned int는 이것이 항상 보장되지 않습니다. 그렇기에 메모리나 문자열의 길이를 구할 땐, unsigned int가 아닌 size_t로 길이가 반환됩니다. 
  
size_t는 unistd.h, stdlib.h 등 여러 헤더파일에 정의되어있습니다.
  
 ```
#ifdef _WIN64    // 64비트일 때  
	typedef unsigned __int64 size_t;    // 8바이트 크기의 부호 없는 정수 자료형  
#else            // 64비트가 아닐 때  
	typedef unsigned int     size_t;    // 4바이트 크기의 부호 없는 정수 자료형  
#endif  
```

## 0.3 restrict

**restrict**는 메모리 접근과 관련하여 최적화를 위해 사용되는 형 한정어이다. 각 포인터가 개별적인 공간을 가리키고 있고 다른 곳에서 접근하지 않겠다는 것을 의미하며 restrict 포인터만이 접근할 수 있다. 그렇기에 이미 restrict로 할당된 공간을 사용하지 않도록 주의해야 한다. 이 키워드는 c99 표준에 해당하며 libft에선 이를 위해 컴파일에 std=99 플래그 사용을 금하고 있기에 사용하지 않았다.
  

# 1. Part1 문제

## 1.1 ft_memset
**```void	*ft_memset(void *b, int c, size_t len);```**  
- b: 바꿀 주소를 가리키는 포인터
- c: 임의로 바꿀 값(부호 없는 문자로 변환됨)
- len: 바꿀 크기
  
받은 주소에서 len의 길이만큼 c로 초기화하는 함수이다.  
이때, c는 함수 내부에서 unsigned char로 변환되기 때문에 원하는 int형으로 바꾸기엔 무리가 있다.  
> 메모리 단위로 바꾸기 위해 unsigned char로 변환한다.  

## 1.2 ft_bzero
**```void	ft_bzero(void *s, size_t n)```**
- s: 바꿀 주소를 가리키는 포인터
- n: 바꿀 크기

받은 주소에서 n의 길이만큼 0으로 초기화하는 함수이다.  
memset과 마찬가지로 메모리 단위로 바꾸기 때문에 unsigned char로 형변환하여 0을 대입한다.  

## 1.3 ft_calloc
**```void	*ft_calloc(size_t count, size_t size)```**
- count: 할당할 자료형의 개수
- size: 자료형의 크기
  
기본적으론 malloc(count * size)와 동일한 기능을 가진 함수이다. 그러나 할당한 메모리 안의 값을 모두 0으로 초기화해주는 동작도 함께 수행한다.

> libftTester의 세 번째 테스트케이스에서 ko가 뜬다.  
> 
> ```ft_calloc(SIZE_MAX, SIZE_MAX) == NULL```  
> 
> 테스트케이스는 다음과 같으며 위에서와 같이 count * size의 크기를 할당하는데 곱한 값이 size_t의 범위를 넘어갈 경우를 확인하는 테스트케이스이다. 이에 대한 해결방법으로 동적할당 실패 시, errno를 이용해 처리할 수 있다고 하나 errno.h안에 정의되어 있는 만큼 현재 사용이 불가할 것으로 보인다.  
> 
> 해당 케이스는 기계 역시 잡지 않는 것으로 보인다.  

## 1.4 ft_memcpy
**```void	*ft_memcpy(void *dst, const void *src, size_t n)```**
- dst: 복사한 값을 저장할 메모리를 가리키는 포인터
- src: 복사할 값을 저장한 메모리를 가리키는 포인터
- n: 복사할 메모리의 개수




# 4. Test result

## Part1
||Libtest|libft-war-machine|libft-unit-test|libftTester|
|:-:|:-:|:-:|:-:|:-:|
|ft_memset|o|o|o|o|
|ft_bzero|o|o|o|o|
|ft_calloc|o|o|o|size_t를 넘어가는 범위는 libft에선 처리 불가(??)|
|ft_memcpy|o|o|x|o|
|ft_memmove|x|x|x|x|
|ft_memchr|o|o|o|o|
|ft_memcmp|x|x|o|x|
|ft_strlen|o|o|o|o|
|ft_strdup|o|o|o|o|
|ft_strlcat|o|o|o|o|
|ft_strlcpy|o|o|o|o|
|ft_strchr|o|o|o|x|
|ft_strrchr|o|o|o|x|
|ft_strnstr|o|x|o|x|
|ft_strncmp|x|x|o|x|
|ft_atoi|o|o|o|o|
|ft_isalpha|o|o|o|o|
|ft_isdigit|o|o|o|o|
|ft_isalnum|o|o|o|o|
|ft_isascii|o|o|o|o|
|ft_isprint|o|o|o|o|
|ft_toupper|o|o|o|o|
|ft_tolower|o|o|o|o|


## Part2
||Libtest|libft-war-machine|libft-unit-test|libftTester|
|:-:|:-:|:-:|:-:|:-:|
|ft_strmapi|o|o|np||
|ft_substr|o|o|np|x|
|ft_strjoin|o|o|np|o|
|ft_strtrim|o|x|np|x|
|ft_split|x|x|x|x|
|ft_itoa|o|o|o||
|ft_striteri|o|o|np||
|ft_putchar_fd|o|o|o||
|ft_putstr_fd|o|o|np||
|ft_putendl_fd|o|o|np||
|ft_putnbr_fd|o|o|o||

## Part3
||Libtest|libft-war-machine|libft-unit-test|libftTester|
|:-:|:-:|:-:|:-:|:-:|
|ft_lstnew|x|x|x|x|
|ft_lstdelone|x|x|x|x|
|ft_lstclear|x|x|x|x|
|ft_lstadd_front|x|x|x|x|
|ft_lstadd_back|x|x|x|x|
|ft_lstsize|x|x|x|x|
|ft_lstiter|x|x|x|x|
|ft_lstmap|x|x|x|x|
|ft_lstlast|x|x|x|x|
