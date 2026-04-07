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

    cout << "Gagal login 3x.\n";
    return false;
}

void isiDataAwal(Sneaker *data, int &jumlah){
    data[0] = {"Nike","AirForce1",1500000,"Baru",{"White",42}};
    data[1] = {"Adidas","Yeezy350",4200000,"Baru",{"Black",43}};
    data[2] = {"Converse","ChuckTaylor",850000,"Bekas",{"Red",41}};
    jumlah = 3;
}

void tambahData(Sneaker *data, int &jumlah){
    cout << "\n=== Tambah Data ===\n";

    cout << "Brand   : "; cin >> (data+jumlah)->brand;
    cout << "Model   : "; cin >> (data+jumlah)->model;
    cout << "Warna   : "; cin >> (data+jumlah)->detail.warna;
    cout << "Ukuran  : "; cin >> (data+jumlah)->detail.ukuran;
    cout << "Harga   : "; cin >> (data+jumlah)->harga;
    cout << "Kondisi : "; cin >> (data+jumlah)->kondisi;

    jumlah++;
    cout << "Data berhasil ditambahkan.\n";
}

void tampilData(Sneaker *data, int jumlah){
    if(jumlah == 0){
        cout << "Data kosong.\n";
        return;
    }

    cout << "\n=== Data Sneaker ===\n";
    for(int i=0; i<jumlah; i++){
        cout << i+1 << ". "
             << (data+i)->brand << " "
             << (data+i)->model << " | "
             << (data+i)->detail.warna << " "
             << (data+i)->detail.ukuran << " | "
             << (data+i)->harga << " | "
             << (data+i)->kondisi << endl;
    }
}

void updateData(Sneaker *data, int jumlah){
    int pilih;
    tampilData(data, jumlah);

    cout << "Pilih nomor : ";
    cin >> pilih;
    pilih--;

    if(pilih >= 0 && pilih < jumlah){
        Sneaker *ptr = &data[pilih]; 

        cout << "Harga baru : ";
        cin >> ptr->harga;

        cout << "Kondisi baru : ";
        cin >> ptr->kondisi;

        cout << "Data berhasil diupdate.\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
}

void hapusData(Sneaker *data, int &jumlah){
    int pilih;
    tampilData(data, jumlah);

    cout << "Pilih nomor : ";
    cin >> pilih;
    pilih--;

    if(pilih >= 0 && pilih < jumlah){
        for(int i=pilih; i<jumlah-1; i++){
            *(data+i) = *(data+i+1); 
        }
        jumlah--;
        cout << "Data berhasil dihapus.\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
}

void menu(){
    cout << "\n=== MENU ===\n";
    cout << "1. Tambah Data\n";
    cout << "2. Tampil Data\n";
    cout << "3. Update Data\n";
    cout << "4. Hapus Data\n";
    cout << "5. Keluar\n";
}

int main(){

    if(!login(akun)){
        return 0;
    }

    isiDataAwal(dataSneaker, jumlahData);

    int pilihan;

    do{
        menu();
        cout << "Pilih : ";
        cin >> pilihan;

        switch(pilihan){
            case 1:
                tambahData(dataSneaker, jumlahData);
                break;
            case 2:
                tampilData(dataSneaker, jumlahData);
                break;
            case 3:
                updateData(dataSneaker, jumlahData);
                break;
            case 4:
                hapusData(dataSneaker, jumlahData);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Menu tidak tersedia.\n";
        }

    }while(pilihan != 5);

    return 0;
}