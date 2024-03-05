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

void pilihan1(){
    double kmh, cms, ms, mph; //variabel untuk menyimpan kecepatan dalam kmh, cms, ms, mph

    cout << "Masukkan kecepatan dalam km/jam: ";
    cin >> kmh; //input kecepatan dalam kmh

    cms = kmh * 27.7778; //konversi kecepatan dalam kmh ke cms
    ms = kmh / 3.6; //konversi kecepatan dalam kmh ke ms
    mph = kmh * 0.621371; //konversi kecepatan dalam kmh ke mph

    //menampilkan hasil konversi kecepatan dalam kmh ke cms, ms, dan mph
    cout << kmh << " km/jam = " << cms << " cm/detik" << endl; 
    cout << kmh << " km/jam = " << ms << " m/detik" << endl;
    cout << kmh << " km/jam = " << mph << " mil/jam" << endl;
}

void pilihan2(){
    double cms, kmh, ms, mph; //variabel untuk menyimpan kecepatan dalam cms, kmh, ms, mph

    cout << "Masukkan kecepatan dalam cm/detik: ";
    cin >> cms; //input kecepatan dalam cms

    kmh = cms / 27778; //konversi kecepatan dalam cms ke kmh
    ms = cms / 100; //konversi kecepatan dalam cms ke ms
    mph = cms / 44704; //konversi kecepatan dalam cms ke mph

    cout << cms << " cm/detik = " << kmh << " km/jam" << endl; //menampilkan hasil konversi kecepatan dalam cms ke kmh, ms, dan mph
    cout << cms << " cm/detik = " << ms << " m/detik" << endl; //menampilkan hasil konversi kecepatan dalam cms ke kmh, ms, dan mph
    cout << cms << " cm/detik = " << mph << " mil/jam" << endl; //menampilkan hasil konversi kecepatan dalam cms ke kmh, ms, dan mph
}

void pilihan3(){
    double ms, kmh, cms, mph;
  
    cout << "Masukkan kecepatan dalam m/detik: ";
    cin >> ms;

    kmh = ms * 3.6;
    cms = ms * 100;
    mph = ms * 2.23694;

    cout << ms << " m/detik = " << kmh << " km/jam" << endl;
    cout << ms << " m/detik = " << cms << " cm/detik" << endl;
    cout << ms << " m/detik = " << mph << " mil/jam" << endl;
}

void pilihan4(){
    double mph, kmh, cms, ms; //variabel untuk menyimpan kecepatan dalam mph, kmh, cms, ms
  
    cout << "Masukkan kecepatan dalam mil/jam: "; 
    cin >> mph; //input kecepatan dalam mph

    kmh = mph * 1.60934; //konversi kecepatan dalam mph ke kmh
    cms = mph * 44.704; //konversi kecepatan dalam mph ke cms
    ms = mph * 0.44704; //konversi kecepatan dalam mph ke ms

    cout << mph << " mil/jam = " << kmh << " km/jam" << endl; //menampilkan hasil konversi kecepatan dalam mph ke kph, cms, dan ms
    cout << mph << " mil/jam = " << cms << " cm/detik" << endl; //menampilkan hasil konversi kecepatan dalam mph ke kph, cms, dan ms
    cout << mph << " mil/jam = " << ms << " m/detik" << endl; //menampilkan hasil konversi kecepatan dalam mph ke kph, cms, dan ms

}

char mengulang(){ //
    char ulang; 
    cout << "Apakah anda ingin mengulang? (y/n) ";
    cin >> ulang;
    return ulang;
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
        cin >> nim_login; //input nim login
        verifikasi = login(nama, nim, nama_login, nim_login); //memeriksa jika inputan nama dan nim benar
        if (perulangan == 3){ //jika melakukan perulangan lebih dari 3x maka program akan mati
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
    cout << "berhasil";
    char ulangi;
    do{
        ulangi = 'n';
        //menampilkan menu konversi kecepatan
        cout << "Pilih menu konversi kecepatan:" << endl; 
        cout << "1. Konversi Kilometer/jam ke Centimeter/detik, Meter/detik, Mil/jam" << endl;
        cout << "2. Konversi Centimeter/detik ke Kilometer/jam, Meter/detik, Mil/jam" << endl;
        cout << "3. Konversi Meter/detik ke Kilometer/jam, Centimeter/detik, Mil/jam" << endl;
        cout << "4. Konversi Mil/jam ke Kilometer/jam, Centimeter/detik, Meter/detik" << endl;
        cout << "5. keluar" << endl; // keluar dari menu konversi kecepatan
        cout << "Masukkan pilihan (1-5): ";

        int opsi;
        cin >> opsi;

        if (opsi == 1) {
        pilihan1(); // kode konversi km/jam
        ulangi = mengulang();
        system("cls");

        } else if (opsi == 2) {
        pilihan2();// kode konversi cm/detik
        ulangi = mengulang();
        system("cls");

        } else if (opsi == 3) {
        pilihan3(); // kode konversi m/detik
        ulangi = mengulang();
        system("cls");

        } else if (opsi == 4) {
        pilihan4(); // kode konversi mil/jam
        ulangi = mengulang();
        system("cls");

        } else if (opsi == 5) {
        exit(0); 
        }
    }
    while (ulangi == 'y');
    return 0;
}