
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

// Koodissa yritetään avata tiedostoa jota ei ole. Tämän takia error
int main() {
    const char *filename = "*/test.txt";

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Tiedoston avaaminen epäonnistui");
        printf("errno: %d\n", errno);
        printf("Virhekuvaus: %s\n", strerror(errno));
    } else {
        printf("Tiedosto avattiin onnistuneesti!\n");
    }

    return 0;
}