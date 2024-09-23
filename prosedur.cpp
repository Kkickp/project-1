#include <iostream>
using namespace std;

// Proses input data nilai mahasiswa
void Data_Nilai_Mhs() {
    int i,n;

    n = 3;
    int nim[n];
    string nama[n];
    float ipk[n];

    for (int i = 0; i < n; i++) {
        cout << "NIM mahasiswa ke-" << i+1 << ": ";
        cin >> nim[i];
    }
    for (int i = 0; i < n; i++) {
        cout << "Nama mahasiswa ke-" << i+1 << ": ";
        cin >> nama[i];
    }
    for (int i = 0; i < n; i++) {
        cout << "IPK mahasiswa ke-" << i+1 << ": ";
        cin >> ipk[i];
    }
    for (int i = 0; i < n; i++) {
        cout << "NIM: " << nim[i] << " Nama: " << nama[i] << " IPK: " << ipk[i] << endl;
    }
}

int main() {

    // Menampilkan data mahasiswa
    Data_Nilai_Mhs();
    return 0;
}
