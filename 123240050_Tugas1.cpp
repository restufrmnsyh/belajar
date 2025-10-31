#include <iostream>
using namespace std;

// Struct Pengguna
struct Pengguna {
    string username;
    string email;
    string password;
};

// Fungsi untuk update username
void updateUsername(Pengguna *p, string newUsername) {
    p->username = newUsername;
}

int main() {
    // 1. Buat variabel dari struct Pengguna
    Pengguna user;

    // 2. Isi data awal dengan input dari user
    cout << "Masukkan username awal : "; cin>> user.username;
    cout << "Masukkan email         : "; cin >> user.email;
    cout << "Masukkan password      : "; cin >> user.password;

    // 3. Cetak informasi awal
    cout << "\n=== Data Awal Pengguna ===\n";
    cout << "Username : " << user.username << endl;
    cout << "Email    : " << user.email << endl;
    cout << "Password : " << user.password << endl;

    // 4. Update username
    string newUsername;
    cout << "\nMasukkan username baru : ";
    cin >> newUsername;
    updateUsername(&user, newUsername);

    // 5. Cetak informasi setelah update
    cout << "\n=== Data Pengguna Setelah Update ===\n";
    cout << "Username : " << user.username << endl;
    cout << "Email    : " << user.email << endl;
    cout << "Password : " << user.password << endl;
    return 0;
}
