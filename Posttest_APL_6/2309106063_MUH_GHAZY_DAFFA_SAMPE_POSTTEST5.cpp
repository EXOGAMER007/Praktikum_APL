#include <iostream>

using namespace std;

int lanjut(){
    string a;
    fflush(stdin);
    cout << "ketik ENTER untuk melanjutkan\n";
    getline(cin, a);
    system("cls");
    return 0;
}

struct variabel_menu{ //mendeklarisi variabel yang akan digunakan dalam fungsi menu utama
    int jml=0, idx; //deklarasi variabel jml untuk menampung jumlah data yang akan ditampilkan dan idx untuk menampung index data yang akan diubah
    string menu; //deklarasi variabel menu untuk menampung data menu yang dipilih
    string champion[5]; //deklarasi array tempat data champion akan disimpan
    int kill[5] = {0, 0, 0, 0, 0}; //rata-rata kill champion
    string ulang = "y"; //agar bisa dapat masuk ke dalam perulangan
    int mode =2; //variabel untuk menyimpan mode pencarian ascending atau descending
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



int tampilkan_data(variabel_menu *data){ //fungsi untuk menampilkan data
    for (int i = 0; i < 5; i++)
    {
        cout << "nama champion ke-" << i + 1 << " " << data->champion[i] << endl;
        cout << "kill rata-rata champion dalam 1 match : " << data->kill[i] << endl;
        cout << "............" << endl;
    }
    return 0;
}

int tambah_data(variabel_menu *data){ //fungsi untuk menambahkan data
    cout << "Tambah data (maksimal 5)\n";
    tampilkan_data(data);
    cout << "Masukan nama champion : ";
    cin.ignore();
    getline(cin, data->champion[data->jml]);
    cout << "Masukan kill rata-rata champion dalam 1 match [0-100] : ";
    cin >> data->kill[data->jml];
    cin.ignore();
    data->jml++;
    system("cls");
    return 0;
}

int ubah_data(variabel_menu *data){ //fungsi untuk mengubah data
    cout << "Ubah data \n";
    tampilkan_data(data);
    cout << "Masukan urutan data (JIKA INPUTAN SALAH MAKA PROGRAM AKAN MATI) : ";
    cin >> data->idx;
    system("cls");
    if (data->idx > data->jml || data->idx < 1){ // jika inputan tidak memenuhi persyaratan
        cout << "EROR\n";
        cout << "mematikan program\n";
        exit(1);
    }
    else if (data->idx <= data->jml){
        cout << "masukan nama champion : ";
        fflush(stdin);
        getline(cin, data->champion[data->idx - 1]);
        cout << "masukan kill rata-rata champion dalam 1 match [0-100] : ";
        cin >> data->kill[data->idx - 1];  
        cin.ignore();
        system("cls");
        return 0;
    }
}



int hapus_data(variabel_menu *data){ //fungsi untuk menghapus data 
    cout << "hapus data\n";
    tampilkan_data(data);
    cout << "masukan nomor data yang ingin di hapus (JIKA INPUTAN SALAH PROGRAM MATI): ";
    cin >> data->idx;
    if (data->idx > data->jml || data->idx < 1){ // jika inputan tidak memenuhi persyaratan
        cout << "EROR\n";
        cout << "mematikan program\n";
        exit(1);
    }
    else if (data->idx <= data->jml){
        for (int i = data->idx - 1; i < data->jml; i++){ // mengganti data dengan data yang berada di index selanjutnya
            data->champion[i] = data->champion[i + 1];
            data->kill[i] = data->kill[i + 1]; 
    }
    data->jml--;
    system("cls");
    return 0;
    }
}

void sort_Champ_Asc(variabel_menu *data){ //fungsi untuk mengurutkan data champion secara ascending
    int n = data->jml;
    int i, j, min_idx;

    
    for (i = 0; i < n - 1; i++) {

        // mencari elemen terkecil dari array yang belum terurut
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (data->champion[j] < data->champion[min_idx])
                min_idx = j;
        }

        // menukar elemen terkecil dengan elemen pertama dari array yang belum terurut
        if (min_idx != i)
            swap(data->champion[min_idx], data->champion[i]);
            swap(data->kill[min_idx], data->kill[i]);
    }
    cout << "data champion sudah diurutkan secara ascending\n";
    tampilkan_data(data);
    lanjut();
}

void sort_Champ_Des(variabel_menu *data) {//fungsi untuk mengurutkan data champion secara descending
    int n = data->jml;
    for (int i = 0; i < n-1; i++) {
        int max_idx = i; // mencari elemen terbesar dari array yang belum terurut
        for (int j = i+1; j < n; j++) {
            if (data->champion[j] > data->champion[max_idx]) {
                max_idx = j;
            }
        }
        // menukar elemen terbesar dengan elemen pertama dari array yang belum terurut
        swap(data->kill[max_idx], data->kill[i]);
        swap(data->champion[max_idx], data->champion[i]);
    }
    tampilkan_data(data);
    lanjut();
}

void sort_kill_Des(variabel_menu *data) { //fungsi untuk mengurutkan data kill secara descending
    int n = data->jml;
    for (int i = 0; i < n-1; i++) {
        int max_idx = i; // mencari elemen terbesar dari array yang belum terurut
        for (int j = i+1; j < n; j++) {
            if (data->kill[j] > data->kill[max_idx]) {
                max_idx = j;
            }
        }
        // menukar elemen terbesar dengan elemen pertama dari array yang belum terurut
        swap(data->kill[max_idx], data->kill[i]);
        swap(data->champion[max_idx], data->champion[i]);
    }
    cout << "data champion sudah diurutkan secara Descending\n";
    tampilkan_data(data);
    lanjut();
}

void sort_champ(variabel_menu *data ){
    cout << "pilih jenis pengurutan\n";
    cout << "1. ascending \n"
            "2. descending \n";
    cin >> data->menu;
    system("cls");
    if (data->menu == "1"){
        sort_Champ_Asc(data);
        data->mode = 1;
    }
    else if (data->menu == "2"){
        sort_Champ_Des(data);
        data->mode = 0;
    }
    else{
        cout << "ERROR\n";
        cout << "mematikan program\n";
        exit(1);
    }
}

int sort_data(variabel_menu *data){ //fungsi untuk mengurutkan data
    cout << "pilih data yang ingin diurutkan\n";
    cout << "1. data champion\n"
            "2. data kill rata-rata (descending)\n";
    cin >> data->menu;
    system("cls");
    if (data->menu == "1"){
        cin.ignore();
        sort_champ(data);
    }
    else if (data->menu == "2"){
        cin.ignore();
        sort_kill_Des(data);
    }
    else{
        cout << "ERROR\n";
        cout << "mematikan program\n";
        exit(1);
    }
    return 0;
}

int BinarySearch_Asc(variabel_menu *data, string x) //fungsi untuk mencari data dengan metode binary search ascending
{ 
    int n = data->jml;
    int l = 0; 
    int r = n - 1; 
  
    
    while (l <= r) { 
  
        // mencari nilai tengah
        int m = l + (r - l) / 2; 
  
        
        // 0 sebagai index 
        int res = -1000; 
  
        if (x == (data->champion[m])) 
            res = 0; 
  
        // cek apakah x ada di tengah
        if (res == 0) 
            return m; 
  
        // jika x lebih kecil, lewati bagian kanan
        if (x > (data->champion[m])) 
            l = m + 1; 
  
        // jika x lebih besar, lewati bagian kiri
        else
            r = m - 1; 
    } 
  
    return -1; 
} 

int BinarySearch_Des(variabel_menu *data, string x) //fungsi untuk mencari data dengan metode binary search descending
{ 
    int n = data->jml;
    int l = 0; 
    int r = n - 1; 
  
    
    while (l <= r) { 
  
        // mencari nilai tengah
        int m = l + (r - l) / 2; 
  

        // 0 sebagai index
        int res = -1000; 
  
        if (x == (data->champion[m])) 
            res = 0; 
  
        // cek apakah x ada di tengah
        if (res == 0) 
            return m; 
  
        // jika x lebih kecil, lewati bagian kanan
        if (x > (data->champion[m])) 
            r = m - 1; 
  
        // jika x lebih besar, lewati bagian kiri
        else
            l = m + 1; 
    } 
  
    return -1; 
} 

string cari(){//fungsi untuk mencari data
    string x;
    cout << "masukkan nama champion yang ingin dicari\n";
    cin.ignore();
    getline(cin, x);
    return x;
}

void hasil_search(int hasil){ //fungsi untuk menampilkan hasil dari search
    if (hasil == -1) 
        cout << ("data tidak ditemukan\n"); 
    else
        cout << ("data di temukan pada index \n") << hasil + 1 << endl; 
}

int search(variabel_menu *data){ //fungsi untuk mencari data
    if (data->mode == 1){//jika data champion sudah diurutkan ascending
        string x = cari();
        tampilkan_data(data);
        int result = BinarySearch_Asc(data, x);
        hasil_search(result);
        lanjut();
    }
    else if (data->mode == 0){//jika data champion sudah diurutkan descending
        string x = cari();
        tampilkan_data(data);
        int result = BinarySearch_Des(data, x);
        hasil_search(result);
        lanjut();
    }
    
    else{//jika data champion belum diurutkan
        cout << "Urutkan data terlebih dahulu\n";
    }
    return 0;
}

void menu_utama(variabel_menu *data){ //fungsi menu utama untuk menampilkan menu
    // Tampilkan menu
    cout<<"menu\n"
    "1. Tambah data champion meta \n"
    "2. Ubah data champion meta \n"
    "3. Lihat list data champion meta \n"
    "4. hapus salah satu data champion meta \n"
    "5. Sort data champion meta dan rata-rata kill\n"
    "6. Search data champion meta\n"
    "7. keluar \n";

    // Input menu yang dipilih
    fflush(stdin);
    cin>>data->menu; 
    system("cls");

    // Menjalankan perintah menu 1
    if (data->menu =="1"){
        tambah_data(data);
        menu_utama(data);
    }
    
    // Menjalankan perintah menu 2
    else if (data->menu == "2")
    {
        ubah_data(data);
        menu_utama(data);
    }

    // Menjalankan perintah menu 3
    else if (data->menu == "3")
    {
        cout << "Tampilan data\n";
        tampilkan_data(data);
        lanjut();
        menu_utama(data);
    }

    // Menjalankan perintah menu 4
    else if (data->menu == "4")
    {
        hapus_data(data);
        menu_utama(data);
    }
    else if (data->menu == "5"){
        sort_data(data);
        menu_utama(data);
    }
    
    else if (data->menu == "6"){
        search(data);
        menu_utama(data);
    }
    

    else if (data->menu == "7")//jika memilih menu 5 maka program akan mati
    {
        cout << "keluar dari program\n";
        exit(0);
    }

    // Menjalankan perintah jika salah memasukan input atau memasukan input menu yang tidak terdaftar
    else
    {
        cout << "error\n";
        menu_utama(data); // memanggil fungsi menu utama untuk menampilkan menu
    }
}

int login2(){ //fungsi login
    variabel_menu data; //deklarasi variabel data untuk menampung data yang akan digunakan dalam fungsi menu utama
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
        menu_utama(&data); //memanggil fungsi menu utama untuk menampilkan menu
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



