#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    
    pid_t pid = fork();
    if (pid > 0) {
        sleep(3);
        execlp("/bin/ps","ps", NULL);
    }

    return 0;
}
