# Inception

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