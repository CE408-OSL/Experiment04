#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child finished.\n");
        return 0;
    } else {
        sleep(10);
        printf("Parent done.\n");
    }
    return 0;
}