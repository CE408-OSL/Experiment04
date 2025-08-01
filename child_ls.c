#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        char *args[] = {"ls", "-l", "-h", NULL};  

        execvp("ls", args);

        perror("execvp failed");
        return 1;
    } else {
        wait(NULL);
        printf("Child process finished\n");
    }

    return 0;
}
