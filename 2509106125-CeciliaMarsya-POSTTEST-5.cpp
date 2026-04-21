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

// GLOBAL
Sneaker dataSneaker[100];
int jumlahData = 0;
User akun = {"cecil","125"};

// ================= LOGIN =================
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

// ================= DATA =================
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

// ================= SORTING =================

// 1. BUBBLE SORT (ASCENDING - BRAND)
void bubbleSortBrand(Sneaker data[], int jumlah){
    for(int i=0; i<jumlah-1; i++){
        for(int j=0; j<jumlah-i-1; j++){
            if(data[j].brand > data[j+1].brand){
                swap(data[j], data[j+1]);
            }
        }
    }
}

// 2. SELECTION SORT (DESCENDING - HARGA)
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

// 3. INSERTION SORT (ASCENDING - UKURAN)
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

// ================= MENU =================
void menu(){
    cout << "\n=== MENU ===\n";
    cout << "1. Tampil Data\n";
    cout << "2. Sorting\n";
    cout << "3. Keluar\n";
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

        if(pilihan == 1){
            tampilData(dataSneaker, jumlahData);
        }

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

    }while(pilihan != 3);

    return 0;
}