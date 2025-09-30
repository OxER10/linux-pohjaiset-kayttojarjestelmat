#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char merkki;

    // Avaa tiedosto lukutilassa
    int fd = open("tavu.txt", O_RDONLY);
    if (fd == -1) {
        std::cerr << "Tiedoston avaaminen epäonnistui.\n";
        return 1;
    }

    // Lue yksi tavu tiedostosta
    ssize_t luettu = read(fd, &merkki, 1);
    if (luettu != 1) {
        std::cerr << "Luku epäonnistui.\n";
        close(fd);
        return 1;
    }
    close(fd);
    std::cout << "Tiedostosta luettu merkki: '" << merkki << "'\n";
    return 0;
}