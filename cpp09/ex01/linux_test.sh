make re;

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" #42
./RPN "7 7 * 7 -"                 #42
./RPN "1 2 * 2 / 2 * 2 4 - +"     #0
./RPN "(1 + 1)"                   #Error
./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" #15
./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / 15 / 1 -" #0
./RPN "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" #42

make fclean
