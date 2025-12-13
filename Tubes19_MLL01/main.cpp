#include <iostream>
#include "MainApp.h"

using namespace std;

int main()
{
    ListProduk LP;
    ListSupplier LS;
    adrSupplier sp;
    adrProduk pr;
    string nama;

    createProdukList(LP);
    createSupplierList(LS);

    pr = allocateProduk("Durian", "Buah", 20000, 10);
    insertProdukLast(LP, pr);

    pr = allocateProduk("Mangga", "Buah", 12000, 25);
    insertProdukLast(LP, pr);

    pr = allocateProduk("Bayam", "Sayur", 11000, 10);
    insertProdukLast(LP, pr);

    printInfotes(LP);
//
//    cout << "Cari produk: ";
//    cin >> nama;
//    pr = searchProduk(LP, nama);
//    cout << "Ketemu di kategori " << pr->infoP.kategori << endl;

    sp = allocateSupplier("Ash", "Bojongsoang");
    insertSupplierFirst(LS, sp);

    sp = allocateSupplier("Bach", "Dayeuhkolot");
    insertSupplierFirst(LS, sp);

    sp = allocateSupplier("Comel", "Baleendah");
    insertSupplierFirst(LS, sp);

    sp = allocateSupplier("Donny", "AAAHHHH");
    insertSupplierFirst(LS, sp);

    printInfotess(LS);

//    cout << "Cari supplier: ";
//    cin >> nama;
//    sp = searchSupplier(LS, nama);
//    cout << "Ada di " << sp->infoS.lokasi << endl;

    adrSupplier as = searchSupplier(LS, "Ash");
    adrSupplier dn = searchSupplier(LS, "Donny");
    adrSupplier cm = searchSupplier(LS, "Comel");
    adrProduk dr = searchProduk(LP, "Durian");
    adrProduk mg = searchProduk(LP, "Mangga");
    adrProduk by = searchProduk(LP, "Bayam");

    // Ash - Durian mangga bayam
    connectSuptoProd(as, dr);
    connectSuptoProd(as, mg);
    connectSuptoProd(as, by);

    // Donny - mangga, bayam
    connectSuptoProd(dn, mg);
    connectSuptoProd(dn, by);

//    cout << "Hapus supplier: ";
//    cin >> nama;
//    sp = searchSupplier(LS, nama);
//    deleteSupplier(LS, sp);

//    printInfotess(LS);
    showAllData(LS);

    cout << "Hapus supplier: ";
    cin >> nama;
    sp = searchSupplier(LS, nama);
    deleteSupplier(LS, sp);

    showAllData(LS);

    //tes hapus Bayam dari Comel (expected output: Supplier tidak menyediakan produk ini)
    deleteProdukfromSupplier(cm, by);

    //tes hapus Mangga dari Donny (expected: Mangga terhapus, sisa Bayam)
    deleteProdukfromSupplier(dn, mg);

    showAllData(LS);

    return 0;
}
