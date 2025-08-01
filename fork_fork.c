#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret1 = fork();
    printf("after first fork. PID: %d\n", getpid());

    int ret2 = fork();
    printf("after second fork. PID: %d\n", getpid());

    int ret3 = fork();
    printf("after third fork. PID: %d\n", getpid());

    if (ret1 == 0 && ret2 != 0 && ret3 != 0) {
        printf("I am child from first fork only\n");
    } else if (ret1 != 0 && ret2 == 0 && ret3 != 0) {
        printf("I am child from second fork only\n");
    } else if (ret1 != 0 && ret2 != 0 && ret3 == 0) {
        printf("I am child from third fork only\n");
    } else if (ret1 == 0 && ret2 == 0 && ret3 == 0) {
        printf("I am the grand-grand-child\n");
    } else if (ret1 > 0 && ret2 > 0 && ret3 > 0) {
        printf("I am the original parent\n");
        wait(NULL); wait(NULL); wait(NULL); 
    }

    return 0;
}
