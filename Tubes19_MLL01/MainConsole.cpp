#include <iostream>
#include <limits>
#include "MainApp.h"

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int filterInput() {
    int input;

    while(true) {
        cin >> input;
        if(cin.fail()){
            clearInputBuffer();
            cout << "Pilihan harus berupa angka.\nMasukkan angka pilihan: ";
        }
        else {
            return input;
        }
    }
}

void tambahSupplier(ListSupplier &LS) {
    string nama, lokasi;
    cout << "\n--- Tambah Supplier ---\n";
    cout << "Nama Supplier: ";
    getline(cin, nama);

    adrSupplier sup = searchSupplier(LS, nama);
    if(sup != nullptr) {
        cout << "Supplier sudah berada di list.\n";
    }
    else {
        cout << "Lokasi: ";
        getline(cin, lokasi);

        adrSupplier sp = allocateSupplier(nama, lokasi);
        insertSupplierFirst(LS, sp);
        cout << "Supplier berhasil ditambahkan!\n";
    }
}

void tambahProduk(ListProduk &LP) {
    string nama, kategori;
    int harga, moq;

    cout << "\n--- Tambah Produk ---\n";
    cout << "Nama Produk: ";
    getline(cin, nama);

    adrProduk prod = searchProduk(LP, nama);
    if(prod != nullptr) {
        cout << "Produk sudah berada di list.\n";
    }
    else {
        cout << "Kategori: ";
        getline(cin, kategori);
        cout << "Harga: ";
        cin >> harga;
        cout << "Minimum Order Quantity (MOQ): ";
        cin >> moq;
        clearInputBuffer();

        adrProduk pr = allocateProduk(nama, kategori, harga, moq);
        insertProdukLast(LP, pr);
        cout << "Produk berhasil ditambahkan!\n";
    }
}

void cariSupplier(ListSupplier &LS) {
    string nama;
    cout << "\n--- Cari Supplier ---\n";
    cout << "Nama Supplier: ";
    getline(cin, nama);

    adrSupplier sp = searchSupplier(LS, nama);
    if(sp != nullptr) {
        cout << "\nSupplier ditemukan!\n";
        cout << "Nama: " << sp->infoS.namaSupplier << endl;
        cout << "Lokasi: " << sp->infoS.lokasi << endl;

        int jumlah = countProductsBySupplier(sp);
        cout << "Jumlah produk yang disediakan: " << jumlah << endl;
    } else {
        cout << "Supplier '" << nama << "' tidak ditemukan.\n";
    }
}

void cariProduk(ListProduk &LP) {
    string nama;
    cout << "\n--- Cari Produk ---\n";
    cout << "Nama Produk: ";
    getline(cin, nama);

    adrProduk pr = searchProduk(LP, nama);
    if(pr != nullptr) {
        cout << "\nProduk ditemukan!\n";
        cout << "Nama: " << pr->infoP.namaProduk << endl;
        cout << "Kategori: " << pr->infoP.kategori << endl;
        cout << "Harga: Rp" << pr->infoP.harga << endl;
        cout << "MOQ: " << pr->infoP.moQ << endl;
    } else {
        cout << "Produk '" << nama << "' tidak ditemukan.\n";
    }
}

void hubungkanSupplierProduk(ListSupplier &LS, ListProduk &LP) {
    string namaSupplier, namaProduk;

    cout << "\n--- Tambahkan Produk ke Supplier ---\n";
    cout << "Nama Supplier: ";
    getline(cin, namaSupplier);
    cout << "Nama Produk: ";
    getline(cin, namaProduk);

    adrSupplier sp = searchSupplier(LS, namaSupplier);
    adrProduk pr = searchProduk(LP, namaProduk);

    if(sp == nullptr) {
        cout << "Supplier '" << namaSupplier << "' tidak ditemukan!\n";
        return;
    }
    if(pr == nullptr) {
        cout << "Produk '" << namaProduk << "' tidak ditemukan!\n";
        return;
    }

    connectSuptoProd(sp, pr);
}

void hapusSupplier(ListSupplier &LS) {
    string nama;
    cout << "\n--- Hapus Supplier ---\n";
    cout << "Nama Supplier yang akan dihapus: ";
    getline(cin, nama);

    adrSupplier sp = searchSupplier(LS, nama);
    if(sp != nullptr) {
        deleteSupplier(LS, sp);
    } else {
        cout << "Supplier '" << nama << "' tidak ditemukan!\n";
    }
}

void hapusProdukDariSupplier(ListSupplier &LS, ListProduk &LP) {
    string namaSupplier, namaProduk;

    cout << "\n--- Hapus Produk dari Supplier ---\n";
    cout << "Nama Supplier: ";
    getline(cin, namaSupplier);
    cout << "Nama Produk yang akan dihapus: ";
    getline(cin, namaProduk);

    adrSupplier sp = searchSupplier(LS, namaSupplier);
    adrProduk pr = searchProduk(LP, namaProduk);

    if(sp == nullptr) {
        cout << "Supplier '" << namaSupplier << "' tidak ditemukan!\n";
        return;
    }
    if(pr == nullptr) {
        cout << "Produk '" << namaProduk << "' tidak ditemukan!\n";
        return;
    }

    deleteProdukfromSupplier(sp, pr);
}

void tampilkanSupplierTerbanyak(ListSupplier &LS) {
    cout << "\n--- Supplier dengan Produk Terbanyak ---\n";
    adrSupplier top = findTopSupplier(LS);

    if(top == nullptr) {
        cout << "Tidak ada supplier.\n";
        return;
    }

    int jumlah = countProductsBySupplier(top);
    cout << "Supplier: " << top->infoS.namaSupplier << endl;
    cout << "Lokasi: " << top->infoS.lokasi << endl;
    cout << "Jumlah produk: " << jumlah << endl;

    adrRelasi r = top->firstRelasi;
    if(r == nullptr) {
        cout << "Produk: (Tidak ada produk)\n";
    } else {
        cout << "Daftar produk:\n";
        int counter = 1;
        while(r != nullptr) {
            cout << counter << ". " << r->toProduk->infoP.namaProduk << endl;
            counter++;
            r = r->next;
        }
    }
}
