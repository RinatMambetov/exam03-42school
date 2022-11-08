gcc -Wall -Wextra -Werror my_mini_paint.c -o my_mini_paint
gcc -Wall -Wextra -Werror orig_mini_paint.c -o orig_mini_paint
./my_mini_paint examples/0 > myres
./orig_mini_paint examples/0 > res
diff myres res
./my_mini_paint examples/1 > myres
./orig_mini_paint examples/1 > res
diff myres res
./my_mini_paint examples/2 > myres
./orig_mini_paint examples/2 > res
diff myres res
./my_mini_paint examples/3 > myres
./orig_mini_paint examples/3 > res
diff myres res
./my_mini_paint examples/4 > myres
./orig_mini_paint examples/4 > res
diff myres res
./my_mini_paint examples/5 > myres
./orig_mini_paint examples/5 > res
diff myres res

rm -f my_mini_paint orig_mini_paint myres res
