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

1. 하드 디스크를 여러 개로 나누어 partition을 설정한다.
2. 각 partition을 LVM으로 사용하기 위해 PV로 변환해준다.
3. 하나 이상의 PV를 그룹화하여 VG로 만든다.
4. 가상의 partition들처럼 VG를 나누어 할당한 것이 LV다.
5. LV를 새 파일시스템(마운트 포인트)과 1대 1로 마운트(연결)한다.

> 파일시스템은 파일이나 자료를 쉽게 발견, 접근할 수 있도록 보관하거나 조직하는 체제이다.

# 5. Sudo

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

# 6. ``` UFW ```

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

# 7. ``` SSH ```

``` SSH ``` (Secure Shell)는 원격으로 호스트 컴퓨터에 접속하기 위해 사용되는 인터넷 프로토콜로 단어 그대로 보안 쉘이다. 기존 유닉스 시스템 쉘에 원격 접속하기 위해 사용하던 텔넷은 암호화가 이루어지지 않아 계정 정보 탈취의 위험성이 높았기에 이에 암호화 기능을 추가하여 1995년에 나온 프로토콜이다.

쉘로 원격 접속하는 것이므로 기본적으로 CLI 상에서 작업한다. 또한 암호화 기법을 사용하기에 통신이 노출되어도 이해할 수 없는 암호화된 문자로 보인다.

![ssh 작동방식](https://user-images.githubusercontent.com/16536810/59079319-2720dc80-891e-11e9-970e-467662d9465a.png)

ssh는 서버에 접속할 때, 비밀번호대신 ssh key를 제출하는 방식이다. 이러한 ssh 키는 공개키(public key)와 비공개키(private key)로 이루어진다. 키를 생성하면 공개키와 비공개키가 생성되는데 비공개키는 로컬 머신(SSH Client), 공개키는 원격 머신(SSH Server)에 있어야 한다. SSH 접속을 시도하면 SSH Client가 로컬 머신의 비공키와 원격 머신의 비공개키를 비교해서 둘이 일치하는지 확인하는 방식으로 동작한다.

이러한 SSH는 다음과 같은 기능을 가진다.
- 보안 접속을 통한 다양한 기능 제공
- IP spoofing(IP 스푸핑, IP 위변조 기법 중 하나)을 방지하는 기능 제공
- X11 패킷 포워딩(TCP/IP 패킷 포워딩의 특별한 경우) 및 일반적인 TCP/IP([참고자료](https://nordvpn.com/ko/blog/tcp-ip-protocol/)) 패킷 포워딩을 제공

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
$ sudo <NEW_USER>@<MAC_IP> -p <HOST_PORT>
```

## 7.5 SSH를 통해 root로 login 할 수 없는가?
```
$ cat /etc/ssh/sshd_config | grep "PermitRootLogin"
```
> ssh 연결을 위해 포트 포워딩이 필요하다.

# 8. Script monitoring
```
printf "#Architecture: "
uname -a

printf "#CPU physical : "
nproc --all

printf "#vCPU : "
cat /proc/cpuinfo | grep processor | wc -l

printf "#Memory Usage: "
free -m | grep Mem | awk '{printf"%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'

printf "#Disk Usage: "
df -a -BM | grep /dev/map | awk '{sum+=$3}END{print sum}' | tr -d '\n'
printf "/"
df -a -BM | grep /dev/map | awk '{sum+=$4}END{print sum}' | tr -d '\n'
printf "MB ("
df -a -BM | grep /dev/map | awk '{sum1+=$3 ; sum2+=$4 }END{printf "%d", sum1 / sum2 * 100}' | tr -d '\n'
printf "%%)\n"

printf "#CPU load: "
mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'

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
journalctl _COMM=sudo | wc -l | tr -d '\n'
printf " cmd\n"
```

```
uname -a // 시스템의 정보를 출력
nproc --all // 물리적으로 설치된 프로세스 갯수
cat /proc/cpuinfo | grep processor | wc -l
free -m // 메모리 사용량을 mb 단위(-m)로 출력한다
df -P // 리눅스 내 디스크 메모리 전체 현황을 한줄로(-P) 출력한다
mpstat // 현재 CPU의 사용량을 출력한다
who -b // 마지막 리부트 날짜와 시간
ss -t | grep -i ESTAB // 활성화된 tcp 네트워크 상태를 출력한다 | 대문자/소문자를 구분하지 않고 ESTAB을 찾는다
who // 서버를 사용하는 유저들을 출력한다
hostname -I // IPv4 주소
```

## 8.1 cron이란?

특정 작업을 특정 시간에 자동으로 실행시키기 위한 시간 기반 job scheduler 형 데몬이다. cron은 crontab이란 설정 파일을 기반으로 작동한다.

> 데몬은 사용자가 직접적으로 제어하지 않고, 백그라운드에서 돌면서 여러 작업을 하는 프로그램을 말한다. 백그라운드 프로세스와 다른 점은 사용자와 상호작용하지 않는 독자적인 프로세스라는 것이다.

## 8.2 10분마다 실행되도록 설정
```
* * * * * command 
| | | | |_ // 요일
| | | |_ // 월
| | |_ // 날짜
| |_ // 시간
|_ // 분

// 예시1) 5일에서 6일까지 2시,3시,4시에 매 10분마다 test.sh 를 실행
*/10 2,3,4 5-6 * * /home/script/test.sh

// 10분마다 monitoring.sh를 싱행
*/10 * * * * /monitoring.sh
```

```
$ sudo crontab -e

// crontab
*/10 * * * * bash ~/monitoring.sh

$ sudo service cron restart
```

---

## 참고 문헌

- [태헌의 notion, born2beroot](https://www.notion.so/born2beroot-2ce1177e08904c329fb437c7fdcd7113)
- [syyim, [스터디 정리]하이퍼바이저의 종류](https://lovejaco.github.io/posts/two-types-of-hypervisors/)
- [Red Hat, 가상머신이란?](https://www.redhat.com/ko/topics/virtualization/what-is-a-virtual-machine#%ED%95%98%EC%9D%B4%ED%8D%BC%EB%B0%94%EC%9D%B4%EC%A0%80-%EC%9C%A0%ED%98%95)
- [Red Hat, yum의 개념과 사용법](https://access.redhat.com/ko/solutions/82093)
- [joonpark.log, aptitude vs apt](https://velog.io/@joonpark/aptitude-vs-apt)
- [SGB IT 프로젝트, 리눅스 LVM에 관하여(Centos 6.6 기준)](https://sgbit.tistory.com/12)
- [외눈박이 행성의 두눈박이 두 번째 집, 12. Linux - Sudo 명령어 및 sudoers 파일](https://whitewing4139.tistory.com/74)
- [위키백과, UFW](https://ko.wikipedia.org/wiki/UFW)
- [hyeseong-dev.log, [리눅스] ssh란?](https://velog.io/@hyeseong-dev/%EB%A6%AC%EB%88%85%EC%8A%A4-ssh%EB%9E%80)