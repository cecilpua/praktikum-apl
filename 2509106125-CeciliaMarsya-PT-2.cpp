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

Sneaker koleksiSneaker[100];
int jumlahData = 0;

User akun = {"cecil", "125"};

bool login(){

    string inputUsername;
    string inputPassword;
    int percobaan = 0;

    while(percobaan < 3){

        cout<<"\n===== LOGIN SISTEM =====\n";
        cout<<"Username : ";
        cin>>inputUsername;

        cout<<"Password : ";
        cin>>inputPassword;

        if(inputUsername == akun.username && inputPassword == akun.password){
            cout<<"Login berhasil!\n";
            return true;
        }
        else{
            cout<<"Login gagal!\n";
            percobaan++;
        }
    }

    cout<<"Anda gagal login 3 kali. Program berhenti.\n";
    return false;
}

void dataAwal(){

    koleksiSneaker[0].brand = "Nike";
    koleksiSneaker[0].model = "AirForce1";
    koleksiSneaker[0].detail.warna = "White";
    koleksiSneaker[0].detail.ukuran = 42;
    koleksiSneaker[0].harga = 1500000;
    koleksiSneaker[0].kondisi = "Baru";

    koleksiSneaker[1].brand = "Adidas";
    koleksiSneaker[1].model = "Yeezy350";
    koleksiSneaker[1].detail.warna = "Black";
    koleksiSneaker[1].detail.ukuran = 43;
    koleksiSneaker[1].harga = 4200000;
    koleksiSneaker[1].kondisi = "Baru";

    koleksiSneaker[2].brand = "Converse";
    koleksiSneaker[2].model = "ChuckTaylor";
    koleksiSneaker[2].detail.warna = "Red";
    koleksiSneaker[2].detail.ukuran = 41;
    koleksiSneaker[2].harga = 850000;
    koleksiSneaker[2].kondisi = "Bekas";

    koleksiSneaker[3].brand = "Puma";
    koleksiSneaker[3].model = "SuedeClassic";
    koleksiSneaker[3].detail.warna = "Blue";
    koleksiSneaker[3].detail.ukuran = 42;
    koleksiSneaker[3].harga = 1200000;
    koleksiSneaker[3].kondisi = "Baru";

    koleksiSneaker[4].brand = "NewBalance";
    koleksiSneaker[4].model = "NB574";
    koleksiSneaker[4].detail.warna = "Grey";
    koleksiSneaker[4].detail.ukuran = 41;
    koleksiSneaker[4].harga = 1800000;
    koleksiSneaker[4].kondisi = "Bekas";

    jumlahData = 5;
}

// CREATE
void tambahData(){

    cout<<"\n=== Tambah Data Sneaker ===\n";

    cout<<"Brand   : ";
    cin>>koleksiSneaker[jumlahData].brand;

    cout<<"Model   : ";
    cin>>koleksiSneaker[jumlahData].model;

    cout<<"Warna   : ";
    cin>>koleksiSneaker[jumlahData].detail.warna;

    cout<<"Ukuran  : ";
    cin>>koleksiSneaker[jumlahData].detail.ukuran;

    cout<<"Harga   : ";
    cin>>koleksiSneaker[jumlahData].harga;

    cout<<"Kondisi : ";
    cin>>koleksiSneaker[jumlahData].kondisi;

    jumlahData++;

    cout<<"Data berhasil ditambahkan.\n";
}

// READ
void tampilData(){

    if(jumlahData == 0){
        cout<<"Belum ada data.\n";
        return;
    }

    cout<<"\n===== DAFTAR KOLEKSI SNEAKER =====\n";
    cout<<"No  Brand        Model          Warna   Ukuran   Harga   Kondisi\n";
    cout<<"---------------------------------------------------------------\n";

    for(int i=0;i<jumlahData;i++){

        cout<<i+1<<" "
        <<koleksiSneaker[i].brand<<" "
        <<koleksiSneaker[i].model<<" "
        <<koleksiSneaker[i].detail.warna<<" "
        <<koleksiSneaker[i].detail.ukuran<<" "
        <<koleksiSneaker[i].harga<<" "
        <<koleksiSneaker[i].kondisi<<endl;
    }
}

// UPDATE
void updateData(){

    int nomor;

    tampilData();

    cout<<"\nPilih nomor data yang ingin diubah : ";
    cin>>nomor;

    nomor--;

    if(nomor >=0 && nomor < jumlahData){

        cout<<"Harga baru : ";
        cin>>koleksiSneaker[nomor].harga;

        cout<<"Kondisi baru : ";
        cin>>koleksiSneaker[nomor].kondisi;

        cout<<"Data berhasil diperbarui.\n";
    }
    else{
        cout<<"Nomor tidak valid.\n";
    }
}

// DELETE
void hapusData(){

    int nomor;

    tampilData();

    cout<<"\nPilih nomor yang ingin dihapus : ";
    cin>>nomor;

    nomor--;

    if(nomor >=0 && nomor < jumlahData){

        for(int i=nomor;i<jumlahData-1;i++){
            koleksiSneaker[i] = koleksiSneaker[i+1];
        }

        jumlahData--;

        cout<<"Data berhasil dihapus.\n";
    }
    else{
        cout<<"Nomor tidak valid.\n";
    }
}

// MAIN
int main(){

    if(!login()){
        return 0;
    }

    dataAwal();

    int pilihan;

    do{

        cout<<"\n===== MENU UTAMA =====\n";
        cout<<"1. Tambah Data Sneaker\n";
        cout<<"2. Lihat Koleksi Sneaker\n";
        cout<<"3. Update Data Sneaker\n";
        cout<<"4. Hapus Data Sneaker\n";
        cout<<"5. Keluar\n";

        cout<<"Pilih menu : ";
        cin>>pilihan;

        if(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Input harus angka!\n";
        continue;
}
        switch(pilihan){

            case 1:
                tambahData();
                break;

            case 2:
                tampilData();
                break;

            case 3:
                updateData();
                break;

            case 4:
                hapusData();
                break;

            case 5:
                cout<<"Program selesai.\n";
                break;

            default:
                cout<<"Menu tidak tersedia.\n";
        }

    }while(pilihan != 5);

    return 0;
}