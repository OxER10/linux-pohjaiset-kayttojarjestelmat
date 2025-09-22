#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 100
#define MAX_ARGS 10

void type_prompt();
bool read_command(char com[], char* par[]);

int main(int argc, char* argv[]) {
    int status = 0;
    char command[MAX_LENGTH];
    char* parameters[MAX_ARGS + 2];
    while (1) {
        type_prompt();
        if (!read_command(command, parameters)) {
            std::cout << "Poistutaan minishell." << std::endl;
            break;
        }
        if (fork() != 0){
            waitpid(-1, &status, 0);
        }
        else {
            execve(command, parameters, NULL);
        }
    }
    return 0;
}   

bool read_command(char com[], char* par[]) {
    char ch = std::cin.get();
    if (ch == '\n') {
        return false;
    }
    std::cin.putback(ch);
    std::cin >> com;
    par[0] = com;
    static char temp[MAX_ARGS][MAX_LENGTH];
    int i = 1;
    while (i <= MAX_ARGS && std::cin.peek() != '\n') {
        std::cin >> temp[i-1];
        par[i] = temp[i-1];
        i++;
    }
    std::cin .ignore();
    par[i] = NULL;
    return true;
}

void type_prompt() {
    std::cout << "Anna komento: ";
}