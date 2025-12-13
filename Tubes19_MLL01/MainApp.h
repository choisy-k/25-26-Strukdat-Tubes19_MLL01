#ifndef MAINAPP_H_INCLUDED
#define MAINAPP_H_INCLUDED
#include <iostream>
#include "Supply_SLL.h"
#include "Relasi_SLL.h"
#include "Produk_DLL.h"

using namespace std;

// untuk tes printout produk dan supply
void printInfotes(ListProduk L);
void printInfotess(ListSupplier L);


// ----- SUBPROGRAM SUPPLIER -----

void createSupplierList(ListSupplier &L);
/*I.S. -
F.F. Terbentuk list Supplier L, dengan first dari L bernilai nil (nullptr).*/

bool isEmptySupplier(ListSupplier L);
/*I.S. Terdefinisi list Supplier L.
F.S. Mengembalikan true jika L kosong, false apabila tidak.*/

adrSupplier allocateSupplier(string nama, string lokasi);
/*I.S. Terdefinisi string nama dan lokasi.
F.S. Mengembalikan elemen supplier baru dengan info nama dan lokasi dimasukkan, serta next dan firstRelasi bernilai nil.*/

void insertSupplierFirst(ListSupplier &L, adrSupplier p);
/*I.S. Terdefinisi list supplier L yang mungkin kosong dan elemen supplier p.
F.S. Elemen p ditambahkan ke dalam list sebagai elemen pertama.*/

void deleteSupplier(ListSupplier &L, adrSupplier p);
/*delete berbagai method, untuk p pakai searchSupplier dulu
showSupplier kayaknya nggak perlu*/
void deleteFirst(ListSupplier &L, adrSupplier p);
void deleteLast(ListSupplier &L, adrSupplier p);
void deleteMiddle(ListSupplier &L, adrSupplier p);

adrSupplier searchSupplier(ListSupplier L, string nama);
/*I.S. Terdefinisi list supplier L dan string nama.
F.S. Mengembalikan elemen supplier dengan nama yang ditentukan apabila ada, dan mengembalikan nil jika tidak ada.*/

adrSupplier findTopSupplier();


// ----- SUBPROGRAM PRODUK -----

void createProdukList(ListProduk &L);
/*I.S. -
F.F. Terbentuk list Produk L, dengan first dan prev dari L bernilai nil (nullptr).*/

bool isEmptyProduk(ListProduk L);
/*I.S. Terdefinisi list Produk L.
F.S. Mengembalikan true jika L kosong, false apabila tidak.*/

adrProduk allocateProduk(string nama, string kat, int harga, int moq);
/*I.S. Terdefinisi string nama dan kategori, integer harga dan MOQ.
F.S. Mengembalikan elemen supplier baru dengan info nama, kategori, harga dan MOQ dimasukkan, serta next dan prev bernilai nil.*/

void insertProdukLast(ListProduk &L, adrProduk p);
/*I.S. Terdefinisi list produk L yang mungkin kosong dan elemen supplier p.
F.S. Elemen p ditambahkan ke dalam list sebagai elemen pertama.*/

adrProduk searchProduk(ListProduk L, string nama);
/*I.S. Terdefinisi list produk L dan string nama.
F.S. Mengembalikan elemen produk dengan nama yang ditentukan apabila ada, dan mengembalikan nil jika tidak ada.*/


// ----- SUBPROGRAM RELASI AND OTHERS RELATED -----

void connectSuptoProd(adrSupplier s, adrProduk r);
/*perlu searchProduk, tapi kayaknya nggak usah ditampilkan di main*/

adrRelasi findRelation(adrSupplier s, adrProduk p);
/*I.S. Terdefinisi elemen supplier dan produk.
F.S. Mengembalikan elemen relasi antara supplier dan produk apabila ada, dan mengembalikan nil jika tidak ada.*/

void deleteProdukfromSupplier(adrSupplier s, adrProduk p);
/*hanya relasi di cut*/

void deleteFirstRelation(adrSupplier s, adrRelasi r);
void deleteLastRelation(adrSupplier s, adrRelasi r);
void deleteMiddleRelation(adrSupplier s, adrRelasi r, adrProduk p);

void showAllData(ListSupplier L);
/* show all supplier with their products, ditambah jumlah total produk
    masukkan disini atau di topSupplier atau buat fungsi baru?
*/


#endif // MAINAPP_H_INCLUDED
