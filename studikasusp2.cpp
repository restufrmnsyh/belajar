#include<iostream>
using namespace std;

//Studi Kasus 1
// void misteri1(char*);

// int main(){
//     char string[] = "characters";
//     cout << "String Sebelum proses adalah : " << string << endl;
//     misteri1(string);
//     cout << "String Setelah proses adalah : " << string << endl;
//     return 0;
// }

// void misteri1(char *s){
//     while (*s != '\0'){
//         if (*s >= 'a' && *s <= 'z'){
//             *s = *s - 32; //32 = ukuran ASCII untuk mengubah huruf kecil ke huruf besar
//             ++s;
//         } 
//     }
// }
// --------------------------------------------

// // Studi Kasus 2
// int misteri3(const char*);
// int main(){
//     char string[80];
//     cout << "Masukkan sebuah string : "; cin.getline(string,80);
//     cout << "Panjang string adalah : " << misteri3(string) << endl;
//     return 0;
// }

// int misteri3(const char *s){
//     int x = 0;
//     for (; *s != '\0'; s++){
//         ++x;
//     }
//     return x;
// }
// --------------------------------------------

// Studi Kasus 3
// Buatlah sebuah program pointer untuk mengubahh nilai yang semula 70  menjadi 85
// fungsi bakal nerima parameter pointer yang menunjuk ke nilai 70
void ubahNilai(int*);
int main(){
    int nilai = 70;
    cout << "Nilai sebelum diubah : " << nilai << endl;
    ubahNilai(&nilai);
    cout << "Nilai setelah diubah : " << nilai << endl;
}

void ubahNilai(int *n){
    *n = 85;
}
// --------------------------------------------