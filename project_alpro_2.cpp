#include <iostream>
#include <string>
using namespace std;
//tes
struct akun 
{
    string username;
    string password;
};

struct buku
{
    string judul;
    string penulis;
};

//Varibel buat Buku
const int max_buku = 3000;
int bukucount = 0;
buku daftarBuku[max_buku];

//Punya Akun
const int max_user = 1000;
int usercount = 0;
akun acc[max_user];

bool found = 0;

void tambahBukuRekursif(int jumlah) {
    if (jumlah == 0 || bukucount >= max_buku) {
        return;
    }
    cout << "Masukkan judul buku: ";
    cin.ignore();
    getline(cin, daftarBuku[bukucount].judul);
    cout << "Masukkan penulis buku: ";
    getline(cin, daftarBuku[bukucount].penulis);
    bukucount++;
    cout << "Buku berhasil ditambahkan!" << endl;
    tambahBukuRekursif(jumlah - 1);
}

void cekBukuRekursif(int index) {
    if (index >= bukucount) {
        return;
    }
    cout << "Judul: " << daftarBuku[index].judul << ", Penulis: " << daftarBuku[index].penulis << endl;
    cekBukuRekursif(index + 1);
}

void cekBuku() {
    if (bukucount == 0) {
        cout << "Tidak ada buku dalam daftar." << endl;
        return;
    }
    cout << "Daftar Buku:" << endl;
    cekBukuRekursif(0);
}

void menuAdmin() {
    system("cls");
    int pilihan;
    do {
        cout << "\n=== MENU ADMIN ===" << endl;
        cout << "[1] Tambah Buku" << endl;
        cout << "[2] Hapus Buku" << endl;
        cout << "[3] Cek Buku" << endl;
        cout << "[4] Logout" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: 
            int jumlah;
                cout << "Masukkan jumlah buku yang ingin ditambahkan: ";
                cin >> jumlah;
                tambahBukuRekursif(jumlah);
            case 2:
            cekBuku();
            case 4: cout << "Logout berhasil!" << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);
}

void daftar(){
    system("cls");
    bool ada = false;
    if(usercount >= max_user){
        cout<<"REGISTRASI GAGAL : KAPASITAS PENUH"<< endl;
    }
    string username, password;
    cout << "\n=== Registrasi ===" << endl;
    cout << "Masukkan username: "; cin >> username;
    cout << "Masukkan password: "; cin >> password;

    for(int i = 0; i < usercount; i++){
        if(username == acc[i].username){
            ada = true;
        };
    };
    
    if(ada == true){
        cout<<"username sudah ada\n";
        cin.get();
    }else if(ada == false){
        
        acc[usercount].username = username;
        acc[usercount].password = password;
        usercount++;
        cout<<"Registrasi berhasil!\n"<<endl;
    }
}

void login(){
    system("cls");


    int life = 0;
    bool loginberhasil = false;
    do{

        
        string input_user, input_pass;
        cout << "Masukan username anda: "; getline(cin, input_user);
        cout << "Masukan pass anda    : "; getline(cin, input_pass);

        if(input_user == "admin" && input_pass == "admin123")
        {
            menuAdmin();
            life = 3;
        }
        else{

            if(usercount==0){
                cout<<"akun belum ada!\n"<<endl;
                life = 3;
                cin.get();
                break;
            }

            for(int i = 0; i < usercount ; i++){
                if(input_user == acc[i].username && input_pass == acc[i].password){
                    found = 1;
                    life = 3;
                    loginberhasil = true;
                    life++;
                    break;

                }else if (input_user != acc[i].username || input_pass != acc[i].password)
                {
                    
                }
            }

            if (loginberhasil)
            {
                cout<<"login berhasil"<<endl;
                if (input_user == "admin") 
                {
                    menuAdmin();
                } else {
                    cout << "Selamat datang, " << input_user << "!\n" << endl;
                }
                
            } else{
                cout<<"kata sandi dan password salah\n";
            }  
        cin.ignore();
        cin.get();
        }
}while(life < 3);

    }


int main(){
    akun acc[max_user];
    bool ulang = 0;
    int choice;
        do{
            system("cls");
        cout<<"[1]daftar\n";
        cout<<"[2]login\n";
        cout<<"[3]keluar\n";
        cout<<"masukkan angka : ";
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1 : daftar();
            break;
            case 2 : login();
            if(found==0){
                return main();
            }else{
                cout<<"masuk sistem"<<endl;
            }
            break; 
        }
    }while(!ulang);
}