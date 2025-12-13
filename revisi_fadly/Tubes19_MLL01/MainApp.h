#ifndef MAINAPP_H_INCLUDED
#define MAINAPP_H_INCLUDED
#include <iostream>
#include "Supply_SLL.h"
#include "Relasi_SLL.h"
#include "Produk_DLL.h"

using namespace std;

/* I.S. List produk L terdefinisi
   F.S. Semua produk dalam list L ditampilkan ke layar */
void printProdukInfo(ListProduk L);

/* I.S. List supplier L terdefinisi
   F.S. Semua supplier dalam list L ditampilkan ke layar */
void printSupplierInfo(ListSupplier L);

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
