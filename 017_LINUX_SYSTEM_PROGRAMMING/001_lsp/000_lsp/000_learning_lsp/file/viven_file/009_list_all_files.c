#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir = opendir(".");  // Open the current directory
    struct dirent *entry;


    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);  // Print the file or directory name
    }

    closedir(dir);  // Close the directory

    return 0;
}

