#include<iostream>
using namespace std;

int main() {
    int pilihan;
    float panjang, lebar, tinggi, luas, keliling, hambatan, arus, tegangan;
    char yuy;


    cout << "Menu Pilihan: " << endl;
    cout << "1. Menghitung Luas Balok" << endl;
    cout << "2. Menghitung Keliling Layang-Layang" << endl;
    cout << "3. Menghitung Hukum Ohm" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Masukkan panjang balok: ";
            cin >> panjang;
            cout << "Masukkan lebar balok: ";
            cin >> lebar;
            cout << "Masukkan tinggi balok: ";
            cin >> tinggi;
            luas = 2 * ((panjang * lebar) + (panjang * tinggi) + (lebar * tinggi));
            cout << "Luas Balok: " << luas << endl;
            break;
        case 2:
            cout << "Masukkan panjang diagonal 1 layang-layang: ";
            cin >> panjang;
            cout << "Masukkan panjang diagonal 2 layang-layang: ";
            cin >> lebar;
            keliling = 2 * (panjang + lebar);
            cout << "Keliling Layang-Layang: " << keliling << endl;
            break;
        case 3:
            cout << "Masukkan nilai hambatan: ";
            cin >> hambatan;
            cout << "Masukkan nilai arus: ";
            cin >> arus;
            if (hambatan == 0) {
                cout << "hambatan tidak boleh nol" << endl;
            } else {
                tegangan = hambatan * arus;
                cout << "tegangan: " << tegangan << "volt" << endl;
            }
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
    }

    cout << endl << "Bagus kan rumusku (y/t)? ";
    cin >> yuy;
        string hasil = (yuy == 'y') ? "Makasih" : ":(";
        cout << "Jawaban anda: " << hasil << endl;

    return 0;
}
