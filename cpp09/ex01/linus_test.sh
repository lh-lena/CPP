make re;

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" #42
./RPN "7 7 * 7 -"                 #42
./RPN "1 2 * 2 / 2 * 2 4 - +"     #0
./RPN "(1 + 1)"                   #Error
make fclean