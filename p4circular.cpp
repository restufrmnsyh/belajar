#include <iostream>
using namespace std;

// Deklarasi Strukur Node
struct Node {
    int info;
    Node* next;
};

// Deklarasi Pointer Global: Tail
Node* tail = NULL;

// Deklarasi Fungsi
bool isListEmpty();
void insertNode(int newInfo);
void deleteNode(int infoDelete);
void printList();

int main() {
    
    int choice, info;
    do {
        cout << "\n=== LINKED LIST MELINGKAR ===" << endl;
        cout << "1. Sisip Node" << endl;
        cout << "2. Hapus Node" << endl;
        cout << "3. Cetak List" << endl;
        cout << "4. Keluar" << endl;
        cout << ">> ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            cout << "-> Masukkan info baru: ";
            cin >> info;
            insertNode(info);
            break;
        case 2:
            cout<< "-> Masukkan info hapus: ";
            cin >> info;
            deleteNode(info);
            break;
        case 3:
            printList();
            break;
        case 4:
            cout << "[ Keluar Program ]" << endl;
            break;
        default:
            cout << "[ Pilihan Tidak Valid ]" << endl;
        }
    } while (choice != 4);

    return 0;
}

// Fungsi untuk mengecek apakah list kosong
bool isListEmpty() {
    return tail == NULL;
}

// Fungsi untuk menyisipkan node baru
void insertNode(int newInfo) {
    // Membuat node baru yang akan disisipkan
    Node* newNode = new Node();
    newNode->info = newInfo;

    // Kondisi jika list masih kosong
    if (isListEmpty()) {
        tail = newNode;
        tail->next = tail;
    } else if (newInfo < tail->next->info) { // Kondisi jika newNode lebih kecil dari kepala
        newNode->next = tail->next;
        tail->next = newNode;
    } else if (newInfo > tail->info) { // Kondisi jika newNode lebih besar dari ekor
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    } else { // Kondisi jika sisip di tengah-tengah
        Node* helper = tail->next;

        // Perulangan untuk mencari posisi yang tepat
        while (helper->next != tail->next && newInfo > helper->next->info) {
            helper = helper->next;
        }

        // Sambungkan node baru di antara 'helper' dan 'helper->next'
        newNode->next = helper->next;
        helper->next = newNode;
    }
    cout << "[ Berhasil: Node " << newInfo << " Berhasil Ditambahkan ]" << endl;
}

// Fungsi untuk menghapus node
void deleteNode(int infoDelete) {
    if (isListEmpty()) {
        cout << "[ Gagal: List Masih Kosong ]" << endl;
        return;
    }

    // Membuat pointer bantuan untuk mencari node dan menghapus node
    Node* head = tail->next;
    Node* nodeDelete;

    // Cari node yang akan dihapus dan node sebelumnya
    Node* previous = tail;
    Node* current = head;
    
    do {
        if (current->info == infoDelete) {
            break; //keluar dari loop jika node ditemukan
        }
        previous = current;
        current = current->next;
    } while (current != head);

    // Jika setelah satu putaran infoDelete tidak ditemukan
    if (current->info != infoDelete) {
        cout << "[ Gagal: Node " << infoDelete << " Tidak Ditemukan ]" << endl;
        return;
    }

    nodeDelete = current;
    // Jika hanya ada satu node dalam list
    if (nodeDelete->next == nodeDelete) {
        tail = NULL;
    } else {
        // Sambungkan node sebelumnya dengan node selanjutnya
        previous->next = nodeDelete->next;
        
        if (nodeDelete == tail) {
            tail = previous;
        }
    }
    
    delete nodeDelete;
    cout << "[ Berhasil: Node " << infoDelete << " Berhasil Dihapus ]" << endl;
}

void printList() {
    cout << "Isi Linked List:" << endl;
    if (isListEmpty()) {
        cout << "[ List Kosong ]" << endl;
    } else {
        Node* head = tail->next;
        Node* current = head;
        cout << "HEAD -> ";
        do {
            cout << current->info << " -> ";
            current = current->next;
        } while (current != head); // Berhenti ketika kembali ke head
        cout << "(kembali ke HEAD: " << head->info << ")" << endl;
    }
}