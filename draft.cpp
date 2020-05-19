#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

class Welcome {
	private :
		string uname;

	public : 
		Welcome() {
		    ofstream operate;

		    operate.open("user.txt");

		    cout << endl;
		    cout << "             -------------------------------------------------------------------------" << endl;
			cout << "                                   Selamat datang di Kalkulator!                      " <<endl;
			cout << "             -------------------------------------------------------------------------" << endl;
		    cout << "               Silahkan Masukkan Username : ";
		    getline(cin, uname);

		    if(!operate.fail()) {
		       	operate << "Username : " << uname << endl;
			    operate.close();
			    cout << endl;
		    }

		    ifstream yourfile;

		    yourfile.open("user.txt");
		}

		~Welcome() {
			cout << "               Terima Kasih, " << uname << ", semoga harimu menyenangkan." << endl;

		}

};

class Rumus : public Welcome{
	private :
		float bil1, bil2, hsl;
		char oper;

	public :
		Rumus(){
			cout << "               Jenis Operasi (+ / - / x / : / ^ )? "; cin >> oper;
			cout << "               Bilangan = "; cin >> bil1;

			rumus :
				if(oper == '+'){
					cout << "               Bilangan = "; cin >> bil2;
					hsl = bil1 + bil2;
				}
				else if(oper == '-'){
					cout << "               Bilangan = "; cin >> bil2;
					hsl = bil1 - bil2;				
				}
				else if(oper == 'x'){
					cout << "               Bilangan = "; cin >> bil2;
					hsl = bil1 * bil2;				
				}
				else if(oper == ':'){
					cout << "               Bilangan = "; cin >> bil2;
					hsl = bil1 / bil2;			
				}
				else if(oper == '^'){
					cout << "               Pangkat  = "; cin >> bil2;
					hsl = pow(bil1, bil2);
				}
				else{
					cout << "               Operasi tidak tersedia." << endl;
				}

			while(oper != '='){
				cout << "\n               Jenis Operasi (+ / - / x / : / ^ / =)? "; cin >> oper;
					if(oper == '='){
						goto akhir;
					}
				cout << "               Hasil    = " << hsl << endl;

				bil1 = hsl;
				goto rumus;
			}

		akhir:
			cout << "               Hasil Akhir = " << hsl << endl;
		}
};

int main() {
	Rumus rms;

	return 0;
} 