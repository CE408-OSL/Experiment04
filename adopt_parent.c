#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child: %d, my parent is %d\n", getpid(), getppid());

        sleep(3);

        printf("Child: %d, my new parent is %d\n", getpid(), getppid());
    } else {
        printf("Parent: exiting...\n");
        return 0;
    }

    return 0;
}
