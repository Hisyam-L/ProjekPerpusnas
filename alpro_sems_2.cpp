#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    bool isBorrowed;
};

Book books[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        cout << "Masukkan judul buku: ";
        cin.ignore();
        getline(cin, books[bookCount].title);
        cout << "Masukkan penulis buku: ";
        getline(cin, books[bookCount].author);
        books[bookCount].isBorrowed = false;
        bookCount++;
        cout << "Buku berhasil ditambahkan!\n";
    } else {
        cout << "Kapasitas buku penuh!\n";
    }
}

void removeBook() {
    string title;
    cout << "Masukkan judul buku yang ingin dihapus: ";
    cin.ignore();
    getline(cin, title);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == title) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            cout << "Buku berhasil dihapus!\n";
            return;
        }
    }
    cout << "Buku tidak ditemukan!\n";
}

void listBooks() {
    cout << "Daftar Buku:\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "Judul: " << books[i].title << " | Penulis: " << books[i].author;
        if (books[i].isBorrowed) {
            cout << " (Dipinjam)";
        }
        cout << endl;
    }
}

void borrowBook() {
    string title;
    cout << "Masukkan judul buku yang ingin dipinjam: ";
    cin.ignore();
    getline(cin, title);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == title && !books[i].isBorrowed) {
            books[i].isBorrowed = true;
            cout << "Buku berhasil dipinjam!\n";
            return;
        }
    }
    cout << "Buku tidak tersedia atau sedang dipinjam!\n";
}

void returnBook() {
    string title;
    cout << "Masukkan judul buku yang ingin dikembalikan: ";
    cin.ignore();
    getline(cin, title);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == title && books[i].isBorrowed) {
            books[i].isBorrowed = false;
            cout << "Buku berhasil dikembalikan!\n";
            return;
        }
    }
    cout << "Buku tidak ditemukan atau belum dipinjam!\n";
}

void adminMenu() {
    int choice;
    do {
        cout << "\nMenu Admin:\n1. Tambah Buku\n2. Hapus Buku\n3. Lihat Buku\n4. Keluar\nPilihan: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: removeBook(); break;
            case 3: listBooks(); break;
            case 4: return;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}

void userMenu() {
    int choice;
    do {
        cout << "\nMenu User:\n1. Lihat Buku\n2. Pinjam Buku\n3. Kembalikan Buku\n4. Keluar\nPilihan: ";
        cin >> choice;
        switch (choice) {
            case 1: listBooks(); break;
            case 2: borrowBook(); break;
            case 3: returnBook(); break;
            case 4: return;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}

int main() {
    int role;
    do {
        cout << "\nSistem Perpustakaan\n1. Admin\n2. User\n3. Keluar\nPilih peran: ";
        cin >> role;
        switch (role) {
            case 1: adminMenu(); break;
            case 2: userMenu(); break;
            case 3: cout << "Keluar dari sistem.\n"; return 0;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}
