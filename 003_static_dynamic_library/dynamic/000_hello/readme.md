---

### **1. Create the Library Source Code**
Create a file called `mylib.c`:
```c
#include <stdio.h>

void hello() {
    printf("Hello from the shared library!\n");
}
```

### **2. Create the Header File**
Create a corresponding header file `mylib.h`:
```c
#ifndef MYLIB_H
#define MYLIB_H

void hello();

#endif
```

### **3. Compile the Shared Library**
Use `gcc` to compile the shared library:
```sh
gcc -fPIC -c mylib.c -o mylib.o
gcc -shared -o libmylib.so mylib.o
```
- `-fPIC`: Generates position-independent code, required for shared libraries.
- `-shared`: Produces a shared object (`.so` file).

### **4. Use the Library in a Program**
Create a test program `main.c`:
```c
#include "mylib.h"

int main() {
    hello();
    return 0;
}
```

### **5. Compile the Test Program**
Compile and link with the shared library:
```sh
gcc main.c -L. -lmylib -o main
```
- `-L.`: Specifies the directory containing `libmylib.so`.
- `-lmylib`: Links against `libmylib.so`.

### **6. Run the Program**
If you get a library loading error, set the `LD_LIBRARY_PATH`:
```sh
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./main
```

This should output:
```
Hello from the shared library!
```

