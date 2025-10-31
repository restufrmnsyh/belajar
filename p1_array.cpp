#include <iostream>
using namespace std;


// array
int main(){
    string nama[5];
    int nim[5];
    float ipk[5];


    for (int i = 0; i < 5; i++){
       cout << "Nama : "; cin >> nama[i];
        cout << "NIM : "; cin >> nim[i];
        cout << "IPK : "; cin >> ipk[i];
    }
    
    for (int i = 0; i < 5; i++){
        cout << "Nama ; " << nama[i] << endl;
        cout << "NIM ; " << nim[i] << endl;
        cout << "IPK ; " << ipk[i] << endl;
    }
    
    // cout << nilai[0] << endl;
    // cout << nilai[2] << endl;
    // nilai [2] = 90;
    // cout << nilai[2] << endl;
    
    // int daftarNilai[3][2] = {
    //     {75, 80},
    //     {80, 90},
    //     {80, 95}
    // };

    // cout << daftarNilai[1][1] << endl;
    // daftarNilai[1][1] = 60;
    // cout << daftarNilai[1][1] << endl;
}

// Struct
// struct Mahasiswa {
//     int nim;
//     string nama;
//     float ipk;
// };

// int main (){
//     Mahasiswa mhs1;
//     mhs1.nim = 123240050;
//     mhs1.nama = "Restu";
//     mhs1.ipk = 3.85;

//     cout << mhs1.nama << endl;
// }