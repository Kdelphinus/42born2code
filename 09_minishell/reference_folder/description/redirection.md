## 1. >

```shell
yes | head -5 > output
cat output
> y
> y
> y
> y
> y
```

`> {filename}` 은 앞선 표준 출력 결과를 `{filename}` 에 저장한다. 만약 `{filename}` 의 파일이 없다면 `0644` 권한으로 새로 생성한다.

그렇기에 `>` 을 구현하기 위해선 `dup2` 를 이용해 파이프 동작이 모두 끝난 표준 출력을 `{filename}` 의 fd로 옮겨놓으면 된다. 이때, `{filename}` 이 없다면 생성하면 된다. 만약 쓸 권한이 없다면 error가 난다.

## 2. <

```shell
echo hello world > input
< input grep hello | wc -l
> 1
```

`< {filename}` 은  명령어들의 표준입력으로 `{filename}` 을 받는다.

그렇기에 `<` 을 구현하기 위해선 `dup2` 를 이용해 파이프 동작 시작 전에 표준 입력을 `{filename}` 의 fd로 옮겨 놓으면 된다. `{filename}` 이 없거나 읽을 권한이 없다면 error가 난다.

## 3. >> (append)

```shell
echo hello world > input
echo goodbye >> input
cat input
> hello world
> goodbye
```

`>> {filename}` 은 `>` 와 거의 동일한 동작을 한다. 두 개의 차이점은 `>` 은 매번 파일 내용을 초기화하지만 `>>` 은 기존 내용에 이어서 작성한다.

그렇기에 `>>` 을 구현하기 위해선 `>` 과 거의 동일하게 만들면 된다. 다만 차이는 `{filename}` 을 open할 때, `O_APPEND` 옵션을 주어야 한다.

## 4. << (heredoc)

```shell
tr a-z A-Z << END_TEXT
> one two three
> four five six
> END_TEXT
ONE TWO THREE
FOUR FIVE SIX
```

`heredoc` 은 위와 같이 `END_TEXT` 가 들어올 때까지 입력을 받아 명령을 수행한다.

이를 구현하는 방법으로는 `get_next_line` 을 이용하여 표준 입력으로 `END_TEXT` 전까지 받고 이를 `exceve` 가 사용할 수 있도록 만드는 것이다. 이때 파이프를 사용하는 방법과 임시 파일을 생성하는 방법이 있는데 대체로 임시 파일을 이용하는 듯 하다.

임시 파일을 이용하면 파일에 대한 관리가 필요하지만, 파이프를 사용하는 것보다 간단하며 버퍼 사이즈 제한으로부터 자유로복 데이터 크기에 대해 신경쓰지 않아도 된다. 따라서 사전에 표준 입력을 돌릴 필요가 없어지므로, fork 작업이 요구되지 않는다. 이를 과정으로 나타내면 다음과 같다.

1. `O_WRONLY` , `O_CREAT` , `O_TRUNC` 모드 및 `0644` 권한으로 임시 파일 생성
2. `END_TEXT` 가 나오기 전까지 임시 파일에 기록
3. `END_TEXT` 를 만나면 기록을 중지하고 임시 파일 닫기
4. `O_TDONLY` 모드로 임시 파일 다시 열기
5. `dup2` 를 통해 표준 입력을 임시 파일로 돌리기
6. 임시 파일 닫기

## Reference

- [Jseo, pipex](https://bigpel66.oopy.io/library/42/inner-circle/8#04cb4ffae21b4cae88ce772e0063c0a9)

