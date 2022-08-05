make re
gcc -Wall -Wextra -Werror main.c -L. -lftprintf
./a.out
read next
make fclean
rm a.out
