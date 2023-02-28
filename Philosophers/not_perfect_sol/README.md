# Philosophers 문제

### Mutex를 이용해서 thread의 동시성 & 교착상태 해결하는 문제

[https://worthpreading.tistory.com/90](https://worthpreading.tistory.com/90)

## < 실행 >

```
$make
$./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

##### 1\. `number_of_philosophers` : n명의 철학자. n개의 포크.

##### 2\. `time_to_die` : 아래의 경우 죽습니다. (ms)

-   마지막 식사를 시작 후, simulation 시작 후 `time_to_die`ms 안에 먹기 시작하지 않은 경우

##### 3\. `time_to_eat` : 철학자가 먹는데에 걸리는 ms.

-   fork 2개 유지

##### 4\. `time_to_sleep` : 철학자가 자는 데에 걸리는 ms.

##### 5\. `number_of_times_each_philosopher_must_eat` (선택 사항)

-   모든 철학자가 n번을 다 먹으면 시뮬레이션이 중지
-   지정하지 않으면 simulation은 철학자가 죽었을 때만 중지

## < 주의 >

#### \> `You can’t have more than 10 ms between the death of a philosopher and when it will print its death.`

-   `time_to_die` - `died 한 ms` < 10ms 인 경우
-   [원격평가시 출력오차 허용범위인 10ms를 초과하게 되는 오류 | 42 wiki (yeosong1.github.io)](https://yeosong1.github.io/%EC%8A%A4%EB%A0%88%EB%93%9C%EB%8C%80%EA%B8%B0)

#### \> deadlock 설정

-   여러 방법이 있습니다. 저는 다음에 오는 philo를 잠시 기다리게 하는 방법 사용

#### \> 함수에서 millisecond(ms), microsecond, second 구분

-   usleep(microsecond)
-   gettimeofday()

#### \> 인자 조건

```
number_of_philosophers < 200 || time_to_die > 60 || time_to_eat > 60 || time_to_sleep > 60
```

#### \> pthread\_mutex\_join -> thread 종료시키기

[42 Philosophers(철학자 문제) 필수지식 정리 - 1 - Better me than yesterday (tistory.com)](https://42kchoi.tistory.com/301?category=966538)

# \--------------------------------------------

# < Philosophers 식사 >

### thread를 사용할 때 `동시성` & `교착상태(deadlock)`을 설명하는 예시

**5명의 철학자가 원탁에 앉아서 식사를 한다. 철학자들 사이에는 포크가 하나씩 놓여 있고, 철학자들은 다음의 과정을 통해 식사를 한다.**

**(꼭! 포크 2개를 들고 밥을 먹어야한다)**

---

**1\. 왼쪽 포크가 사용 가능해질 때까지 생각을 한다. 만약 사용 가능해지면 집어든다.**

**2\. 오른쪽 포크가 사용 가능해질 때까지 생각을 한다. 만약 사용 가능해지면 집어든다.**

**3\. 양쪽의 포크를 잡으면 정해진 시간만큼 식사를 한다.**

**4\. 오른쪽 포크를 내려놓는다.**

**5\. 왼쪽 포크를 내려놓는다.**

**6\. 다시 1번으로 돌아간다.**

---

[https://gwpaeng.tistory.com/125?category=894930](https://gwpaeng.tistory.com/125?category=894930)

### \> Program

-   실행되지 않은 코드 덩어리(.exe etc)
-   운영체제가 메모리 공간을 할당하지 않는다(정적)

### \> Process

-   실행되고 있는 프로그램

### \> thread

-   Process의 코드에 정의된 절차에 따라 실행되는 특정한 수행 경로
-   코드내에 선언된 함수들

[https://velog.io/@raejoonee/%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4%EC%99%80-%EC%8A%A4%EB%A0%88%EB%93%9C%EC%9D%98-%EC%B0%A8%EC%9D%B4](https://velog.io/@raejoonee/%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4%EC%99%80-%EC%8A%A4%EB%A0%88%EB%93%9C%EC%9D%98-%EC%B0%A8%EC%9D%B4)
