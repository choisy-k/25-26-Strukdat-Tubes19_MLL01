#include <iostream>
#include <limits>
#include "MainApp.h"

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMenu() {
    cout << "\n=== SISTEM MANAJEMEN SUPPLIER & PRODUK ===\n";
    cout << "1. Tambah Supplier\n";
    cout << "2. Tambah Produk\n";
    cout << "3. Cari Supplier\n";
    cout << "4. Cari Produk\n";
    cout << "5. Hubungkan Supplier dengan Produk\n";
    cout << "6. Tampilkan Semua Supplier\n";
    cout << "7. Tampilkan Semua Produk\n";
    cout << "8. Tampilkan Semua Data (Supplier + Produk)\n";
    cout << "9. Hapus Supplier\n";
    cout << "10. Hapus Produk dari Supplier\n";
    cout << "11. Tampilkan Supplier dengan Produk Terbanyak\n";
    cout << "12. Hitung Jumlah Produk per Supplier\n";
    cout << "0. Keluar\n";
    cout << "Pilihan: ";
}

void tambahSupplier(ListSupplier &LS) {
    string nama, lokasi;
    cout << "\n--- Tambah Supplier ---\n";
    cout << "Nama Supplier: ";
    getline(cin, nama);
    cout << "Lokasi: ";
    getline(cin, lokasi);

    adrSupplier sp = allocateSupplier(nama, lokasi);
    insertSupplierFirst(LS, sp);
    cout << "Supplier berhasil ditambahkan!\n";
}

void tambahProduk(ListProduk &LP) {
    string nama, kategori;
    int harga, moq;

    cout << "\n--- Tambah Produk ---\n";
    cout << "Nama Produk: ";
    getline(cin, nama);
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

    cout << "\n--- Hubungkan Supplier dengan Produk ---\n";
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

void hitungProdukPerSupplier(ListSupplier &LS) {
    cout << "\n--- Jumlah Produk per Supplier ---\n";

    if(isEmptySupplier(LS)) {
        cout << "Tidak ada supplier.\n";
        return;
    }

    adrSupplier s = LS.first;
    while(s != nullptr) {
        int jumlah = countProductsBySupplier(s);
        cout << "- " << s->infoS.namaSupplier << ": " << jumlah << " produk\n";
        s = s->next;
    }
}

int main() {
    ListProduk LP;
    ListSupplier LS;

    createProdukList(LP);
    createSupplierList(LS);

    // Data sample untuk testing
    adrProduk pr;
    pr = allocateProduk("Durian", "Buah", 20000, 10);
    insertProdukLast(LP, pr);
    pr = allocateProduk("Mangga", "Buah", 12000, 25);
    insertProdukLast(LP, pr);
    pr = allocateProduk("Bayam", "Sayur", 11000, 10);
    insertProdukLast(LP, pr);

    adrSupplier sp;
    sp = allocateSupplier("Ash", "Bojongsoang");
    insertSupplierFirst(LS, sp);
    sp = allocateSupplier("Bach", "Dayeuhkolot");
    insertSupplierFirst(LS, sp);

    int pilihan;
    do {
        displayMenu();
        cin >> pilihan;
        clearInputBuffer();

        switch(pilihan) {
            case 1:
                tambahSupplier(LS);
                break;
            case 2:
                tambahProduk(LP);
                break;
            case 3:
                cariSupplier(LS);
                break;
            case 4:
                cariProduk(LP);
                break;
            case 5:
                hubungkanSupplierProduk(LS, LP);
                break;
            case 6:
                cout << "\n--- Daftar Supplier ---\n";
                printSupplierInfo(LS);
                break;
            case 7:
                cout << "\n--- Daftar Produk ---\n";
                printProdukInfo(LP);
                break;
            case 8:
                showAllData(LS);
                break;
            case 9:
                hapusSupplier(LS);
                break;
            case 10:
                hapusProdukDariSupplier(LS, LP);
                break;
            case 11:
                tampilkanSupplierTerbanyak(LS);
                break;
            case 12:
                hitungProdukPerSupplier(LS);
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan program!\n";
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
        }

        cout << "\nTekan Enter untuk melanjutkan...";
        clearInputBuffer();

    } while(pilihan != 0);

    return 0;
}
