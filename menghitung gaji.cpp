#include <iostream>
#include <string>
using namespace std;

struct Karyawan {
    string nama;
    float bulanKontrak;
    float gajiAwal;
};

void naikGaji(Karyawan *karyawan, int n, int bulan) {
    if (bulan > 0) {
        karyawan[n - bulan].gajiAwal *= 1 + 0.1; // Naik 10%
        naikGaji(karyawan, n, bulan - 1); // Rekursi untuk bulan berikutnya
    }
}

void tampilkanData(Karyawan *karyawan, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Gaji akhir " << karyawan[i].nama << ": " << karyawan[i].gajiAwal << endl;
    }
}

int main() {
    int n = 3;
    Karyawan *karyawan = new Karyawan[n];

    karyawan[0].nama = "Doni";
    karyawan[0].bulanKontrak = 3;
    karyawan[0].gajiAwal = 3000000;

    karyawan[1].nama = "Lena";
    karyawan[1].bulanKontrak = 6;
    karyawan[1].gajiAwal = 3500000;

    karyawan[2].nama = "Dewi";
    karyawan[2].bulanKontrak = 9;
    karyawan[2].gajiAwal = 4000000;

    cout << "Masukkan gaji naik untuk Doni (3 jt): ";
    double gajiNaikDoni;
    cin >> gajiNaikDoni;
    karyawan[0].gajiAwal = gajiNaikDoni;

    cout << "Masukkan gaji naik untuk Lena (3.5 jt): ";
    double gajiNaikLena;
    cin >> gajiNaikLena;
    karyawan[1].gajiAwal = gajiNaikLena;

    cout << "Masukkan gaji naik untuk Dewi (4 jt): ";
    double gajiNaikDewi;
    cin >> gajiNaikDewi;
    karyawan[2].gajiAwal = gajiNaikDewi;

    naikGaji(karyawan, n, 3); // Naik gaji selama 3 bulan
    naikGaji(karyawan, n, 6); // Naik gaji selama 6 bulan
    naikGaji(karyawan, n, 9); // Naik gaji selama 9 bulan
    tampilkanData(karyawan, n);

    delete[] karyawan;
    return 0;
}
