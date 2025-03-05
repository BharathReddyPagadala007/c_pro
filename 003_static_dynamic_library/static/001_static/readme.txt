   gcc -c mymath.c -o mymath.o
   ar rcs libmymath.a mymath.o


   gcc main.c -L. -lmymath -o main
   ./main




clean:

 rm -rf *.a *.o main
