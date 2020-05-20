#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <cmath>
#include <windows.h> // StdSetCursorPosition
using namespace std;

class Welcome {
    private :
        string uname;

    public : 
        Welcome() {
            ofstream operate;

            operate.open("user.txt");

            cout << endl;
            cout << "             --------------------------------------------------------------------------" << endl;
            cout << "                                   Selamat datang di Kalkulator !                      " << endl;
            cout << "             --------------------------------------------------------------------------" << endl;
            cout << "               Silahkan Masukkan Nama Anda : ";
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
            getch();
        }

};

class Rumus : public Welcome{
    private :
        float bil1, bil2, hsl;
        string oper;

    public :
        Rumus(){
            operasi :
                cout << "               Jenis Operasi ( + | - | x or * | : or / | ^ | sin | cos | tan )? "; getline(cin, oper);

            if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^" | oper == "sin" | oper == "cos" | oper == "tan"){
                if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^"){
                    input1 :
                        cout << "               Bilangan    = "; cin >> bil1;

                    rumus :
                        if(oper == "+"){
                            cout << "               Bilangan    = "; cin >> bil2;
                            hsl = bil1 + bil2;
                        }
                        else if(oper == "-"){
                            cout << "               Bilangan    = "; cin >> bil2;
                            hsl = bil1 - bil2;              
                        }
                        else if(oper == "x" | oper == "*"){
                            cout << "               Bilangan    = "; cin >> bil2;
                            hsl = bil1 * bil2;              
                        }
                        else if(oper == ":" | oper == "/"){
                            cout << "               Bilangan    = "; cin >> bil2;
                            hsl = bil1 / bil2;          
                        }
                        else if(oper == "^"){
                            cout << "               Pangkat     = "; cin >> bil2;
                            hsl = pow(bil1, bil2);
                        }
                }
                else if (oper == "sin" | oper == "cos" | oper == "tan"){
                    cout << "               Bilangan    = "; cin >> bil2;

                    trigonometri :
                        if(oper == "sin"){
                            hsl = sin(bil2);
                            cout << "               Hasil       = " << hsl << endl;
                        }
                        else if(oper == "cos"){
                            hsl = cos(bil2);
                            cout << "               Hasil       = " << hsl << endl;
                        }
                        else if(oper == "tan"){
                            hsl = tan(bil2);
                            cout << "               Hasil       = " << hsl << endl;
                        }
                }

                if(isinf(hsl)){
                    goto akhir;
                }
                else{
                    while(oper != "="){
                        cout << "\n               Jenis Operasi ( + | - | x or * | : or / | ^ | sin | cos | tan | = )? "; cin >> oper;

                        if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^"){
                            cout << "               Hasil       = " << hsl << endl;

                            bil1 = hsl;
                            goto rumus;
                        }
                        else if(oper == "="){
                            goto akhir;
                        }
                        else if(oper == "sin" | oper == "cos" | oper == "tan"){
                            bil2 = hsl;
                            goto trigonometri;
                        }
                        else{
                            cout << "               Operasi tidak tersedia." << endl;
                        }
                    }

                    akhir:
                        cout << "               Hasil Akhir = " << hsl << endl << endl;
                }
            }
            else{
                cout << "               Operasi tidak tersedia." << endl << endl;

                goto operasi;
                goto input1;
            }
        }
};

int main(){
    Rumus rms;

    return 0;
}
