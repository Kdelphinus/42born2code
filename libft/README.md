# Contents

## 0. [개념](#0-개념)  
- [void pointer](#01-void-pointer)  
- [size_t](#02-size_t)  
- [restrict](#03-restrict)  

## 1. [Part1 문제](#1-part1-문제)  
|[ft_memset](#11-ft_memset)|[ft_bzero](#12-ft_bzero)|[ft_calloc](#13-ft_calloc)|[ft_memcpy](#14-ft_memcpy)|[ft_memmove](#15-ft_memmove)|[ft_memchr](#16-ft_memchr)|
|:---:|:---:|:---:|:---:|:---:|:---:|
|[ft_memcmp](#17-ft_memcmp)|[ft_strlen](#18-ft_strlen)|[ft_strdup](#19-ft_strdup)|[ft_strlcat](#110-ft_strlcat)|[ft_strlcpy](#111-ft_strlcpy)|[ft_strchr](#112-ft_strchr)|
|[ft_strrchr](#113-ft_strrchr)|[ft_strnstr](#114-ft_strnstr)|[ft_strncmp](#115-ft_strncmp)|[ft_atoi](#116-ft_atoi)|[ft_isalpha](#117-ft_isalpha)|[ft_isdigit](#118-ft_isdigit)|
|[ft_isalnum](#119-ft_isalnum)|[ft_isascii](#120-ft_isascii)|[ft_isprint](#121-ft_isprint)|[ft_toupper](#122-ft_toupper)|[ft_tolower](#123-ft_tolower)||
  
## 2. [Part2 문제](#2-part2-문제)  
|[ft_strmapi](#21-ft_strmapi)|[ft_substr](#22-ft_substr)|[ft_strjoin](#23-ft_strjoin)|[ft_strtrim](#24-ft_strtrim)|
|:---:|:---:|:---:|:---:|
|[ft_split](#25-ft_split)|[ft_itoa](#26-ft_itoa)|[ft_striteri](#27-ft_striteri)|[ft_putchar_fd](#28-ft_putchar_fd)|
|[ft_putstr_fd](#29-ft_putstr_fd)|[ft_putendl_fd](#210-ft_putendl_fd)|[ft_putnbr_fd](#211-ft_putnbr_fd)||

## 3. [Bonus 문제](#3-bonus-문제)  
## 4. [Test result](#4-test-result)  
- [Part1](#41-part1)  
- [Part2](#42-part2)  
- [Bonus](#43-bonus)  


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

```
if (dst == 0 && src == 0)
	return (0);
```
> memset이 구동되는 과정을 보면 dst만 null이거나 src만 null일 땐 세그멘테이션 오류가 난다. 즉, 원본 함수에서도 예외 처리를 하지 않는다. 그러나 dst와 src가 모두 null일 땐, 원본 함수가 null을 반환하기 때문에 이와 동일하게 두 값이 모두 null일 때만 예외처리를 하였다.

## 1.5 ft_memmove
**```void	*ft_memmove(void *dst, const void *src, size_t len)```**
- dst: 복사한 값을 저장할 주소를 가진 포인터
- src: 복사할 값을 가진 주소를 가진 포인터 
- len: 복사할 길이

memcpy는 겹치는 공간을 처리하면 dst가 src를 덮어씌울 수 있어 원하는 작동이 이루어지지 않을 수 있다. 그러나 memmove는 dst와 src의 위치를 파악해 겹치는 메모리가 있더라도 동작을 원할히 하도록 만들어준다.

## 1.6 ft_memchr
**```void	*ft_memchr(const void *s, int c, size_t n)```**
- s: 검색을 시작할 주소
- c: 찾아야 하는 (사실상) 아스키 코드값
- n: 찾을 범위

s라는 주소가 들어오면 n의 범위까지 탐색하며 c라는 값을 가지고 있는 메모리 주소를 찾는 함수다. 만약 범위 안에 여러개가 있다면 가장 먼저 나온 주소를 리턴해준다. 그리고 찾지 못한다면 null을 리턴한다.

## 1.7 ft_memcmp
**```int	ft_memcmp(const void *s1, const void *s2, size_t n)```**
- s1: 비교할 메모리 주소 1 
- s2: 비교할 메모리 주소 2
- n: 비교할 범위

memcmp는 주어진 두 개의 주소값을 n만큼 비교하여 완전히 일치하면 0, 일치하지 않으면 두 메모리 주소에 있는 값의 대소구분의 결과를 리턴한다. 메모리를 확인하는 과정은 unsigned char로 형변환되어 이루어지기 때문에 결국 아스키 코드의 차가 리턴된다.

## 1.8 ft_strlen
**```size_t	ft_strlen(const char *s)```**
- s: 길이를 구할 문자열

strlen은 주어진 문자열의 길이를 구하는 함수이다. 이때 문자열의 끝은 null로 간주하고 계산한다.

## 1.9 ft_strdup
**```char	*ft_strdup(const char *s1)```**
- s1: 복사할 문자열

strdup는 문자열 s1의 크기만큼 공간을 새로 할당하여 할당한 공간에 s1을 복사하여 리턴하는 함수이다. 이때, 할당에 실패하면 null을 리턴하게 된다.

## 1.10 ft_strlcat
**```size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)```**
- dst: 뒤에 src를 붙일 문자열
- src: dst 뒤에 붙을 문자열
- dstsize: 붙일 문자열의 길이

strlcat은 dst 문자열 뒤에 dstsize - dst_len - 1만큼 src를 붙이는 함수이다. dstsize는 dst의 길이와 null의 길이도 포함해주어야 하기에 실제로 뒤에 붙는 src의 길이는 dstsize - dst_len - 1이 된다. 만약 dstsize - dst_len - 1이 0보다 크지 않으면 dst 뒤에 문자열을 붙여녛지 않는다.  
그리고 리턴되는 값은 **min(dstsize, dst_len) + src_len**이다.

## 1.11 ft_strlcpy
**```size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)```**
- dst: 복사한 값을 저장할 문자열
- src: 복사할 값을 가지고 있는 문자열
- dstsize: 복사할 길이

strlcpy는 dst에 dstsize - 1만큼 src를 복사하는 함수이다. dstsize - 1을 하는 이유는 strlcpy는 null을 보장하기 때문이다. 또한 src < dstsize - 1이면 src가 끝날 때까지만 복사하고 dstsize가 0이면 아무것도 복사하지 않는다.  
strlcpy의 리턴값은 복사된 길이와 관계없이 항상 src의 길이이다. 

## 1.12 ft_strchr
**```char	*ft_strchr(const char *s, int c)```**
- s: 탐색할 문자열
- c: 찾을 문자의 아스키코드

strchr 함수는 주어진 문자열에서 c와 같은 값을 찾아서 그 주소를 반환하는 함수이다. 문자열에 c가 없으면 null을 반환한다.  
  
들어온 int값을 char로 형변환시켜서 s와 비교해야 libftTester 케이스에 걸리지 않는다.  


## 1.13 ft_strrchr
**```char	*ft_strrchr(const char *s, int c)```**
- s: 탐색할 문자열
- c: 찾을 문자의 아스키 코드

strrchr 함수는 strchr과 찾는 순서를 제외하고 완전히 동일한 함수다. 가장 마지막에 위치한 c를 찾는, 즉 뒤에서부터 c를 찾는 함수이며 마지막 null도 문자열에 포함하여 탐색한다.  
  
들어온 int값을 char로 형변환시켜서 s와 비교해야 libftTester 케이스에 걸리지 않는다.  

## 1.14 ft_strnstr
**```char	*ft_strnstr(const char *haystack, const char *needle, size_t len)```**
- haystack: 원본 문자열
- needle: 찾고자 하는 문자열
- len: 원본 문자열에서 탐색하고자 하는 범위

strnstr은 haystack의 len까지의 길이에서 needle이 있는지 찾는 함수이다. 이때, needle이 빈 문자열이면 haystack을 반환하고 len이나 haystack의 길이보다 needle의 길이가 길면 찾을 수 없으므로 바로 null을 반환해준다. 

## 1.15 ft_strncmp
**```int	ft_strncmp(const char *s1, const char *s2, size_t n)```**
- s1: 비교할 문자열 1
- s2: 비교할 문자열 2
- n: 비교할 문자의 개수

strncmp는 n개의 문자까지만 같은지 비교하는 함수다. 만약 n이 두 개의 문자열보다 길다면 문자열이 끝날 때까지만 확인한다. 다른 문자가 나오거나 문자들을 모두 확인하면 마직막으로 확인한 두 문자의 아스키 코드의 차이를 반환한다. 그렇기에 문자가 끝까지 동일하면 0을, 다르다면 두 문자의 차이를 반환하게 된다.

## 1.16 ft_atoi
**```int	ft_atoi(const char *str)```**
- str: int형으로 바꿀 문자열

atoi 함수는 받은 문자열을 int형으로 변환하는 함수다. 처음에 isspace에 포함하는 공백들을 무시하고 부호는 하나만 받으며 그 후로 숫자가 아닌 값이 나올 때까지 얻은 수를 int형으로 변환한다.  
  
이때, int를 넘어가는 수가 들어오면 오버플로우되도록 방치하는데 이마저도 넘어가 long long의 범위까지 넘어가게되면 -1(long long의 범위보다 클 때)과 0(long long의 범위보다 작을 때)을 반환하게 된다. 

## 1.17 ft_isalpha
**```int	ft_isalpha(int c)```**
- c: 확인할 아스키코드

isalpha는 받은 변수가 알파벳 아스키 코드 범위에 포함되어 있는지 확인하여 포함되어있으면 1, 아니면 0을 반환하는 함수이다.

## 1.18 ft_isdigit
**```int	ft_isdigit(int c)```**
- c: 확인할 아스키 코드

isdigit은 받은 변수가 숫자 아스키 코드 범위에 포함되어 있는지 확인하여 포함되어있으면 1, 아니면 0을 반환하는 함수이다.


## 1.19 ft_isalnum
**```int	ft_isalnum(int c)```**
- c: 확인할 아스키 코드

isalnum은 받은 변수가 숫자나 알파벳 아스키 코드 범위에 포함되어 있는지 확인하여 포함되어있으면 1, 아니면 0을 반환하는 함수이다.


## 1.20 ft_isascii
**```int	ft_isascii(int c)```**
- c: 확인할 아스키 코드

isascii은 받은 변수가 아스키 코드 범위에 포함되어 있는지 확인하여 포함되어있으면 1, 아니면 0을 반환하는 함수이다.


## 1.21 ft_isprint
**```int	ft_isprint(int c)```**
- c: 확인할 아스키 코드

isprint은 받은 변수가 출력 가능한 아스키 코드 범위에 포함되어 있는지 확인하여 포함되어있으면 1, 아니면 0을 반환하는 함수이다.


## 1.22 ft_toupper
**```int	ft_toupper(int c)```**
- c: 바꿀 아스키 코드 값

toupper는 받은 변수가 소문자이면 대문자로 바꾸고 그 외에 값이면 그대로 반환하는 함수다.


## 1.23 ft_tolower
**```int	ft_tolower(int c)```**
- c: 바꿀 아스키 코드 값

toupper는 받은 변수가 대문자이면 소문자로 바꾸고 그 외에 값이면 그대로 반환하는 함수다.  
  
# 2. Part2 문제

## 2.1 ft_strmapi
**```char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))```**
- s: 함수를 적용할 문자열
- f: 문자열의 각 문자를 적용할 함수

ft_strmapi는 해당 문자의 인덱스와 문자를 주어진 함수에 넣어 나온 값으로 새로운 문자열을 생성하는 함수다. 

## 2.2 ft_substr
**```char	*ft_substr(char const *s, unsigned int start, size_t len)```**
- s: 부분 문자열을 생성할 원본 문자열
- start: 부분 문자열의 시작 인덱스
- len: 부분 문자열의 최대 길이

ft_substr은 원본 문자열의 start 인덱스에서 최대 len 길의 문자를 새로 할당한 주소에 복사하여 반환하는 함수이다.  

> 특이사항  
>  
> 1. start >= s_len  
> 만약 시작 인덱스가 주어진 원본 문자열을 벗어난다면 빈 문자열을 반환한다.
>  
> 2. s_len - start  
> malloc할 때, 원본 문자열의 길이에서 시작 인덱스를 빼줘서 알맞는 문자열의 길이만 할당한다.  

## 2.3 ft_strjoin
**```char	*ft_strjoin(char const *s1, char const *s2)```**
- s1: 접두 문자열
- s2: 접미 문자열

ft_strjoin은 s1 + s2의 값을 새로 할당된 메모리에 복사하여 반환하는 함수이다.  
  
## 2.4 ft_strtrim
**```char	*ft_strtrim(char const *s1, char const *set)```**
- s1: 양쪽을 잘라낼 원본 문자열
- set: 제거될 문자들의 집합

ft_strtrim은 문자열의 양쪽 끝에 set에 포함된 문자들이 있으면 제거하는 함수이다. 

> 예시  
>  
> 1) s1 = "ABCCBA", set = "AB" -> result = "CC"  
> 2) s1 = "ACCBACBA", set = "AB" -> result = "CCBAC"  
> 3) s1 = "Hello world!", set = "Hlde" -> result = "o world!"  
  
> 특이사항
>  
> end - start + 1은 trim된 후 문자열의 길이다. 그렇기에 이것이 0 이하이면 빈 문자열이 반환된다.  
> 만약 end - start + 1이 0보다 클 경우, null의 크기를 하나 더 추가하여 malloc 해준다.
>  
> 또한 트림할 위치를 파악할 때, 문자열을 넘어가지 않도록 주의한다.  

## 2.5 ft_split
**```char	**ft_split(char const *s, char c)```**
- s: 구분자 기준으로 나눌 원본 문자열
- c: 구분자

ft_split은 문자 c를 기준으로 s를 나눈 값들을 저장한 char의 이중 포인터를 반환하는 함수다. 

## 2.6 ft_itoa
**```char	*ft_itoa(int n)```**
- n: 문자열로 바꿀 정수

ft_itoa는 받은 정수를 문자열로 바꿔 반환하는 함수다. 부호에 따른 크기 할당과 int 범위에 넘어가 오버플로우가 나지 않도록 주의해야 한다. 

## 2.7 ft_striteri
**```void	ft_striteri(char *s, void (*f)(unsigned int, char*))```**
- s: 함수를 적용할 문자열
- f: 문자열의 적용할 함수

ft_striteri는 문자의 인덱스와 문자의 주소를 사용하는 함수 f를 문자열의 문자에 모두 적용시키는 함수다.

## 2.8 ft_putchar_fd
**```void	ft_putchar_fd(char c, int fd)```**
- c: 출력할 문자
- fd: 값이 쓰여질 파일 식별자(file descriptor)

ft_putchar_fd는 주어진 fd의 형태로 문자를 출력하는 함수다.

## 2.9 ft_putstr_fd
**```void	ft_putstr_fd(char *s, int fd)```**
- s: 출력할 문자열
- fd: 값이 쓰여질 파일 식별자

ft_putstr_fd는 주어진 fd의 형태로 문자열을 출력하는 함수다.

## 2.10 ft_putendl_fd
**```void	ft_putendl_fd(char *s, int fd)```**
- s: 출력할 문자열
- fd: 값이 쓰여질 파일 식별자

ft_putendl_fd는 주어진 fd의 형태로 문자열을 줄바꿈하여 출력하는 함수다.

## 2.11 ft_putnbr_fd
**```ft_putnbr_fd(int n, int fd)```**
- n: 출력할 숫자
- fd: 값이 쓰여질 파일 식별자

ft_putnbr_fd는 주어진 fd의 형태로 숫자를 문자열로 출력하는 함수다.


# 4. Test result

## 4.1 Part1
||Libtest|libft-war-machine|libft-unit-test|libftTester|
|:-:|:-:|:-:|:-:|:-:|
|ft_memset|o|o|o|o|
|ft_bzero|o|o|o|o|
|ft_calloc|o|o|o|size_t를 넘어가는 범위는 libft에선 처리 불가(??)|
|ft_memcpy|o|o|o|o|
|ft_memmove|o|o|o|o|
|ft_memchr|o|o|o|o|
|ft_memcmp|o|o|o|o|
|ft_strlen|o|o|o|o|
|ft_strdup|o|o|o|o|
|ft_strlcat|o|o|o|o|
|ft_strlcpy|o|o|o|o|
|ft_strchr|o|o|o|o|
|ft_strrchr|o|o|o|o|
|ft_strnstr|o|o|o|o|
|ft_strncmp|o|o|o|o|
|ft_atoi|o|o|o|o|
|ft_isalpha|o|o|o|o|
|ft_isdigit|o|o|o|o|
|ft_isalnum|o|o|o|o|
|ft_isascii|o|o|o|o|
|ft_isprint|o|o|o|o|
|ft_toupper|o|o|o|o|
|ft_tolower|o|o|o|o|


## 4.2 Part2
||Libtest|libft-war-machine|libft-unit-test|libftTester|
|:-:|:-:|:-:|:-:|:-:|
|ft_strmapi|o|o|np||
|ft_substr|o|o|np|_**MKO**_|
|ft_strjoin|o|o|np|o|
|ft_strtrim|o|_**A**_|np|_**LEAKS.KO**_|
|ft_split|_**X**_|_**X, A**_|_**crash**_, np|_**B**_|
|ft_itoa|o|o|o||
|ft_striteri|o|o|np||
|ft_putchar_fd|o|o|o||
|ft_putstr_fd|o|o|np||
|ft_putendl_fd|o|o|np||
|ft_putnbr_fd|o|o|o||

## 4.3 Bonus
||Libtest|libft-war-machine|libft-unit-test|libftTester|
|:-:|:-:|:-:|:-:|:-:|
|ft_lstnew|_**X**_|_**X**_|_**X**_|_**X**_|
|ft_lstdelone|_**X**_|_**X**_|_**X**_|_**X**_|
|ft_lstclear|_**X**_|_**X**_|_**X**_|_**X**_|
|ft_lstadd_front|_**X**_|_**X**_|_**X**_|_**X**_|
|ft_lstadd_back|_**X**_|_**X**_|_**X**_|_**X**_|
|ft_lstsize|_**X**_|_**X**_|_**X**_|_**X**_|
|ft_lstiter|_**X**_|_**X**_|_**X**_|_**X**_|
|ft_lstmap|_**X**_|_**X**_|_**X**_|_**X**_|
|ft_lstlast|_**X**_|_**X**_|_**X**_|_**X**_|
