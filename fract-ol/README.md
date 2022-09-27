# fract-ol

# Index
[0. 개념](#0-개념)  
- [0.1 fractal](#01-fractal)  
- [0.2 Mandelbrot set](#02-mandelbrot-set)  
- [0.3 Julia set](#03-julia-set)  
- [0.4 복소수의 표현](#04-복소수의-표현)  

[1. Mandatory part](#1-mandatory-part)  

[2. Bonus part](#2-bonus-part)  

# 0. 개념
## 0.1 fractal

`` 프랙탈 `` 은 일부 작은 조각이 전체와 비슷한 기하학적 형태를 말한다. 이러한 프랙탈은 생성 기법에 따라 네 가지로 분류할 수 있다.

- 시간매개형 프랙탈(Escape-time fractals, 궤도 프랙탈)
	- 기하학적 대체 규칙에 의해 만들어진 도형
	- 점화식으로 만들어지는 프랙탈
	- 망델브로 집합, 쥘리아 집합 등
	- ![망델브로 집합](https://upload.wikimedia.org/wikipedia/commons/thumb/5/56/Mandelset_hires.png/600px-Mandelset_hires.png)<망델브로 집합>
- 반복함수계(Iterated function system)
	- 기하학적 대체 규칙에 의해 만들어진 도형
	- 자연에서 찾을 수 있는 프랙탈과 다르게 전체와 부분이 완전히 일치
	- 칸토어 집합, 시에르핀스키 삼각형, 시에르핀스키 카펫, 코흐 곡선, 페아노 곡선 등
	- ![시에르핀스키 삼각형](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b7/SierpinskiTriangle.PNG/440px-SierpinskiTriangle.PNG)<시에르핀스키 삼각형>
- 기이한 끌개(Strange attractors)
	- 주어진 사상이나 방정식의 해를 이용해 초기값을 반복적으로 변환한 것
	- 자기유사성이 핵심인 프랙탈은 위상수학분야, 초기조건의 민감성이 핵심인 카오스 이론은 미분방정식 분야에 속한다. 그러면서 프랙탈은 가까운 두 점이 가진 정보가 완전히 다르다는 점에서 초기조선의 민감성을 가지고 카오스 이론의 끌개는 프랙탈 구조를 갖기에 서로 밀접한 관계를 가진다.
	- 카오스 이론과 관계가 있음
- 무작위적 프랙탈(Random fractals)
	- 결정론적이지 않고 추측 통계학적으로 만들어진 것

이들 중 기하학적인 프랙탈만 완전한 자기유사성을 가지며 망델브로 집합 등의 대부분 프랙탈은 자기유사성이 약하며 `` 통계적인 `` 자기유사성을 가지고 있다. 이는 확대할 때마다 자신의 모습이 변형된 형태로 나타난다. 그렇기에 자기유사성을 기준으로도 프랙탈을 두가지 분류로 나눌 수 있다.

- 준-자기유사적 프랙탈(통계학적 프랙탈)
	- 자기유사성이 낮음
	- 자연에서 찾은 프랙탈처럼 부분과 전체가 대략적으로 비슷
- 완전-자기유사적 프랙탈(규칙적 프랙탈)
	- 자기유사성이 높음
	- 부분과 전체의 모양이 정확하게 일치
	- 위에 있는 시에르핀스키 삼각형이 대표적인 예


## 0.2 Mandelbrot set

`` 망델브로 집합 `` 은 브누아 망델브로가 고안한 프랙탈이다. 망델브로 집합은 시간매개형 프랙탈로 점화식으로 만들어지는 점화식이다. 점화식을 발산하지 않게 하는 $c$ 들의 집합이다.

$$ 
\begin{aligned}
&z_0 = 0 (단,\;  z_n은\;복소수) \\
&z_{n+1} = z_n^2 + c
\end{aligned}
$$

이를 복소수를 사용하지 않고 정의하려면 모든 복소수를 실수부와 허수부로 나누면 된다. 만약 $z_n$ 을 $(x_n,y_n)$ 로, $c$ 를 $(a,b)$ 로 바꾸면 위 점화식을 다음과 같이 쓸 수 있다. 

$$
\begin{aligned}
&(x_0,y_0) = (0,0) \\
&x_{n+1} = x_n^2 - y_n^2 + a \\
&y_{n+1} = 2 x_n y_n + b(단, \; x_n,y_n,a,b는 \; 실수)
\end{aligned}
$$

망델브로 집합을 실제로 그릴 때는 점화식에 따라 수열이 발산하는지 수렴하는지 검사하여 그린다. $z_n > |2|$ 일 때, 즉 $x_n^2 + y_n^2 > 2^2$ 일 때, 발산한다고 할 수 있으며 이때 $c$ 는 망델브로 집합에 속하지 않는다. 이때 2를 경계값이라고 한다.  

반대로 2를 초과하지 않는 경우, 계산이 무한히 이어지기에 적당한 $n$ 값에서 끊어주어야 한다. 그렇기에 이론적인 망델브로 집합은 얻을 수 없으며 근사한 집합만 얻을 수 있다.

## 0.3 Julia set

`` 줄리아 집합 `` 은 망델브로 집합과 점화식은 비슷하다.

$$
z_{n+1} = z_n^2 + c
$$

그러나 망델로브와 다르게 발산하지 않는 $z$ 의 집합으로 그린다. 즉, $z$ 와 $c$ 의 역할이 반대인 것이다.

![여러가지 julia](https://horizon.kias.re.kr/wp-content/uploads/2019/12/julia.png)

## 0.4 복소수의 표현

복소수는 실수 부분과 순허수를 합쳐서 $a+bi \; (여기서 \; i^2 = -1)$ 로 표현되는 수를 의미한다. 이러한 복소수는 x축을 실수, y축을 허수를 표현하여 좌표평면에 나타낼 수 있다. 

<img src="https://javalab.org/wp-content/uploads/complex_number.png" height=350px width=500px>

# 1. Mandatory part

- 당신의 소프트웨어는 줄리아 세트와 만델브로 세트를 제공해야 한다.
- 마우스 휠이 거의 무한대로 확대 및 축소됩니다(컴퓨터의 제한 범위 내에서). 이것이 바로 프랙탈의 원리입니다.
- 각 프랙탈의 깊이를 표시하려면 최소한 몇 가지 색을 사용해야 합니다. 사이키델릭 효과만 잘 활용하면 더욱 좋다.
- 표시할 프랙탈 유형을 정의하기 위해 매개 변수가 명령줄에 전달됩니다. 매개 변수가 제공되지 않거나 매개 변수가 올바르지 않으면 프로그램에서 사용 가능한 매개 변수 목록을 표시하고 올바르게 종료합니다.
- 프랙탈 매개 변수에 더 많은 매개 변수를 사용하거나 무시해야 합니다.
- 프로그램의 매개 변수를 사용하여 다른 Julia 집합을 만들 수 있어야 합니다.
- ESC가 프로그램을 종료합니다.
- minilibX의 이미지를 사용하는 것이 좋습니다.

# 2. Bonus part

- 다른 프랙탈이 하나 더 있다(온라인에서 참조되는 프랙탈의 종류는 100가지가 넘는다).
- 줌은 실제 마우스 위치를 따릅니다.
- 확대/축소 외에도: 화살표와 함께 이동합니다.
- 색상 범위를 이동합니다.

# 3번째 프랙탈 후보
- [Multibrot set](https://en.wikipedia.org/wiki/Multibrot_set)
- [Tricorn](https://en.wikipedia.org/wiki/Tricorn_(mathematics))
- [Buddhabrot](https://en.wikipedia.org/wiki/Buddhabrot)
- [Mandelbox](https://en.wikipedia.org/wiki/Mandelbox)
- [Burning Ship fractal](https://en.wikipedia.org/wiki/Burning_Ship_fractal)
# 참고 자료

- [위키백과, 프랙탈](https://ko.wikipedia.org/wiki/%ED%94%84%EB%9E%99%ED%83%88)
- [위키백과, 망델브로 집합](https://ko.wikipedia.org/wiki/%EB%A7%9D%EB%8D%B8%EB%B8%8C%EB%A1%9C_%EC%A7%91%ED%95%A9)
- [위키백과, 쥘리아 집합](https://ko.wikipedia.org/wiki/%EC%A5%98%EB%A6%AC%EC%95%84_%EC%A7%91%ED%95%A9)
- [자바실험실, 망델브로 집합](https://javalab.org/mandelbrot_set/)
- [카이스트 문희태 명예교수, 프랙탈 - 줄리아 집합](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=moonuga&logNo=220057782966)
- [권석준, 패턴의 과학 [1]: 패턴의 자기닮음꼴과 프랙탈 차원](https://horizon.kias.re.kr/12112/)