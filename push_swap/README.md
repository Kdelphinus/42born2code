# Push_swap

## Index
0. [Mandatory 개요](#0-mandatory-개요)  
1. [Quick sort](#1-quick-sort)  
2. [Logic](#2-logic)  
3. [Checker](#3-checker)  
4. [참고 문헌](#참고-문헌)  

## 0. Mandatory 개요

### 0.1 목표
- a와 b, 두 개의 스택을 이용하여 a 스택에 오름차순으로 정렬하는 것

### 0.2 조건
- a에 서로 중복되지 않는 음수, 혹은 양수 등 정수 범위 안에 난수가 있다.
- b는 비어있다.
- 인자에 정수가 아니거나 범위를 초과, 혹은 중복이 있으면 Error와 줄바꿈을 출력한다.
- 아래와 같은 연산만 사용 가능하다.

### 0.3 연산
- sa : swap a - 스택 a의 가장 위에 있는 두 원소의 위치를 서로 바꾼다. 원소가 하나이거나 없으면 아무것도 하지 않는다.

- sb : swap b - 스택 b의 가장 위에 있는 두 원소의 위치를 서로 바꾼다. 원소가 하나이거나 없으면 아무것도 하지 않는다.

- ss : sa와 sb를 동시에 실행한다.

- pa : push a - 스택 b에서 가장 위(탑)에 있는 원소를 가져와서, 스택 a의 맨 위(탑)에 넣는다. 스택 b가 비어 있으면 아무 것도 하지 않는다.

- pb : push b - 스택 a에서 가장 위(탑)에 있는 원소를 가져와서, 스택 b의 맨 위(탑)에 넣는다. 스택 a가 비어있으면 아무 것도 하지 않는다.

- ra : rotate a - 스택 a의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.

- rb : rotate b - 스택 b의 모든 원소들을 위로 1 인덱스 만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.

- rr : ra와 rb를 동시에 실행한다.

- rra : reverse rotate a - 스택 a의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.

- rrb : reverse rotate b - 스택 b의 모든 원소들을 아래로 1 인덱스 만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.

- rrr : rra와 rrb를 동시에 실행한다.

### 0.4 규칙

- Makefile 제출, relink 안 됨
- 전역 변수 사용 불가
- 'push_swap' 이라는 이름의 프로그램 작성
- 정수 목록으로 포맷된 스택으로 인수 사용
- 첫 번째 인수가 스택에 가장 맨 위에 있어야 한다.
- 프로그램은 스택 a를 오름찬순 정렬할 수 있는 가장 작은 명령 목록을 푶시해야 한다.
- 명령어는 '\n'으로 구분해야 하며 그 외에는 아무 것도 구분하지 않는다.
- 최소 작업으로 정렬이 수행되도록 만들어야 한다.
- 매개변수가 입력되지 않은 경우, 프로그램은 아무 것도 표시하지 않고 프롬프트를 반환
- 오류의 경우, 표준 오류에 "Error"를 표시한 다음 "\n"을 표시해야 한다. 
    - 정수가 아닌 인자가 들어올 경우
    - 정수의 범위를 넘어가는 경우
    - 중복된 인자가 있는 경우
- 올바른 인자와 잘못된 인자가 들어왔을 때  
    ![error](img/error.png)
- checker를 사용했을 때  
    ![checker](img/checker.png)

## 1. Quick sort

**Quick sort**는 평균적인 상황에서 최고의 성능을 나타내는 정렬 방법 중 하나이다.
병합 정렬, 힙 정렬과 마찬가지로 $O(n \log n)$ 의 시간복잡도가 소요된다.

방식은 간단한데 적절한 피벗(원소) 하나를 정하고 피벗보다 작은 것은 피벗 앞으로, 큰 것은 피벗 뒤로 빼내어 피벗보다 큰 것과 작은 것으로 나눈다.
그렇게 정렬해야 할 원소들의 개수가 0 또는 1이 될 때까지 나누며 반복하는 것이다.

![퀵 정렬](https://github.com/Kdelphinus/Python_study/blob/main/Baekjoon/solve_step_by_step/10_sort/image/quick_sort.png?raw=true)

위와 같은 방식으로 진행된다고 할 수 있다.
그런데 이러한 퀵 정렬은 피벗이 최소값이나 최대값으로 결정되면 성능이 $O(n^2)$ 까지 안 좋아질 수 있다.
그렇기에 최대한 중간값을 피벗으로 정하는 것이 퀵 정렬을 효율적으로 사용하는 방법이다.

그러나 퀵 정렬을 하는 데이터들은 정렬이 되어 있지 않아 중간값을 찾기 어려우므로 양쪽 끝 값 중 하나나 중간에 있는 값, 혹은 랜덤으로 피벗을 정해서 사용한다.

더 자세한 내용은 [나무위키](https://namu.wiki/w/%EC%A0%95%EB%A0%AC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98#s-2.2.3)나 [짧게 정리한 것](https://github.com/Kdelphinus/Python_study/tree/main/Baekjoon/solve_step_by_step/10_sort#323-%ED%80%B5-%EC%A0%95%EB%A0%ACquick-sort)을 참고하면 된다.

## 2. Logic

지금부터 나오는 로직은 [minckim 님의 로직](https://www.notion.so/push_swap-c15e62229b9541d78fadec4d6aae8b50)을 정리한 것이다.
고민고민 해봤으나 마땅한 해결책을 구하지 못하고 다른 이의 로직을 보고 공부하며 풀게 되었다.
제꺼보다 원본글을 보는 것이 더 이해하기 편합니다.

### 2.1 피벗을 이용하여 두 그룹으로 나누기

![두 스택으로 나누기](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2Fa38281a9-58c0-49e1-bd36-20bdf8ba00ae%2FUntitled.png?id=2403c0ad-f324-479e-930b-653f63484414&table=block&spaceId=b6810e4f-c754-428d-956f-6e3d22679454&width=1620&userId=&cache=v2)

퀵 소트를 푸쉬 스왑에 이용한다면 가장 먼저 생각나는건 하나의 스택은 피벗보다 같거나 큰 수, 다른 하나의 스택은 피벗보다 작은 수를 넣는 방법이 떠오른다.

이때 우리는 명령어를 최대한 최소화해야 한다. 그렇기에 먼저 정렬을 하여 중간값을 알아낸 후, 그 값을 피벗으로 잡고 나누는 상태로 진행하고자 한다.

### 2.2 특정 영역을 수정하지 않으면서 두 그룹으로 나누기

첫 피벗을 통해 나누는 것은 구상이 간단하다. 허나 여러 배열을 만들 수 없고 두 개의 스택만 사용하여 정렬해야 하기에 필연적으로 특정 구간의 배열은 고정해야한다.
이를 위해 스택에 들어간 전체 개수가 아닌, 정렬해야 하는 원소의 개수만 정렬하면 된다.

#### 2.2.1 스택 A에서

![A에서 두 그룹 나누기](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2F30da0ea7-0be6-4ae2-989a-4009f48b7309%2FUntitled.png?id=1a19cb6b-e426-494f-917e-6cac282bfec7&table=block&spaceId=b6810e4f-c754-428d-956f-6e3d22679454&width=1600&userId=&cache=v2)

스택 A에서는 피벗보다 큰 수는 A의 뒤로, 작은 수는 B에 쌓은 뒤, A에서 뒤로 넘긴 횟수만큼 다시 앞으로 넘겨주면 정렬된 원소들은 고정된 상태에서 피벗을 이용하여 두 그룹으로 나눌 수 있다.

#### 2.2.2 스택 B에서

![B에서 두 그룹 나누기](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2Fac9ea105-b7af-4111-9527-ba3fd5f10de0%2FUntitled.png?id=db1370c7-1d2b-4200-8ba2-19f621ca12c9&table=block&spaceId=b6810e4f-c754-428d-956f-6e3d22679454&width=1550&userId=&cache=v2)

스택 B에서는 A와 반대로 작은 수를 B의 뒤로, 큰 수를 A에 쌓은 뒤, B에서 뒤로 넘긴 횟수만큼 다시 앞으로 넘겨주면 정렬된 원소들은 고정된 상태에서 피벗을 이용하여 두 그룹으로 나눌 수 있다.

### 2.3 피벗들을 이용하여 세 그룹으로 나누기

![세 그룹 나누기](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2F513ef834-bef8-445b-b972-77cbde91c492%2FUntitled.png?id=da87a452-ec47-4cee-9cdb-4935743bddad&table=block&spaceId=b6810e4f-c754-428d-956f-6e3d22679454&width=1600&userId=&cache=v2)

만약 피벗을 두 개 잡는다면 숫자들을 세 그룹으로 나눌 수 있을 것이다.
스택 A에서 나눈다고 가정했을 때, 두 개의 피벗보다 큰 값은 A의 뒤로, 나머지 값들은 B로 넘기는데 여기서도 작은 피벗보다 작은 값은 B 뒤로 넘기면 세 개의 그룹으로 나눠진다.

### 2.4 특정 영역을 수정하지 않으면서 세 그룹으로 나누기

이제 2.3을 토대로 세 그룹으로 나누며 스택 A와 B를 이동할 수 있다.
여기서 그룹이 나눠지면서 [3] > [2] > [1] 순으로 그룹이 묶여진다.

#### 2.4.1 스택 A에서

![a를 세 그룹으로 나누기](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2Fd829276f-66bd-470b-ae30-91c7ffc51a20%2FUntitled.png?id=bbc2615d-a359-40d8-a38c-ebcfa692c917&table=block&spaceId=b6810e4f-c754-428d-956f-6e3d22679454&width=1560&userId=&cache=v2)

위를 보면 가장 큰 그룹인 [3]은 A의 뒤로 빠지고 [2]와 [1]은 우선 B로 넘어간 뒤, 중간 크기 그룹인 [2]가 먼저 정렬되어 A에 쌓일 수 있도록 B 위에 위치함을 확인할 수 있다. 이를 위해 [2] 그룹에 포함되는, 즉 첫번째 피벗보단 큰 수들을 B에 뒤에 쌓고 다시 앞으로 가져오는 과정을 거친다.

#### 2.4.2 스택 B에서

![b를 세 그룹으로 나누기](https://www.notion.so/image/https%3A%2F%2Fs3-us-west-2.amazonaws.com%2Fsecure.notion-static.com%2F4c9b978f-8b02-4418-a1b2-6c3767f7a8c8%2FUntitled.png?id=69e6996d-af11-44b7-b992-77450c48994f&table=block&spaceId=b6810e4f-c754-428d-956f-6e3d22679454&width=1550&userId=&cache=v2)

2.4.1과 거의 유사하다.
이번엔 가장 작은 그룹이 B에 남고 A에 [2], [3]으로 쌓이는 과정이 진행되는 것을 볼 수 있다.
이때, [2]가 이동되기 전에 [3]을 먼저 정렬해야 정렬이 순차적으로 쌓일 수 있음을 유의해야 한다.

### 2.5 최적화

- 범위가 2, 3일 때는 하드코딩으로
- 특정 인덱스 이후로 피벗보다 큰 값만 있다면 ra를 더 이상 호출하지 않는다.
- 스택 A가 이미 정렬되어있다면 넘어가기

## 3. Checker

### 3.1 bonus 폴더

새로운 프로그램인 checker를 만들어야 하고 하나의 makefile에서 두 개의 타겟을 입력마다 다르게 만드는 것을 확실히 모르기에 폴더를 하나 더 파서 makefile을 하나 더 만드는 방식으로 진행했다.

### 3.2 명령어 가져오기

gnl로 명령어를 가져오는 과정에서 gnl은 \n까지 가져오므로 NULL까지 확인하기 위해선 \n을 포함해서 체크를 해야 한다.

### 3.3 EOF(End of File)

c언어는 운영체제와 관계없이, 파일의 끝에 도달했을 때 언제나 특별한 값을 반환하며 이를 EOF라고 한다.
실제로 이 값은 -1을 나타낸다.

우리가 만드는 checker는 명령어를 직접 입력 받을 수도 있다.
이때는 UNIX에선 라인의 시작 위치에서 Ctrl + D, 윈도우에선 라인의 어디서든 Ctrl + Z를 누르고 Enter를 누르면 EOF를 발생시킬 수 있다.

# 참고 문헌
- [42 seoul, push_swap](https://cdn.intra.42.fr/pdf/pdf/67975/en.subject.pdf)
- [minckim님의 push_swap 가이드](https://www.notion.so/push_swap-c15e62229b9541d78fadec4d6aae8b50)
- [push_swap_tester](https://github.com/laisarena/push_swap_tester)
- [push_swap_tester_2](https://github.com/louisabricot/push_swap_tester)
- [push swap tester 3](https://github.com/minckim42/push_swap_tester)
