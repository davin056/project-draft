#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {

	ofstream os("test.txt", ios::app);
	string uname,rating;
	map<string, string> data;
  	map<string,string>::iterator itr;

	// pada bagian constructor
	cout << "Masukkan nama pengguna: ";
	getline(cin,uname); // input nama	
	
	//pada bagian destructor
	cout << "Beri peringkat 1-10: ";
	cin >> rating; //input rating
	os << "\n" << uname; // menambahkan nama ke txt
	os << "\n" << rating; // menambahkan rating ke txt
	data.insert(pair<string, string>(uname,rating)); // membuat map berisi uname dan rating untuk memenuhi map
	itr = data.begin(); // karena mapnya cuma satu jadi langsung disimpan di iterator
	cout << itr->first; // output map

return 0;
}
