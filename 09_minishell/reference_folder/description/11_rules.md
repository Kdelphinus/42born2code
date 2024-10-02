**과제에 맞게 변형된 11가지 규칙**

- 규칙 적용은 한 캐릭터씩 (1 charator) 그리고 규칙의 순서대로 확인합니다. 현재는 ***input** 으로 만들어져있습니다. 1 char를 읽으면서 word로 임시 저장되어질 예정입니다.

1. 현재 들어온 캐릭터가 개행일때 (*input == \n)
	- 의미 : **readline**은 문장으로 데이터를 받기 때문에 개행의 의미는 토큰화의 끝을 의미합니다.
<br>
<br>

2. **새로운 단어(word)** 의 첫번째 character가 지정되지 않았으면서 숫자와 리다이렉션의 조합일때
	```
		2<  1< etc.. 
		asd2< 는 앞의 'asd2'가 단어로 인식됨
	```
	- 의미 : 새로운 단어가 만들어지고 있는데 앞에 숫자(fd)가 함께 있는 리다이렉션 조합이면 핸들링 합니다.
<br>
<br>

3. 현재 문자(***input**)가 ' 이거나 " 일때
	- quote state, double-qoute state 등으로 상태 체크를 위한 state 변수들이 필요합니다.
	- 의미 : 이 경우 다음 문자까지가 하나의 문자열(string)으로 인식되어야 합니다. 예를 들어, 'Hello, world!'나 "Hello, world!"와 같은 문자열이 여기에 해당됩니다. 이 규칙은 따옴표로 묶인 문자열과 escape character를 구분하는 역할을 합니다.
<br>
<br>

4.	현재 문자(***input**)가 unqouted state이면서 현재 문자가 $ 이거나  ` 일떄
	- expension state 를 둬서 상태 저장이 필요합니다.
	- 의미 : 이 경우 해당 문자 다음에 오는 문자열은 변수명이나 커맨드라인 명령어로 해석되어야 합니다.
	```
		output=`ls`
		echo $output
	```
	ls 명령어의 결과가 output 변수에 저장되고, echo 명령어로 출력할 수 있습니다.
<br>
<br>

5.  현재 문자(***input**)가 unqouted state 이고 unexpension state 인데 redirection 일때
	- 의미 : rd_type 과 fd (0, 1)을 이용해 t_word(new)를 생성합니다.
<br>
<br>

6. 현재 문자(***input**)가 unqouted 이면서 공백 (' ') 일때
	- new word
<br>
<br>

7. 현재 문자(***input**)가 첫번째 캐릭터가 아닐때 (앞에서 단어가 이어지고 있을때)
	- word에 문자 추가
<br>
<br>

8. (new)word의 첫번째 character가 결정되지 않았고, 현재 문자(***input**)가 # 일때
	-  주석처리
<br>
<br>

9. 그 외에는 새로운 단어(new word)의 첫번째 캐릭터로 간주합니다.
<br>
<br>