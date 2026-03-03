#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string nama, password;
    int kesempatan = 0;
    string nama_benar = "Cecilia";
    string password_benar = "125";

    while (kesempatan < 3) {

        cout << "===== LOGIN =====" << endl;
        cout << "Masukkan nama : ";
        cin >> nama;   // diperbaiki
        cout << "Masukkan password (3 digit terakhir NIM): ";
        cin >> password;

        if (nama == nama_benar && password == password_benar) {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Login salah!\n";
            kesempatan++;
        }
    }

    if (kesempatan == 3) {
        cout << "Anda gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    double nilai;

    cout << fixed << setprecision(2); 

    do {
        cout << "\n===== MENU KONVERSI PANJANG =====" << endl;
        cout << "1. Meter -> Kilometer dan Centimeter" << endl;
        cout << "2. Kilometer -> Meter dan Centimeter" << endl;
        cout << "3. Centimeter -> Meter dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "Masukkan nilai Meter: ";
                cin >> nilai;
                cout << "\n=== HASIL KONVERSI ===" << endl;
                cout << "Kilometer  : " << nilai / 1000 << " km" << endl;
                cout << "Centimeter : " << nilai * 100 << " cm" << endl;
                break;

            case 2:
                cout << "Masukkan nilai Kilometer: ";
                cin >> nilai;
                cout << "\n=== HASIL KONVERSI ===" << endl;
                cout << "Meter      : " << nilai * 1000 << " m" << endl;
                cout << "Centimeter : " << nilai * 100000 << " cm" << endl;
                break;

            case 3:
                cout << "Masukkan nilai Centimeter: ";
                cin >> nilai;
                cout << "\n=== HASIL KONVERSI ===" << endl;
                cout << "Meter      : " << nilai / 100 << " m" << endl;
                cout << "Kilometer  : " << nilai / 100000 << " km" << endl;
                break;

            case 4:
                cout << "Terima kasih telah menggunakan program." << endl;
                break;

            default:
                cout << "Pilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 4);

    return 0;
}