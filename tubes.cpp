#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <map>
#include <vector>
#include <windows.h>

#define Batas_kiri 3
#define Batas_kanan 43
#define Batas_atas 11
#define Batas_bawah 36
#define Border_alas char(205)
#define Border_samping char(206)

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

template <class A>
class Tampilan{
	public :
		void printKalkulator(){
			gotoxy(24, 2); cout << "KKKK    KKKK AAAAAAAAAAAA LLLL     KKKK    KKKK UUUU    UUUU LLLL     AAAAAAAAAAAA TTTTTTTTTTTT   OOOOOOOO   RRRRRRRRRR ";
			gotoxy(24, 3); cout << "KKKK    KKKK AAAAAAAAAAAA LLLL     KKKK    KKKK UUUU    UUUU LLLL     AAAAAAAAAAAA TTTTTTTTTTTT  OOOOOOOOOO  RRRR    RRR";
			gotoxy(24, 4); cout << "KKKK   KKKK  AAAA    AAAA LLLL     KKKK   KKKK  UUUU    UUUU LLLL     AAAA    AAAA     TTTT     OOOO    OOOO RRRR    RRR";
			gotoxy(24, 5); cout << "KKKKKKKKK    AAAAAAAAAAAA LLLL     KKKKKKKKK    UUUU    UUUU LLLL     AAAAAAAAAAAA     TTTT     OOOO    OOOO RRRRRRRRR  ";
			gotoxy(24, 6); cout << "KKKK   KKKK  AAAAAAAAAAAA LLLL     KKKK   KKKK  UUUU    UUUU LLLL     AAAAAAAAAAAA     TTTT     OOOO    OOOO RRRR   RRR ";
			gotoxy(24, 7); cout << "KKKK    KKKK AAAA    AAAA LLLLLLLL KKKK    KKKK  UUUUUUUUUU  LLLLLLLL AAAA    AAAA     TTTT      OOOOOOOOOO  RRRR    RRR";
			gotoxy(24, 8); cout << "KKKK    KKKK AAAA    AAAA LLLLLLLL KKKK    KKKK   UUUUUUUU   LLLLLLLL AAAA    AAAA     TTTT       OOOOOOOO   RRRR    RRR";
		}

		void printKalkulator(A i){
			for(i = Batas_atas; i <= Batas_bawah; i++){ //batas kanan kiri kalkulator
				gotoxy(Batas_kiri, i); cout << Border_samping;
				gotoxy(Batas_kanan, i); cout << Border_samping;
			}

			for(i = Batas_kiri + 1; i <= Batas_kanan - 1; i++){ //batas atas, tengah, bawah kalkulator
				gotoxy(i, Batas_atas); cout << Border_alas;
				gotoxy(i, Batas_atas + 5); cout << Border_alas;
				gotoxy(i, Batas_bawah); cout << Border_alas;
			}

			for(i = Batas_atas; i <= 13; i++){ //batas kanan kiri tempat nampilin perhitungan
				gotoxy(Batas_kiri + 3, i + 1); cout << Border_samping;
				gotoxy(Batas_kanan - 3, i + 1); cout << Border_samping;
			}

			for(i = 7; i <= 39; i++){ //batas atas bawah tempat nampilin perhitungan
				gotoxy(i, Batas_atas + 1); cout << Border_alas;
				gotoxy(i, Batas_atas + 3); cout << Border_alas;
			}
			
			for(i = Batas_atas; i <= 11; i++){ //bacaan merk
				gotoxy(Batas_kiri + 14, i + 4); cout << "GREEN LANTERN";
			}
			
			for(i = Batas_atas; i <= 13; i++){ //batas kanan kiri sin, cos, tan, ac
				gotoxy(Batas_kiri + 6, i + 6); cout << Border_samping;
				gotoxy(Batas_kiri + 12, i + 6); cout << Border_samping;

				gotoxy(Batas_kiri + 17, i + 6); cout << Border_samping;
				gotoxy(Batas_kiri + 23, i + 6); cout << Border_samping;

				gotoxy(Batas_kiri + 28, i + 6); cout << Border_samping;
				gotoxy(Batas_kiri + 34, i + 6); cout << Border_samping;
			}

			for(i = 10; i <= 14; i++){ //batas atas bawah sin
				gotoxy(i, Batas_atas + 6); cout << Border_alas;
				gotoxy(i, Batas_atas + 8); cout << Border_alas;
			}

			for(i = 21; i <= 25; i++){ //batas atas bawah cos
				gotoxy(i, Batas_atas + 6); cout << Border_alas;
				gotoxy(i, Batas_atas + 8); cout << Border_alas;
			}

			for(i = 32; i <= 36; i++){ //batas atas bawah tan
				gotoxy(i, Batas_atas + 6); cout << Border_alas;
				gotoxy(i, Batas_atas + 8); cout << Border_alas;
			}

			for(i = Batas_atas; i <= 11; i++){ //bacaan sin, cos, tan, ac 
				gotoxy(Batas_kiri + 8, i + 7); cout << "Sin";
				gotoxy(Batas_kiri + 19, i + 7); cout << "Cos";
				gotoxy(Batas_kiri + 30, i + 7); cout << "Tan";
			}

			for(i = Batas_atas; i <= 13; i++){ //batas kanan kiri 7, 8, 9, :
				gotoxy(Batas_kiri + 3, i + 10); cout << Border_samping;
				gotoxy(Batas_kiri + 7, i + 10); cout << Border_samping;

				gotoxy(Batas_kiri + 10, i + 10); cout << Border_samping;
				gotoxy(Batas_kiri + 14, i + 10); cout << Border_samping;

				gotoxy(Batas_kiri + 17, i + 10); cout << Border_samping;
				gotoxy(Batas_kiri + 21, i + 10); cout << Border_samping;

				gotoxy(Batas_kiri + 26, i + 10); cout << Border_samping;
				gotoxy(Batas_kiri + 30, i + 10); cout << Border_samping;
			}

			for(i = 7; i <= 9; i++){ //batas atas bawah 7
				gotoxy(i, Batas_atas + 10); cout << Border_alas;
				gotoxy(i, Batas_atas + 12); cout << Border_alas;
			}

			for(i = 14; i <= 16; i++){ //batas atas bawah 8
				gotoxy(i, Batas_atas + 10); cout << Border_alas;
				gotoxy(i, Batas_atas + 12); cout << Border_alas;
			}

			for(i = 21; i <= 23; i++){ //batas atas bawah 9
				gotoxy(i, Batas_atas + 10); cout << Border_alas;
				gotoxy(i, Batas_atas + 12); cout << Border_alas;
			}

			for(i = 30; i <= 32; i++){ //batas atas bawah :
				gotoxy(i, Batas_atas + 10); cout << Border_alas;
				gotoxy(i, Batas_atas + 12); cout << Border_alas;
			}

			for(i = Batas_atas; i <= 11; i++){ //bacaan 7, 8, 9, :
				gotoxy(Batas_kiri + 5, i + 11); cout << "7";
				gotoxy(Batas_kiri + 12, i + 11); cout << "8";
				gotoxy(Batas_kiri + 19, i + 11); cout << "9";
				gotoxy(Batas_kiri + 28, i + 11); cout << ":";
			}

			for(i = Batas_atas; i <= 13; i++){ //batas kanan kiri 4, 5, 6, x
				gotoxy(Batas_kiri + 3, i + 14); cout << Border_samping;
				gotoxy(Batas_kiri + 7, i + 14); cout << Border_samping;

				gotoxy(Batas_kiri + 10, i + 14); cout << Border_samping;
				gotoxy(Batas_kiri + 14, i + 14); cout << Border_samping;

				gotoxy(Batas_kiri + 17, i + 14); cout << Border_samping;
				gotoxy(Batas_kiri + 21, i + 14); cout << Border_samping;

				gotoxy(Batas_kiri + 26, i + 14); cout << Border_samping;
				gotoxy(Batas_kiri + 30, i + 14); cout << Border_samping;
			}

			for(i = 7; i <= 9; i++){ //batas atas bawah 4
				gotoxy(i, Batas_atas + 14); cout << Border_alas;
				gotoxy(i, Batas_atas + 16); cout << Border_alas;
			}

			for(i = 14; i <= 16; i++){ //batas atas bawah 5
				gotoxy(i, Batas_atas + 14); cout << Border_alas;
				gotoxy(i, Batas_atas + 16); cout << Border_alas;
			}

			for(i = 21; i <= 23; i++){ //batas atas bawah 6
				gotoxy(i, Batas_atas + 14); cout << Border_alas;
				gotoxy(i, Batas_atas + 16); cout << Border_alas;
			}

			for(i = 30; i <= 32; i++){ //batas atas bawah x
				gotoxy(i, Batas_atas + 14); cout << Border_alas;
				gotoxy(i, Batas_atas + 16); cout << Border_alas;
			}

			for(i = Batas_atas; i <= 11; i++){ //bacaan 4, 5, 6, x
				gotoxy(Batas_kiri + 5, i + 15); cout << "4";
				gotoxy(Batas_kiri + 12, i + 15); cout << "5";
				gotoxy(Batas_kiri + 19, i + 15); cout << "6";
				gotoxy(Batas_kiri + 28, i + 15); cout << "x";
			}

			for(i = Batas_atas; i <= 13; i++){ //batas kanan kiri 1, 2, 3, -
				gotoxy(Batas_kiri + 3, i + 18); cout << Border_samping;
				gotoxy(Batas_kiri + 7, i + 18); cout << Border_samping;

				gotoxy(Batas_kiri + 10, i + 18); cout << Border_samping;
				gotoxy(Batas_kiri + 14, i + 18); cout << Border_samping;

				gotoxy(Batas_kiri + 17, i + 18); cout << Border_samping;
				gotoxy(Batas_kiri + 21, i + 18); cout << Border_samping;

				gotoxy(Batas_kiri + 26, i + 18); cout << Border_samping;
				gotoxy(Batas_kiri + 30, i + 18); cout << Border_samping;
			}

			for(i = 7; i <= 9; i++){ //batas atas bawah 1
				gotoxy(i, Batas_atas + 18); cout << Border_alas;
				gotoxy(i, Batas_atas + 20); cout << Border_alas;
			}

			for(i = 14; i <= 16; i++){ //batas atas bawah 2
				gotoxy(i, Batas_atas + 18); cout << Border_alas;
				gotoxy(i, Batas_atas + 20); cout << Border_alas;
			}
			
			for(i = 21; i <= 23; i++){ //batas atas bawah 3
				gotoxy(i, Batas_atas + 18); cout << Border_alas;
				gotoxy(i, Batas_atas + 20); cout << Border_alas;
			}
			
			for(i = 30; i <= 32; i++){ //batas atas bawah -
				gotoxy(i, Batas_atas + 18); cout << Border_alas;
				gotoxy(i, Batas_atas + 20); cout << Border_alas;
			}
			
			for(i = Batas_atas; i <= 11; i++){ //bacaan 1, 2, 3, -
				gotoxy(Batas_kiri + 5, i + 19); cout << "1";
				gotoxy(Batas_kiri + 12, i + 19); cout << "2";
				gotoxy(Batas_kiri + 19, i + 19); cout << "3";
				gotoxy(Batas_kiri + 28, i + 19); cout << "-";
			}
			
			for(i = Batas_atas; i <= 13; i++){ //batas kanan kiri 0, ., +
				gotoxy(Batas_kiri + 6, i + 22); cout << Border_samping;
				gotoxy(Batas_kiri + 10, i + 22); cout << Border_samping;

				gotoxy(Batas_kiri + 14, i + 22); cout << Border_samping;
				gotoxy(Batas_kiri + 18, i + 22); cout << Border_samping;

				gotoxy(Batas_kiri + 26, i + 22); cout << Border_samping;
				gotoxy(Batas_kiri + 30, i + 22); cout << Border_samping;
			}
			
			for(i = 10; i <= 12; i++){ //batas atas bawah 0
				gotoxy(i, Batas_atas + 22); cout << Border_alas;
				gotoxy(i, Batas_atas + 24); cout << Border_alas;
			}
			
			for(i = 18; i <= 20; i++){ //batas atas bawah .
				gotoxy(i, Batas_atas + 22); cout << Border_alas;
				gotoxy(i, Batas_atas + 24); cout << Border_alas;
			}
			
			for(i = 30; i <= 32; i++){ //batas atas bawah +
				gotoxy(i, Batas_atas + 22); cout << Border_alas;
				gotoxy(i, Batas_atas + 24); cout << Border_alas;
			}
			
			for(i = Batas_atas; i <= 11; i++){ //bacaan 0, ., +
				gotoxy(Batas_kiri + 8, i + 23); cout << "0";
				gotoxy(Batas_kiri + 16, i + 23); cout << ".";
				gotoxy(Batas_kiri + 28, i + 23); cout << "+";
			}
			
			for(i = Batas_atas; i <= 17; i++){ //batas kanan kiri ^
				gotoxy(Batas_kiri + 33, i + 10); cout << Border_samping;
				gotoxy(Batas_kiri + 37, i + 10); cout << Border_samping;
			}
			
			for(i = 37; i <= 39; i++){ //batas atas bawah ^
				gotoxy(i, Batas_atas + 10); cout << Border_alas;
				gotoxy(i, Batas_atas + 16); cout << Border_alas;
			}
			
			for(i = Batas_atas; i <= 11; i++){ //bacaan ^
				gotoxy(Batas_kiri + 35, i + 13); cout << "^";
			}
			
			for(i = Batas_atas; i <= 17; i++){ //batas kanan kiri =
				gotoxy(Batas_kiri + 33, i + 18); cout << Border_samping;
				gotoxy(Batas_kiri + 37, i + 18); cout << Border_samping;
			}
			
			for(i = 37; i <= 39; i++){ //batas atas bawah =
				gotoxy(i, Batas_atas + 18); cout << Border_alas;
				gotoxy(i, Batas_atas + 24); cout << Border_alas;
			}
			
			for(i = Batas_atas; i <= 11; i++){ //bacaan =
				gotoxy(Batas_kiri + 35, i + 21); cout << "=";
			}
		}
};

class Welcome{
	private :
		string nama, rate;

	public :
		map<string,string> user;
        map<string,string>::iterator itr;

		Welcome(){
            for(int i = 7; i <= 160; i++){
				gotoxy(i, Batas_atas + 1); cout << Border_alas;
			}

			gotoxy(0, Batas_atas); cout << "\tMasukkan Nama Anda : ";
			getline(cin, nama);
		}

		~Welcome(){
			ofstream operate;
        	operate.open("user.txt", ios::app); // gunakan file txt kosong

			gotoxy(0, Batas_atas + 22);

           	gotoxy(0, Batas_atas + 1); cout << "\tSilahkan berikan rating 1-10 : ";
           	cin >> rate;
           	user.insert(pair<string, string>(rate, nama));

           	itr = user.begin();
           	if(!operate.fail()){
                operate << "Username : " << nama << endl;
           		operate << "Rating   : " << rate << endl << endl;
                operate.close();
                cout << endl;
            }

            ifstream yourfile;
            yourfile.open("user.txt");

           	for(int i = 7; i <= 160; i++){
				gotoxy(i, Batas_atas + 3); cout << Border_alas;
			}

			for(int i = 7; i <= 160; i++){
				gotoxy(i, Batas_atas + 5); cout << Border_alas;
			}

            gotoxy(49, Batas_atas + 4); cout << "\tTerima kasih " << itr->second << " semoga harimu menyenangkan." << endl;
            cout << endl << endl << '\t';
            system("pause");
        }

        virtual int hitung() = 0;
};

class Kalkulator : public Welcome{
	private :
		float bil1, bil2, hsl;
		string oper, pil;

	public :
		void Operasi(){
            cout << "\t\t\t\t\t\t    Jenis Operasi? ";
            cin >> oper;
        }

        void Bilangan1(){
            while(cout << "\t\t\t\t\t\t    Bilangan     = " && !(cin >> bil1)){
            	cin.clear();
            	cin.ignore();
            	cout << "\t\t\t\t\t\t    Harap memasukkan angka." << endl;
            }
        }

        void Bilangan2(){
        	while(cout << "\t\t\t\t\t\t    Bilangan     = " && !(cin >> bil2)){
            	cin.clear();
            	cin.ignore();
            	cout << "\t\t\t\t\t\t    Harap memasukkan angka." << endl;
            }
        }

        void Radian(){
        	while(cout << "\t\t\t\t\t\t    Radian       = " && !(cin >> bil2)){
            	cin.clear();
            	cin.ignore();
            	cout << "\t\t\t\t\t\t    Harap memasukkan angka." << endl;
            }
        }

        void Tanya(){
            cout << "\t\t\t\t\t\t    Apakah anda ingin melakukan perhitungan kembali (y/n)? ";
            cin >> pil;
            cout << endl;
        }

		int tambah(){
            return hsl = bil1 + bil2;
        }

        int kurang(){
            return hsl = bil1 - bil2;              
        }

        int kali(){
            return hsl = bil1 * bil2;              
        }

        int bagi(){
            return hsl = bil1 / bil2;          
        }
        
        int pangkat(){
            return hsl = pow(bil1, bil2);
        }

        int sinus(){
            return hsl = sin(bil2);
        }

        int cosinus(){
            return hsl = cos(bil2);
        }

        int tangen(){
            return hsl = tan(bil2);
        }

        int hitung(){
            try{
            	cout << endl;
                operasi :
                    Operasi();
                
                if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^" | oper == "sin" | oper == "cos" | oper == "tan"){
                    if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^"){
                        Bilangan1();

                        tambah_kurang_kali_bagi_pangkat :
                            if(oper == "+"){
                                Bilangan2();
                                tambah();
                            }
                            else if(oper == "-"){
                                Bilangan2();
                                kurang();
                            }
                            else if(oper == "x" | oper == "*"){
                                Bilangan2();
                                kali();
                            }
                            else if(oper == ":" | oper == "/"){
                                Bilangan2();
                                bagi();
                            }
                            else if(oper == "^"){
                                Bilangan2();
                                pangkat();
                            }
                    }
                    else if(oper == "sin" | oper == "cos" | oper == "tan"){
                        Radian();

                        sin_cos_tan :
                            if(oper == "sin"){
                                sinus();
                            }
                            else if(oper == "cos"){
                                cosinus();
                            }
                            else if(oper == "tan"){
                                tangen();
                            }
                    }

                    if(!isinf(hsl)){
                        while(oper != "="){
                        	if(!isnan(hsl)){
	                            gotoxy(9, 13);
	                            cout << "                             ";
	                            gotoxy(9, 13);
	                            cout << hsl;
	                            
	                            hasil :
		                            gotoxy(0, Batas_atas + 4);
		                            cout << "\t\t\t\t\t\t                                                                                  " << endl;
		                            cout << "\t\t\t\t\t\t                                                                                  " << endl;
		                            cout << "\t\t\t\t\t\t                                                                                  " << endl;
		                            cout << "\t\t\t\t\t\t                                                                                  " << endl;
		                            cout << "\t\t\t\t\t\t                                                                                  " << endl;
		                            cout << "\t\t\t\t\t\t                                                                                  " << endl;
		                            cout << "\t\t\t\t\t\t                                                                                  " << endl;
		                            cout << "\t\t\t\t\t\t                                                                                  " << endl;
		                            cout << "\t\t\t\t\t\t                                                                                  " << endl;
		                            cout << "\t\t\t\t\t\t                                                                                  " << endl;

		                            gotoxy(0, Batas_atas + 4);
		                            Operasi();

		                            if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^"){
		                                bil1 = hsl;
		                                goto tambah_kurang_kali_bagi_pangkat;
		                            }
		                            else if(oper == "="){
		                                cout << "\t\t\t\t\t\t    Hasil Akhir  = " << hsl << endl << endl;

		                                tanya :
				                            Tanya();

				                            if(pil == "y" | pil == "Y"){
				                            	tes :
					                            	gotoxy(9, 13);
				                            		cout << "                             ";
				                            		gotoxy(0, Batas_atas + 4);
				                            		cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    cout << "\t\t\t\t\t\t                                                                                  " << endl;
								                    gotoxy(0, Batas_atas + 4);
					                                goto operasi;
				                            }
				                            else if(pil == "n" | pil == "N"){
								                gotoxy(0, Batas_atas);
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
								                cout << "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            " << endl;
				                                return 0;
				                            }
				                            else 
				                                goto tanya;
		                            }
		                            else if(oper == "sin" | oper == "cos" | oper == "tan"){
		                                bil2 = hsl;
		                                goto sin_cos_tan;
		                            }
	                        }
	                        else{
	                        	hsl = 0;
	                        	gotoxy(9, 13);
	                            cout << "                             ";
	                            gotoxy(9, 13);
	                            cout << hsl;
	                            goto hasil;
	                        }
                        }
                    }
                    else{
                        throw range_error("range_error");
                    }
                }
                else{
                	goto tes;
                }
            }
            catch(exception& e){
            	gotoxy(9, 13);
                cout << "                             ";
                gotoxy(9, 13);
                cout << hsl;
                gotoxy(0, Batas_atas + 4);
                cout << "\t\t\t\t\t\t                                                                                  " << endl;
                cout << "\t\t\t\t\t\t                                                                                  " << endl;
                cout << "\t\t\t\t\t\t                                                                                  " << endl;
                cout << "\t\t\t\t\t\t                                                                                  " << endl;
                cout << "\t\t\t\t\t\t                                                                                  " << endl;
                cout << "\t\t\t\t\t\t                                                                                  " << endl;
                cout << "\t\t\t\t\t\t                                                                                  " << endl;
                cout << "\t\t\t\t\t\t                                                                                  " << endl;
                cout << "\t\t\t\t\t\t                                                                                  " << endl;
                cout << "\t\t\t\t\t\t                                                                                  " << endl;

                gotoxy(0, Batas_atas + 4);
                cout << "\t\t\t\t\t\t    Hasil Akhir  = Tak Hingga" << endl << endl;
                cout << "\t\t\t\t\t\t    "; system("pause");

                gotoxy(0, Batas_atas);
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
                cout << "                                                                                                                                                                                                                                                      " << endl;
            }
        }
};

class Sandi{
	public:
    	int cypher(){
	    char a, random;
	    float ratio = 0;
	    int i, m, n, o;
	    string b;
        vector<char>::iterator itr;

	    srand((unsigned) time(0));
	    m = (rand() % 25) + 1;

	    daftar:
	        vector<char>v1;

	    	gotoxy(79, Batas_atas + 1);
	        cout << "\tDaftar menu\n\n" 
	             << "\t1. 5 huruf" << endl
	             << "\t2. 10 huruf" << endl
	             << "\t3. 15 huruf" << endl
	             << "\t4. 20 huruf" << endl
	             << "\t5. Custom" << endl
	             << "\t6. Kembali ke menu utama" << endl
	             << "\tPilih nomor : ";
	        cin >> o;


	        if(o == 1)
	            n = 5;
	        else if(o == 2)
	            n = 10;
	        else if(o == 3)
	            n = 15;
	        else if(o == 4)
	            n = 20;
	        else if(o == 5){
	            cout << "\tMasukkan jumlah huruf (antara 1-20) : ";
	            cin >> n;

	            if(n > 20 || n <= 0){
	                n = 5;
	                cout << "\tDiluar ketentuan! Sistem menggunakan preset 5." << endl;
	            }
	        }
	        else if(o == 6){
	          	gotoxy(79, Batas_atas + 1);
	            cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
	            gotoxy(79, Batas_atas + 1);
	            
	            return 0;
	        }
	        else {
				cout << "\tTidak ada dalam daftar menu. Silahkan ulangi." << endl << endl;
				cout << "\t"; system("pause");

				gotoxy(79, Batas_atas + 1);
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
	            cout << "\t                                                                                                                                                             " << endl;
	            cout << "\t                                                                                                                                                             " << endl;
	            cout << "\t                                                                                                                                                             " << endl;
	            cout << "\t                                                                                                                                                             " << endl;
	            cout << "\t                                                                                                                                                             " << endl;
	            cout << "\t                                                                                                                                                             " << endl;
	            cout << "\t                                                                                                                                                             " << endl;
	            cout << "\t                                                                                                                                                             " << endl;
	            cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
	            gotoxy(79, Batas_atas + 1);
	            goto daftar; 
	        }


	        cout << "\n\tDekripsikan enkripsi berikut." << endl;
	        cout << "\t";

	        for (i = 0; i < n; i++) {
	            random = (rand() % 26) + 65;
	            v1.push_back(random);
	            a = random+m;
	            
	            if(a > 90) {
	            	a = a - 26;
	        	}
	            else{}
	            
	            cout << a;
	        }

	        cout << "\n\tKunci: " << m << endl;


	        cout << "\tMasukkan jawaban anda (tanpa spasi) : ";
	        cin >> b;

	        vector<char>v2(b.begin(),b.end());
	        for(itr = v2.begin(); itr != v2.end(); itr++){
	            if(*itr > 90)
	                *itr = *itr - 32;
	            else{}
	        }


	        if(v2.size() > v1.size()){
	            cout << "\tDekripsi anda melebihi teks. Semoga lebih baik dalam percobaan berikutnya." << endl;
	            cout << "\tJawaban yang benar : ";
	            
	            for(itr = v1.begin(); itr != v1.end(); itr++){
	            	cout << *itr;
	        	}
	            
	            cout << endl << endl;
                cout << "\t"; system("pause");

				gotoxy(79, Batas_atas + 1);
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
			    cout << "\t                                                                                                                                                             " << endl;
				gotoxy(79, Batas_atas + 1);
				goto daftar;
	        }
	        else if(v2.size() < v1.size()){
	            cout << "\tDekripsi anda kurang lengkap. Semoga lebih baik dalam percobaan berikutnya." << endl;
	            cout << "\tJawaban yang benar : ";
	            
	            for(itr = v1.begin(); itr != v1.end(); itr++){
	            	cout << *itr;
	        	}
	        	
	        	cout << endl << endl;
	            cout << "\t"; system("pause");
              	gotoxy(79, Batas_atas + 1);
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				cout << "\t                                                                                                                                                             " << endl;
				gotoxy(79, Batas_atas + 1);
				goto daftar;
	        }
	        else{}


	        if(v1 == v2)
	            cout << "\tDekripsi berhasil." << endl;
	        else{
	            cout << "\tDekripsi kurang tepat. Semoga lebih baik dalam percobaan berikutnya." << endl;
	            cout << "\tJawaban yang benar : ";
	            
	            for(itr = v1.begin(); itr != v1.end(); itr++){
	            	cout << *itr;
	        	}
	        	
	        	cout << endl;
	        }


            for(i = 0; i < n; i++){
                if(v2[i] == v1[i])
                    ratio++;
            } 
              
            cout << "\tAkurasi: " << (ratio/n)*100 << "%" << endl << endl;
            cout << "\t"; system("pause");

	        gotoxy(79, Batas_atas + 1);
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        cout << "\t                                                                                                                                                             " << endl;
	        gotoxy(79, Batas_atas + 1);
            goto daftar;
    	}

};

int main(){
	system("cls");
	int i, fitur;
	Tampilan<int> tmpl;
	tmpl.printKalkulator();
	Welcome *wlc;
	Kalkulator calc;
	Sandi snd;

	awal:
		tmpl.printKalkulator();
		gotoxy(79, Batas_atas + 2);
		cout << "\tMenu Utama\n\n"
        	 << "\tSilahkan pilih fitur yang ingin digunakan:" << endl
        	 << "\t1. Kalkulator" << endl
	         << "\t2. Sandi Caesar" <<endl
	         << "\t3. Keluar" <<endl
	         << "\tMasukkan nomor opsi yang dipilih : ";
        cin >> fitur;

    switch(fitur) {
        case 1 : {
            system("cls");  
            tmpl.printKalkulator();	 
            tmpl.printKalkulator(i);
            gotoxy(0, Batas_atas + 3); 
            wlc = &calc;
	    	wlc -> hitung();
            system("cls");
            goto awal;
        }
        case 2 : {
            system("cls");  
            tmpl.printKalkulator();
            gotoxy(0, Batas_atas + 2);   
            snd.cypher();
            system("cls");
            goto awal;
        }
        case 3 : {
            system("cls");  
            tmpl.printKalkulator();
            break;
        }
        default : {
        	system("cls");
        	goto awal;
        }
    }

	return 0;
}
