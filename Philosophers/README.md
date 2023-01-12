# Philosophers

## Index
- [0. Subject](#0-subject)
  - [0.1 개요](#01-개요)
  - [0.2 Overview](#02-overview)
  - [0.3 Global rules](#03-global-rules)
  - [0.4 Mandatory part](#04-mandatory-part)
  - [0.5 Bonus part](#05-bonus-part)
- [참고 문헌](#참고-문헌)

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

## 1. 개념 정리
길어서 문서를 나눴다. [이 곳](https://github.com/Kdelphinus/42born2code/blob/main/Philosophers/Operating_System.md)에 있으며 OS에 대해 알고 있다면 안 읽어도 된다.

## 참고 문헌
- [42, Philosophers](https://cdn.intra.42.fr/pdf/pdf/67985/en.subject.pdf)

