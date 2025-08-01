#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int ret = fork();

    if (ret == 0) {
        // run in child...
        return 23; 
    } else {
        int rc = 0;
        wait(&rc); 
        printf("return code is %d\n", WEXITSTATUS(rc)); 
    }

    return 0;
}
