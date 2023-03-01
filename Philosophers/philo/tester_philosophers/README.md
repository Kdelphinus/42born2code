# tester_philosophers
<img width="803" alt="Screen Shot 2022-05-25 at 13 20 48" src="https://user-images.githubusercontent.com/60470877/170179090-39f0f31a-0461-46dc-ad49-eb0dc21b555c.png">

> ⚠️ Important notes :
> - Colored log format may not be supported for some tests.
> - Failing this test does not necessary mean your philosopher fails to meet the requirements.<br>
> Reference: https://discord.com/channels/691903146909237289/691908977918738453/881739363719979009 (Private link for 42Tokyo students)


# Installation
```
git clone https://github.com/mfunyu/tester_philosophers.git &&
python3 -m pip install pyparsing
```
### Directory structure
```
── philosophers
   ├── Makefile
   ├── includes
   ├── srcs
   └── tester_philosophers
```

# Usage
### run all tests
```shell
./tester_philosophers/test.sh
```
### display help
```
$> ./tester_philosophers/test.sh help
Call test.sh with a cmd arg to exec single test
./test.sh arg:  [check wrong arguments]
./test.sh time: [check chronology of timestamps]
./test.sh retval: [check return values]
./test.sh advanced: [visualize fork and check for more detailded conditions]
```
### run advanced test

- add command-line arguments as the same order from `./philo`
```
./tester_philosophers/run.sh [philo_nbs] [death_time] [eat_time] [sleep_time]
```
