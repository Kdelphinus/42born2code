# pipex

# 0. External functs

## 0.1 errno

``errno`` 는 <errno.h> 파일에 있는 광역변수로써 라이브러리 함수 수행 중 에러가 발생하면 에러 코드를 가진다.
함수 실행 중 에러없이 리턴되었다면 errno는 0을 가지지만 수행 중 에러가 발생했다면 0 이외의 값을 갖는다.

```
#include <stdio.h>
#include <errno.h>

int	main(void)
{
	FILE *fp;

	fp = fopen( "./test.c", "r");       // 파일이 있음
	printf( "error = %d\n", errno);		// error = 0
	fclose( fp);
	printf( "error = %d\n", errno);		// error = 0

	fp = fopen( "./nofile.c", "r");     // 파일이 없음
	printf( "error = %d\n", errno);		// error = 2
	fclose( fp);						// segmentation fault
	printf( "error = %d\n", errno);

	return 0;
}
```

## 0.2 perror

```
#include <stdio.h>

void perror(const char *str);
```

``perror`` 은 오류 메세지를 출력하는 함수다.

전역 변수 ``errno`` 의 값을 해석하여 이에 해당하는 시스템 오류 메세지를 표준 오류 출력 스트림(stderr)에 출력한다.

``str`` 은 시스템 오류 메세지 다음에 이어서 출력할 사용자 정의 메세지를 받는다.
만약 널 포인터라면 시스템 오류 메세지만 출력된다.
관습적으로 프로그램의 이름이 인자로 주로 사용된다.

## 0.3 strerror

```
#include <string.h>

char	*strerror(int errnum);
```

``strerror`` 함수는 오류 메세지 문자열을 가리키는 포인터를 가져온다.

``errnum`` 인자는 오류 번호를 가지며 보편적으로 errno의 값을 넣는다.
errnum을 통해 발생한 오류에 알맞은 오류 메세지를 가리키는 포인터를 반환하며 이 때, 반환되는 포인터는 문자열 리터럴을 가리키기에 그 내용이 바뀔 수 없다.

또한 strerror에 의해 출력되는 오류 메세지는 현재 사용중인 컴파일러나 플랫폼에 따라 다를 수 있다.

# 참고 자료
- [tseo.log, [C]](https://velog.io/@t1won/C-C-yee43s5w)
- [팔만코딩경, [pipex]파이프 이해하기](https://80000coding.oopy.io/a19eda17-f1e2-454d-8182-7ae3271506fd#8a6afcee-eb48-4f63-836a-d25f16c57fc9)
- [바다야크, C언어 에러 번호 구하는 변수 errno](https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EC%97%90%EB%9F%AC-%EB%B2%88%ED%98%B8-%EA%B5%AC%ED%95%98%EB%8A%94-%EB%B3%80%EC%88%98-errno)