#include<iostream>
using namespace std;

// Sebuah perusahaan membutuhkan aplikasi pemutar lagu yang memiliki fitur mengelola playlist lagu. Dalam playlist terdapat judul lagu dan durasi lagu.
// Aplikasi pemutar lagu ini dapat:
// Menambahkan lagu di awal dan diakhir playlist
// Menampilkan seluruh playlist
// Menghapus lagu berdasarkan judul lagu

struct Node{
    string judul;
    int durasi;
    Node *kanan;
    Node *kiri;
};

struct Node *buatNode(string judul, int durasi) {
    Node *newNode = new Node;
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->kanan = nullptr;
    newNode->kiri = nullptr;
    return newNode;
};

void tambahLaguBelakang(Node *&head, string judul, int durasi);
void tambahLaguDepan(Node *&head, string judul, int durasi);
void tampilkanPlaylist(Node *head);
void hapusLagu(Node *&head, string key);

int main(){
    Node *head = nullptr;
    tambahLaguBelakang(head, "everything u are", 4);
    tambahLaguBelakang(head, "Tarot", 3);
    tambahLaguDepan(head, "Kita ke sana", 6);
    tambahLaguBelakang(head, "Serana", 5);

    tampilkanPlaylist(head);
    cout << endl;
    hapusLagu(head, "Tarot");
    tampilkanPlaylist(head);
    return 0;
}

void tambahLaguBelakang(Node *&head, string judul, int durasi){
    Node *newNode = buatNode(judul, durasi);
    if (head == nullptr){
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->kanan != nullptr){
        temp = temp->kanan;
    }
    temp->kanan = newNode;
    newNode->kiri = temp;
    cout << "Lagu -" << judul << "- ditambahkan ke playlist.\n";
}

void tambahLaguDepan(Node *&head, string judul, int durasi){
     Node *newNode = buatNode(judul, durasi);
     newNode->kanan = head;
     if (head != nullptr){
          head->kiri = newNode;
     }
     head = newNode;
     cout << "Lagu -" << judul << "- ditambahkan di depan playlist.\n";
}


void tampilkanPlaylist(Node *head){
     if (head == nullptr){
         cout << "Playlist kosong.\n";
     return;
     }
     cout << "Daftar Lagu dalam Playlist:\n";
     Node *temp = head;
     while (temp){
         cout << "- " << temp->judul << " (" << temp->durasi << " menit)\n";
         temp = temp->kanan;
     }
}

void hapusLagu (Node *&head, string key){
    Node *temp = head;
     while (temp != nullptr && temp->judul != key){
         temp = temp->kanan;
     }
     if (temp == nullptr){
         cout << "Lagu -" << key << "- Tidak ditemukan";
         return;
    }
    if (head == temp){
        head = temp->kanan;
    }
     if (temp->kanan != nullptr){
        temp->kanan->kiri = temp->kiri;
    }
    if (temp->kiri != nullptr){
        temp->kiri->kanan = temp->kanan;
    }
    delete temp;
    cout << "Lagu -" << key << "- dihapus dari playlist.\n";
    
}