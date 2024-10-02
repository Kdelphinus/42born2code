# C++ Modules

## General rules

### Compiling
- `-Wall -Wextra -Werror` 플래그가 있어야 함
- `-std=c++98` 버전으로 컴파일 되야 함

### 형식 및 이름 규칙
- 각 문제 별 폴더 이름은 `ex00, ex01, ..., ex[number]` 이다.
- 이름은 **UpperCamelCase** 형식으로 명명해야 한다.
- 특별한 경우가 아닌 이상, 모든 출력 메세지는 반드시 개행으로 끝나야 하며 표준 출력에 표시되어야 한다.
- Norminette은 사용하지 않는다.

### 허용/금지 함수
- 표준 라이브러리의 모든 함수들이 허용된다.
- 하지만 외장 라이브러리(C++11나 Boost 라이브러리)는 금지된다.
- 또한 *printf(), *alloc(), free()도 금지된다.
- `using namespace <ns_name>` 과 `friend` 키워드 역시 금지된다.
- **STL** 의 사용은 오직 Module 08과 09에서만 사용 가능하다.
- Containers(vector, list, map 등)와 Algorithms(<algorithm> 헤더에 있는 모든 함수들)은 금지된다.

### 설계 요구
- memory leaks 금지
- Module 02 ~ 09의 클래스들은 명시적으로 규정된 것들을 제외하고 **Orthodox Canonical Form** 을 지켜야 한다.
- 헤더 파일에 함수를 구현하면 안 된다.
  - 원문: Any function implementation put in a header file (except for function templates)
    means 0 to the exercise.
- 각 헤더를 다른 헤더와 독립적으로 사용이 가능해야 한다. 그렇기에 필요한 모든 종속성을 포함해야 한다.
- 그러나 include guards를 추가하여 이중 포함 문제는 피해야 한다.

### 그 외
- 필요한 경우 파일을 추가할 수 있습니다. 필수 파일을 제출하는 한, 다른 파일도 자유롭게 제출할 수 있습니다.
- 과제의 지침이 짧을 수 있지만 평가에서 명시되지 않은 요구사항이 있을 수 있습니다.
- 시작하기 전에, 각 모듈을 읽어보세요.
