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
Sneaker koleksiSneaker[100];
int jumlahData = 0;
User akun = {"cecil", "125"};

// ================= LOGIN =================
bool login(User akunUser){

    string inputUsername, inputPassword;
    int percobaan = 0;

    while(percobaan < 3){

        cout<<"\n===== LOGIN SISTEM =====\n";
        cout<<"Username : "; cin>>inputUsername;
        cout<<"Password : "; cin>>inputPassword;

        if(inputUsername == akunUser.username && inputPassword == akunUser.password){
            cout<<"Login berhasil!\n";
            return true;
        } else {
            cout<<"Login gagal!\n";
            percobaan++;
        }
    }

    cout<<"Gagal login 3 kali.\n";
    return false;
}

// ================= DATA AWAL =================
void dataAwal(Sneaker data[], int &jumlah){

    data[0] = {"Nike","AirForce1",1500000,"Baru",{"White",42}};
    data[1] = {"Adidas","Yeezy350",4200000,"Baru",{"Black",43}};
    data[2] = {"Converse","ChuckTaylor",850000,"Bekas",{"Red",41}};
    data[3] = {"Puma","SuedeClassic",1200000,"Baru",{"Blue",42}};
    data[4] = {"NewBalance","NB574",1800000,"Bekas",{"Grey",41}};

    jumlah = 5;
}

// ================= CREATE =================
void tambahData(Sneaker data[], int &jumlah){

    cout<<"\n=== Tambah Data Sneaker ===\n";

    cout<<"Brand   : "; cin>>data[jumlah].brand;
    cout<<"Model   : "; cin>>data[jumlah].model;
    cout<<"Warna   : "; cin>>data[jumlah].detail.warna;
    cout<<"Ukuran  : "; cin>>data[jumlah].detail.ukuran;
    cout<<"Harga   : "; cin>>data[jumlah].harga;
    cout<<"Kondisi : "; cin>>data[jumlah].kondisi;

    jumlah++;
    cout<<"Data berhasil ditambahkan.\n";
}

// ================= READ =================
void tampilData(Sneaker data[], int jumlah){

    if(jumlah == 0){
        cout<<"Belum ada data.\n";
        return;
    }

    cout<<"\n===== DATA SNEAKER =====\n";

    for(int i=0;i<jumlah;i++){
        cout<<i+1<<". "
        <<data[i].brand<<" "
        <<data[i].model<<" "
        <<data[i].detail.warna<<" "
        <<data[i].detail.ukuran<<" "
        <<data[i].harga<<" "
        <<data[i].kondisi<<endl;
    }
}

// ================= OVERLOADING =================
void tampilData(Sneaker data[], int jumlah, string kondisiCari){

    cout<<"\n=== FILTER KONDISI: "<<kondisiCari<<" ===\n";

    for(int i=0;i<jumlah;i++){
        if(data[i].kondisi == kondisiCari){
            cout<<data[i].brand<<" "<<data[i].model<<endl;
        }
    }
}

// ================= UPDATE =================
void updateData(Sneaker data[], int jumlah){

    int nomor;
    tampilData(data, jumlah);

    cout<<"\nPilih nomor : ";
    cin>>nomor;
    nomor--;

    if(nomor >=0 && nomor < jumlah){

        cout<<"Harga baru : ";
        cin>>data[nomor].harga;

        cout<<"Kondisi baru : ";
        cin>>data[nomor].kondisi;

        cout<<"Data berhasil diupdate.\n";
    } else {
        cout<<"Nomor tidak valid.\n";
    }
}

// ================= DELETE =================
void hapusData(Sneaker data[], int &jumlah){

    int nomor;
    tampilData(data, jumlah);

    cout<<"\nPilih nomor : ";
    cin>>nomor;
    nomor--;

    if(nomor >=0 && nomor < jumlah){

        for(int i=nomor;i<jumlah-1;i++){
            data[i] = data[i+1];
        }

        jumlah--;
        cout<<"Data berhasil dihapus.\n";
    } else {
        cout<<"Nomor tidak valid.\n";
    }
}

// ================= REKURSIF =================
int hitungJumlah(int jumlah){
    if(jumlah == 0)
        return 0;
    return 1 + hitungJumlah(jumlah - 1);
}

// ================= PROSEDUR =================
void tampilMenu(){

    cout<<"\n===== MENU =====\n";
    cout<<"1. Tambah Data\n";
    cout<<"2. Lihat Data\n";
    cout<<"3. Update Data\n";
    cout<<"4. Hapus Data\n";
    cout<<"5. Total Data (Rekursif)\n";
    cout<<"6. Filter Kondisi\n";
    cout<<"7. Keluar\n";
}

// ================= MAIN =================
int main(){

    if(!login(akun)){
        return 0;
    }

    dataAwal(koleksiSneaker, jumlahData);

    int pilihan;

    do{
        tampilMenu();
        cout<<"Pilih : ";
        cin>>pilihan;

        switch(pilihan){

            case 1:
                tambahData(koleksiSneaker, jumlahData);
                break;

            case 2:
                tampilData(koleksiSneaker, jumlahData);
                break;

            case 3:
                updateData(koleksiSneaker, jumlahData);
                break;

            case 4:
                hapusData(koleksiSneaker, jumlahData);
                break;

            case 5:
                cout<<"Total data: "<<hitungJumlah(jumlahData)<<endl;
                break;

            case 6:
                tampilData(koleksiSneaker, jumlahData, "Baru");
                break;

            case 7:
                cout<<"Program selesai.\n";
                break;

            default:
                cout<<"Menu tidak ada.\n";
        }

    }while(pilihan != 7);

    return 0;
}