# **get_next_line**

# 0. 개념

## 0.1 static 변수
static 변수(정적 변수)는 지역 변수(**선언된 함수 또는 파일 내에서만 사용이 가능**)와 전역 변수(**프로그램이 실행되는 최초에만 초기화되며 프로그램이 종료되는 때까지 메모리 공간에 존재**)의 특성을 합친 변수이다. 특성은 다음과 같다.

- 함수가 끝나더라도 저장된 값이 유지된다. 
- 프로그램이 끝나면 자동으로 삭제된다. 
- 외부정적변수라면 다른 소스파일에서, 내부정적변수라면 다른 함수에서 참조할 수 없다.
- 프로그램이 실행될 때, 값이 0으로 초기화된다.
	> 내부정적변수(함수 내에 선언된 지역변수)이고 그 함수가 실행되지 않았을지라도 프로그램 실행 시에 초기화된다.  

```
#include <stdio.h>

int	test()
{
	static int	num;
	
	num++;
	return (num);
}

int	main(void)
{
	for (int i = 0; i < 5; i++)
		printf("%d ", test());
	printf("\n");
	return (0);
}
```

위 코드를 실행시키면 for문을 돌 때마다 test함수를 호출한다. 이때 정적 변수 num은 프로그램이 실행될 때에만 0으로 초기화되며 함수를 호출할 때마다 1이 더해지는 동작이 이뤄진다. 그렇기에 **1 2 3 4 5**로 출력된다.  

> 정적 변수는 함수의 매개 변수로 사용할 수 없다. 함수의 매개 변수에 static을 붙인 변수를 선언하면 error가 나며 static을 붙이지 않고 받는다면 값이 유지되지 않는다.

# 0.2 read 함수
```**ssize_t	read(int fd, void *buf, size_t nbytes)**```
- 헤더: unistd.h
- fd: 파일 디스크립터
- buf: 파일을 읽어 드릴 버퍼
- nbytes: 버퍼의 크기

read 함수는 open 함수로 연 파일의 내용을 읽을 때 사용하는 함수다. 정상적으로 작동되었다면 읽어들인 바이트 수를 반환하며 실패했을 땐, -1을 반환한다. 