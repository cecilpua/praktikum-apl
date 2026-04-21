#include <iostream>
using namespace std;

struct DetailSneaker{
    string warna;
    int ukuran;
};

struct Sneaker{
    string brand;
    string model;
    int harga;
    string kondisi;
    DetailSneaker detail;
};

struct User{
    string username;
    string password;
};

Sneaker dataSneaker[100];
int jumlahData = 0;
User akun = {"cecil","125"};

bool login(User user){
    string username, password;
    int percobaan = 0;

    while(percobaan < 3){
        cout << "\n=== LOGIN ===\n";
        cout << "Username : "; cin >> username;
        cout << "Password : "; cin >> password;

        if(username == user.username && password == user.password){
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "Login gagal!\n";
            percobaan++;
        }
    }
    return false;
}

void isiDataAwal(Sneaker *data, int &jumlah){
    data[0] = {"Nike","AirForce1",1500000,"Baru",{"White",42}};
    data[1] = {"Adidas","Yeezy350",4200000,"Baru",{"Black",43}};
    data[2] = {"Converse","ChuckTaylor",850000,"Bekas",{"Red",41}};
    jumlah = 3;
}

void tampilData(Sneaker *data, int jumlah){
    cout << "\n=== Data Sneaker ===\n";
    for(int i=0; i<jumlah; i++){
        cout << i+1 << ". "
             << data[i].brand << " "
             << data[i].model << " | "
             << data[i].detail.warna << " "
             << data[i].detail.ukuran << " | "
             << data[i].harga << " | "
             << data[i].kondisi << endl;
    }
}

void bubbleSortBrand(Sneaker data[], int jumlah){
    for(int i=0; i<jumlah-1; i++){
        for(int j=0; j<jumlah-i-1; j++){
            if(data[j].brand > data[j+1].brand){
                swap(data[j], data[j+1]);
            }
        }
    }
}

void selectionSortHarga(Sneaker data[], int jumlah){
    for(int i=0; i<jumlah-1; i++){
        int indeksMaks = i;

        for(int j=i+1; j<jumlah; j++){
            if(data[j].harga > data[indeksMaks].harga){
                indeksMaks = j;
            }
        }
        swap(data[i], data[indeksMaks]);
    }
}

void insertionSortUkuran(Sneaker data[], int jumlah){
    for(int i=1; i<jumlah; i++){
        Sneaker kunci = data[i];
        int j = i-1;

        while(j >= 0 && data[j].detail.ukuran > kunci.detail.ukuran){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = kunci;
    }
}


// Linear Search (Brand)
int linearSearchBrand(Sneaker *data, int jumlah, string targetBrand){
    for(int indeks = 0; indeks < jumlah; indeks++){
        if(data[indeks].brand == targetBrand){
            return indeks;
        }
    }
    return -1;
}

// Binary Search (Harga)
int binarySearchHarga(Sneaker *data, int jumlah, int targetHarga){
    int indeksAwal = 0;
    int indeksAkhir = jumlah - 1;

    while(indeksAwal <= indeksAkhir){
        int indeksTengah = (indeksAwal + indeksAkhir) / 2;

        if(data[indeksTengah].harga == targetHarga){
            return indeksTengah;
        }
        else if(data[indeksTengah].harga < targetHarga){
            indeksAwal = indeksTengah + 1;
        }
        else{
            indeksAkhir = indeksTengah - 1;
        }
    }
    return -1;
}

// ================= MENU =================
void menu(){
    cout << "\n=== MENU ===\n";
    cout << "1. Tampil Data\n";
    cout << "2. Sorting\n";
    cout << "3. Searching\n";
    cout << "4. Keluar\n";
}

// ================= MAIN =================
int main(){

    if(!login(akun)){
        cout << "Gagal login.\n";
        return 0;
    }

    isiDataAwal(dataSneaker, jumlahData);

    int pilihan;

    do{
        menu();
        cout << "Pilih : ";
        cin >> pilihan;

        // ===== TAMPIL DATA =====
        if(pilihan == 1){
            tampilData(dataSneaker, jumlahData);
        }

        // ===== SORTING =====
        else if(pilihan == 2){
            int pilihSorting;

            cout << "\n=== PILIH SORTING ===\n";
            cout << "1. Brand (Ascending - Bubble)\n";
            cout << "2. Harga (Descending - Selection)\n";
            cout << "3. Ukuran (Ascending - Insertion)\n";
            cout << "Pilih : ";
            cin >> pilihSorting;

            if(pilihSorting == 1){
                bubbleSortBrand(dataSneaker, jumlahData);
            }
            else if(pilihSorting == 2){
                selectionSortHarga(dataSneaker, jumlahData);
            }
            else if(pilihSorting == 3){
                insertionSortUkuran(dataSneaker, jumlahData);
            }

            tampilData(dataSneaker, jumlahData);
        }

        // ===== SEARCHING =====
        else if(pilihan == 3){
            int pilihSearch;

            cout << "\n=== MENU SEARCHING ===\n";
            cout << "1. Cari Brand (Linear Search)\n";
            cout << "2. Cari Harga (Binary Search)\n";
            cout << "Pilih : ";
            cin >> pilihSearch;

            // --- Linear Search ---
            if(pilihSearch == 1){
                string cariBrand;
                cout << "Masukkan brand: ";
                cin >> cariBrand;

                int hasil = linearSearchBrand(dataSneaker, jumlahData, cariBrand);

                if(hasil != -1){
                    cout << "Data ditemukan:\n";
                    cout << dataSneaker[hasil].brand << " "
                         << dataSneaker[hasil].model << endl;
                } else {
                    cout << "Data tidak ditemukan\n";
                }
            }

            // --- Binary Search ---
            else if(pilihSearch == 2){
                int cariHarga;
                cout << "Masukkan harga: ";
                cin >> cariHarga;

                // WAJIB SORT DULU
                selectionSortHarga(dataSneaker, jumlahData);

                int hasil = binarySearchHarga(dataSneaker, jumlahData, cariHarga);

                if(hasil != -1){
                    cout << "Data ditemukan:\n";
                    cout << dataSneaker[hasil].brand << " "
                         << dataSneaker[hasil].model << endl;
                } else {
                    cout << "Data tidak ditemukan\n";
                }
            }
        }

    }while(pilihan != 4);

    return 0;
}