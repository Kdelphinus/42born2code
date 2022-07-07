[0. 개념](#0.-개념)
[1. Part1 문제](#1.-Part1-문제)


# 0. 개념

## void pointer

**void pointer**는 자료형이 정해져 있지 않기 떄문에 임의의 자료형 포인터도 받을 수 있다. 이는 다시 말해 가져올 값이나 저장할 값의 크기도 모른다는 의미다. 그렇기에 void pointer는 역참조가 불가하다. 그렇기에 void pointer를 받는 함수에 값을 넣기 위해선 형변환을 거쳐서 값을 대입해야 한다.

> void  *b;
> char  c;
> *(char *)(b) = c;



# 1. Part1 문제

## 1.1 ft_memset
**void  \*ft_memset(void \*b, int c, size_t len);**
- b: 바꿀 주소를 가리키는 포인터
- c: 임의로 바꿀 값(부호 없는 문자로 변환됨)
- len: 바꿀 크기
  
받은 주소에서 len의 길이만큼 c로 초기화하는 함수이다.  
이때, c는 함수 내부에서 unsigned char로 변환되기 때문에 원하는 int형으로 바꾸기엔 무리가 있다.  
> 메모리 단위로 바꾸기 위해 unsigned char로 변환한다.  


# Test result

## Part1
||Libtest|libft-war-machine|libft-unit-test|libftTester|
|:-:|:-:|:-:|:-:|:-:|
|ft_memset|o|o|o|o|
|ft_bzero|o|o|o|o|
|ft_calloc|o|o|o|x|
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
