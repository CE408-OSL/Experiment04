#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Child process...\n");
    } else if (pid > 0) {
        wait(NULL); 
        printf("Parent process...\n");
    } else {
        perror("fork failed :(");
    }

    return 0;
}
