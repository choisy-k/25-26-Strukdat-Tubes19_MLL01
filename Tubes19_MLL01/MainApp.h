#ifndef MAINAPP_H_INCLUDED
#define MAINAPP_H_INCLUDED
#include <iostream>
#include "Supply_SLL.h"
#include "Relasi_SLL.h"
#include "Produk_DLL.h"

using namespace std;

// ----- SUBPROGRAM MAIN -----

/*I.S. Input user di cin bisa valid maupun invalid (bukan integer)
F.S. Input user dibersihkan dari memori (input buffer cleanup)*/
void clearInputBuffer();

/*I.S. Input user di cin bisa valid maupun invalid (bukan integer)
F.S. Mengembalikan input jika integer atau error message jika input bukan integer*/
int filterInput();

/*I.S. Terdefinisi list supplier LS
F.S. Data supplier dimasukkan ke prosedur insertSupplier() jika belum ada di list*/
void tambahSupplier(ListSupplier &LS);

/*I.S. Terdefinisi list produk LP
F.S. Data produk dimasukkan ke prosedur insertProdukLast() jika belum ada di list*/
void tambahProduk(ListProduk &LP);

/*I.S. Terdefinisi list supplier LS
F.S. Memanggil dan menampilkan hasil dari fungsi searchSupplier()*/
void cariSupplier(ListSupplier &LS);

/*I.S. Terdefinisi list produk LP
F.S. Memanggil dan menampilkan hasil dari fungsi searchProduk()*/
void cariProduk(ListProduk &LP);

/*I.S. Terdefinisi list supplier LS dan list produk LP
F.S. Satu elemen supplier terhubung ke satu elemen produk lewat relasi*/
void hubungkanSupplierProduk(ListSupplier &LS, ListProduk &LP);

/*I.S. Terdefinisi list supplier LS
F.S. Menunjukkan pesan konfirmasi apakah supplier sudah terhapus, atau tidak ditemukan*/
void hapusSupplier(ListSupplier &LS);

/*I.S. Terdefinisi list supplier LS dan list produk LP
F.S. Menunjukkan pesan konfirmasi apakah produk sudah dihapus dari supplier, atau produk tidak ditemukan*/
void hapusProdukDariSupplier(ListSupplier &LS, ListProduk &LP);

/*I.S. Terdefinisi list supplier LS
F.S. Menunjukkan data supplier dengan produk terbanyak, beserta nama produk-produknya*/
void tampilkanSupplierTerbanyak(ListSupplier &LS);



// ----- SUBPROGRAM SUPPLIER -----

/* I.S. -
   F.S. Terbentuk list Supplier L, dengan first dari L bernilai nil (nullptr).*/
void createSupplierList(ListSupplier &L);

/* I.S. Terdefinisi list Supplier L.
   F.S. Mengembalikan true jika L kosong, false apabila tidak.*/
bool isEmptySupplier(ListSupplier L);

/* I.S. Terdefinisi string nama dan lokasi.
   F.S. Mengembalikan elemen supplier baru dengan info nama dan lokasi dimasukkan, serta next dan firstRelasi bernilai nil.*/
adrSupplier allocateSupplier(string nama, string lokasi);

/* I.S. Terdefinisi list supplier L yang mungkin kosong dan elemen supplier p.
   F.S. Elemen p ditambahkan ke dalam list sebagai elemen pertama.*/
void insertSupplierFirst(ListSupplier &L, adrSupplier p);

/* I.S. Terdefinisi list supplier L dan elemen supplier p yang akan dihapus.
   F.S. Elemen p dihapus dari list L dan semua relasinya dihapus.*/
void deleteSupplier(ListSupplier &L, adrSupplier p);

/* I.S. Terdefinisi list supplier L dan string nama.
   F.S. Mengembalikan elemen supplier dengan nama yang ditentukan apabila ada, dan mengembalikan nil jika tidak ada.*/
adrSupplier searchSupplier(ListSupplier L, string nama);

/* I.S. Terdefinisi list supplier L.
   F.S. Mengembalikan supplier dengan jumlah produk terbanyak, atau nil jika list kosong.*/
adrSupplier findTopSupplier(ListSupplier L);

/* I.S. List supplier L terdefinisi
   F.S. Semua supplier dalam list L ditampilkan ke layar */
void printSupplierInfo(ListSupplier L);


// ----- SUBPROGRAM PRODUK -----

/* I.S. -
   F.F. Terbentuk list Produk L, dengan first dan prev dari L bernilai nil (nullptr).*/
void createProdukList(ListProduk &L);

/* I.S. Terdefinisi list Produk L.
   F.S. Mengembalikan true jika L kosong, false apabila tidak.*/
bool isEmptyProduk(ListProduk L);

/* I.S. Terdefinisi string nama dan kategori, integer harga dan MOQ.
   F.S. Mengembalikan elemen produk baru dengan info nama, kategori, harga dan MOQ dimasukkan, serta next dan prev bernilai nil.*/
adrProduk allocateProduk(string nama, string kat, int harga, int moq);

/* I.S. Terdefinisi list produk L yang mungkin kosong dan elemen produk p.
   F.S. Elemen p ditambahkan ke dalam list sebagai elemen terakhir.*/
void insertProdukLast(ListProduk &L, adrProduk p);

/* I.S. Terdefinisi list produk L dan string nama.
   F.S. Mengembalikan elemen produk dengan nama yang ditentukan apabila ada, dan mengembalikan nil jika tidak ada.*/
adrProduk searchProduk(ListProduk L, string nama);

/* I.S. List produk L terdefinisi
   F.S. Semua produk dalam list L ditampilkan ke layar */
void printProdukInfo(ListProduk L);


// ----- SUBPROGRAM RELASI AND OTHERS RELATED -----

/* I.S. Terdefinisi elemen supplier s dan produk p.
   F.S. Terbentuk relasi antara supplier s dan produk p.*/
void connectSuptoProd(adrSupplier s, adrProduk p);

/* I.S. Terdefinisi elemen supplier dan produk.
   F.S. Mengembalikan elemen relasi antara supplier dan produk apabila ada, dan mengembalikan nil jika tidak ada.*/
adrRelasi findRelation(adrSupplier s, adrProduk p);

/* I.S. Terdefinisi elemen supplier s dan produk p.
   F.S. Relasi antara supplier s dan produk p dihapus.*/
void deleteProdukfromSupplier(adrSupplier s, adrProduk p);

/* I.S. Terdefinisi list supplier L.
   F.S. Semua supplier beserta produk yang disediakan ditampilkan ke layar.*/
void showAllData(ListSupplier L);

/* I.S. Terdefinisi list supplier L dan supplier s.
   F.S. Mengembalikan jumlah produk yang disediakan oleh supplier s.*/
int countProductsBySupplier(adrSupplier s);

#endif // MAINAPP_H_INCLUDED
