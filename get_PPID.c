#include <stdio.h>
#include <unistd.h>  

int main() {
    pid_t pid = getpid(); 
    pid_t ppid = getppid();
    
    printf("PID: %d\n", pid);
    printf("PPID: %d\n", ppid);

    return 0;
}
