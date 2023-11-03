#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
   
    char *inputPath = malloc(256);

    printf("Enter file path or directory path: ");
    fgets(inputPath, 256, stdin);
    inputPath[strcspn(inputPath, "\n")] = '\0';

    struct stat filestat;

    if (stat(inputPath, &filestat) == -1) {
        perror("error while stat");
        return 1;
    }
    else {
        mode_t permissions = filestat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
        
        printf("File Permissions: %o\n", permissions);

        // To display in a more human-readable format:
        printf("Owner Permissions: %o\n", (permissions & S_IRWXU));
        printf("Group Permissions: %o\n", (permissions & S_IRWXG));
        printf("Others Permissions: %o\n", permissions & S_IRWXO);
    }


}