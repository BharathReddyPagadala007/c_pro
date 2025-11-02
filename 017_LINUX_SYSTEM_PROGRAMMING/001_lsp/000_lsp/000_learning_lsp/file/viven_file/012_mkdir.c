#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // Create the "Backup" directory in the parent directory (../Backup)
    if (mkdir("../Backup", 0755) == 0) {
        printf("Directory 'Backup' created in the parent directory.\n");
    } else {
        perror("Error creating directory");
    }

    return 0;
}

