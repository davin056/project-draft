#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Welcome {
    protected :
        string uname;

    public :
        Welcome() {
            ofstream operate;

            operate.open("user.txt");

            cout << endl;
            cout << "\t\t ----------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t Selamat Datang Di Kalkulator !" << endl;
            cout << "\t\t ----------------------------------------------------------------------------" << endl;
            cout << "\t\t Silahkan masukkan nama anda : ";
            getline(cin, uname);
            system("cls");

            if(!operate.fail()) {
                operate << "Username : " << uname << endl;
                operate.close();
                cout << endl;
            }

            ifstream yourfile;

            yourfile.open("user.txt");
        }

        ~Welcome() {
            cout << "\t\t\t\t Terima kasih " << uname << " semoga harimu menyenangkan" << endl;
            cout << "\t\t ----------------------------------------------------------------------------" << endl;
            // getch();
        }

        virtual void Kalkulator() = 0;
        virtual void Kalkulator(float bil1, float bil2, float hsl, string oper, string pil) = 0;

};

template <class A, class B>

class Rumus : public Welcome {
    public :
        void Kalkulator() {
            cout << "\t\t ----------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t Selamat Menggunakan Kalkulator" << endl;
            cout << "\t\t ----------------------------------------------------------------------------" << endl << endl;
        }

        void Kalkulator(A bil1, A bil2, A hsl, B oper, B pil) {
            try {

                operasi :
                    cout << "\t\t Jenis operasi ( + | - | x or * | : or / | ^ | sin | cos | tan )? "; 
                    cin >> oper;

                if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^" | oper == "sin" | oper == "cos" | oper == "tan") {
                    if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^") {

                        input :
                            cout << "\t\t Bilangan    = "; 
                            cin >> bil1;

                        rumus :
                            if(oper == "+") {
                                cout << "\t\t Bilangan    = "; 
                                cin >> bil2;
                                hsl = bil1 + bil2;
                            }

                            else if(oper == "-") {
                                cout << "\t\t Bilangan    = "; 
                                cin >> bil2;
                                hsl = bil1 - bil2;              
                            }

                            else if(oper == "x" | oper == "*") {
                                cout << "\t\t Bilangan    = "; 
                                cin >> bil2;
                                hsl = bil1 * bil2;              
                            }

                            else if(oper == ":" | oper == "/") {
                                cout << "\t\t Bilangan    = "; 
                                cin >> bil2;
                                hsl = bil1 / bil2;          
                            }

                            else if(oper == "^") {
                                cout << "\t\t Pangkat     = "; 
                                cin >> bil2;
                                hsl = pow(bil1, bil2);
                            }
                    }

                    else if (oper == "sin" | oper == "cos" | oper == "tan") {
                        cout << "\t\t Radian      = "; 
                        cin >> bil2;

                        trigonometri :
                            if(oper == "sin") {
                                hsl = sin(bil2);
                                cout << "\t\t Hasil       = " << hsl << endl;
                            }

                            else if(oper == "cos") {
                                hsl = cos(bil2);
                                cout << "\t\t Hasil       = " << hsl << endl;
                            }

                            else if(oper == "tan") {
                                hsl = tan(bil2);
                                cout << "\t\t Hasil       = " << hsl << endl;
                            }
                    }
                    
                    if(!isinf(hsl)) {
                        while(oper != "=") {
                            cout << "\n\t\t Jenis operasi ( + | - | x or * | : or / | ^ | sin | cos | tan | = )? "; 
                            cin >> oper;

                            if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^") {
                                cout << "\t\t Hasil       = " << hsl << endl;

                                bil1 = hsl;
                                goto rumus;
                            }

                            else if(oper == "=") {
                                cout << "\t\t Hasil akhir = " << hsl << endl << endl;

                                tanya :   
                                    cout << "\t\t Apakah anda ingin melakukan perhitungan kembali (y/n)? "; 
                                    cin >> pil; 
                                    cout << endl;

                                    if(pil == "y" | pil == "Y") {
                                        goto operasi;
                                    }

                                    else if(pil == "n" | pil == "N") {
                                        goto akhir;
                                    }

                                    else{
                                        goto tanya;
                                    }
                            }

                            else if(oper == "sin" | oper == "cos" | oper == "tan") {
                                bil2 = hsl;
                                goto trigonometri;
                            }

                            else {
                                cout << "\t\t Operasi tidak tersedia." << endl;
                            }
                        }
                    }

                    else {
                        throw range_error("range_error");
                    }

                    akhir:
                        cout << "\t\t ----------------------------------------------------------------------------" << endl;          
                }

                else {
                    cout << "\t\t Operasi tidak tersedia." << endl << endl;
                    goto operasi;
                }
            }

            catch(exception& e) {
                cout << "\t\t Hasil akhir = tak hingga" << endl << endl;
                cout << "\t\t ----------------------------------------------------------------------------" << endl;
            }
        }
};

int main() {

    system("cls");
    system("color 02");
    string oper, pil;
    float bil1, bil2, hsl;

    Welcome *wlc;
    Rumus<float, string> rms;

    wlc = &rms;
    wlc -> Kalkulator();
    wlc -> Kalkulator(bil1, bil2, hsl, oper, pil);

return 0;
}
