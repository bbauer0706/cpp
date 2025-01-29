#include "../include.h"

//Funktionen benennen

int main() {
    // Printen
    cout << "Print this text" << endl;

    // Einlesen
    int n;
    std::cin >> n;

    // if vs ?-Operator
    bool is_n_greater_than_0 = n > 0;
    if (is_n_greater_than_0) {
        std::cout << "n ist groesser als 0" << std::endl;
    } else {
        std::cout << "n ist kleiner als 0" << std::endl;
    }

    std::cout << n << " ist" << (is_n_greater_than_0 ? " groesser" : " kleiner")
    << " als 0" << std::endl;

    // Initialisieren
    int b{1};
    int n{3};

    // for-Schleifen
    int res{1};
    for (int i{0}; i < n; ++i) {
        res *= b;
    }

    // while-Schleife
    int res{b};
    while (n > 1) {
        res *= b;
        --n;
    }


}