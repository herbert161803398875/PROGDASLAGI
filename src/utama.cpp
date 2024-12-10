#include "utama.h"

// Konstruktor
SistemRental::SistemRental() {
    loadBarang();
}

// Memuat data barang dari file
void SistemRental::loadBarang() {
    ifstream bukuFile("data/buku.txt");
    string line;
    while (getline(bukuFile, line)) {
        stringstream ss(line);
        string judul, penulis, penerbit, tahun;
        int tebal;
        getline(ss, judul, '|');
        getline(ss, penulis, '|');
        ss >> tebal;
        ss.ignore();
        getline(ss, penerbit, '|');
        getline(ss, tahun);
        daftarBuku.push_back(Buku(judul, penulis, tebal, penerbit, tahun));
    }

    ifstream mobilFile("data/mobil.txt");
    while (getline(mobilFile, line)) {
        stringstream ss(line);
        string jenis, spesifikasi, nomor_polisi;
        int tahun;
        getline(ss, jenis, '|');
        ss >> tahun;
        ss.ignore();
        getline(ss, spesifikasi, '|');
        getline(ss, nomor_polisi);
        daftarMobil.push_back(Mobil(jenis, tahun, spesifikasi, nomor_polisi));
    }

    ifstream sepedaFile("data/sepeda.txt");
    while (getline(sepedaFile, line)) {
        stringstream ss(line);
        string jenis, nomor_sepeda;
        getline(ss, jenis, '|');
        getline(ss, nomor_sepeda);
        daftarSepeda.push_back(Sepeda(jenis, nomor_sepeda));
    }
}

// Menampilkan barang yang tersedia
void SistemRental::tampilkanBarangAvailable() {
    cout << "\nBarang Tersedia: \n";
    cout << "Buku:\n";
    for (auto &buku : daftarBuku) {
        if (!buku.isDipinjam) {
            cout << buku.judul << " - " << buku.penulis << " - " << buku.penerbit << " - " << buku.tahun << endl;
        }
    }

    cout << "\nMobil:\n";
    for (auto &mobil : daftarMobil) {
        if (!mobil.isDipinjam) {
            cout << mobil.jenis << " - " << mobil.spesifikasi << " - " << mobil.nomor_polisi << " - " << mobil.tahun << endl;
        }
    }

    cout << "\nSepeda:\n";
    for (auto &sepeda : daftarSepeda) {
        if (!sepeda.isDipinjam) {
            cout << sepeda.jenis << " - " << sepeda.nomor_sepeda << endl;
        }
    }
}

// Fungsi pinjam barang
void SistemRental::pinjamBarang(string kategori) {
    string input;
    if (kategori == "Buku") {
        cout << "Masukkan judul buku yang ingin dipinjam: ";
        cin.ignore();
        getline(cin, input);

        for (auto &buku : daftarBuku) {
            if (buku.judul == input && !buku.isDipinjam) {
                buku.isDipinjam = true;
                keranjang.push_back(buku.judul);
                cout << "Buku " << buku.judul << " berhasil dipinjam.\n";
                simpanBarangDipinjam();
                return;
            }
        }
        cout << "Buku tidak tersedia.\n";
    }
    // Implementasi pinjam mobil dan sepeda serupa dengan Buku
}

// Fungsi kembalikan barang
void SistemRental::kembalikanBarang() {
    string input;
    cout << "Masukkan nama barang yang ingin dikembalikan: ";
    cin.ignore();
    getline(cin, input);

    // Kembalikan Buku
    for (auto &buku : daftarBuku) {
        if (buku.judul == input && buku.isDipinjam) {
            buku.isDipinjam = false;
            cout << "Buku " << buku.judul << " berhasil dikembalikan.\n";
            simpanBarangDipinjam();
            return;
        }
    }
    // Implementasi pengembalian mobil dan sepeda serupa dengan Buku
}

// Fungsi untuk melihat keranjang
void SistemRental::lihatKeranjang() {
    cout << "\nKeranjang Peminjaman:\n";
    for (const auto &item : keranjang) {
        cout << item << endl;
    }
}

// Fungsi untuk menghitung total harga
double SistemRental::hitungTotalHarga() {
    double total = 0;
    for (const auto &item : keranjang) {
        // Harga per barang ditentukan di sini (buku, mobil, sepeda)
        total += 50; // Asumsi harga tetap untuk contoh
    }
    return total;
}

// Menyimpan barang yang dipinjam dalam file
void SistemRental::simpanBarangDipinjam() {
    ofstream bukuPinjam("data/bukuterpinjam.txt");
    for (auto &buku : daftarBuku) {
        if (buku.isDipinjam) {
            bukuPinjam << buku.judul << "|" << buku.penulis << "|" << buku.tebal << "|"
                       << buku.penerbit << "|" << buku.tahun << endl;
        }
    }
    bukuPinjam.close();
    // Simpan data mobil dan sepeda terpinjam jika diperlukan
}

// Menu utama aplikasi
void SistemRental::menu() {
    int pilihan;
    while (true) {
        cout << "\n1. Pinjam Barang\n2. Kembalikan Barang\n3. Lihat Keranjang\n4. Hitung Total Harga\n5. Exit\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string kategori;
            cout << "Masukkan kategori barang (Buku, Mobil, Sepeda): ";
            cin.ignore();
            getline(cin, kategori);
            pinjamBarang(kategori);
        } else if (pilihan == 2) {
            kembalikanBarang();
        } else if (pilihan == 3) {
            lihatKeranjang();
        } else if (pilihan == 4) {
            cout << "Total Harga: " << hitungTotalHarga() << "\n";
        } else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan sistem rental.\n";
            break;
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    }
}

// Input pelanggan
void SistemRental::inputPelanggan(string nama) {
    pelanggan = nama;
}
