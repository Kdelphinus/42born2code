# Born2beroot

# Index
[1. Project overview](#1-project-overview)  
- [1.1 virtual machine은 무엇인가?](#11-virtual-machine은-무엇인가)
- [1.2 CentOS와 Debian의 차이점](#12-CentOS와-Debian의-차이점)
- [1.3 virtual machine의 장점](#13-virtual-machine의-장점)
- [1.4 aptitude와 apt의 차이점 (in debian)](#14-aptitude와-apt의-차이점-in-debian)
- [1.5 APPArmor(Application Armor)는 무엇인가?](#15-apparmorapplication-armor는-무엇인가)
  
[2. Simple setup](#2-simple-setup)
- [2.1 시작 시 GUI 환경이 아닌가?](#21-시작-시-gui-환경이-아닌가)
- [2.2 machine에 연결할 경우, password를 요구하는가?](#22-machine에-연결할-경우-password를-요구하는가)
- [2.3 password가 주어진 정책에 맞는가?](#23-password가-주어진-정책에-맞는가)
- [2.4 UFW service가 실행되었는가?](#24-ufw-service가-실행되었는가)
- [2.5 SSH service가 실행되었는가?](#25-ssh-service가-실행되었는가)
- [2.6 OS가 Debian인가?](#26-os가-debian인가)

[3. User](#3-user)
- [3.1 평가 받는 학생#의 유저가 sudo와 user42 그룹에 속해져있는가?](#31-평가-받는-학생의-유저가-sudo와-user42-그룹에-속해져있는가)
- [3.2 새로운 유저 생성 후, 평가자가 password policy에 맞는 password를 설정 후, passowrd policy의 설정 방법 설명](#32-새로운-유저-생성-후-평가자가-password-policy에-맞는-password를-설정-후-password-policy의-설정-방법-설명)
- [3.3 evaluating 그룹을 만든 후, 해당 그룹에 새 유저를 추가](#33-evaluating-그룹을-만든-후-해당-그룹에-새-유저를-추가)

[4. Hostname & Partitions](#4-hostname--partitions)
- [4.1 hostname이 myko42인가?](#41-hostname이-myko42인가)
- [4.2 hostname을 변경 후, restart하기](#42-hostname을-변경-후-restart하기)
- [4.3 원래 이름으로 복원](#43-원래-이름으로-복원)
- [4.4 partitions 확인하기](#44-partitions-확인하기)
- [4.5 partitions와 subject 비교](#45-partitions와-subject-비교)
- [4.6 LVM이란?](#46-lvm이란)

[5. Sudo](#5-sudo)
- [5.1 sudo 프로그램이 설치되어있는가?](#51-sudo-프로그램이-설치되어있는가)
- [5.2 새 user를 sudo 그룹에 할당하기](#52-새-user를-sudo-그룹에-할당하기)
- [5.3 sudo의 값](#53-sudo의-값)
- [5.4 sudo의 장점](#54-sudo의-장점)
- [5.5 /var/log/sudo/ 폴더에 한 개 이상의 파일이 존재하는가?](#55-varlogsudo-폴더에-한-개-이상의-파일이-존재하는가)
- [5.6 sudo 명령어 실행 후, 로그 파일이 업데이트되었는가?](#56-sudo-명령어-실행-후-로그-파일이-업데이트되었는가)

[6. UFW](#6-ufw)
- [6.1 UFW의 설치 여부 확인](#61-ufw의-설치-여부-확인)
- [6.2 UFW의 작동 여부 확인](#62-ufw의-작동-여부-확인)
- [6.3 active된 UFW rule list 확인 & port 4242에 관한 rule 존재여부](#63-active된-ufw-rule-list-확인--port-4242에-관한-rule-존재여부)
- [6.4 port 8080에 새로운 rule 추가 & rule list에 해당 rule이 추가되었는지 확인](#64-port-8080에-새로운-rule-추가--rule-list에-해당-rule이-추가되었는지-확인)
- [6.5 새로운 rule 삭제](#65-새로운-rule-삭제)

[7. SSH](#7-ssh)
- [7.1 SSH의 설치 여부](#71-ssh의-설치-여부)
- [7.2 SSH의 작동 여부](#72-ssh의-작동-여부)
- [7.3 SSH service가 port 4242만 사용하는가?](#73-ssh-service가-port-4242만-사용하는가)
- [7.4 SSH를 이용해 새 user로 login하기](#74-ssh를-이용해-새-user로-login하기)
- [7.5 SSH를 통해 root로 login 할 수 없는가?](#75-ssh를-통해-root로-login-할-수-없는가)

[8. Script monitoring](#8-script-monitoring)
- [8.0 monitoring.sh](#80-monitoringsh)
- [8.1 cron이란?](#81-cron이란)

[참고](#참고)

# 1. Project overview

## 1.1 virtual machine은 무엇인가?

하나의 물리 서버에서 여러개의 운영체제를 구동할 수 있도록하는 기술이다. 
이때 하이퍼바이저는 하드웨어를 관리하며 물리적 리소스를 가상 환경과 분리시킨다.  

### 1.1.1 하이퍼바이저(hypervisor)

하이퍼바이저는 가상 머신을 생성하고 구동하는 소프트웨어다. 가상 머신 모니터라고도 불리며 하이퍼바이저 운영 체제와 가상 머신의 리소스를 분리해 가상 머신의 생성과 관리를 지원한다.

할당되었던 리소스를 각 가상 머신에 제공하고, 물리 리소스에 대해 가상 머신 리소스의 일정을 관리한다. 물리적 하드웨어는 계속해서 실행 작업을 수행하므로 하이퍼바이저가 일정을 관리하는 동안 CPU가 가상 머신에서 요청한대로 CPU 명령을 계속 실행한다. 

![하이퍼바이저](https://cdn.shortpixel.ai/client/q_glossy,ret_img/https://www.pathpartnertech.com/wp-content/uploads/2020/02/hypervisors.png)

#### 1.1.1.1 유형 1

베어메탈 하이퍼바이저라고 불리는 유형 1은 베어메탈(bare metal)에 기반한다.  

> - 베어메탈이란  
> IT에선 베어메탈의 의미는 ``` 어떤 소프트웨어도 담겨 있지 않은 하드웨어 ``` 를 의미하며 다른 점에선 ``` 하드웨어만을 구매할 수 있는 제품 ``` 을 의미하기도 한다.  

호스트의 하드웨어에서 직접 구동되어 게스트 운영 체제를 관리하는 것을 의미한다. 그렇기에 가상머신 리소스는 하이퍼바이저에 의해 하드웨어에 직접 예약된다.  

이런 유형의 하이퍼바이저는 엔터프라이즈 데이터 센터와 서버 기반 환경에서 일반적으로 사용된다.  

#### 1.1.1.2 유형 2

호스트 하이퍼바이저라고 불리는 유형 2는 기존의 운영 체제에서 소프트웨어 레이어 또는 애플리케이션으로 구동된다. 가상 머신 리소스는 호스트 운영 체제에 따라 예약된 후, 하드웨어에 대해 실행된다.  

VMware와 Virtualbox 역시 유형 2의 하이퍼바이저를 사용한다.  


> Host와 Guest
> 하이퍼바이저가 설치되는 물리 하드웨어를 ``` host ``` , 하이퍼바이저에서 리소스를 사용하는 여러 가상머신을 ``` guest ``` 라고 한다.

### 1.1.2 가상화의 종류

가상화는 방식에 따라 호스트 가상화, 하이퍼바이저 가상화, 컨테이너 가상화로 나뉜다.

#### 1.1.2.1 호스트 가상화

호스트 가상화는 기본이 되는 host OS 위에 guest OS가 구동되는 방식이다. virtual box 등이 이에 해당한다.

- 장점: 가상의 하드웨어를 에뮬레이팅하기에 호스트 운영체제에 크게 제약사항이 없다.
- 단점: OS위에 OS가 얹히는 방식이기에 오버헤드(어떤 처리를 하기 위해 들어가는 간접적인 처리 시간 · 메모리 등)가 클 수 있다.

![호스트 가상화](https://tech.cloud.nongshim.co.kr/wp-content/uploads/2018/09/Image0.png)

#### 1.1.2.2 하이퍼바이저 가상화

하이퍼바이저 가상화는 host OS없이 하드웨어에 하이퍼바이저를 설치하여 이용하는 방식이다. 

- 장점: 별도의 호느스 os가 없기 때문에 오버헤드가 적고 하드웨어를 직접 제어하기에 효율적으로 리소스를 관리할 수 있다.
- 단점: 자체적으로 머신에 대한 관리 기능이 없기 때문에 관리를 위한 컴퓨터나 콘솔이 필요하다.

하이퍼바이저 가상화는 세부저긍로 전가상화와 반가상화로 분류된다.

![하이퍼바이저 가상화](https://tech.cloud.nongshim.co.kr/wp-content/uploads/2018/09/Image.png)

##### 1.1.2.2.1 전가상화(Full-Virtualization)

전가상화는 하드웨어를 완전히 가상화하는 방식으로 Hardware Virtual Machine으로도 불린다. 하이퍼바이저를 실행하면 DOM0라는 관리용 가상 머신이 실행되고, 모든 가상머신들은 DOM0를 통해서만 하드웨어 접근이 이루어진다. 그렇기에 하이퍼바이저는 가상화된 OS가 무엇이든지 명령어를 알아들을 수 있다.

- 장점: 하드웨어를 완전히 가상화하기 때문에 게스트 OS의 별다른 수정이 필요없다.
- 단점: 하이퍼바이저가 모든 명령을 중재하기에 성능이 비교적 느리다.

##### 1.1.2.2.2 반가상화(Para-Virtualization)

반가상화는 전가상화와 달리 하드웨어를 완전히 가상화하지 않는다. 이는 전가상화의 단점인 성능저하 문제를 해결하기 위함인데 하이퍼콜(hyper call)이라는 인터페이스를 통해 하이퍼바이저에게 직접 요청을 날린다. 그렇기에 각 OS들이 각각의 번역기를 가지고 명령을 보내는 것이다.

- 장점: 전가상화에 비해 성능이 빠르다.
- 단점: 하이퍼바이저에게 하이퍼 콜을 요청할 수 있도록 각 OS의 커널을 수정해야한다. 그렇기에 오픈소스 OS가 아니라면 반가상화를 이용하기 어렵다.

#### 1.1.2.3 컨테이너 가상화

컨테이너 가상화는 호스트 OS 위에 컨테이너 관리 소프트웨어를 설치하여 논리적으로 컨테이너를 나누어 사용한다. 컨테이너는 어플리케이션 동작을 위한 라이브러리와 어플리케이션 등으로 구성되기떄문에 이를 각각의 서버처럼 사용할 수 있다.

- 장점: 오버헤드가 적어 가볍고 빠르다.

![컨테이너 가상화](https://tech.cloud.nongshim.co.kr/wp-content/uploads/2018/09/Image2.png)

## 1.2 CentOS와 Debian의 차이점

두 OS 모두 `` 리눅스 커널 + 자유소프트웨어 `` 로 구성된 리눅스 배포판이다. 그렇기에 두 OS의 차이는 자유소프트웨어(패키지 포맷, 패키지 관리 툴 등)이다.

> 리눅스 커널이란?  
>  
> 리눅스 OS의 주요 구성 요소이며 컴퓨터 하드웨어와 프로세스를 잇는 핵심 인터페이스이다.  
>  
> 커널이란 이름은 단단한 껍질 안의 씨앗처럼 OS 내에 위치하고 어떤 유형에 관계없이 하드웨어의 모든 주요 기능을 제어하기 때문에 붙은 이름이다. 

### 1.2.1 CentOS

- RHEL(레드헷 엔터프라이즈 리눅스, 레드헷이 개발한 컴퓨터 운영체제이자 유로기업용 서버 OS)에서 사후 기술지원과 상표권을 배제하고 제작한 오픈소스
- 패키지 포맷으로 .rpm 확장자를 사용하고, yum(yellow dog update, duke university에서 RPM 설치를 개선하기 위해 개발한 패키지 관리자)을 패키지 관리 툴로 사용한다.

### 1.2.2 Debian

- debian 프로젝트에서 제작한 오픈소스다.
- 패키지 포맷으로 .deb 확장자를 사용하고 dpkg(데비안 패키지 관리 시스템의 기초가 되는 소프트웨어)와 APT를 패키지 관리 툴로 사용한다.
- 패키지 관리가 매우 편하다.
- Ubuntu는 debian 기반의 OS다.
- APT는 처음에는 debian 계열을 위해 고안되었으나 현재는 .rpm 패키지와도 호환되도록 업데이트되어서 CentOS에서도 사용 가능하다.

## 1.3 virtual machine의 장점

1. 비용 절감  
여러 가상 환경을 하나의 인프라(하드웨어)에서 설치하기에 물리적 인프라 설치 공간을 줄일 수 있게 된다. 이 때문에 많은 서버를 유지 보수하지 않아도 되고 많은 전력을 사용할 필요가 없어 비용을 줄이는 데 도움이 된다.

2. 간편함 + 속도
새로운 OS를 구동하려는 경우, 물리적 서버를 포함한 새 환경 전체를 준비하는 것보다 빠르고 간편하다.

3. downtime(시스템을 이용할 수 없는 시간)의 최소화
vm은 호스트가 예기치 않게 중단될 경우, 다른 물리적 서버의 하이퍼바이저로 이전할 수 있다. 이는 유용한 백업 대책이 있다는 의미이다.  

## 1.4 aptitude와 apt의 차이점 (in debian)

### 1.4.1 aptitude

``` aptitude ``` 는 사용자 인터페이스를 추가해 사용자가 대화형으로 패키지를 검색해 설치, 제거할 수 있는 하이 레벨 패키지 관리 도구이다. 

- GUI와 CLI 모두 제공
- apt-get의 command-line argument를 제공하기 때문에 apt-get을 완전히 대체 가능
- apt-get보다 더 많은 기능을 가지고 있음

### 1.4.2 apt

``` apt ``` (Advanced Packaging Tool)는 소프트웨어의 설치와 제거를 처리하는 패키지 관리 툴이다. 초기에는 .deb 패키지 관리를 위해 만들어졌지만 현재는 .rpm 패키지와도 호환된다. 

- CLI만 제공
- 여러가지 apt(cache, mark, get)에서 자주 사용하는 옵션만 추출하여 사용자들이 보기 편하고 사용하기 쉽게 만든 것
- 설치할 패키지 명을 입력하면 '/etc/apt/sources.list'에 지정된 소스 목록에서 해당 패키지 + 종속성 목록과 함께 찾아 자동으로 설치되기에 종속성 문제를 걱정하지 않아도 됨

### 1.4.3 차이점

결과적으로 aptitude가 더 방대하고 apt의 기능들도 모두 포함한다. 그 외에도 몇가지 차이점이 있다.

- 패키지를 삭제할 때, aptitude는 사용되지 않는 패키지(종속성때문에 설치한 패키지)까지 삭제한다. 하지만 apt는 사용자가 '-auto-remove', 'apt-get autoremove'를 명시해야 한다.
- aptitude는 'why', 'why-not' 명령어를 통해 어떤 동작이 왜 되고 안 되는지 확인할 수 있다.
- apt는 설치, 제거 중 충돌이 일어날 경우 종료되지만 aptitude는 해결 방법을 제시할 수 있다.

## 1.5 APPArmor(Application Armor)는 무엇인가?

``` APPArmor ``` 는 리눅스 커널의 보안 시스템이다. 오픈 소스이고 생성한 개별 프로그램에 대한 profile 파일을 통해 여러 권한을 통제함으로 개별 프로그램을 보호한다.

- 네트워크 액세스 권한
- raw 소켓([참고자료](https://mangkyu.tistory.com/16)) 액세스 권한
- 파일의 읽기, 쓰기, 실행 권한

## 1.6 SELinux

CentOS의 경우

# 2. Simple setup

## 2.1 시작 시 GUI 환경이 아닌가?

## 2.2 machine에 연결할 경우, password를 요구하는가?

## 2.3 password가 주어진 정책에 맞는가?
- 길이 10자 이상
- 대문자, 숫자 포함
- 같은 문자 최대 3번

## 2.4 UFW service가 실행되었는가?
```
$ sudo ufw status
```

## 2.5 SSH service가 실행되었는가?
```
$ systemctl status ssh
```

## 2.6 OS가 Debian인가?
```
$ cat /etc/os-release
```

# 3. User

## 3.1 평가 받는 학생의 유저가 sudo와 user42 그룹에 속해져있는가?
```
$ groups <USER_NAME>
// or
$ getent group sudo user42
// or
$ id <USER_NAME>
```

## 3.2 새로운 유저 생성 후, 평가자가 password policy에 맞는 password를 설정 후, password policy의 설정 방법 설명
```
$ sudo adduser <NEW_USER>
```
```
$ sudo vi /etc/login.defs
 
PASS_MAX_DAYS 30 // 30일 후 만료
PASS_MIN_DAYS 2  // 최소 사용기간 2일
PASS_WARN_AGE 7  // 7일전에 경고 보내기

$ sudo apt install libpam-pwquality // 패키지 설치
$ sudo vi /etc/pam.d/common-password // 이 파일에서 비밀번호 정책 수정

/// common-passwrod 파일 수정
retry=3 // 암호 재입력은 최대 3회까지
minlen=10 // 최소 길이 10
difok=7 // 기존 패스워드와 달라야 하는 문자 수 7
maxrepeat=3 // 동일한 문자를 반복 가능한 최대 횟수 3
ucredit=-1 // 대문자 한개 이상 포함
lcredit=0 // 소문자를 한 개 이상 포함하라는 말이 없다.
dcredit=-1 // digit 한개 이상 포함
reject_username // username이 그대로 혹은 reversed 된 문자는 패스워드로 사용 불가
enforce_for_root // root 계정도 위의 정책들 적용
```

## 3.3 evaluating 그룹을 만든 후, 해당 그룹에 새 유저를 추가
```
$ sudo groupadd evaluating
$ sudo usermod -aG evaluating <NEW_USER>
```

-G: user가 명시된 그룹에만 속하게 된다.  
-Ga: user가 기존에 속해져 있던 그룹 + 명시된 그룹에 속하게 된다.

## 3.4 새 유저 삭제
```
sudo deluser <USER_NAEM>

or

sudo deluser --remove-home <USER_NAME> # 사용자, 홈 디렉토리, 메일 스풀을 모두 삭제
```

### 3.5 비밀번호 변경
```
passwd <USER_NAME>
```

### 3.6 그룹 삭제


# 4. Hostname & Partitions

## 4.1 hostname이 myko42인가?
```
$ hostnamectl
```

## 4.2 hostname을 변경 후, restart하기
```
$ sudo hostnamectl set-hostname <HOST_NAME>
$ sudo reboot
```

## 4.3 원래 이름으로 복원

## 4.4 partitions 확인하기
```
$ lsblk
```

## 4.5 partitions와 subject 비교

## 4.6 LVM이란?

``` LVM ``` (Logical Volume Manager)은 리눅스의 저장 공간을 효율적이고 유연하게 관리하기 위한 커널의 한 부분이다.  

일반적인 disk partitioning은 하드 디스크를 partitioning 한 후, OS 영역에 마운트하여 read/write를 수행한다.
이 경우, 저장 공간의 크기가 고정되어 증설/축소가 어렵다.

이에 반해 ``` LVM ``` 은 volume이라는 단위로 저장 장치를 다룬다. 그렇기에 스토리지의 확장과 변경에 유연하며 크기를 변경할 때, 기존 데이터의 이전이 필요 없다. 또한 여러 개의 하드 디스크 공간을 합쳐서 하나의 디스크처럼 사용할 수도 있다.

### 4.6.1 LVM 관련 용어

![관련 용어](https://t1.daumcdn.net/cfile/tistory/260BBB3855F932B218)

1. 파티션(Partition)
    - 하나의 하드디스크에 대해 영역을 나누는 것을 의미
    - fdisk로 파티션 설정 가능

2. 물리적 볼륨(PV, Physical Volume)
    - 실제 디스크 장치를 분할한 파티션된 상태를 의미
    - PV는 일정한 크기의 PE들로 구성

3. 물리적 확장(PE, Physical Extent)
    - PV를 구성하는 일정한 크기의 블록
    - 보통 1PE는 4MB에 해당
    - PE와 LE는 1:1 대응

4. 볼륨 그룹(VG, Volume Group)
    - PV들이 모여서 생성되는 단위
    - 사용자는 VG를 원하는대로 쪼개서 LV로 만듬

5. 논리적 볼륨(LV, Logical Volume)
    - 사용자가 최종적으로 사용하는 단위
    - VG에서 필요한 크기로 할당받아 LV를 생성

6. VGDA(Volume Group Descriptor Area)
    - 볼륨그룹의 모든 정보가 기록되는 부분
    - VG의 이름, 상태, 속해있는 PV, LV, PE, LE들의 할당 상태 등을 저장
    - 각 물리볼륨의 첫 부분에 저장

### 4.6.2 LVM 작동 방법

1. 하드 디스크를 여러 개로 나누어 partition을 설정한다.
2. 각 partition을 LVM으로 사용하기 위해 PV로 변환해준다.
3. 하나 이상의 PV를 그룹화하여 VG로 만든다.
4. 가상의 partition들처럼 VG를 나누어 할당한 것이 LV다.
5. LV를 새 파일시스템(마운트 포인트)과 1대 1로 마운트(연결)한다.

> 파일시스템은 파일이나 자료를 쉽게 발견, 접근할 수 있도록 보관하거나 조직하는 체제이다.

# 5. Sudo

## 5.0 sudo vs root

### 5.0.1 sudo

- 현재 계정에서 root 권한을 빌려오는 것
- 즉, sudo 자체가 유저는 아니며 root가 거부한다면 root 권한을 빌려올 수 없다.

### 5.0.2 root

- 다른 계정에서도 `` su `` 를 이용하여 root 계정으로 변환 가능
> su: root 계정으로 로그인하나 root 계정의 환경변수를 가져오지 않고 현재 계정의 환경변수를 사용  
> su - 계정명: root 계정의 환경변수까지 사용



## 5.1 sudo 프로그램이 설치되어있는가?
```
$ sudo --version
```

## 5.2 새 user를 sudo 그룹에 할당하기
```
$ sudo usermod -aG sudo <NEW_USER>
```

## 5.3 sudo의 값
```
$ sudo visudo

// 보안을 위해 secure_path(sudo가 사용할 수 있는 경로)를 제한하라
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

// Authentication 획득 실패 시 출력되는 error 메시지
Defaults        authfail_message="Failed to obtain permission"

// password가 일치하지 않는 경우 출력되는 error 메시지
Defaults        badpass_message="Failed to pass password"

// log(input, output)의 저장을 해당 디렉토리에 하라
Defaults        iolog_dir="/var/log/sudo"

// sudo 명령어 실행 시 입력된 명령어를 iolog_dir에 log로 저장하라
Defaults        log_input

// sudo 명령어 실행 시 출력 결과를 iolog_dir에 log로 저장하라
Defaults        log_output

// sudo 명령어가 tty(콘솔, 터미널) 외부(cron)에서 실행되지 않도록하라
Defaults        requiretty

// 일치하지 않는 password인 경우 입력은 3회로 제한하라
Defaults        passwd_tries=3
```

secure_path는 명령을 수행하기 위해 sudo가 실행할 소프트웨어를 찾는 경로를 의미한다.

> ``` /A:/B ``` -> A에 없으면 B에서 찾으라는 의미

> ** requiretty **
> 
> cron 등이 실제 tty를 통해 접속된 상태에서만 sudo 명령어 실행이 가능하도록 하는 옵션이다.

### 5.3.1 tty

``` tty ``` 는 예전에 정보를 컴퓨터에 입력하고 컴퓨터에서 정보를 가져오는 데 사용한 텔레타이프(TTY)에서 유래했으며 현재는 일반적으로 Unix/Linux에서 터미널을 나타내는데 사용한다. 

## 5.4 sudo의 장점

sudo는 일반 사용자가 root 권한을 빌려 명령을 실행하기 위해 사용한다. 그렇기에 다음과 같은 장점이 생긴다.

- 시스템 침입자가 sudo를 사용하면 sudoers(sudo 명령어를 사용할 수 있는 계정을 관리하는 파일)에 자신이 노출되므로 침입을 확인할 수 있다.  
- root 계정에 장시간 접속하지 않아도 되므로 위험한 명령어를 실행할 가능성이 낮아진다.  
- sudo 사용 시에는 log가 남아 추적이 쉽다.  
- root의 password를 타인과 공유하지 않아도 된다.

## 5.5 /var/log/sudo/ 폴더에 한 개 이상의 파일이 존재하는가?
```
$ sudo ls /var/log/sudo
```

## 5.6 sudo 명령어 실행 후, 로그 파일이 업데이트되었는가?
```
$ sudo apt update
$ sudo ls /var/log/sudo/00/00
```

# 6. UFW

``` UFW ``` 는 Uncomplicated Firewall의 약자로 복잡하지 않은 방화벽 관리 프로그램이다. 

> 방화벽 관리 프로그램은 데이터 패킷을 분석하고 적요오딘 규칙 집합을 기반으로 허용 여부를 결정하여 들어오고 나가는 네트워크 트래픽을 제어하는 소프트웨어나 하드웨어 기반 네트워크 보안 시스템이다.

일반적으로 리눅스에선 Iptables를 방화벽으로 사용하지만 복잡하다는(절차상 번거로운) 단점이 있다. 그래서 이를 쉽게(간편하게) 사용할 수 있도록 사용하는 것이 ``` UFW ``` 이다. 대표적으로 외부 침입자가 내부 network에 침입하는 경우를 막기위해 사용한다.

우리 과제에선 port 22를 닫고 port 4242를 여는데 사용했다.

## 6.1 UFW의 설치 여부 확인
```
$ sudo ufw --version
```

## 6.2 UFW의 작동 여부 확인
```
$ sudo ufw status
```

## 6.3 active된 UFW rule list 확인 & port 4242에 관한 rule 존재여부
```
$ sudo cat /etc/ufw/user.rules
```

## 6.4 port 8080에 새로운 rule 추가 & rule list에 해당 rule이 추가되었는지 확인
```
$ sudo ufw allow 8080
$ sudo cat /etc/ufw/user.rules
```

## 6.5 새로운 rule 삭제
```
$ sudo ufw status numbered
$ sudo ufw delete <NUMBER>
```

or

```
ufw delete allow <PORT_NUMBER>
```

# 7. SSH

``` SSH ``` (Secure Shell)는 원격으로 호스트 컴퓨터에 접속하기 위해 사용되는 인터넷 프로토콜로 단어 그대로 보안 쉘이다. 기존 유닉스 시스템 쉘에 원격 접속하기 위해 사용하던 텔넷은 암호화가 이루어지지 않아 계정 정보 탈취의 위험성이 높았기에 이에 암호화 기능을 추가하여 1995년에 나온 프로토콜이다.

쉘로 원격 접속하는 것이므로 기본적으로 CLI 상에서 작업한다. 또한 암호화 기법을 사용하기에 통신이 노출되어도 이해할 수 없는 암호화된 문자로 보인다.

![ssh 작동방식](https://user-images.githubusercontent.com/16536810/59079319-2720dc80-891e-11e9-970e-467662d9465a.png)

ssh는 서버에 접속할 때, 비밀번호대신 ssh key를 제출하는 방식이다. 이러한 ssh 키는 공개키(public key)와 비공개키(private key)로 이루어진다. 키를 생성하면 공개키와 비공개키가 생성되는데 비공개키는 로컬 머신(SSH Client), 공개키는 원격 머신(SSH Server)에 있어야 한다. SSH 접속을 시도하면 SSH Client가 로컬 머신의 비공키와 원격 머신의 비공개키를 비교해서 둘이 일치하는지 확인하는 방식으로 동작한다.

이러한 SSH는 다음과 같은 기능을 가진다.
- 보안 접속을 통한 다양한 기능 제공
- IP spoofing(IP 스푸핑, IP 위변조 기법 중 하나)을 방지하는 기능 제공
- X11 패킷 포워딩(TCP/IP 패킷 포워딩의 특별한 경우) 및 일반적인 TCP/IP([참고자료](https://nordvpn.com/ko/blog/tcp-ip-protocol/)) 패킷 포워딩을 제공

## 7.0 SSH의 작동원리

ssh가 발급하는 키는 비대칭키(공개키, 비공개키)와 대칭키가 있다. 비대칭키는 ssh 서버로 접속을 할 때 사용하고 대칭키는 서버 인증이 끝난 뒤, 정보를 교환하기 위해 사용된다. 

### 7.0.1 SSH 접속 과정

1. 클라이언트가 키젠해서 공개키, 비공개키를 다 가지고 있다.
2. 접속 요청을 받은 서버는 클라이언트에게 자신의 공개키를 전송한다.
3. 최초 접속일 경우, 서버로부터 전달받은 공개키를 로컬에 저장할 지 물어보고 동의 시, 저장한다.
4. 클라이언트는 해당 서버에 접속하기 위해 사용할 key pair(비대칭키)의 id를 전송한다.
5. 서버는 해당 id에 매칭되는 공개키를 발급했는지 확인한다.
6. 확인되었다면 난수 값을 생성하고 이를 해당 id의 공개키로 암호화하여 클라이언트에게 전송한다.
7. 클라이언트는 전달받은 암호화된 난수 값을 해당 개인키로 복호화한다.
8. 복호화한 난수를 이용하여 MD5 해시 값을 계산하여 서버로 전송한다.
9. 서버도 생성한 난수 값을 이용하여 MD5 해시 값을 계산하고 받은 값과 비교한다.
10. 같다면 접속을 허용한다.

### 7.0.2 SSH 데이터 통신 과정

접속 시, 대칭키를 생성하고 보낼 때는 대칭키로 암호화, 받을 때는 대칭키로 복호화한다. 통신이 종료되면 대칭키는 폐기되고 다시 접속할 때마다 새로운 대칭키를 생성한다.

## 7.1 SSH의 설치 여부
```
$ sudo ssh -V
```

## 7.2 SSH의 작동 여부
```
$ systemctl status ssh
```

## 7.3 SSH service가 port 4242만 사용하는가?
```
$ sudo vi /etc/ssh/sshd_config
```

> sshd_config -> server 측 설정
> ssh_config -> client 측 설정

## 7.4 SSH를 이용해 새 user로 login하기
```
$ ssh <NEW_USER>@<MAC_IP> -p <HOST_PORT>
```

## 7.5 SSH를 통해 root로 login 할 수 없는가?
```
$ cat /etc/ssh/sshd_config | grep "PermitRootLogin"
```
> ssh 연결을 위해 포트 포워딩이 필요하다.

## 7.6 키를 발급받아서 ssh 연결하기

```
$ ssh-keygen -t rsa -C <KEY_NAME>
```

그리고 경로의 마지막을 <KEY_NAME>으로 하여 새로운 키를 생성한다.  
그러면 ~/.ssh 에 KEY_NAME, KEY_NAME.pub가 생긴다. 그러면 먼저 키를 ssh 서버에 복사한다.

```
$ ssh-copy-id <USER_NAME>@<IP_NUMBER> -i <KEY_NAME.pub path> -p <PORT_NUMBER>
```

그러면 서버의 ~/.ssh에도 키가 생성된다. 이렇게 조건이 맞을 때에 접속이 가능하다.

```
$ ssh <USER_NAME>@<IP_NUMBER> -i <KEY_NAME path> -p <PORT_NUMBER>
```

# 8. Script monitoring
```
printf "#Architecture: "
uname -a

printf "#CPU physical : "
lscpu | grep -E '^Core|^Socket' | rev | cut -d ' ' -f1 | rev | awk 'BEGIN {mul = 1} {mul *= $1} END {print mul}'

printf "#vCPU : "
lscpu | grep -E '^CPU\(s\):' | rev | cut -d ' ' -f1 | rev

printf "#Memory Usage: "
free -m | grep Mem | awk '{printf"%d/%dMiB (%.2f%%)\n", $3, $2, $3/$2 * 100}' 

tdisk=`df -BM | grep -v ^Filesystem | awk '{sum += $2} END {printf sum}'`
udisk=`df -BM | grep -v ^Filesystem | awk '{sum += $3} END {printf sum}'`
echo $udisk $tdisk | awk '{printf "#Disk Usage: %d/%dMiB (%d%%)\n", $1, $2, $1/$2*100}'

###
printf "#Disk Usage: "
used=`df -BMB | grep '/dev/mapper/' | awk '{sum+=$3} END {print sum}'`
total=`df -BMB | grep '/dev/mapper/' | awk '{sum+=($3+$4)} END {print sum}'`
echo $used $total | awk '{printf"%d/%dMB (%d%%)\n", $1, $2, $1/$2*100}'
###

printf "#CPU load: "
mpstat | grep all | rev | cut -d ' ' -f1 | rev | awk '{printf "%.2f%%\n", 100-$1}'

printf "#Last boot: " 
who -b | awk '{printf $3" "$4"\n"}'

printf "#LVM use: "
if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ] ; then printf "yes\n" ; else printf "no\n" ; fi

printf "#Connections TCP : "
ss | grep -i tcp | wc -l | tr -d '\n'
printf " ESTABLISHED\n"

printf "#User log: "
who | wc -l

printf "#Network: IP "
hostname -I | tr -d '\n'
printf "("
ip link show | awk '$1 == "link/ether" {print $2}' | sed '2, $d' | tr -d '\n'
printf ")\n"

printf "#Sudo : "
ls -lR /var/log/sudo/ | grep log$ | wc -l | tr -d '\n'
printf " cmd\n"
```

## 8.0 monitoring.sh

### 8.0.1 uname -a

- 시스템의 정보를 출력하는 명령어
- -a: 시스템의 모든 정보를 가져온다.
- uname만 하면 os만 가져온다.

### 8.0.2 lscpu

- lscpu: cpu에 관련된 내용 출력
- grep -E '^내용' : 내용으로 시작하는 행 grep
- awk 'BEGIN {mul = 1} {mul *= $1} END {print mul}': 소켓당 코어 * 소켓 수 = physical CPU수
- vCPU의 개수 : 코어당 스레드 수 * 소켓당 코어 * 소켓 수 

### 8.0.3 cat /proc/cpuinfo

- cpu 정보를 가져온다.
- processor는 프로세서의 id
- 따라서 processor만 가져와 줄 개수를 구하면 가상 cpu의 개수
- 가상 cpu는 물리적 cpu와 기본적으론 다르지 않다.
- 그러나 하이퍼 스레딩을 사용하면 하나의 cpu 당, 두 개의 프로세서를 담당하기에 물리적 cpu의 2배로 늘어난다.
- [하이퍼 스레딩 참고 자료](https://coolenjoy.net/bbs/37/3269?device=pc)

### 8.0.4 free -m 

- free: 빈 메모리와 사용하는 메모리를 표시
- -m: 메비바이트(mib) 단위로 표시
- --mega: 메가바이트 단위로 표시

> 메비바이트
>   
> 메비바이트(mebibyte, MiB)란 메가바이트(megabyte, MB)와 조금의 차이를 보인다.  
> - 1MB = 1,000,000 byte (= 1000 ** 2)
> - 1MiB = 1,048,576 byte (= 1024 ** 2)
>  
> 설명을 쉽게 하기 위해 mega, kilo, giga 등의 SI 단위를 붙이며 엄밀히 1024 byte를 1000 byte로 나눠 해석했다. 그러나 용량의 단위가 커지면서 24 byte의 차이가 큰 차이를 가져오기 시작했다. (지수로 커지기에) 그래서 엄밀하게 1024 byte를 사용한 단위의 필요성이 대두되었고 이에 i를 사이에 붙여 단위들을 만들게 되었다.
>   
> - 1024 KiB = 1 MiB

### 8.0.5 df 

- 사용가능한 디스크 공간을 보여주는 명령어
- -B(+size): 뒤에 오는 사이즈를 단위로 공간들을 출력한다. 

> - BM: 메비바이트 단위로 출력  
> - BMB: 메가바이트 단위로 출력  
> - 그 외에 G, GB, K, KB 등 여러 단위로 출력 가능

- /dev/mapper 폴더만 가져온 이유는 우리가 쓰는 공간이 맞는 듯
- 윈도우에서 c드라이브에 OS 용량을 포함해서 하듯이 여기도 전체 용량을 더하여 하는 것이 더 맞다고 여김

### 8.0.6 mpstat

- 사용가능한 CPU와 core 별로 사용율을 모니터링하는 명령어
- 레드햇 계열에선 sysstat 패키지를 설치할 때, 같이 설치
- CPU: 보는 CPU, all이면 모든 cpu, 그외에는 cpu의 번호
- %usr: 사용자 레벨(어플리케이션)이 사용한 CPU 사용율
- %nice: nice 우선순위(프로세스의 우선순위를 변경하는 명령어, [참고](https://jhnyang.tistory.com/394))와 함께 사용자 레벨에서 수행된 CPU 사용율
- %sys: 시스템 레벨(커널)에서 사용한 CPU 사용율
- %iowait: I/O 처리 때문에 기다리는 CPU 시간 백분율
- %irq: H/W 인터럽트를 서비스하기 위해 사용된 CPU 사용율
- %soft: S/W 인터럽트를 서비스하기 위해 사용된 CPU 사용율
- %steal: 하이퍼바이저가 다른 가상 프로세서에 의해 서비스될 때 기다리는 CPU 시간 백분율
- %guest: 가상 프로세서가 실행하기 위해 사용되는 CPU 사용율
- %idle: 유휴한 CPU 시간 백분율
> 유휴 시간: 컴퓨터가 작동 가능한데도 작업을 하지 않는 시간, 주로 컴퓨터의 입출력을 위한 대기 시간

- 따라서 현재 사용하고 있는 프로세서는 유휴한 CPU를 제외한 나머지이다.
- 이는 %usr ~ %gnice를 더한 것과 100 - %idle한 값이 일치한다.

### 8.0.7 who

- 누가 로그인했는지 보여주는 명령어
- -b: 마지막 리부트 날짜를 보여준다. 

### 8.0.8 lsblk

- 리눅스 디바이스 정보를 출력하는 명령어로 blkid보다 더 상세한 정보를 표시
- lvm은 type에서 lvm으로 표시되기에 grep으로 가져오기 편하다.
- -gt: 앞의 값이 더 큰 경우
- 즉, 0보다 클 때만 then으로, 작거나 같으면 else로 간다.
- 더 많은 쉘 스크립트 조건문은 [여기](https://jink1982.tistory.com/48) 참고

### 8.0.9 ss

- 리눅스 시스템의 소켓 상태를 조회할 수 있는 명령어
- netstat과 비슷한 동작을 하지만 최근 리눅스 배포판에선 ss를 권장
- 기본적인 연결을 tcp로 하기에 활성화된 tcp를 확인
  
- 기본적으론 listening socket(연결을 위해 대기 중인 소켓)을 제외한 현재 연결된 모든 소켓(TCP/UDP/Unix)을 표시한다.
- -a: 모든 소켓 표시
- -f: 옵션으로 소켓 유형 조회(unix, inet, inet6, link, netlink, vsock)
- -t: TCP 소켓만 표시

### 8.0.10 who

- 서버에 로그인 중인 유저들의 로그들을 출력한다.
- /var/run/utmp 파일에 저장
- 사용자가 원격으로 서버에 로그인할 때 사용자 정보를 저장하고 사용자가 원격 호스트에서 로그아웃할 때 정보를 제거한다.

### 8.0.11 hostname

- 시스템의 호스트네임을 보여주는 명령어
- 옵션에 따라 다른 시스템 관련 정보나 호스트네임을 변경할 수도 있다.

- -I: 호스트의 모든 주소를 가져온다. (루프백과 ipv6는 생략)
- 만약 네트워크 인터페이스가 여러 개라면 어떤 네트워크 디바이스로 라우팅 되는지 확인할 수 없기에 확인절차가 필요
- 허나 crontab을 통해서 처리는 불가

### 8.0.12 ip

- 리눅스 시스템 관리자가 알아야 하는 네트워크 인터페이스를 구성하기 위한 명령어
- link: 네트워크 인터페이스를 표시하고 수정
- link/ether에 있는 MAC 주소를 가져옴
- ether가 여러개 나올 경우를 대비하여 sed '2, $d'로 2번째 줄 지우기

### 8.0.13 sudo 로그

- sudo 로그는 /var/log/sudo/00 안에 생김
- 그 안에 00이란 폴더 안에 00, 01, 02, ..., 11, ..., 1A 이런식으로 순차적으로 생성
- 그 후, 숫자와 알파벳으로 만들 수 있는 모든 두자리를 사용하면 01이란 폴더를 새로 만들고 반복
- 그렇기에 /var/log/sudo/00 안에 있는 모든 하위 폴더를 확인하여 log로 끝나는 파일의 개수를 세는 것으로 확인
- log로 끝나는 파일은 log란 파일만 존재한다.

## 8.1 cron이란?

특정 작업을 특정 시간에 자동으로 실행시키기 위한 시간 기반 job scheduler 형 데몬이다. cron은 crontab이란 설정 파일을 기반으로 작동한다.
즉, `` 특정 시간에 특정 작업을 할 수 있게 도와주는 것 `` 이 cron이다. 

> 데몬은 사용자가 직접적으로 제어하지 않고, 백그라운드에서 돌면서 여러 작업을 하는 프로그램을 말한다. 백그라운드 프로세스와 다른 점은 사용자와 상호작용하지 않는 독자적인 프로세스라는 것이다.

### 8.1.1 crontab basic

- 편집
```
$ crontab -e
```

일단 기본 명령어는 e옵션을 이용한 것으로 위 명령어를 입력하면 크론탭을 설정할 수 있는 장소로 들어간다. 

- 보기
```
$ crontab -l
```

만약 보고만 싶다면 l옵션으로 cat과 같은 동작을 실행시킬 수 있다. 

- 삭제
```
$ crontab -r
```

그리고 크론탭의 설정을 삭제하고 싶다면 r옵션을 이용하면 된다. 

### 8.1.2 주기 결정
```
* * * * * command 
| | | | |_ // 요일
| | | |_ // 월
| | |_ // 날짜
| |_ // 시간
|_ // 분

// 예시1) 5일에서 6일까지 2시,3시,4시에 매 10분마다 test.sh 를 실행
*/10 2,3,4 5-6 * * /home/script/test.sh

// 10분마다 monitoring.sh를 실행, wall명령어를 통해 전체로 보냄
*/10 * * * * /monitoring.sh | wall
```

```
$ sudo crontab -e

// crontab
*/10 * * * * bash ~/monitoring.sh

$ sudo service cron restart
```

- 서버 시작 시, script 실행 안 되게 수정
```
$ sudo systemctl disable cron
$ sudo reboot
$ sudo service cron status
$ sudo systemctl enable cron
```

### 8.1.3 팁

크론을 쓸 때는 한 줄에 하나의 명령만 써야 한다.
```
# 잘못된 예
* * * 5 5
/home/script/test.sh
```

```
# 잘된 예
* * * 5 5 /home/script/test.sh
```

```
# 실행이 안될 때
- monitoring.sh 절대경로인지 확인
- 파일 권한 확인
```

### 8.1.4 crontab off

```
sudo systemctl disable cron # 끈다.
sudo systemctl status cron # 꺼졌는지 확인
reboot # 리부트
```

그 외에도 크론 작업 내역을 로그로 남기거나 기존 크론 내역을 백업할 수도 있다. 이에 대해서는 [이곳](https://jdm.kr/blog/2)을 참고하면 된다.

---

## 참고

- [태헌의 notion, born2beroot](https://www.notion.so/born2beroot-2ce1177e08904c329fb437c7fdcd7113)
- [syyim, [스터디 정리]하이퍼바이저의 종류](https://lovejaco.github.io/posts/two-types-of-hypervisors/)
- [Red Hat, 가상머신이란?](https://www.redhat.com/ko/topics/virtualization/what-is-a-virtual-machine#%ED%95%98%EC%9D%B4%ED%8D%BC%EB%B0%94%EC%9D%B4%EC%A0%80-%EC%9C%A0%ED%98%95)
- [Red Hat, yum의 개념과 사용법](https://access.redhat.com/ko/solutions/82093)
- [joonpark.log, aptitude vs apt](https://velog.io/@joonpark/aptitude-vs-apt)
- [SGB IT 프로젝트, 리눅스 LVM에 관하여(Centos 6.6 기준)](https://sgbit.tistory.com/12)
- [외눈박이 행성의 두눈박이 두 번째 집, 12. Linux - Sudo 명령어 및 sudoers 파일](https://whitewing4139.tistory.com/74)
- [위키백과, UFW](https://ko.wikipedia.org/wiki/UFW)
- [hyeseong-dev.log, [리눅스] ssh란?](https://velog.io/@hyeseong-dev/%EB%A6%AC%EB%88%85%EC%8A%A4-ssh%EB%9E%80)
- [JDM's Blog, 리눅스 크론탭 사용법](https://jdm.kr/blog/2)
- [Mr.november11, [Linux]sudo 명령어 수행 시 sudo: sorry, you must have a tty to run do Error가 발생할 때 해결 방안
출처: https://november11tech.tistory.com/98 [Mr.november11:티스토리]](https://november11tech.tistory.com/98)
- [NDS 클라우드 기술 블로그, [소개] 가상화의 종류 3가지](https://tech.cloud.nongshim.co.kr/2018/09/18/%EA%B0%80%EC%83%81%ED%99%94%EC%9D%98-%EC%A2%85%EB%A5%983%EA%B0%80%EC%A7%80/)
- [Today I Learned... 염초코, [공부] SSH (Secure Shell) : 기초 및 심화 개념](https://choco4study.tistory.com/32)
- [skylove1982, 리눅스에서 CPU 정보를 확인하는 8가지 명령어](https://skylove1982.tistory.com/entry/%EB%A6%AC%EB%88%85%EC%8A%A4%EC%97%90%EC%84%9C-CPU-%EC%A0%95%EB%B3%B4%EB%A5%BC-%ED%99%95%EC%9D%B8%ED%95%98%EB%8A%94-8%EA%B0%80%EC%A7%80-%EB%AA%85%EB%A0%B9%EC%96%B4-cpuinfo-lscpu-hardinfo-lshw-nproc-dmidecode-cpuid-inxi)
- [서버 모니터링 by 이동인, MiB와 MB는 어떻게 다른가?](https://brunch.co.kr/@leedongins/133)
- [IT 이야기, [명령어] mpstat 설명](https://blueyikim.tistory.com/555)
- [오뇽, [리눅스 명령어]who - 호스트에 로그인한 사용자 정보 출력](https://shaeod.tistory.com/623)
