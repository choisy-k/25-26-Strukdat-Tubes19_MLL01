#include <iostream>
#include "MainApp.h"

using namespace std;

int main() {
    ListProduk LP;
    ListSupplier LS;

    createProdukList(LP);
    createSupplierList(LS);

    // Data sample untuk testing
    adrProduk pr;
    pr = allocateProduk("DURIAN", "Buah", 20000, 10);
    insertProdukLast(LP, pr);
    pr = allocateProduk("MANGGA", "Buah", 12000, 25);
    insertProdukLast(LP, pr);
    pr = allocateProduk("BAYAM", "Sayur", 11000, 10);
    insertProdukLast(LP, pr);

    adrSupplier sp;
    sp = allocateSupplier("ASH", "Bojongsoang");
    insertSupplierFirst(LS, sp);
    sp = allocateSupplier("BACH", "Dayeuhkolot");
    insertSupplierFirst(LS, sp);
    sp = allocateSupplier("CONNIE", "Baleendah");
    insertSupplierFirst(LS, sp);
    sp = allocateSupplier("DONNY", "Cimahi");
    insertSupplierFirst(LS, sp);

    adrSupplier as = searchSupplier(LS, "ASH");
    adrSupplier dn = searchSupplier(LS, "DONNY");
    adrSupplier cm = searchSupplier(LS, "CONNIE");
    adrProduk dr = searchProduk(LP, "DURIAN");
    adrProduk mg = searchProduk(LP, "MANGGA");
    adrProduk by = searchProduk(LP, "BAYAM");

    // Ash - Durian mangga bayam
    connectSuptoProd(as, dr);
    connectSuptoProd(as, mg);
    connectSuptoProd(as, by);

    // Donny - mangga, bayam
    connectSuptoProd(dn, mg);
    connectSuptoProd(dn, by);


    int pilihan;

    do {
        cout << "\n==================================================";
        cout << "\n======= SISTEM MANAJEMEN SUPPLIER & PRODUK =======\n";
        cout << "==================================================\n";
        cout << "1. Tambah Supplier\n";
        cout << "2. Tambah Produk\n";
        cout << "3. Cari Supplier\n";
        cout << "4. Tambah Produk ke Supplier\n";
        cout << "5. Daftar Supplier\n";
        cout << "6. Hapus Supplier\n";
        cout << "7. Hapus Produk dari Supplier\n";
        cout << "8. Tampilkan Supplier dengan Produk Terbanyak\n";
        cout << "0. Keluar\n";

        bool validInput = false;

        // mencegah menu muncul sampai user memasukkan input valid
        while(!validInput) {
            cout << "\nPilihan: ";
            cin >> pilihan;

            if(cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Pilihan harus berupa angka." << endl;
            }
            else {
                if(pilihan >= 0 && pilihan <= 8) {
                    validInput = true;
                }
                else {
                    cout << "[ERROR] Masukkan angka antara 0-8." << endl;
                }
            }
        }

        switch(pilihan) {
        case 1:
            tambahSupplier(LS);
            break;
        case 2:
            tambahProduk(LP, LS);
            break;
        case 3:
            cariSupplier(LS);
            break;
        case 4:
            hubungkanSupplierProduk(LS, LP);
            break;
        case 5:
            showAllData(LS);
            break;
        case 6:
            hapusSupplier(LS);
            break;
        case 7:
            hapusProdukDariSupplier(LS, LP);
            break;
        case 8:
            tampilkanSupplierTerbanyak(LS);
            break;
        case 0:
            cout << "\nTerima kasih atas waktu Anda.\nMenutup program...\n";
            break;
        default:
            cout << "[ERROR] Pilihan tidak valid.\n";
        }

        // mencegah menu muncul sampai user menekan Enter.
        cout << "\nTekan Enter untuk melanjutkan.";
        cin.ignore(10000, '\n');
        cin.get();

    } while(pilihan != 0);

    return 0;
}
