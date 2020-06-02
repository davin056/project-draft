#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {

	ofstream os("test.txt", ios::app);
	string nama;
	map<string, string> data;
  	map<string,string>::iterator itr;


	cout << "Masukkan nama pengguna: ";
	getline(cin,nama); // input nama
	os << "\n" << nama; // menambahkan nama ke txt
	data.insert(pair<string, string>(nama,"pengguna")); // membuat map berisi nama pengguna dan "pengguna" untuk memenuhi map
	itr = data.begin(); // karena mapnya cuma satu jadi langsung disimpan di iterator
	cout << itr->first; // output map

return 0;
}