#ifndef UTAMA_H
#define UTAMA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

// Struktur untuk Buku, Mobil, Sepeda
struct Buku {
    string judul, penulis, penerbit, tahun;
    int tebal;
    bool isDipinjam;

    Buku(string j, string p, int t, string pe, string th) :
        judul(j), penulis(p), tebal(t), penerbit(pe), tahun(th), isDipinjam(false) {}
};

struct Mobil {
    string jenis, spesifikasi, nomor_polisi;
    int tahun;
    bool isDipinjam;

    Mobil(string j, int t, string s, string np) : 
        jenis(j), tahun(t), spesifikasi(s), nomor_polisi(np), isDipinjam(false) {}
};

struct Sepeda {
    string jenis, nomor_sepeda;
    bool isDipinjam;

    Sepeda(string j, string ns) : jenis(j), nomor_sepeda(ns), isDipinjam(false) {}
};

// Kelas utama untuk manajemen barang
class SistemRental {
private:
    vector<Buku> daftarBuku;
    vector<Mobil> daftarMobil;
    vector<Sepeda> daftarSepeda;
    vector<string> keranjang;
    string pelanggan;
    time_t waktuPinjam;

    void simpanBarang();
    void simpanBarangDipinjam();
    void pinjamBarang(string kategori);
    void kembalikanBarang();
    void lihatKeranjang();
    double hitungTotalHarga();
public:
    SistemRental();
    void menu();
    void loadBarang();
    void inputPelanggan(string nama);

    // Pindahkan fungsi ini ke public
    void tampilkanBarangAvailable();
};

#endif
