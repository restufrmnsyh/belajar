// Sebuah restoran memiliki sistem antrean untuk pelanggan yang ingin melakukan
// pembelian makanan dan minuman. Setiap pelanggan yang datang akan
// mengantre untuk mendapatkan layanan dari kasir. Setelah dilayani, pelanggan
// akan meninggalkan antrean. Sistem ini menggunakan struktur data queue untuk
// mengelola antrean pelanggan.
// Fitur yang Diperlukan:
// Menambah nama dan id pelanggan ke antrean (enqueue) secara dinamis a.k.a.
// di-input manual oleh sistem.
// Menghapus nama pelanggan dari antrean setelah ia dilayani (dequeue).
// Menampilkan daftar pelanggan dalam antrean.
// Reset antrean jika sistem sedang diperbaiki
// Menghitung jumlah antrean

#include<iostream>
using namespace std;

struct pelanggan {
    string nama;
    int id;
    pelanggan *next;
};

pelanggan *front = nullptr, *rear = nullptr;

bool isEmpty();
void enqueue();
void dequeue();
void daftarAntrean();
void resetAntrian();
int hitungAntrean();

int main(){
    int pilih;
    do {
        cout << "==== SISTEM ANTREAN RESTORAN ===\n";
        cout << "1. Tambah Pelanggan (enqueue)\n";
        cout << "2. Layani Pelanggan (dequeue)\n";
        cout << "3. Tampilkan Antrean\n";
        cout << "4. Reset Antrean\n";
        cout << "5. Hitung Jumlah Antrean\n";
        cout << "6. Keluar\n";
        cout << "Pilih Menu: "; cin >> pilih;
        cin.ignore();
        switch (pilih){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            daftarAntrean();
            break;
        case 4:
            resetAntrian();
            break;
        case 5:
            hitungAntrean();
            break;
        case 6:
            cout << "terima kasih\n";
            exit(0);
            break;
        default:
            cout << "Pilihan Tidak Valid\n";
            break;
        }
    } while (pilih!=6);
    
}

bool isEmpty(){
    if (front == nullptr){
        return true;
    } else {
        return false;
    }
}

void enqueue(){
    pelanggan *newPelanggan = new pelanggan();
    cout << "Nama Pelanggan: "; getline(cin, newPelanggan->nama);
    cout << "ID pelanggan: "; cin >> newPelanggan->id;
    cin.ignore();
    newPelanggan -> next = nullptr;

    if (isEmpty()){
        front = rear = newPelanggan;
    } else {
        rear->next = newPelanggan;
        rear = newPelanggan;
    }
    cout << newPelanggan->nama << " Masuk ke Queue" << endl;
}

void dequeue(){
    if(isEmpty()){
        cout << "[KOSONG] Tidak Ada Antrean!\n";
        return;
    }

    pelanggan *temp = front;
    cout << front->nama << " Keluar dari antrian" << endl;
    front = front->next;
    delete temp;
}

void daftarAntrean(){
    if(isEmpty()){
        cout << "Antrean Kosong.\n";
        return;
    }
    cout << "=== DAFTAR PELANGGAN DALAM ANTREAN ===\n";
    pelanggan *temp = front;
    while (temp != nullptr){
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}

void resetAntrian(){
    if (isEmpty()){
        cout << "Antrean Kosong\n";
        return;
    }
    
    while(!isEmpty()) dequeue();
    cout << "Antrean telah di-reset.\n";
}

int hitungAntrean(){
    int jumlah = 0;
    pelanggan *temp = front;
    while (temp!= nullptr){
        jumlah++;
        temp = temp->next;
    }
    cout << "Jumlah antrian sekarang ada " << jumlah << " orang" << endl;
    return jumlah;
}