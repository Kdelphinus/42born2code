# Philosophers

## Index
- [0. Subject](#0-subject)
  - [0.1 개요](#01-개요)
  - [0.2 Overview](#02-overview)
  - [0.3 Global rules](#03-global-rules)
  - [0.4 Mandatory part](#04-mandatory-part)
  - [0.5 Bonus part](#05-bonus-part)
- [1. OS 개념 정리](#1-os-개념-정리)
- [2. 함수 정리](#2-함수-정리)
  - [1) usleep](#1-usleep)
  - [2) gettimeofday](#2-gettimeofday)
  - [3) pthread_create](#3-pthread_create)
  - [4) pthread_detach](#4-pthread_detach)
  - [5) pthread_join](#5-pthread_join)
  - [6) pthread_mutex_init](#6-pthread_mutex_init)
  - [7) pthread_mutex_destroy](#7-pthread_mutex_destroy)
  - [8) pthread_mutex_lock](#8-pthread_mutex_lock)
  - [9) pthread_mutex_unlock](#9-pthread_mutex_unlock)
- [3. data race 확인](#3-data-race-확인)
- [참고 문헌](#참고-문헌)
- [Tester](#tester)

## 0. Subject

### 0.1 개요
- Version: 10
- Summary
  - 프로세스 스레딩의 기본과 스레드를 만드는 방법을 익힌다.
  - mutexes가 무엇인지 배운다.

### 0.2 Overview
- 한 명 이상의 철학자들이 원형테이블에 앉아있다. 테이블 가운데에는 스파게티가 있는 큰 그릇이 있다.
- 철학자들은 **먹기, 생각하기, 잠자기**를 할 수 있다.이때 한 가지 행동을 하면서 동시에 다른 행동은 할 수 없다.
- 또한 테이블 위에는 철학자들만큼 많은 포크들이 놓여있다.
- 하나의 포크만으로 스파게티를 먹기엔 너무 불편하기에 철학잗르은 양손에 포크를 들고 먹는다.
- 식사가 끝나면, 그들은 포크를 테이블에 놓고 잠을 잔다. 그리고 일어나면 그들은 생각하기 시작한다. 이 시뮬레이션은 철학자가 아사할 때 끝난다.
- 모든 철학자들은 먹어야하며 절대 굶어선 안 된다.
- 철학자들은 서로 이야기할 수 없다.
- 철학자들은 다른 철학자가 죽을지 알 수 없다.
- 철학자들이 죽음을 피해야 한다는 것은 말할 필요도 없다!

### 0.3 Global rules
- 전역변수는 금지된다.
- 만들어진 프로그램은 아래와 같은 인자들은 입력 받아야 한다.
  - **number_of_philosophers**: 철학자의 수이자 포크의 개수
  - **time_to_die**(in millisecond): 마지막 식사나 시뮬레이션이 시작된 지 **time_to_die** ms지날만큼 먹지 않으면 철학자는 죽는다.
  - **time_to_eat**(in millisecond): 철학자가 식사하는데 걸리는 시간, 이 시간동안 그들은 두 개의 포크를 사용한다.
  - **time_to_sleep**(in millisecond): 철학자가 잠자는 시간
  - **number_of_times_each_philosopher_must_eat**(optional argument): 만약 철학자들이 최소한 **number_of_times_each_philosopher_must_eat**만큼 먹었다면 시뮬레이션을 종료한다. 만약 인자가 주어지지 않으면 철학자가 죽을 때, 시뮬레이션을 종료한다.
- 각각의 철학자는 1 ~ **number_of_philosophers** 사이의 번호를 가진다.
- 철학자 1은 **number_of_philosophers** 옆에 앉는다. 다른 철학자 N은 철학자 N - 1과 철학자 N + 1 사이에 앉는다.
  
- 프로그램의 log에 관해선 다음과 같다.
  - 철학자의 모든 상태 변경은 다음과 같은 형식을 따라야 한다.
    - **timestamp_in_ms X** has taken a fork
    - **timestamp_in_ms X** is eating
    - **timestamp_in_ms X** is sleeping
    - **timestamp_in_ms X** is thinking
    - **timestamp_in_ms X** died
    - **timestamp_in_ms**: 현재 시간, **X**: 철학자 숫자
  - 상태 메세지는 다른 메세지와 섞여선(혼동해선) 안 된다.
  - 철학자가 사망한지 10ms가 지나기 전에 철학자가 죽었다는 것을 알려야 한다.

> 만들어진 프로그램은 반드시 data race가 일어나서는 안 된다.

### 0.4 Mandatory part
|**Program name**|philo|
|:---|:---|
|**Turn in files**|Makefile, *.h, *.c, in directory philo|
|**Makefile**|Name, all, clean, fclaen, re|
|**Arguments**|number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]|
|**External functs.**|memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, phtread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock|
|**Libft authorized**|No|
|**Description**|Philosophers with threads and mutexes|

- 각각의 철학자는 thread여야 한다.
- 각각 철학자 한 명에 포크가 하나씩 있다. 철학자가 여러 명이면 철학자마다 왼쪽과 오른쪽에 포크가 있다. 철학자가 한 명이면 포크도 하나만 있다.
- 철학자가 포크를 복제하지 못하도록 각 포크에 대해 mutex 상태를 보호해야 한다.

### 0.5 Bonus part
|**Program name**|philo_bonus|
|:---|:---|
|**Turn in files**|Makefile, *.h, *.c, in directory philo_bonus|
|**Makefile**|Name, all, clean, fclaen, re|
|**Arguments**|number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]|
|**External functs.**|memset, printf, malloc, free, write, fork, kill, exit, pthread_create, phtread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink|
|**Libft authorized**|No|
|**Description**|Philosophers with processes and semaphores|

- 모든 포크들은 책상 중간에 있다.
- 그들은 상태가 없는 메모리를 가지고 있지만 사용 가능한 포크의 수는 semaphore에 나타난다.
- 각각의 철학자는 하나의 process여야 한다. 그러나 main process는 철학자가 되어선 안 된다.

### 0.6 Submission
- Mandatory part directory: **philo/**
- Bonus part directory: **philo_bonus/**

## 1. OS 개념 정리
길어서 문서를 나눴다. [이 곳](https://github.com/Kdelphinus/42born2code/blob/main/Philosophers/Operating_System.md)에 있으며 OS에 대해 알고 있다면 안 읽어도 된다.

## 2. 함수 정리

### 1) usleep

```c
#include <unistd.h>

int sleep(useconds_t usec);
```

마이크로초 단위로 sleep한다. 100000ms = 1s이다.

### 2) gettimeofday

```c
#include <sys/time.h>

int gettimeofday(struct timeval *tv, void *tzp)
```

현재 시간을 가져오고 시스템의 시간값을 설정하는 함수이다. 

### 3) pthread_create

```c
#include <pthread.h>

int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```

**pthread_create** 는 새로운 쓰레드를 생성한다. 새로운 쓰레드는 **start_rutine** 함수를 **arg** 인자로 실행시키면서 생성된다. 생성된 쓰레드는 pthread_exit을 호출하거나 start_rutin에서 return 할 경우 제거된다.

**attr** 인자는 쓰레드와 관련된 특성을 지정하기 위한 용도로 사용된다. 이에 대해선 pthread_attr_init을 참고해야 한다. attr을 NULL로 지정하면 기본 특성으로 지정된다. 리눅스에서 쓰레드는 joinable과 non real-time 스케쥴 정책을 기본 특성으로 가진다.

return 값은 성공할 경우, **thread** 에 쓰레드 식별번호를 저장하고, 0을 리턴한다. 반대로 실패했을 경우는 0이 아닌 에러코드를 반환한다. 에러는 쓰레드 생성을 위한 자원이 부족하거나, PTHREAD_THREADS_MAX를 초과해서 쓰레드 생성을 요청할 경우, 발생한다.

### 4) pthread_detach

```c
#include <pthread.h>

int pthread_detach(pthread_t th);
```

**pthread_detach** 는 실행 중인 쓰레드를 detached(분리) 상태로 만든다. 쓰레드 식별자 **th** 를 가지는 쓰레드를 메인쓰레드에서 분리시킨다. 이를 통해 th를 가지는 쓰레드가 종료되는 즉시, 쓰레드의 모든 자원을 되돌려 줄 것을 보장한다. 만약 분리되지 않았다면 쓰레드가 종료되어도 pthread_join을 호출하지 않는 한 자원을 되돌려주지 않는다.

pthread_detach 함수를 호출하는 대신, pthread_create 시, pthread_attr_t에 detachstate를 지정해 줌으로써 detach상태로 생성할 수도 있다. pthread_attr_t는 pthread_attr_init 함수를 이용해서 변경할 수 있다.

return 값은 성공할 경우 0, 실패할 경우 0이 아닌 값을 리턴한다. 실패할 경우는 th식별자를 가진 쓰레드가 존재하지 않거나 이미 detach 상태인 경우이다.

### 5) pthread_join

```c
#include <pthread.h>

int pthread_join(pthread_t th, void **thread_return);
```

**pthread_join** 은 **th** 로 시작되는 쓰레드가 종료되는 것을 기다린다. 이러한 쓰레드의 종료는 **pthread_exit** 로 종료되거나 혹은 리턴되는 경우 발생한다.

**thread_return** 값이 NULL이 아니라면, th의 리턴값이 저장된 영역이 전달되게 된다.

th 식별번호를 가지는 쓰레드가 join되기 위해서는 반드시 joinable 상태의 쓰레드로 작동하고 있어야지만 한다. 만약 기다리는 쓰레드가 pthread_detach 함수를 통해서 detached 상태가 되었거나 pthread_create로 실행될 때, PTHREAD_CREATE_DETACHED 특성으로 실행되었다면 join으로 기다릴 수 없게 된다.

joinable 쓰레드는 종료된다해도 즉시 메모리 자원 등이 해제되지 않는다. 이러한 쓰레드는 pthread_join 함수를 만나야지만 자원을 해제한다. 그럼으로 모든 joinable 쓰레드에 대해서는 반드시 pthread_join을 호출해주어야 한다. 그렇지 않으면 누수가 발생한다.

return 값은 성공할 경우, 쓰레드 식별자인 th에 식별번호를 저장하고 0을 리턴한다. 만약 실패한다면 0이 아닌 에러코드 값을 반환한다. 이때 실패 경우로 th가 잘못된 경우나 th가 detached 상태일 때가 있다.

### 6) pthread_mutex_init

```c
#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutex_attr *attr);
```

**pthread_mutex_init** 은 mutex를 초기화시키는 함수이다. 

첫번째 인자인 **mutex** 는 초기화시킬 mutex 객체이고, 두번째 인자인 **attr** 은 특징을 정의한다. mutex는 fast(기본), recursive, error checking에 세 가지 특징을 가지고 있다. attr이 NULL이면 기본 특성이 선택된다.

return 값은 성공할 경우 0, 실패할 경우는 -1을 반환하며 이땐 적당한 errno값을 설정한다. 실패할 경우는 뮤텍스가 제대로 초기화되지 않았거나 (attr이 error checking일 때 한정하여) 뮤텍스가 이미 잠겨있을 때 발생한다.

> ### mutex란?
> 
> mutex는 MUTual EXclusion(상호 배제) devide의 줄임말로 쓰레드간 공유하는 데이터 영역을 보호하기 위해서 사용한다. 이때, 데이터 영역의 보호는 critical section(임계 영역)을 만들고 임계 영역 내, 단 하나의 쓰레드만 진입 가능하도록 한다.
> 
> mutex는 unlock과 lock이란 행동만 가능하다. lock은 임계영역에 진입하기 위한 요청, unlock은 임계영역을 나오면서 다른 쓰레드에게 임계영역을 돌려주기 위한 요청이다. 만약 쓰레드가 임계영역에 진입하기 위해 lock을 요청했는데 이미 다른 쓰레드가 임계영역에 있다면 해당 쓰레드가 unlock으로 임계영역에서 나올 때까지 기다린다.
>
> mutex의 특징인 fast와 recursive는 lock을 얻은 쓰레드가 다시 lock을 얻을 수 있도록 할 지, 결정하는 용도로 사용된다. 특성을 따로 지정하지 않으면 fast가 자동으로 선택된다.
>
> fast: 하나만 lock이 되도록
> recursive: 중첩되어 lock을 걸 수 있다.

### 7) pthread_mutex_destroy

```c
#include <pthread.h>

int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

**pthread_mutex_destroy** 는 mutex 객체를 삭제하고 자원을 되돌려준다. 그렇기에 더 이상 사용되지 않는 mutex는 반드시 이 함수를 이용해 지워주는 것이 권장된다. 왜냐하면 (리눅스 기준으로) 쓰레드가 종료되었어도 mutex 객체는 여전히 남아있기 때문이다.

return 값은 성공 시 0, 실패 시 그에 맞는 error 번호를 반환한다. 에러의 종류는 mutex가 lock 상태거나 유효하지 않은(즉, 잘못 초기화된 것일 때) mutex일 때, 발생한다.

### 8) pthread_mutex_lock

```c
#include <pthread.h>

int pthread_mutex_lock(pthread_mutex_t *mutex);
```

**pthread_mutex_lock** 은 임계영역에 진입하기 위해 mutex에게 lock을 요청하는 함수다. 만약 mutex가 unlock 상태라면 쓰레드는 잠금을 얻고 임계영역에 진입하게 된다. 다른 쓰레드가 이미 lock 상태라면 lock 상태가 될 수 있을 때까지 대기하다가 lock 상태가 된다.

return 값은 성공 시 0, 실패 시 그에 맞는 error 번호를 반환한다. 에러의 종류는 mutex가 lock 상태거나 유효하지 않은(즉, 잘못 초기화된 것일 때) mutex일 때, 발생한다.

### 9) pthread_mutex_unlock

```c
#include <pthread.h>

int pthread_mutex_unlock(pthread_mutex_t *mutex);
```

**pthread_mutex_unlock** 은 mutex의 lock 상태를 해제시킨다. 만약 fast mutex라면 언제나 unlock 상태를 되돌려준다. 만약 recursive mutex라면 잠겨있는 mutex의 수를 감소시키고 이 수가 0이 된다면 mutex 잠금을 되돌려주게 된다.

return 값은 성공 시 0, 실패 시 그에 맞는 error 번호를 반환한다. 에러의 종류는 mutex가 lock 상태거나 유효하지 않은(즉, 잘못 초기화된 것일 때) mutex일 때, 발생한다.

## 3. data race 확인

### 1) fsanitize 이용(편함)

```shell
-fsanitize=thread -g
```

컴파일할 때, 위 플래그를 추가하면 data race가 뜰 때 에러 표시를 내며 멈춘다.


## 2) valgrind 이용 (에러를 더 잘 잡음)

mac에서 사용하기 위해선 brew를 통해 valgrind를 설치해야 한다.

```shell
valgrind --tool=helgrind ./philo 4 410 200 200 7
```

또는 DRD 플래그를 이용해 data race를 확인할 수 있는데 이는 Linux에서만 사용 가능하다고 한다.

```shell
valgrind --tool=drd ./philo 4 410 200 200 7
```

fsanitize보다 더 깐깐하게 잡기 때문에 하드코어해진다.

## 참고 문헌
- [42, Philosophers](https://cdn.intra.42.fr/pdf/pdf/67985/en.subject.pdf)
- [JOINC, 시스템 라이브러리 함수](https://www.joinc.co.kr/w/man/3)
- [saeyeong tistory, c로 식사하는 철학자 문제 풀기](https://saeyeong.tistory.com/8)
- [팔만코딩경, Philosophers](https://80000coding.oopy.io/d098a24a-eada-4d4b-84f6-34b48fd37af8)
- [stack overflow, ticket_lock 구현](https://stackoverflow.com/questions/5385777/implementing-a-fifo-mutex-in-pthreads)

## Tester
- [philosophers-visualizer](https://nafuka11.github.io/philosophers-visualizer/)
- [GOAT095, philosophers-tester](https://github.com/GOAT095/philosophers-tester)
- [MichelleJiam, LazyPhilosophersTester](https://github.com/MichelleJiam/LazyPhilosophersTester)
- [newlinuxbot, Philosophers-42Project-Tester](https://github.com/newlinuxbot/Philosphers-42Project-Tester)
