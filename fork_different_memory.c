#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int x = 100; 
    int ret = fork();

    if (ret == 0) {
        x = 200; 
        printf("Child: x = %d\n", x);
        return 0;
    } else {
        wait(NULL);
        printf("Parent: x = %d\n", x);
    }

    return 0;
}
