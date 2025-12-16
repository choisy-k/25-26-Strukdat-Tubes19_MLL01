#include <iostream>
#include <limits>
#include "MainApp.h"

using namespace std;

void displayMenu() {
    cout << "\n==================================================";
    cout << "\n======= SISTEM MANAJEMEN SUPPLIER & PRODUK =======\n";
    cout << "==================================================\n";
    cout << "1. Tambah Supplier\n";
    cout << "2. Tambah Produk\n";
    cout << "3. Cari Supplier\n";
    cout << "4. Cari Produk\n";
    cout << "5. Tambah Produk ke Supplier\n";
    cout << "6. Tampilkan List Supplier\n";
    cout << "7. Tampilkan List Produk\n";
    cout << "8. Tampilkan Data (Supplier + Produk)\n";
    cout << "9. Hapus Supplier\n";
    cout << "10. Hapus Produk dari Supplier\n";
    cout << "11. Tampilkan Supplier dengan Produk Terbanyak\n";
    cout << "0. Keluar\n";
    cout << "Pilihan: ";
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
        pilihan = filterInput();
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
            case 0:
                cout << "\nTerima kasih telah menggunakan program kami!\n";
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
        }

        cout << "\nTekan Enter untuk melanjutkan...";
        clearInputBuffer();

    } while(pilihan != 0);

    return 0;
}
