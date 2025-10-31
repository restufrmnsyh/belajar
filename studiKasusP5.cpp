#include <iostream>
using namespace std;

// Anggap saja Anda adalah seorang pustakawan yang baru bekerja. Tugas Anda
// adalah mengatur tumpukan buku di meja. Aturan yang harus Anda ikuti sangat
// ketat:
// Buku hanya bisa diletakkan di paling atas tumpukan.
// Buku hanya bisa diambil dari paling atas tumpukan.
// Kita akan menggunakan struktur data Stack untuk memodelkan tumpukan buku
// ini. Operasi yang Tersedia:
// push(buku): Menambahkan buku baru ke tumpukan.
// pop(): Mengambil buku dari tumpukan.
// peek(): Melihat buku yang ada di paling atas tanpa mengambilnya.
// count(): Menghitung banyak buku di tumpukan.

struct Buku{
    string judul;
    string pengarang;
    int tahunTerbit;
    Buku *next;
    Buku *prev;
};

Buku *top, *bottom, *newBuku, *hapus, *bantu;

void initStack();
bool isEmpty();
void push();
void pop();
void peek();
void count();

int main(){
    int pilihan;
    initStack();
    do{
        cout << "==== MENU TUMPUKAN BUKU ====\n";
        cout << "1. Tambah Buku (Push)\n";
        cout << "2. Hapus Buku (Pop)\n";
        cout << "3. Lihat Buku Paling Atas (Peek)\n";
        cout << "4. Hitung Jumlah Buku (Count)\n";
        cout << "5. Keluar\n";
        cout << "Pilih Menu: "; cin >> pilihan;
        cin.ignore();
        switch (pilihan){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            count();
            break;
        case 5:
            cout << "Terima kasih telah menggunakan program ini.\n";
            exit(0);
            break;
        default:
            break;
        }
    } while (pilihan != 5);
    
}

void initStack(){
    top = NULL;
    bottom = NULL;
}

bool isEmpty(){
    return top == NULL;
}

void push(){
    newBuku = new Buku();
    cout << "Judul: "; getline(cin, newBuku->judul);
    cout << "Pengarang: "; getline(cin, newBuku->pengarang);
    cout << "Tahun Terbit: "; cin >> newBuku->tahunTerbit;
    cin.ignore();
    newBuku->prev = newBuku->next = NULL;
    if(isEmpty()){
        top = newBuku;
        bottom = newBuku;
    } else {
        top->next = newBuku;
        newBuku->prev = top;
        top = newBuku;
    }
}

void pop(){
    if(isEmpty()){
        cout << "Tidak ada Buku di Tumpukan!\n";
    } else {
        hapus = top;
        if(top == bottom){
            top = NULL;
            bottom = NULL;  
        } else {
            top = top->prev;
            top->next = NULL;
        }
        delete hapus;
    }
}

void peek(){
    if(isEmpty()){
        cout << "Tidak ada Buku di Tumpukan!\n";
    } else {
        cout << "Buku Teratas: \n";
        cout << "Judul: " << top->judul << endl;
        cout << "Pengarang: " << top->pengarang << endl;
        cout << "Tahun Terbit: " << top->tahunTerbit << endl;
    }
}

void count(){
    if(isEmpty()){
        cout << "Tidak ada Buku di Tumpukan!\n";
    } else {
        bantu = top;
        int jumlah = 0;
        while(bantu != NULL){
            jumlah++;
            bantu = bantu->prev;
        }
        cout << "Jumlah Buku di Tumpukan: " << jumlah << endl;
    }
}

