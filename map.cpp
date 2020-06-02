#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main() {
	string x;
	string z;

   // inisialisasi map dengan nama hogwarts
   map<string, string> hogwarts;

	cout << "Masukkan Marga dan Nama!" << endl;
	cin >> x;
	z = "hehe";

   // sisipkan elemen key-value berupa nim (key) dan nama (value)
   hogwarts.insert(pair<string, string>(x, z));
   //hogwarts.insert(pair<int, string>(1402032, "Hermione Granger"));
   //hogwarts.insert(pair<int, string>(1402043, "Ron Weasley"));

   // cetak ke layar
   map<string, string>::iterator itr;
   cout << "\tDaftar Siswa Hogwarts : \n";
   cout << "\tNAMA\n";
   for (itr = hogwarts.begin(); itr != hogwarts.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
   }
   cout << endl;

   // sisipkan elemen tambahan
   // hogwarts.insert(pair<int, string>(1403055, "Draco Malfoy"));
   // hogwarts.insert(pair<int, string>(1403061, "Cho Chang"));
   // hogwarts.insert(pair<int, string>(1402047, "Dean Thomas"));
	 //
   // // tampilkan seluruh map (setelah disisipkan)
   // cout << "\tDaftar Siswa Hogwarts (setelah penyisipan elemen): \n";
   // cout << "\tNIM\tNAMA\n";
   // for (itr = hogwarts.begin(); itr != hogwarts.end(); ++itr) {
   //      cout << '\t' << itr->first
   //           << '\t' << itr->second << '\n';
   // }
   // cout << endl;
	 //
   // // menghapus salah satu record
   // cout << "Menghapus salah satu elemen menggunakan perintah hogwarts.erase(1403055)\n" << endl;
   // hogwarts.erase(1403055);
	 //
   // // tampilkan seluruh map (setelah menghapus elemen dengan key 1403055
   // cout << "\tDaftar Siswa Hogwarts (setelah penghapusan elemen key 1403055): \n";
   // cout << "\tNIM\tNAMA\n";
   // for (itr = hogwarts.begin(); itr != hogwarts.end(); ++itr) {
   //      cout << '\t' << itr->first
   //           << '\t' << itr->second << '\n';
   // }
   // cout << endl;
	 //
   // // mengakses salah satu elemen
   // cout << "Elemen dengan key 1402032 adalah " << hogwarts[1402032] << endl;
	 //
   // // copy sebagian elemen
   // cout << "\nCopy sebagian elemen..." << endl;
	 //
   // map<int, string> hogwarts2(hogwarts.find(1402047), hogwarts.end());
	 //
   // // tampilkan map hogwarts2
   // cout << "\tIsi map hogwarts2 (copy sebagian elemen dari map hogwarts):\n";
   // cout << "\tNIM\tNAMA\n";
   // for (itr = hogwarts2.begin(); itr != hogwarts2.end(); ++itr) {
   //      cout << '\t' << itr->first
   //           << '\t' << itr->second << '\n';
   // }
   // cout << endl;

   return 0;
}
