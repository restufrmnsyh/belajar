#include<iostream>
using namespace std;

int main(){
    // int x,y; /*x dan y bertipe integer*/
    // int *px;  /*px adalah pointer yang menunjuk objek*/

    // x = 87; 
    // px = &x; /*px berisi alamat dari x*/
    // /*&= ambil alamat, * = ambil nilai dari alamat*/
    // y = *px; /* y berisi nilai dari alamat px */

    // cout << "Alamat x : " << &x << endl;
    // cout << "Isi px : " << px << endl;
    // cout << "Isi x : " << x << endl;
    // cout << "Nilai yang ditunjuk px : " << *px << endl;
    // cout << "Nilai y = " << y << endl;

    // ------------------------------------------

    // Operasi aritmatika pada pointer 1 (Perbandingan Lokasi)
    // int a = 100, b = 200, *pa, *pb;
    // //yang deklarasi lebih dulu dianggap lebih tinggi alamatnya
    // pa = &a; 
    // pb = &b;

    // if (pa < pb){
    //     cout << "Pa menunjuk ke memori lebih rendah dari pb" << endl;
    // }
    // if (pa == pb){
    //     cout << "Pa menunjuk ke memori yang sama dengan pb" << endl;
    // }
    // if (pa > pb){
    //     cout << "Pa menunjuk ke memori lebih tinggi dari pb" << endl;
    // }

    // -------------------------------------------

    // Operasi aritmatika pada pointer 2 (Penunjuk Array)
    // int nilai [3], *penunjuk;
    // nilai[0] = 190;
    // nilai[1] = 280;
    // nilai[2] = 370;

    // penunjuk = &nilai[1];

    // cout << "Nilai " << *(penunjuk - 1) << " ada di alamat memori " << penunjuk - 1 << endl;
    // cout << "Nilai " << *(penunjuk + 0) << " ada di alamat memori " << penunjuk + 1 << endl;
    // cout << "Nilai " << *(penunjuk + 1) << " ada di alamat memori " << penunjuk + 2 << endl;

    // -------------------------------------------
    // Pointer dan string
    // char tokoh[] = "Boboiboy Sopan";
    // char *ptokoh = "Boboiboy Sopan";
    // cout << "Tokoh = " << tokoh << endl; 
    // cout << "pTokoh = " << ptokoh << endl;

    // ptokoh+=9; //menggeser 9 karakter

    // cout << endl;
    // cout << "Tokoh = " << tokoh << endl;
    // cout << "pTokoh = " << ptokoh << endl;

    // --------------------------------------------
    // Pointer dan Array
    int x[5], *p, k;
    p = x;
    x[0] = 5;
    x[1] = x[0];
    x[2] = *p + 2; //nilai yang ditunjuk p(5) + 2 = 7
    x[3] = *(p + 1) - 3; //nilai yang ditunjuk p(0+1) = x[1] = 5 - 3 = 2
    x[4] = *(x + 2); // diisi dengan nilai (0+2) = x[2] = 7

    for ( k = 0; k < 5; k++){
        cout << "Nilai x[" << k << "] = "  << x[k] << endl;
    }
    

}