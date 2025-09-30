#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    char merkki;

    std::cout << "Anna yksi merkki: ";
    std::cin >> merkki;

    // Luo tiedosto kirjoitustilassa, jos ei ole olemassa
    int fd = open("tavu.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        std::cerr << "Tiedoston avaaminen epäonnistui.\n";
        return 1;
    }

    ssize_t kirjoitettu = write(fd, &merkki, 1);
    if (kirjoitettu != 1) {
        std::cerr << "Kirjoitus epäonnistui.\n";
        close(fd);
        return 1;
    }

    close(fd);

    std::cout << "Merkki '" << merkki << "' kirjoitettu tiedostoon tavu.txt\n";
    return 0;
}