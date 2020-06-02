#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main() {
	string x;
	string z;

   // inisialisasi map dengan nama hogwarts
   map<string, string> hogwarts;

	cout << "Masukkan Nama!" << endl;
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

  
   return 0;
}
