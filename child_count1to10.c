#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        for (int i = 1; i <= 10; i++) {
            printf("%d\n", i);
        }
        return 0;
    } else {
        wait(NULL);
        printf("Child process finished.\n");
    }

    return 0;
}
