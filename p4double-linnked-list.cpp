#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    int info;
    Node* next; // Pointer untuk ke node berikutnya
    Node* prev; // Pointer untuk ke node sebelumnya
};

// Deklarasi Pointer Global: head dan tail
Node* head = NULL;
Node* tail = NULL;

// Deklarasi Fungsi
bool isListEmpty();
void insertNode(int newInfo);
void deleteNode(int infoDelete);
void printListForward();
void printListBackward();

int main() {

    int choice, info;
    do {
        cout << "\n=== LINKED LIST GANDA ===" << endl;
        cout << "1. Sisip Node" << endl;
        cout << "2. Hapus Node" << endl;
        cout << "3. Cetak List Maju" << endl;
        cout << "4. Cetak List Mundur" << endl;
        cout << "5. Keluar" << endl;
        cout << ">> ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            cout << "-> Masukkan info newNode: ";
            cin >> info;
            insertNode(info);
            break;
        case 2:
            cout<< "-> Masukkan info hapus: ";
            cin >> info;
            deleteNode(info);
            break;
        case 3:
            printListForward();
            break;
        case 4:
            printListBackward();
            break;
        case 5:
            cout << "[ Keluar Program ]" << endl;
            break;
        default:
            cout << "[ Pilihan Tidak Valid ]" << endl;
        }
    } while (choice != 5);

    return 0;
}

// Fungsi untuk mengecek apakah list kosong
bool isListEmpty() {
    return head == NULL;
}

// Fungsi untuk menyisipkan node newNode
void insertNode(int newInfo) {
    // Membuat node baru yang akan disisipkan
    Node* newNode = new Node();
    newNode->info = newInfo;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Kondisi jika list masih kosong.
    if (isListEmpty()) {
        head = newNode;
        tail = newNode;
    } else if (newInfo < head->info) { // Kondisi jika newNode lebih kecil dari kepala
        newNode->next = head; // sisip di depan
        head->prev = newNode;
        head = newNode;
    } else if (newInfo > tail->info) { // Kondisi jika newNode lebih besar dari ekor
        tail->next = newNode; // sisip di belakang
        newNode->prev = tail;
        tail = newNode;
    } else { // Kondisi jika sisip di tengah-tengah
        Node* bantu = head;
        // Cari posisi yang tepat.
        while (bantu->next != NULL && newInfo > bantu->next->info) {
            bantu = bantu->next;
        }
        // Sambungkan node newNode di antara 'bantu' dan 'bantu->next'.
        newNode->next = bantu->next;
        newNode->prev = bantu;
        if (bantu->next != NULL) {
            bantu->next->prev = newNode;
        }
        bantu->next = newNode;
    }
    cout << "[ Berhasil: Node " << newInfo << " Berhasil Ditambahkan ]" << endl;
}

// Fungsi untuk menghapus node
void deleteNode(int infoDelete) {
    if (isListEmpty()) {
        cout << "[ Gagal: List Masih Kosong ]" << endl;
        return;
    }

    // Mencari node yang akan dihapus
    Node* nodeDelete = head;
    while (nodeDelete != NULL && nodeDelete->info != infoDelete) {
        nodeDelete = nodeDelete->next;
    }

    if (nodeDelete == NULL) {
        cout << "[ Gagal: Node " << infoDelete << " Tidak Ditemukan ]" << endl;
        return;
    }

    // Jika hanya ada satu node dalam list
    if (nodeDelete == head && nodeDelete == tail) {
        head = NULL;
        tail = NULL;
    } else if (nodeDelete == head) { // Jika yang dihapus adalah head
        head = nodeDelete->next; //hapus depan
        head->prev = NULL;
    } else if (nodeDelete == tail) { // Jika yang dihapus adalah tail
        tail = nodeDelete->prev; //hapus belakang
        tail->next = NULL;
    } else { // Jika yang dihapus di tengah tenah.
        nodeDelete->prev->next = nodeDelete->next;
        nodeDelete->next->prev = nodeDelete->prev;
    }

    delete nodeDelete;
    cout << "[ Berhasil: Node " << infoDelete << " Berhasil Dihapus ]" << endl;
}

void printListForward() {
    cout << "Isi Linked List (Maju):" << endl;
    if (isListEmpty()) {
        cout << "[ List Kosong ]" << endl;
    } else {
        Node* current = head;
        cout << "HEAD -> ";
        while (current != NULL) {
            cout << current->info << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
}

void printListBackward() {
    cout << "Isi Linked List (Mundur):" << endl;
    if (isListEmpty()) {
        cout << "[ List Kosong ]" << endl;
    } else {
        Node* current = tail;
        cout << "TAIL -> ";
        while (current != NULL) {
            cout << current->info << " -> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }
}