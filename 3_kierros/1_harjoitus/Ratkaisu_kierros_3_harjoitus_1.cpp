#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Komentoriviargumentteja: " << argc - 1 << " kpl.\n";
    std::cout << "Ja ne ovat:\n";
    for (int i = 1; i < argc; i++) {
        std::cout << argv[i] << "\n";
    }
    return 0;
}