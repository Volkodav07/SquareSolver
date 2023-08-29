@CHCP 1251>NUL

gcc -Wall -E main.cpp -o main.i
gcc -Wall -E equation_solver.cpp -o equation_solver.i
gcc -Wall -E Test.cpp -o Test.i

gcc -Wall -S main.i -o main.s
gcc -Wall -S equation_solver.i -o equation_solver.s
gcc -Wall -S Test.i -o Test.s

gcc -Wall -g3 -c main.cpp
gcc -Wall -g3 -c equation_solver.cpp
gcc -Wall -g3 -c Test.cpp

gcc -Wall main.o equation_solver.o Test.o -o GitHub

