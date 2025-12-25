#include <iostream>
#include <string>
#include "MainApp.h"

using namespace std;

string toUpper(string input) {
    for(int i = 0; i < input.length(); i++) {
        if(input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - ('a' - 'A');
        }
    }
    return input;
}

void tambahSupplier(ListSupplier &LS) {
    string nama, lokasi;
    cout << "\n--- Tambah Supplier ---\n";
    cout << "Nama Supplier: ";
    cin >> nama;
    nama = toUpper(nama);

    adrSupplier sup = searchSupplier(LS, nama);
    if(sup != nullptr) {
        cout << "[ERROR] Supplier sudah berada di list.\n";
    }
    else {
        cout << "Lokasi: ";
        cin >> lokasi;

        adrSupplier sp = allocateSupplier(nama, lokasi);
        insertSupplierFirst(LS, sp);
        cout << "[SUCCESS] Supplier berhasil ditambahkan!\n";
    }
}

void tambahProduk(ListProduk &LP, ListSupplier &LS) {
    string nama, kategori, namaSup;
    int harga, moq;

    cout << "\n--- Tambah Produk ---\n";
    cout << "Nama Produk: ";
    cin >> nama;
    nama = toUpper(nama);

    adrProduk prod = searchProduk(LP, nama);
    if(prod != nullptr) {
        cout << "[ERROR] Produk sudah berada di list.\n";
    }
    else {
        cout << "Kategori: ";
        cin >> kategori;
        cout << "Harga: ";
        cin >> harga;
        cout << "Minimum Order Quantity (MOQ): ";
        cin >> moq;

        adrProduk pr = allocateProduk(nama, kategori, harga, moq);
        insertProdukLast(LP, pr);
        cout << "[SUCCESS] Produk berhasil ditambahkan!\n\n";

        cout << "Daftarkan produk ke supplier: ";
        cin >> namaSup;
        namaSup = toUpper(namaSup);
        adrSupplier sp = searchSupplier(LS, namaSup);
        if(sp != nullptr) {
            connectSuptoProd(sp, pr);
            cout << "\n[SUCCESS] Produk telah didaftarkan ke supplier!\n";
        } else {
            cout << "[ERROR] Supplier '" << namaSup << "' tidak ditemukan.\n";
        }
    }
}

void cariSupplier(ListSupplier &LS) {
    string nama;
    int jumlah;
    cout << "\n--- Cari Supplier ---\n";
    cout << "Nama Supplier: ";
    cin >> nama;
    nama = toUpper(nama);

    adrSupplier sp = searchSupplier(LS, nama);
    if(sp != nullptr) {
        cout << "\n[SUCCESS] Supplier ditemukan!\n";
        cout << "Nama: " << sp->infoS.namaSupplier << endl;
        cout << "Lokasi: " << sp->infoS.lokasi << endl;

        jumlah = countProductsBySupplier(sp);
        cout << "Jumlah produk yang disediakan: " << jumlah << endl;
    } else {
        cout << "[ERROR] Supplier '" << nama << "' tidak ditemukan.\n";
    }
}

void hubungkanSupplierProduk(ListSupplier &LS, ListProduk &LP) {
    string namaSupplier, namaProduk;

    cout << "\n--- Tambahkan Produk ke Supplier ---\n";
    cout << "Nama Produk: ";
    cin >> namaProduk;
    namaProduk = toUpper(namaProduk);
    adrProduk pr = searchProduk(LP, namaProduk);

    if(pr == nullptr) {
        cout << "[ERROR] Produk '" << namaProduk << "' tidak ditemukan.\n";
    }
    else {
        cout << "Nama Supplier: ";
        cin >> namaSupplier;
        namaSupplier = toUpper(namaSupplier);
        adrSupplier sp = searchSupplier(LS, namaSupplier);

        if(sp == nullptr) {
            cout << "[ERROR] Supplier '" << namaSupplier << "' tidak ditemukan\n";
        }
        else {
            connectSuptoProd(sp, pr);
        }
    }
}

void hapusSupplier(ListSupplier &LS) {
    string nama;
    cout << "\n--- Hapus Supplier ---\n";
    cout << "Nama Supplier yang akan dihapus: ";
    cin >> nama;
    nama = toUpper(nama);

    adrSupplier sp = searchSupplier(LS, nama);
    if(sp != nullptr) {
        deleteSupplier(LS, sp);
    } else {
        cout << "[ERROR] Supplier '" << nama << "' tidak ditemukan.\n";
    }
}

void hapusProdukDariSupplier(ListSupplier &LS, ListProduk &LP) {
    string namaSupplier, namaProduk;

    cout << "\n--- Hapus Produk dari Supplier ---\n";
    cout << "Nama Supplier: ";
    cin >> namaSupplier;
    namaSupplier = toUpper(namaSupplier);
    adrSupplier sp = searchSupplier(LS, namaSupplier);

    if(sp == nullptr) {
        cout << "[ERROR] Supplier '" << namaSupplier << "' tidak ditemukan.\n";
    }
    else {
        cout << "Nama Produk yang akan dihapus: ";
        cin >> namaProduk;
        namaProduk = toUpper(namaProduk);
        adrProduk pr = searchProduk(LP, namaProduk);

        if(pr == nullptr) {
            cout << "[ERROR] Produk '" << namaProduk << "' tidak ditemukan.\n";
        }
        else {
            deleteProdukfromSupplier(sp, pr);
        }
    }
}

void tampilkanSupplierTerbanyak(ListSupplier &LS) {
    adrSupplier top = findTopSupplier(LS);
    int jumlah;

    if(top == nullptr) {
        cout << "[ERROR] Supplier sedang tidak menyediakan produk.\n";
    }
    else {
        jumlah = countProductsBySupplier(top);
        cout << "\nTop Supplier: " << top->infoS.namaSupplier << endl;
        cout << "Menyediakan " << jumlah << " produk.\n";
        cout << "Lokasi: " << top->infoS.lokasi << endl;
    }
}
