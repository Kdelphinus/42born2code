# Libft

[libft notion](https://brassy-plate-60f.notion.site/Libft-adeddc0490d541a5b79580a5e17a1a8a)

# 핵심 포인트

- memcpy는 오버플로우등의 모든 오류를 쓰는사람이 고려해야 하는 함수이다.
- memmove는 dest < src (주소값)일때 뒤에서부터 차례로 옮겨주고, 그 반대의 경우에는 앞에서부터 옮겨준다.
- memcpy는 겹침이 고려되지 않았지만, 실제로 작동은 고려해서 작동한다. 따라서 그 기준에 맞추어 사용하자.
- strchr(strrchr) 비교시 int는 char로 형변환, 문자열 마지막 ‘\0’도 체크, str = NULL 일때 segmentation fault
- 메모리참조 연산때에는 unsigned char형을 이용하여 1바이트씩 접근한다.
- strnstr은 haystack에서 len개의 char만 사용하여 strstr을 진행한다. 따라서 needle의 길이가 len보다 길 경우, 항상 null pointer를 반환한다.
- calloc을 비롯한 allocate함수에서 기본적으로 바이트단위로 접근하며 ,calloc의 경우에는 매개변수로 요소의 갯수, 각 요소의 크기(1 = 1byte)를 가진다.
- trim의 경우 앞과 뒤의 해당 구분자들을 제거해주는데, 양옆 2번 길이를 측정하는 과정에서 구분자로만 이루어진 경우를 생각하여야 한다.
- write의 리턴값은 전달한 바이트수이며, 에러가 발생시 -1을 반환한다.
