#include <iostream>

using namespace std;

int login(string nama, string nim, string nama_login, string nim_login){
    if (nama == nama_login && nim == nim_login){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int verifikasi; //variabel untuk menyimpan hasil verifikasi
    int perulangan = 0; //variabel untuk menyimpan jumlah perulangan
    do
    {
        string nama = "muh ghazy daffa sampe"; //variabel untuk menyimpan nama
        string nim = "2309106063"; //variabel untuk menyimpan nim
        string nama_login; //variabel untuk menyimpan nama login untuk dibandingkan dengan variabel nama
        string nim_login; //variabel untuk menyimpan nim login untuk dibandingkan dengan variabel nim

        cout << "masukan nama : ";
        getline(cin, nama_login); //input nama login
        cout << "masukan nim : ";
        getline(cin,nim_login); //input nim login
        verifikasi = login(nama, nim, nama_login, nim_login); //memeriksa jika inputan nama dan nim benar

        if (perulangan == 2){ //jika melakukan perulangan lebih dari 3x maka program akan mati
                exit(0);
        }

        else if (verifikasi == 1){ //jika nama dan nim benar maka login berhasil
            system("cls"); //membersihkan terminal
            cout << "selamat datang " << nama_login << " dengan nim " << nim_login << endl;
        }

        else if (verifikasi == 0){ //jika nama dan nim salah makan akan melakukan perulangan
            perulangan++;
            system("cls"); //membersihkan terminal
            cout << "nama atau nim yang dimasukan salah" << endl;
            cout << "jumlah perulangan : " << perulangan << endl;
            cout << "salah 3x program akan mati" << endl;
        }
    }

    while (verifikasi == 0); // syarat perulangan

    int jml=0, idx; //deklarasi variabel jml untuk menampung jumlah data yang akan ditampilkan dan idx untuk menampung index data yang akan diubah
    string menu; //deklarasi variabel menu untuk menampung data menu yang dipilih
    string champion[5]; //deklarasi array tempat data champion akan disimpan
    string ulang = "y"; //agar bisa dapat masuk ke dalam perulangan
    
    // Tampilkan menu
    while (ulang == "y"){ 
        cout<<"menu\n"
    "1. Tambah data champion meta \n"
    "2. Ubah data champion meta \n"
    "3. Lihat list data champion meta \n"
    "4. hapus salah satu data champion meta \n"
    "5. keluar \n";;

    // Input menu yang dipilih
    cin>>menu; 
    system("cls");

    // Menjalankan perintah menu 1
    if (menu =="1"){
        cout << "tambah data \n";
        cout << "masukan nama champion : ";
        cin.ignore();
        getline(cin, champion[jml]);
        jml++;
    }
    
    // Menjalankan perintah menu 2
    else if (menu == "2"){
        cout << "ubah data \n";
        cout << "masukan urutan data : ";
        cin >> idx;
        cout << "masukan nama champion : ";
        cin.ignore();
        getline(cin, champion[idx-1]);
    }

    // Menjalankan perintah menu 3
    else if (menu == "3"){
        cout << "tampilan data\n";
        for (int i = 0; i < 5; i++){
            cout << "nama champion ke-"<< i+1 <<" "<< champion[i]<< endl;
            cout << "............" << endl;
        }
    }
    
    // Menjalankan perintah menu 4
    else if (menu == "4"){
        cout << "hapus data\n";
        cout << "masukan nomor data yang ingin di hapus : ";
        cin >> idx;
        

        for (int i = idx-1; i < jml; i++){
            champion[i] = champion[i+1]; //mengganti data dengan data yang berada di index selanjutnya
        }
        jml--;
        
    } 

    else if (menu == "5"){
        cout << "keluar dari program\n";
        exit(0);    
    }
    

    // Menjalankan perintah jika salah memasukan input atau memasukan input menu yang tidak terdaftar
    else{
        cout << "error\n";
    }

    // Menjalankan perintah jika ingin mengulang
    cout << "apakah ingin mengulang? (y/n) : ";
    cin>>ulang;
    system("cls");

    // Menjalankan perintah untuk berhenti dari looping
    if (ulang != "y" && ulang != "Y"){
        break;
    }
    }
    
}