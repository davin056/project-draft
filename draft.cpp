#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

class Welcome{
    protected :
        string uname;

    public :
        Welcome(){
            ofstream operate;

            operate.open("user.txt");

            cout << endl;
            cout << "\t\t ----------------------------------------------------------------------------" << endl;
            cout << "\t\t\t    Selamat Datang Di Aplikasi Kalkulator Dan Sandi Caesar !" << endl;
            cout << "\t\t ----------------------------------------------------------------------------" << endl;
            cout << "\t\t Silahkan masukkan nama anda : ";
            getline(cin, uname);
            system("cls");

            if(!operate.fail()){
                operate << "Username : " << uname << endl;
                operate.close();
                cout << endl;
            }

            ifstream yourfile;

            yourfile.open("user.txt");

            cout << "\t\t ----------------------------------------------------------------------------" << endl;
            cout << "\t\t\t    Selamat Menggunakan Aplikasi Kalkulator Dan Sandi Caesar" << endl;
            cout << "\t\t ----------------------------------------------------------------------------" << endl << endl;
        }

        ~Welcome(){
            cout << "\t\t\t\tTerima kasih " << uname << " semoga harimu menyenangkan" << endl;
            cout << "\t\t ----------------------------------------------------------------------------" << endl;
            // getch();
        }

        virtual int kalkulator(float bil1, float bil2, float hsl, string oper, string pil) = 0;

};


template <class A, class B>

class Rumus : public Welcome {
    public :
        int kalkulator(A bil1, A bil2, A hsl, B oper, B pil){
            try{
                operasi :
                    cout << "\t\t Jenis operasi ( + | - | x or * | : or / | ^ | sin | cos | tan )? "; 
                    cin >> oper;

                if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^" | oper == "sin" | oper == "cos" | oper == "tan"){
                    if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^"){
                        input :
                            cout << "\t\t Bilangan    = "; 
                            cin >> bil1;

                        rumus :
                            if(oper == "+"){
                                cout << "\t\t Bilangan    = "; 
                                cin >> bil2;
                                hsl = bil1 + bil2;
                            }
                            else if(oper == "-"){
                                cout << "\t\t Bilangan    = "; 
                                cin >> bil2;
                                hsl = bil1 - bil2;              
                            }
                            else if(oper == "x" | oper == "*"){
                                cout << "\t\t Bilangan    = "; 
                                cin >> bil2;
                                hsl = bil1 * bil2;              
                            }
                            else if(oper == ":" | oper == "/") {
                                cout << "\t\t Bilangan    = "; 
                                cin >> bil2;
                                hsl = bil1 / bil2;          
                            }
                            else if(oper == "^"){
                                cout << "\t\t Pangkat     = "; 
                                cin >> bil2;
                                hsl = pow(bil1, bil2);
                            }
                    }

                    else if (oper == "sin" | oper == "cos" | oper == "tan"){
                        cout << "\t\t Radian      = "; 
                        cin >> bil2;

                        trigonometri :
                            if(oper == "sin"){
                                hsl = sin(bil2);
                                cout << "\t\t Hasil       = " << hsl << endl;
                            }
                            else if(oper == "cos"){
                                hsl = cos(bil2);
                                cout << "\t\t Hasil       = " << hsl << endl;
                            }
                            else if(oper == "tan"){
                                hsl = tan(bil2);
                                cout << "\t\t Hasil       = " << hsl << endl;
                            }
                    }
                    
                    if(!isinf(hsl)){
                        while(oper != "="){
                            cout << "\n\t\t Jenis operasi ( + | - | x or * | : or / | ^ | sin | cos | tan | = )? "; 
                            cin >> oper;

                            if(oper == "+" | oper == "-" | oper == "x" | oper == "*" | oper == ":" | oper == "/" | oper == "^"){
                                cout << "\t\t Hasil       = " << hsl << endl;

                                bil1 = hsl;
                                goto rumus;
                            }
                            else if(oper == "="){
                                cout << "\t\t Hasil akhir = " << hsl << endl << endl;

                                tanya :   
                                    cout << "\t\t Apakah anda ingin melakukan perhitungan kembali (y/n)? "; 
                                    cin >> pil; 
                                    cout << endl;

                                    if(pil == "y" | pil == "Y"){
                                      system("cls");
                                      goto operasi;
                                    }
                                    else if(pil == "n" | pil == "N"){
                                        goto akhir;
                                    }
                                    else{
                                        goto tanya;
                                    }
                            }
                            else if(oper == "sin" | oper == "cos" | oper == "tan"){
                                bil2 = hsl;
                                goto trigonometri;
                            }
                            else{
                                cout << "\t\t Operasi tidak tersedia." << endl;
                            }
                        }
                    }
                    else{
                        cout << "\t\t Hasil akhir = Tak hingga" << endl << endl;
                        goto tanya;
                    }

                    akhir:
                        cout << "\t\t ----------------------------------------------------------------------------" << endl;          
                }
                else{
                    cout << "\t\t Operasi tidak tersedia." << endl << endl;
                    goto operasi;
                }
            }
            catch(exception& e){
                
            }
        }
};


class Sandi {

public:
    int cypher() {
        char a,random;
        float ratio=0;
        int i,m,n,o;
        string b;
        vector<char>::iterator itr;

        srand((unsigned) time(0));
        m = (rand() % 25) + 1;

        daftar:
            vector<char>v1;

            cout << "Daftar menu" <<endl 
                 << "1. 5 huruf" << endl
                 << "2. 10 huruf" << endl
                 << "3. 15 huruf" << endl
                 << "4. 20 huruf" << endl
                 << "5. custom" << endl
                 << "6. kembali ke menu utama" << endl
                 << "Pilih nomor: ";
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
                cout << "Masukkan jumlah huruf (antara 1-20): ";
                cin >> n;
                if(n > 20 || n<= 0){
                    n = 5;
                    cout << "Diluar ketentuan! Sistem menggunakan preset 5." << endl;
                }
            }
            else if(o == 6){
                return 0;
            }
            else {
                cout << "Tidak ada dalam daftar menu. Silahkan ulangi." << endl;
                goto daftar; 
            }


            cout << "\nDekripsikan enkripsi berikut." << endl;
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
            cout << "\nKunci: " << m << endl;


            cout << "Masukkan jawaban anda (tanpa spasi): ";
            cin >> b;
            vector<char>v2(b.begin(),b.end());
            for(itr = v2.begin(); itr != v2.end(); itr++){
                if(*itr > 90)
                    *itr = *itr - 32;
                else{}
            }


            if(v2.size() > v1.size()){
                cout << "Dekripsi anda melebihi teks. Semoga lebih baik dalam percobaan berikutnya." << endl << endl;
                goto daftar;
            }
            else if(v2.size() < v1.size()){
                cout << "Dekripsi anda kurang lengkap. Semoga lebih baik dalam percobaan berikutnya." << endl << endl;
                goto daftar;
            }
            else{}


            if(v1 == v2)
                cout << "Dekripsi berhasil." << endl;
            else
                cout << "Dekripsi kurang tepat. Semoga lebih baik dalam percobaan berikutnya." << endl;


            for(i = 0; i < n; i++){
                if(v2[i] == v1[i])
                    ratio++;
            }   
            cout << "Akurasi: " << (ratio/n)*100 << "%" << endl << endl;
            goto daftar;
    }

};


int main(){
    system("cls");
    system("color 06");
    string oper, pil;
    float bil1, bil2, hsl;
    int fitur;

    Welcome *wlc;
    Rumus<float, string> rms;
    Sandi snd;

    awal:
        cout << "\nMenu Utama" << "\n\n" << "Silahkan pilih fitur yang ingin digunakan:" << endl
        << "1. Kalkulator" << endl
        << "2. Sandi Caesar" <<endl
        << "3. Keluar" <<endl
        << "Masukkan nomor fitur: ";
        cin >> fitur;

    switch(fitur) {
        case 1 : {
            cout << endl;   
            wlc = &rms;
            wlc -> kalkulator(bil1, bil2, hsl, oper, pil);
            goto awal;
        }
        case 2 : {
            cout << endl;   
            snd.cypher();
            goto awal;
        }
        case 3 : {
            cout << endl;
            break;
        }
    }

return 0;
}
