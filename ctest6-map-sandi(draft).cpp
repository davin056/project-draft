#include <iostream>
#include <fstream>
#include <iterator>
#include <map>

using namespace std;

// enkripsi sederhana caesar cryptography
class Kriptografi {
public:   
   string enkripsi(string str) {
      for(int i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] + 2;

      return str;
   }

   string dekripsi(string str) {
      for(int i = 0; (i < 100 && str[i] != '\0'); i++)
         str[i] = str[i] - 2;
      
      return str;
   }
};

class Autentikasi : public Kriptografi {
public:
    // deklarasi map untuk menyimpan akun
    map<string, string> akun;
    string a;
    map<string,string>:: iterator itr;

    Autentikasi() {
       // inisialisasi data akun
       // key = nama user
       // value = password yang sudah dienkripsi
       // "hcuknmqovk" merupakan string yang terenkripsi dengan teks aslinya adalah "fasilkomti" 
       akun.insert(pair<string, string>("admin", "hcuknmqovk"));

    }

    bool auth(string username, string password) {
       //
       // LATIHAN
       // lengkapi method auth yang digunakan untuk autentikasi user dan password 
       //
       // PETUNJUK:
       // 1. Cek apakah elemen pada map (akun) ditemukan atau tidak menggunakan method find()
       // 2. Membandingkan value elemen dengan user input dengan menggunakan method compare() pada string   
       a = enkripsi(password);

       itr = akun.begin();

       if (username.compare(itr->first) == 0 && a.compare(itr->second) == 0)
          return true;
       else
          return false;
    }

};

class Data { // berisi akun dengan nama "map data" dan fungsi fstream

private:
  int l;
  string hapus,user,profesi,a,b;
  map<string, string> data;
  map<string,string>:: iterator itr;

public:
  int sistem() {

  ofstream os("ctest6ex.cpp", ios::app);
  ifstream is("ctest6ex.cpp");

  if(is.is_open()) {

    menu:
      cout << endl;
      cout << "Pilih salah satu menu yang ingin diakses dengan memasukkan nomor." << endl
         << "1.Tampilkan daftar akun" << endl
         << "2.Tambah akun baru" << endl
         << "3.Hapus akun" << endl
         << "4.Keluar" << endl << endl
         << "Masukkan nomor disini: ";
      cin >> l;

      logik:
        if(l == 1) { // menyimpan data dari teks ke map data
          while(true) {
            getline(is,a);
            getline(is,b);
            data[a] = b;
            if(is.eof()){
              goto show;
            }
          }
        }
        
        else if(l == 2) { // membuat akun baru
          cout << "Username: ";
          cin >> user;
          os << endl << user;
          cout << "Profesi : ";
          cin >> profesi;
          os << endl <<profesi;
          data[user] = profesi;
          l = 1;
          goto logik;
        } 

        else if(l == 3) { // menghapus akun dengan key sebagai rujukan
          cout << "Masukkan username akun yang ingin dihapus" <<endl;
            cin >> hapus;
          data.erase(hapus);
            goto show;
        }

        else if(l == 4) { // keluar dari program
          goto akhir;
        }

        else{ // meminta konfirmasi kembali jika input yang dimasukkan salah
          cout << "Input tidak tersedia, mohon ulangi." << endl;;
          goto menu;
        }

        show: // statement untuk menampilkan semua akun
          cout << endl << "Berikut daftar akun yang tersimpan: " << endl;
          for (itr = data.begin(); itr != data.end(); ++itr) {
                cout << itr->first << "\t" << itr->second << '\n';
            }
            goto menu;

        akhir: // penutup
          cout << "Terima kasih" << endl;

    }

  else {}

  is.close();
  }

};


int main() {
   string user, passwd;

   cout << "Masukkan nama user: ";
   cin >> user;
   cout << "Masukkan password: ";
   cin >> passwd;

   Autentikasi aut;
   Data dt;

   if (aut.auth(user, passwd)) {
      cout << "Login berhasil... " << endl;
      dt.sistem();
   }

   else 
      cout << "Login gagal...";

   cout << endl;
   return 0;
}