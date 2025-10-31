#include <iostream>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;

// Fungsi tambah data (urut berdasarkan NIM)
void tambahData(string nim, string nama) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nim = nim;
    baru->nama = nama;
    baru->next = NULL;

    // Jika list kosong atau NIM lebih kecil dari head
    if (head == NULL || nim < head->nim) {
        baru->next = head;
        head = baru;
    } else {
        Mahasiswa* temp = head;
        while (temp->next != NULL && temp->next->nim < nim) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
}

// Fungsi hapus data berdasarkan NIM
void hapusData(string nim) {
    if (head == NULL) {
        cout << "Data kosong!" << endl;
        return;
    }
    if (head->nim == nim) {
        Mahasiswa* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Data dengan NIM " << nim << " berhasil dihapus." << endl;
        return;
    }
    Mahasiswa* temp = head;
    while (temp->next != NULL && temp->next->nim != nim) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Data dengan NIM " << nim << " tidak ditemukan." << endl;
    } else {
        Mahasiswa* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
        cout << "Data dengan NIM " << nim << " berhasil dihapus." << endl;
    }
}

// Fungsi tampilkan semua data
void tampilData() {
    if (head == NULL) {
        cout << "Data kosong!" << endl;
        return;
    }
    Mahasiswa* temp = head;
    cout << "Daftar Mahasiswa:" << endl;
    while (temp != NULL) {
        cout << "NIM: " << temp->nim << ", Nama: " << temp->nama << endl;
        temp = temp->next;
    }
}

// Fungsi cari data berdasarkan NIM
void cariData(string nim) {
    Mahasiswa* temp = head;
    while (temp != NULL) {
        if (temp->nim == nim) {
            cout << "Data ditemukan -> NIM: " << temp->nim << ", Nama: " << temp->nama << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Data dengan NIM " << nim << " tidak ditemukan." << endl;
}

int main() {
    int pilihan;
    string nim, nama;

    do {
        cout << "\n=== MENU LINKED LIST MAHASISWA ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Cari Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                tambahData(nim, nama);
                break;
            case 2:
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> nim;
                hapusData(nim);
                break;
            case 3:
                tampilData();
                break;
            case 4:
                cout << "Masukkan NIM yang dicari: ";
                cin >> nim;
                cariData(nim);
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
