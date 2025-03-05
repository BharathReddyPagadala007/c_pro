/mnt/g/embsys/Pagadala007/a_interview_prep/c/c_pro/003_static_dynamic_library/dynamic/001_math
$ make
mkdir -p build
gcc -fPIC -Iinc -c src/mathlib.c -o build/mathlib.o
gcc -shared -o build/libmath.so build/mathlib.o
gcc -Iinc -Lbuild src/main.c -lmath -o build/main
/mnt/g/embsys/Pagadala007/a_interview_prep/c/c_pro/003_static_dynamic_library/dynamic/001_math
$ ls
Makefile  build  inc  src
/mnt/g/embsys/Pagadala007/a_interview_prep/c/c_pro/003_static_dynamic_library/dynamic/001_math
$ make run
export LD_LIBRARY_PATH=build:$LD_LIBRARY_PATH && ./build/main
Add: 10 + 5 = 15
Sub: 10 - 5 = 5
Mul: 10 * 5 = 50
