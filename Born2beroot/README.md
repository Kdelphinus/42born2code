# Born2beroot

# Index

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

## 1.2 ``` CentOS ``` 와 ``` Dibian ``` 의 차이점

두 OS 모두 ``` 리눅스 커널 + 자유소프트웨어 ``` 로 구성된 리눅스 배포판이다. 그렇기에 두 OS의 차이는 자유소프트웨어(패키지 포맷, 패키지 관리 툴 등)이다.

> 리눅스 커널이란?  
>  
> 리눅스 OS의 주요 구성 요소이며 컴퓨터 하드웨어와 프로세스를 잇는 핵심 인터페이스이다.  
>  
> 커널이란 이름은 단단한 껍질 안의 씨앗처럼 OS 내에 위치하고 어떤 유형에 관계없이 하드웨어의 모든 주요 기능을 제어하기 때문에 붙은 이름이다. 

### 1.2.1 ``` CentOS ```

- RHEL(레드헷 엔터프라이즈 리눅스, 레드헷이 개발한 컴퓨터 운영체제이자 유로기업용 서버 OS)에서 사후 기술지원과 상표권을 배제하고 제작한 오픈소스
- 패키지 포맷으로 .rpm 확장자를 사용하고, yum(yellow dog update, duke university에서 RPM 설치를 개선하기 위해 개발한 패키지 관리자)을 패키지 관리 툴로 사용한다.

### 1.2.2 ``` Debian ```

- debian 프로젝트에서 제작한 오픈소스다.
- 패키지 포맷으로 .deb 확장자를 사용하고 dpkg(데비안 패키지 관리 시스템의 기초가 되는 소프트웨어)와 APT를 패키지 관리 툴로 사용한다.
- 패키지 관리가 매우 편하다.
- Ubuntu는 debian 기반의 OS다.
- APT는 처음에는 debian 계열을 위해 고안되었으나 현재는 .rpm 패키지와도 호환되도록 업데이트되어서 CentOS에서도 사용 가능하다.

## 1.3 ``` virtual machine ``` 의 장점

1. 비용 절감  
여러 가상 환경을 하나의 인프라(하드웨어)에서 설치하기에 물리적 인프라 설치 공간을 줄일 수 있게 된다. 이 때문에 많은 서버를 유지 보수하지 않아도 되고 많은 전력을 사용할 필요가 없어 비용을 줄이는 데 도움이 된다.

2. 간편함 + 속도
새로운 OS를 구동하려는 경우, 물리적 서버를 포함한 새 환경 전체를 준비하는 것보다 빠르고 간편하다.

3. downtime(시스템을 이용할 수 없는 시간)의 최소화
vm은 호스트가 예기치 않게 중단될 경우, 다른 물리적 서버의 하이퍼바이저로 이전할 수 있다. 이는 유용한 백업 대책이 있다는 의미이다.  

## 1.4 ``` aptitude ``` 와 ``` apt ``` 의 차이점 (in debian)

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

## 1.5 ``` APPArmor ``` (Application Armor)는 무엇인가?

``` APPArmor ``` 는 리눅스 커널의 보안 시스템이다. 오픈 소스이고 생성한 개별 프로그램에 대한 profile 파일을 통해 여러 권한을 통제함으로 개별 프로그램을 보호한다.

- 네트워크 액세스 권한
- raw 소켓([참고자료](https://mangkyu.tistory.com/16)) 액세스 권한
- 파일의 읽기, 쓰기, 실행 권한

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
$ groups
// or
$ getent group sudo user42
// or
$ id
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
PASS_MIN_LEN 10  // 최소 10글자 이상

$ sudo apt install libpam-pwquality // 패키지 설치
$ sudo vi /etc/pam.d/common-password // 이 파일에서 비밀번호 정책 수정

/// common-passwrod 파일 수정
retry=3 // 암호 재입력은 최대 3회까지
minlen=10 // 최소 길이 10
difok=7 // 기존 패스워드와 달라야 하는 문자 수 7
maxrepeat=3 // 동일한 문자를 반복 가능한 최대 횟수 3
ucredit=-1 // 대문자 한개 이상 포함
lcredit=-1 // 소문자 한개 이상 포함
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

## 4.6 ``` LVM ``` 이란?

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


---

## 참고 문헌

- [태헌의 notion, born2beroot](https://www.notion.so/born2beroot-2ce1177e08904c329fb437c7fdcd7113)
- [syyim, [스터디 정리]하이퍼바이저의 종류](https://lovejaco.github.io/posts/two-types-of-hypervisors/)
- [Red Hat, 가상머신이란?](https://www.redhat.com/ko/topics/virtualization/what-is-a-virtual-machine#%ED%95%98%EC%9D%B4%ED%8D%BC%EB%B0%94%EC%9D%B4%EC%A0%80-%EC%9C%A0%ED%98%95)
- [Red Hat, yum의 개념과 사용법](https://access.redhat.com/ko/solutions/82093)
- [joonpark.log, aptitude vs apt](https://velog.io/@joonpark/aptitude-vs-apt)
- [SGB IT 프로젝트, 리눅스 LVM에 관하여(Centos 6.6 기준)](https://sgbit.tistory.com/12)
