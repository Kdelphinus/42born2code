# Inception

## Index
- [Subject](#subject)
  - [General guidelines](#general-guidelines)
  - [Mandatory part](#mandatory-part)
    - [설정해야 할 것](#설정해야-할-것)
    - [그 외 주의사항](#그-외-주의사항)
- [개념](#개념)
  - [Docker](#docker)
  - [Container](#container)
  - [Imgae](#imgae)
  - [레이어 저장방식](#레이어-저장방식)
  - [Dockerfile](#dockerfile)
  - [Docker-compose](#docker-compose)
- [참고 문헌](#참고-문헌)

## Subject

### General guidelines

- 이 프로젝트는 가상머신 위에서 작업해야 한다.
- 프로젝트 구성에 필요한 모든 파일은 `srcs` 폴더에 있어야 한다.
- `Makefile`은 `root` 폴더에 위치해야 한다. 또한 전체 애플리케이션을 설정해야 한다.
- 즉, `docker-compose.yml` 파일을 통해 `Docker image`를 빌드해야 한다.

### Mandatory part

이 프로젝트는 특정 규칙에 따라 다양한 서비스로 구성된 소규모 인프라를 설정하는 것으로 구성된다.
전체 프로젝트는 가상 머신에서 수행해야 하며 `docker compose`를 사용해야 한다.

- 각 docker image는 해당 서비스와 동일한 이름을 가져야 한다. 그리고 전용 컨테이너에서 실행되어야 한다.
- 성능 문제를 위해 컨테이너는 두 번째로 안정적인 버전(penultimate stable version)의 `Alpine`이나 `Debian`을 사용해야 한다.
- 또한 서비스당 하나씩 자체 `Dockerfiles`을 작성해야 한다. `Dockerfiles`은 반드시 Makefile에서 `docker-compose.yml`로 호출해야 한다.

> 즉, 프로젝트의 docker image를 직접 빌드해야 한다.

- 기존 docker image나 DockerHub 같은 서비스 사용은 금지된다. (Alpine, Debian은 제외)

#### 설정해야 할 것

- TLSv1.2나 TLSv1.3의 `NGINX`를 포함하는 도커 컨테이너
- nginx를 제외한 `WordPress` + `php-fpm`(반드시 설치 및 구성해야 한다.)를 포함한 도커 컨테이너
- nginx를 제외한 `MariaDB`를 포함한 도커 컨테이너
- `WordPress database`를 포함한 볼륨
- `WordPress website files`를 포함한 두번째 볼륨
- 컨테이너들을 연결하는 `docker-network`를 설정한다.
- 컨테이너가 crash나면 다시 시작해야 한다.

> Docker 컨테이너는 가상 머신이 아니다. 그러므로 `tail -f` 등을 기반으로 하는 hacky patch를 사용하지 않는 것이 좋다.
> demon의 작동 방식과 사용하는 것이 좋은지 나쁜지에 대해 읽어보면 좋다.

> host나 --link, links 등 네트워크 사용은 금지된다. 네트워크 줄은 docker-compose.yml 파일에 있어야 한다.  
> 컨테이너는 무한 루프를 실행하는 명령으로 시작하면 안 된다. 이는 entrypoint나 entrypoint scripts를 사용하는 모든 명령어에도 적용된다.  
> 다음은 몇 가지 금지된 hacky patches들이다.  
> ->  tail -f, bash, sleep infinity, while true.

> `PID 1`과 Dockrfiles 모범 사례에 대해 찾아보면 좋다.

- WordPress 데이터베이스 반드시 두 명의 사용자가 있어야 하며 그 중 하나는 관리자여야 한다. 이때 이름은 admin/Admin이란 단어가 포함되면 안 된다.

> 보륢은 도커를 사용하는 호스트 머신의 /home/login/data 폴더에서 사용할 수 있다. 물론 login은 사용자 계정으로 바꿔야 한다.

작업을 더욱 간단하게 하려면, 도메인 이름이 로컬 IP 주소를 가리키도록 구성해야 한다.

도메인의 이름은 반드시 `login.42.fr` 이어야 한다. 여기서도 사용자의 login 이름을 사용해야 한다.
예를 들어, 너가 myko라면 `myko.42.fr`이 myko의 웹사이트를 가리키는 IP 주소로 리다이렉트된다.

> #### 그 외 주의사항
> - 최신 태그는 금지된다.
> - Dockerfile들에는 비밀번호가 없어야 한다.
> - 환경 변수는 반드시 사용해야 한다.
> - 또한 `.env` 파일을 사용하여 환경 변수를 저장할 것을 강력히 권장한다. 이때, `.env` 파일은 `srcs` 폴더의 루트 폴더에 있어야 한다.
> - NGINX 컨테이너는 포트 443을 통해서만 인프라로 진입할 수 있어야 한다. 443 포트를 통해서만 인프라에 접속할 수 있으며, TLSv1.2나 TLSv1.3을 프로토콜로 사용해야 한다.

프로젝트의 다이어그램이다.

![diagram.png](img/diagram.png)

폴더 구조의 한 예시이다.

![directory_structures.png](img/directory_structures.png)

> 보안상의 이유로 모든 자격 증명, API 키, 환경 변수 등은 .env 파일에 로컬로 저장하고 git에선 무시해야 한다.
> 공개적으로 저장된 자격 증명을 사용하면 0점을 받게 된다.

## 개념

### Docker
- 컨테이너 기반의 오픈소스 가상화 플랫폼
- 다양한 프로그램, 실행환경을 컨테이너로 추상화하하고 동일한 인터페이스를 제공하여 프로그램의 배포 및 관리를 단순하게 해준다.
- 백엔드 프로그램, 데이터베이스 서버, 메시지 큐 등 어떤 프로그램도 컨테이너로 추상화 가능
- 그리고 어떤 환경에서도 실행 가능

### Container
- 격리된 공간에서 프로세스가 동작하는 기술
- 기존 가상화 대상이었던 OS 대신 프로세스를 격리하는 방식을 `리눅스 컨테이너`라고 한다.

### Imgae
- 컨테이너 실행에 필요한 파일과 설정값 등을 포함하고 있는 것
- 상태값을 가지지 않고 변하지 않는다.
- 컨테이너는 이미지를 실행한 상태라고 볼 수 있으며 추가되거나 변하는 값은 컨테이너에 저장된다.

### 레이어 저장방식
- 이미지는 여러 개의 읽기 전용 레이어로 구성되며 이 레이어를 바탕으로 파일 시스템을 구성한다.
- 그렇기에 기존 이미지에 파일을 추가해도 레이어 하나만 추가하기에 굉장히 효율적이다.

### Dockerfile
```dockerfile

# vertx/vertx3 debian version
FROM subicura/vertx3:3.3.1
MAINTAINER chungsub.kim@purpleworks.co.kr

ADD build/distributions/app-3.3.1.tar /
ADD config.template.json /app-3.3.1/bin/config.json
ADD docker/script/start.sh /usr/local/bin/
RUN ln -s /usr/local/bin/start.sh /start.sh

EXPOSE 8080
EXPOSE 7000

CMD ["start.sh"]
```
- 이미지를 만들기 위한 설정 파일
- 자체 DSL(Domain Specific Language)을 사용하여 이미지 생성 과정을 정의한다.

### Docker compose
- 단일 서버에서 여러 개의 컨테이너를 하나의 서비스로 정의해 묶음으로 관리할 수 있는 작업 환경을 제공하는 도구
- 여러 개의 컨테이너가 하나의 어플리케이션으로 동작할 때 각각의 컨테이너 테스트를 위해 일일이 컨테이너를 실행하는 것은 매우 번거롭기 때문에 Docker compose를 사용한다.
- docker compose는 여러 개의 컨테이너의 옵션과 환경을 정의한 파일을 읽어 컨테이너를 순차적으로 생성하는 방식으로 동작한다.
- 이때, 각 컨테이너의 의존성, 네트워크, 볼륨 등과 컨테이너의 수 등도 조절할 수 있다.

#### docker-compose.yml
```yaml
version: '3.9' # yaml 파일 포맷 버전

services: # 도커 컴포즈로 생성할 컨테이너 옵션 정의
  db: # 생성할 컨테이너 이름 
    image: mysql:8 # 사용할 이미지
    volumes: # 컨테이너에서 사용할 볼륨
    - db:/var/lib/mysql
    restart: unless-stopped # 컨테이너가 종료되었을 때 자동으로 재시작
    environment: # 컨테이너 내부에서 사용할 환경변수
    - MYSQL_ROOT_PASSWORD=seosh817
    - MYSQL_DATABASE=seosh817
    - MYSQL_USER=seosh817
    - MYSQL_PASSWORD=seosh817
    networks: # 컨테이너가 사용할 네트워크
    - wordpress

  wordpress:
    depends_on: # 특정 컨테이너와 의존 관계, 이 항목에 명시된 컨테이너가 먼저 실행
    - db
    image: wordpress:latest
    ports: # 서비스의 컨테이너를 개방할 포트
    - "8000:80"
    restart: unless-stopped
    environment:
      WORDPRESS_DB_HOST: db:3306
      WORDPRESS_DB_USER: seosh817
      WORDPRESS_DB_PASSWORD: seosh817
      WORDPRESS_DB_NAME: seosh817
    networks:
    - wordpress

volumes:
  db: {}

networks:
  wordpress: {}
```
> yaml 파일에서 들여쓰기는 tab이 아닌 공백 2칸으로 한다.
- docker-compose.yml은 기존 run 명령어를 yaml 파일로 변환한 것이다.
- 위 docker-compose.yml 파일은 wordpress와 mysql 두 개의 서비스가 존재하고 볼륨을 db, 네트워크를 wordpress로 정의하였다.

```shell
# Foreground로 도커 컴포즈 프로젝트 실행
$ docker-compose up

# Background로 도커 컴포즈 프로젝트 실행
$ docker-compose up -d

# 프로젝트 이름 my-project로 변경하여 도커 컴포즈 프로젝트 실행
$ docker-compose -p my-project up -d

# docker-compose scale 명령어로 각 서비스에 여러개의 컨테이너를 생성
# 단, scale 시 주의할 점은 포트를 여러개 지정하면 충돌이나므로 호스트 포트는 하나만 지정해주어야 함.
$ docker-compose scale [서비스명]=[컨테이너 갯수]
```
- `-d`: 도커 컴포즈 프로젝트를 백그라운드에서 실행
- `-p`: 프로젝트 이름 지정, 명시하지 않으면 현재 디렉토리의 이름

```shell
# 프로젝트 내 컨테이너 및 네트워크 종료 및 제거
$ docker-compose down

# 프로젝트 내 컨테이너, 네트워크 및 볼륨 종료 및 제거
$ docker-compose down -v
```
- `-v`: 프로젝트 내 볼륨까지 제거

```shell
# 프로젝트 내 컨테이너 목록 확인
$ docker-compose ps
```


## 참고 문헌
- [42seoul, inception](./en.subject.pdf)
- [Shane's planet, Ubuntu 20.04 LTS) Docker 설치하기](https://shanepark.tistory.com/237)
- [subicura, 초보를 위한 도커 안내서 - 도커란 무엇인가?](https://subicura.com/2017/01/19/docker-guide-for-beginners-1.html)
- [seunghwaan, 도커 컴포즈 - 개념 정리 및 사용법](https://seosh817.tistory.com/387)