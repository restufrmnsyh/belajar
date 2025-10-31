#include <iostream>
using namespace std;

struct Mahasiswa {
    int nim;
    string nama;
    float ipk;
};

// int main(){
//     const int JUMLAH_MHS = 5;
//     Mahasiswa mhs[JUMLAH_MHS];
//     for (int i = 0; i < JUMLAH_MHS; i++){
//         cout << "Nama : "; cin >> mhs[i].nama;
//         cout << "NIM : "; cin >> mhs[i].nim;
//         cout << "IPK : "; cin >> mhs[i].ipk;
//         cout << "====================" << endl;
//     }

//     for (int i = 0; i < JUMLAH_MHS; i++){
//         cout << "Nama ; " << mhs[i].nama << endl;
//         cout << "NIM ; " << mhs[i].nim << endl;
//         cout << "IPK ; " << mhs[i].ipk << endl;
//         cout << "====================" << endl;
//     }
// }

// int main (){
//     string mahasiswa[5][3];  //5 jumlah mahasiswa, 3 tipe data
//     for (int i = 0; i < 5; i++){
//         cout << "Nama : "; cin >> mahasiswa[i][0];
//         cout << "NIM : "; cin >> mahasiswa[i][1];
//         cout << "IPK : "; cin >> mahasiswa[i][2];
//         cout << "====================" << endl;
//     }

//     for (int i = 0; i < 5; i++){
//         cout << "Nama ; " << mahasiswa[i][0] << endl;
//         cout << "NIM ; " << mahasiswa[i][1] << endl;
//         cout << "IPK ; " << mahasiswa[i][2] << endl;
//         cout << "====================" << endl;
//     }
// }

int main (){
    Mahasiswa mhs1;
    //mahasiswa mhs2;
    Mahasiswa *ptr_mhs;

    mhs1.nim = 123240050;
    mhs1.nama = "Restu";
    mhs1.ipk = 3.85;

    ptr_mhs = &mhs1; //akses alamat mhs1

    cout << mhs1.ipk << endl;
    cout << ptr_mhs->ipk << endl;

}