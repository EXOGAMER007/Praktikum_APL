#include <iostream>

using namespace std;

struct variabel_menu{ //mendeklarisi variabel yang akan digunakan dalam fungsi menu utama
    int jml=0, idx; //deklarasi variabel jml untuk menampung jumlah data yang akan ditampilkan dan idx untuk menampung index data yang akan diubah
    string menu; //deklarasi variabel menu untuk menampung data menu yang dipilih
    string champion[5]; //deklarasi array tempat data champion akan disimpan
    string ulang = "y"; //agar bisa dapat masuk ke dalam perulangan
};

struct variabel_login{ //mendeklarisi variabel yang akan digunakan dalam fungsi login
    string nama = "muh ghazy daffa sampe"; //variabel untuk menyimpan nama
    string nim = "2309106063"; //variabel untuk menyimpan nim
    string nama_login; //variabel untuk menyimpan nama login untuk dibandingkan dengan variabel nama
    string nim_login; //variabel untuk menyimpan nim login untuk dibandingkan dengan variabel nim
    int verifikasi; //variabel untuk menyimpan hasil verifikasi
    int perulangan = 0; //variabel untuk menyimpan jumlah perulangan
};

struct variabel{
    struct variabel_menu menu; //variabel untuk menyimpan data menu yang dipilih
    struct variabel_login login; //variabel untuk menyimpan data login yang dipilih
};

int login(string nama, string nim, string nama_login, string nim_login){ //fungsi untuk memeriksa apakah nama dan nim login benar
    if (nama == nama_login && nim == nim_login){ //jika inputan nama dan nim benar
        return 1;
    }
    else{ //jika inputan nama dan nim salah
        return 0;
    }
}


void menu_utama(){ //fungsi menu utama untuk menampilkan menu
    variabel_menu data; //deklarasi variabel data untuk menampung data yang akan digunakan dalam fungsi menu utama
    // Tampilkan menu
    cout<<"menu\n"
    "1. Tambah data champion meta \n"
    "2. Ubah data champion meta \n"
    "3. Lihat list data champion meta \n"
    "4. hapus salah satu data champion meta \n"
    "5. keluar \n";;

    // Input menu yang dipilih
    fflush(stdin);
    cin>>data.menu; 
    system("cls");

    // Menjalankan perintah menu 1
    if (data.menu =="1"){
        cout << "tambah data \n";
        cout << "masukan nama champion : ";
        cin.ignore();
        getline(cin, data.champion[data.jml]);
        data.jml++;
        system("cls");
        menu_utama();
    }
    
    // Menjalankan perintah menu 2
    else if (data.menu == "2")
    {
        cout << "ubah data \n";
        cout << "masukan urutan data (JIKA INPUTAN SALAH MAKA PROGRAM AKAN MATI) : ";
        cin >> data.idx;
        system("cls");
        if (data.idx > data.jml || data.idx < 1){ // jika inputan tidak memenuhi persyaratan
            cout << "EROR\n";
            cout << "mematikan program\n";
            exit(1);
        }
        else if (data.idx <= data.jml){
            cout << "masukan nama champion : ";
            fflush(stdin);
            getline(cin, data.champion[data.idx - 1]);
            system("cls");
            menu_utama();
        }
        
    }

    // Menjalankan perintah menu 3
    else if (data.menu == "3")
    {
        cout << "tampilan data\n";
        for (int i = 0; i < 5; i++)
        {
            cout << "nama champion ke-" << i + 1 << " " << data.champion[i] << endl;
            cout << "............" << endl;
        }
        menu_utama();
    }

    // Menjalankan perintah menu 4
    else if (data.menu == "4")
    {
        cout << "hapus data\n";
        cout << "masukan nomor data yang ingin di hapus (JIKA INPUTAN SALAH PROGRAM MATI): ";
        cin >> data.idx;
        if (data.idx > data.jml || data.idx < 1){ // jika inputan tidak memenuhi persyaratan
            cout << "EROR\n";
            cout << "mematikan program\n";
            exit(1);
        }
        else if (data.idx <= data.jml){
            for (int i = data.idx - 1; i < data.jml; i++){
                data.champion[i] = data.champion[i + 1]; // mengganti data dengan data yang berada di index selanjutnya

        }
        data.jml--;
        menu_utama();
        }
    }

    else if (data.menu == "5")//jika memilih menu 5 maka program akan mati
    {
        cout << "keluar dari program\n";
        exit(0);
    }

    // Menjalankan perintah jika salah memasukan input atau memasukan input menu yang tidak terdaftar
    else
    {
        cout << "error\n";
        menu_utama(); // memanggil fungsi menu utama untuk menampilkan menu
    }
}

int login2(){ //fungsi login
    variabel_login masuk; //deklarasi variabel login untuk menampung data yang akan digunakan dalam fungsi login

    cout << "masukan nama : ";
    getline(cin, masuk.nama_login); //input nama login
    cout << "masukan nim : ";
    getline(cin,masuk.nim_login); //input nim login
    masuk.verifikasi = login(masuk.nama, masuk.nim, masuk.nama_login, masuk.nim_login); //memeriksa jika inputan nama dan nim benar

    if (masuk.perulangan == 2){ //jika melakukan perulangan lebih dari 3x maka program akan mati
            exit(0);
    }

    else if (masuk.verifikasi == 1){ //jika nama dan nim benar maka login berhasil
        system("cls"); //membersihkan terminal
        cout << "selamat datang " << masuk.nama_login << " dengan nim " << masuk.nim_login << endl;
        menu_utama(); //memanggil fungsi menu utama untuk menampilkan menu
        return 0;
    }

    else if (masuk.verifikasi == 0){ //jika nama dan nim salah makan akan melakukan perulangan
        masuk.perulangan++;
        system("cls"); //membersihkan terminal
        cout << "nama atau nim yang dimasukan salah" << endl;
        cout << "jumlah perulangan : " << masuk.perulangan << endl;
        cout << "salah 3x program akan mati" << endl;
        login2(); //memanggil fungsi login2 untuk melakukan perulangan 
        return 0;
        }
}

int main(){
    
    login2(); //memanggil fungsi untuk login

    return 0;
}



