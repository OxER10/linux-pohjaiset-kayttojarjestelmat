#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    char* args[] = {"/",NULL};
    int status = 0;
    if (fork() != 0){
        waitpid(-1, &status, 0);
    }
    else {
        execve("/bin/ls", args, NULL);
    }
}