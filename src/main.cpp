#include "utama.h"

int main() {
    SistemRental system;

    cout << "Masukkan nama pelanggan: ";
    string nama;
    getline(cin, nama);
    system.inputPelanggan(nama);

    cout << "Selamat datang di sistem rental.\n";
    system.tampilkanBarangAvailable();
    system.menu();

    return 0;
}
