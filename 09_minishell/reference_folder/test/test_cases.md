# TEST CASES

## echo
```bash
echo $?
echo $?
echo ??
echo ?
echo $??
echo $USERname
echo $USER name
echo "$USER na"me
echo '$USER na'me
echo "$$USER"
echo hi$USER
echo hi"$USER"
echo $USEEER
echo ?$USER
echo hell"o"" "from " 42"
echo "$USER ?"
```
```bash
echo -n
echo -n hello
"echo" "-n" "hello"
"echo" "-n hello"
"echo -n" "hello"
"echo" "-n-n-n-n-n-n-n-n" "hello"
```

## ls
```bash
ls
ls -l
ls -al
```

## quit, 반환값
```bash
quit 113
echo $?
wrongcmd
echo $?
ls
echo $?
```

## 잡다하게 섞은 거
```bash
< infile cat
< infile cat | grep a
< infile cat | grep a | wc
< infile cat | grep a | wc -l
cat < infile
```

## SHLVL 환경변수
```bash
env
env | grep SHLVL
./minishell
env | grep SHLVL -> SHLVL 값 확인
```

## export, unset
```bash
export a=b b=c c=d
export a=aa b=cc
export A=B B=C
unset a
unset b c A B
*exportO=o
*exportO+=o
```
## cd
```bash
cd ~
cd
cd -
echo $OLDPWD
```

## ctrl + [d, c, \ ]
```bash
```
## pwd
```bash
pwd
```
## heredoc + append
```bash
<< eof cat >> infile -> infile 뒤에 추가됨
<< HERE_DOC > a.txt | cat a.txt | wc -l
<< HERE_DOC > a.txt | cat a.txt
ls -al | > a.txt
ls -al | cat
```
```bash
cat | cat | ls
```

```
시작하자마자 unset OLDPWD
Pwd 인자
env | grep SHLVL -> 시작하자마자 ++
```
```bash
echo ' " $HOME " '
```

## 사라진 경로 테스트
```bash
mkdir test
cd test
rm -rf ../test
pwd
Cd .
Env | grep PWD
```

[https://42born2code.slack.com/archives/CNA2Z8RBP/p1642091711022100](https://42born2code.slack.com/archives/CNA2Z8RBP/p1642091711022100)
```bash
echo $P$P$P$PWD
<< eof | cat
echo -nnnnnnnnn -n -nnnnnm
|
ls | | wc
echo "''$PWD'''qwere"qwqwer$P$P$PWD"'$PWD'"
ls |;
ls |&
$_ : env | grep SHLVL
echo $TEST > $TEST
unset PWD
cd ...
- [ ] ls /*/
export a="ls -la"
$a
l's'
- [ ] export a =asd //갱신x
  - [ ] a가 존재할 때 a=로 갱신 O
  - [ ] a=가 존재할 때 a로 갱신 X
  - [ ] a와 a=가 동시에 존재할 수 없음
export a="algo=k"
unset HOME && cd ~
export a='algo"algo'
echo "$a"
avoid awk
export a=">>"
ls $a algo
exit 4 y fuera de las shell echo $?
exit a1
exit 1a
<< ola | grep 42 | cat
export a="ls -la"
"$a"
ls | exit | wc
cd .. | rm -rf minishell
```

https://github.com/solaldunckel/minishell-tester/blob/master/test.sh
```bash
# ECHO TESTS
 echo test tout
 echo test tout
 echo -n test tout
 echo -n -n -n test tout

# CD TESTS
 cd .. ; pwd
 cd /Users ; pwd
 cd ; pwd
 mkdir test_dir ; cd test_dir ; rm -rf ../test_dir ; cd . ; pwd ; cd . ; pwd ; cd .. ; pwd

# PIPE TESTS
 cat tests/lorem.txt | grep arcu | cat -e
 echo test | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e
 ### -> fd가 255를 넘어 오류처리 하기로

 ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls
 ### -> fd가 255를 넘어 오류처리 하기로

 cat /dev/random | head -c 100 | wc -c

# ENV EXPANSIONS + ESCAPE
 export TEST=abc
 echo test \ test
 echo "test
 echo $TEST
 echo "$TEST"
 echo '$TEST'"
 echo "$TEST$TEST$TEST"
 echo "$TEST$TEST=lol$TEST"
 echo " $TEST lol $TEST"
 echo $TEST$TEST$TEST
 echo $TEST$TEST=lol$TEST""lol
 echo $TEST lol $TEST
 echo test "" test "" test

 echo "$=TEST"
 echo "$"
 echo "$?TEST"
 echo $TEST $TEST
 echo "$1TEST"

 echo "$T1TEST"

# ENV EXPANSIONS
 export =
 export 1TEST=
 export TEST
 export ""=""
 export TES=T=""
 export TE+S=T=""
 export TEST=LOL ; echo $TEST
 export TEST=LOL ; echo $TEST$TEST$TEST=lol$TEST
 export TEST=LOL; export TEST+=LOL ; echo $TEST
 ###  -> +=연산자까지 구현 범위일지 고민
 ENV_SHOW="env | grep SHLVL"
 EXPORT_SHOW="export | grep SHLVL"
 $ENV_SHOW ->env에 인자가 들어오면 오류메세지를 띄워주자 -> subject분야가아니라 안함
 $EXPORT_SHOW
 export TEST="ls -l - a"
 echo $TEST

# REDIRECTIONS
 echo test > ls ; cat ls
 echo test > ls >> ls >> ls ; echo test >> ls; cat ls
 > lol echo test lol; cat lol
 >lol echo > test>lol>test>>lol>test mdr >lol test >test; cat test
 cat < ls
 cat < ls > ls

# MULTI TESTS
 echo testing multi ; echo "test 1 ; | and 2" ; cat tests/lorem.txt | grep Lorem

# SYNTAX ERROR
 ;; test
 | test
 echo > <
 echo | |
 <

# EXIT
 exit 42
 exit 42 53 68
 exit 259
 exit 9223372036854775807
 exit -9223372036854775808
 exit 9223372036854775808
 exit -9223372036854775810
 exit -4
 exit wrong_command
 gdagadgag
 ls -Z
 cd gdhahahad
 ls -la | wtf
```

`1. Simple Command`  
/bin/ls  
/bin/echo  
/bin/cat  
/adsasdasd/sadasd/ls  

`2. Arguments`  
/bin/ls -l .  
/bin/echo Hello  
/bin/cat srcs/main.c  

`3. echo`  
echo  
echo Hello  
echo -n Hello  
echo -nnnn Hello  
echo -n -n -n Hello  
echo Hel     lo  

`4. exit`  
exit  
exit 3  
exit 123  
exit a  

`5. Return value of a process`  
0 : success (/bin/ls -l . -> echo $?)  
1 : file not found (/bin/ls -l invalid -> echo $?)  
127 : cmd not found (asdf)  
- [ ] 126 : is dir (/bin)
- [ ] 258 : syntax error (>>>>>)
- [ ] 130 : child int (cat -> Ctrl-C)
- [ ] 131 : child quit (cat -> Ctrl-\\)

`7. Signal` (왜 6번이 없는지 모르겠지만 제 탓 아님)  
Ctrl-C  
Ctrl-D  
Ctrl+\\  

`8. Double Quotes`  
echo "Hello" | cat -e  
echo "Hello  
- [ ] echo " Hello ; echo 123    " | cat -e
- [ ] echo " \\\\\\" \\$HOME $HOME "
- [ ] echo "'$HOME'"  

`9 ~ 11. env + export + unset`  
env  
export TEST1=1 -> env, export 확인  
export TEST2 -> env, export 확인  
export TEST3= -> env, export 확인  
unset TEST1 -> env, export 확인  
unset TEST2 -> env, export 확인  
unset TEST3 -> env, export 확인  

`12. Environment Variables`  
echo $HOME  
echo $PATH  
echo "$HOME"  
echo "$PATH"  
echo '$HOME'  
echo '$PATH'  

`13 ~ 14. cd + pwd`
pwd ls  
cd srcs -> pwd ls  
cd . -> pwd ls  
cd .. -> pwd ls  
cd ../../../../../../../../../  
cd ././././././././  
cd ../../././../.././././../  
cd invalid -> echo $?  

`15. Relative Path`  
ls -l  
cat srcs/main.c  
ls -l ../../.././././../  

`16. Environment Path`  
ls -> unset PATH -> ls  
(bash: ls: No such file or directory)  
- [ ] PATH에 가장 왼쪽에 있는 디렉터리 (path1 & path2)

`17. Simple Quotes`  
echo 'Hello'  
echo 'Hello  
echo ''  
echo '$HOME'  
echo ' $HOME  ; ; ; echo $PATH $ '  
- [ ] echo '\\\\\\\\""""'
- [ ] echo '"$HOME"'  

`18. Redirection`
echo Hello > tmp (새로 만들어)  
echo World >> tmp (추가모드)  
cat < tmp  
grep int < srcs/main.c  
echo Hello > tmp1 > tmp2 > tmp3  
\> tmp4 echo ABC  
ls -l > tmp6 | grep d  

`19. Pipe` (개행까지 복사하면 제대로 동작 X)  
cat /etc/passwd | grep ':' | more  
ls -l | grep d  
ls invalid | grep d | more  
ls -l | grep d > tmp5  
Cat | cat | ls  

`20. Go Crazy`  
askdfjasdkhakdjfhadfhadjkadhfjkahdfjksdfuiyweuifhweuifhwuihfiwudhfiuwhdfuiwd  
echo a s k d f j a s d k h a k d j f h a d f h a d j k a d h f j k a h d f j k s d f u i y  
echo ' " $HOME " '  
mkdir test  
cd test  
rm -rf ../test  
pwd  
