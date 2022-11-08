gcc -Wall -Wextra -Werror my_micro_paint.c -o my_micro_paint
gcc -Wall -Wextra -Werror orig_micro_paint.c -o orig_micro_paint
./my_micro_paint examples/0 > myres
./orig_micro_paint examples/0 > res
diff myres res
./my_micro_paint examples/1 > myres
./orig_micro_paint examples/1 > res
diff myres res
./my_micro_paint examples/2 > myres
./orig_micro_paint examples/2 > res
diff myres res
./my_micro_paint examples/3 > myres
./orig_micro_paint examples/3 > res
diff myres res
./my_micro_paint examples/4 > myres
./orig_micro_paint examples/4 > res
diff myres res
./my_micro_paint examples/5 > myres
./orig_micro_paint examples/5 > res
diff myres res
./my_micro_paint examples/6 > myres
./orig_micro_paint examples/6 > res
diff myres res
./my_micro_paint examples/7 > myres
./orig_micro_paint examples/7 > res
diff myres res
./my_micro_paint examples/8 > myres
./orig_micro_paint examples/8 > res
diff myres res
./my_micro_paint examples/9 > myres
./orig_micro_paint examples/9 > res
diff myres res

rm -f my_micro_paint orig_micro_paint myres res
