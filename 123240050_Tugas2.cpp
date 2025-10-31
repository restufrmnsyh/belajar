#include<iostream>
using namespace std;

//NIM 123240050 -> Genap -> Circular Linked List

struct Lagu {
    int id;
    string judul;
    string penyanyi;
    Lagu* next;
};

//Deklarasi pointer Global
Lagu* tail = NULL; //menunjuk node terakhir
Lagu* current = NULL; // menunjuk lagu yang diputar saat ini

//Deklarasi Fungsi
bool isListEmpty();
void tambahLagu(int id, string judul, string penyanyi);
void hapusLagu(int id);
void putarSelanjutnya();
void tampilkanPlaylist();
void tampilkanSekarang();

int main (){
    int pilih, id;
    string judul, penyanyi;
    do {
        cout << "===== PLAYLIST LAGU =====\n";
        tampilkanSekarang();
        cout << "=========================\n";
        cout << "| 1. Tambah Lagu        |\n";
        cout << "| 2. Hapus Lagu         |\n";
        cout << "| 3. Putar Selanjutnya  |\n";
        cout << "| 4. Tampilkan Playlist |\n";
        cout << "| 5. Keluar             |\n";
        cout << "=========================\n";
        cout << "Pilihan : "; cin >> pilih;
        switch (pilih) {
            case 1:
                cout << "ID Lagu : "; cin >> id;
                cin.ignore();
                cout << "Judul Lagu : "; getline(cin, judul);
                cout << "Nama Penyanyi : "; getline(cin, penyanyi);
                tambahLagu(id, judul, penyanyi);
                break;
            case 2:
                hapusLagu(id); 
                break;
            case 3:
                putarSelanjutnya();
                break;
            case 4:
                tampilkanPlaylist(); 
                break;
            case 5:
                cout << "Terima Kasih" << endl;
                exit(0); 
                break;            
            default:
                cout << "Pilihan tidak tersedia, silakan coba lagi:)\n";
                break;
        }
    } while (pilih!=5);
}

// Fungsi untuk mengecek apakah list kosong
bool isListEmpty() {
    return tail == NULL;
}

// Fungsi Tambah Lagu
void tambahLagu(int id, string judul, string penyanyi){
    //Cek Apakah ID sudah ada
    if(!isListEmpty()){
        Lagu* temp = tail->next;
        do {
            if (temp->id == id){
                cout << "[ Gagal: ID lagu sudah ada dalam playlist! ]\n";
                return;
            }
            temp = temp->next;
        } while (temp != tail->next);
    }

    // Membuat node baru yang akan disisipkan
    Lagu* newLagu = new Lagu();
    newLagu -> id = id;
    newLagu -> judul = judul;
    newLagu -> penyanyi = penyanyi;

    //Kondisi jika list masih kosong
    if (isListEmpty()){
        tail = newLagu;
        tail->next = tail;
        current = newLagu; // Lagu pertama langsung diputar
    } else if (id < tail->next->id){ 
        //sisip depan
        newLagu -> next = tail->next;
        tail->next = newLagu;
    } else if (id > tail->id){ 
        //sisip belakang
        newLagu->next = tail->next;
        tail->next = newLagu;
        tail = newLagu;
    } else { //Kondisi jika sisip di tengah-tengah
        Lagu* helper = tail->next;

        //Perulangan untuk mencari posisi yang tepat
        while (helper ->next != tail->next && id > helper->next->id){
           helper = helper->next;
        }

        //sambungkan node baru diantara 'helper' dan 'helper->next'
        newLagu->next = helper->next;
        helper->next = newLagu;
    }   
    cout << "[ Berhasil: Lagu '" << judul << "' Berhasil Ditambahkan ]" << endl;
}

//Fungsi untuk menghapus lagu
void hapusLagu(int id){
    if (isListEmpty()){
        cout << "[ Gagal: List Masih Kosong! ]" << endl;
        return;
    }
    cout << "ID lagu yang akan dihapus: "; cin >> id;
    
    //Pointer bantuan untuk cari lagu dan hapus lagu
    Lagu* head = tail->next;
    Lagu *LaguDelete;

    //Cari id Lagu yang akan dihapus dan id sebelumnya
    Lagu* prev = tail;
    Lagu* sekarang = head;
    
    do {
        if(sekarang->id == id){
            break; //keluar dari loop jika ditemukan
        }
        prev = sekarang;
        sekarang = sekarang->next;
    } while (sekarang != head);

    // Jika setelah satu putaran laguDelete tidak ditemukan
    if(sekarang->id != id){
        cout << "[ Gagal: Lagu dengan ID " << id << " Tidak Ditemukan ]" << endl;
        return;
    }

    LaguDelete = sekarang;
    //Jika hanya ada satu id dalam list
    if(LaguDelete -> next == LaguDelete){
        tail = NULL;
        current = NULL; //reset lagu yang sedang diputar
    } else {
        //sambungkan id sebelumnya dengan id selanjutnya
        prev->next = LaguDelete->next;
        if(LaguDelete == tail){
            tail = prev;
        }
        //kalau lagu yang sedang diputar dihapus, pindah ke lagu selanjutnya
        if(current == sekarang){
            current = sekarang->next; 
            cout << "[ Memutar Lagu Selanjutnya ]\n";
        }
    } 
    delete LaguDelete;
    cout << "[ Berhasil: Lagu dengan ID " << id << " Berhasil Dihapus ]" << endl;
}

//Fungsi untuk putar lagu selanjutnya
void putarSelanjutnya(){
    if(isListEmpty()){
        cout << "[ Playlist Kosong! ]\n";
        return;
    }

    if(current == NULL){
        current = tail->next; //Kalau belum ada, mulai dari head
    } else {
        current = current->next;
    }
    cout << "[ Memutar Lagu Selanjutnya ]\n";
}

void tampilkanSekarang(){
    cout << "Memutar: ";
    if(current == NULL){
        cout << "(Tidak Ada)\n";
    } else {
        cout << current->judul << endl;
    }
}

//Fungsi untuk menampilkan playlist
void tampilkanPlaylist(){
    cout << "Isi Playlist: " << endl; 
    if(isListEmpty()){
        cout << "[ List Kosong ]" << endl;
    } else {
        Lagu* head = tail->next;
        Lagu* current = head;
        do{
            cout << "ID: " << current->id << ", Judul: " << current ->judul << ", Penyanyi: " << current -> penyanyi << endl; 
            current = current ->next;
        } while(current!=head); //Berhenti ketika kembali ke head
    }
}