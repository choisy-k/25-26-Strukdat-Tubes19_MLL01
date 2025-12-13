#include <iostream>
#include "MainApp.h"

using namespace std;

void connectSuptoProd(adrSupplier s, adrProduk p){
    if(s == nullptr || p == nullptr) {
        cout << "Error! Salah satu atau kedua data tidak ditemukan di list." << endl;
    }
    else {
        adrRelasi r = new elmRelasi;
        r->next = nullptr;
        r->toProduk = nullptr;

        if(s->firstRelasi == nullptr) {
            s->firstRelasi = r;
            r->toProduk = p;
        }
        else {
            r->next = s->firstRelasi; //insertfirst
            s->firstRelasi = r;
            r->toProduk = p;
        }
        cout << "\nSuccess!\n Produk " << p->infoP.namaProduk << " sudah ditambahkan ke Supplier " << s->infoS.namaSupplier << "." << endl;

    }
}

adrRelasi findRelation(adrSupplier s, adrProduk p){
        //temukan relasi
    adrRelasi r = s->firstRelasi;
    adrRelasi findR = nullptr;
    while(r != nullptr && findR == nullptr) {
        if(r->toProduk == p) {
            findR = r;
        }
        r = r->next;
    }
    return findR;
}

void deleteProdukfromSupplier(adrSupplier s, adrProduk p){
    adrRelasi r = findRelation(s, p);

    //hapus relasi
    if(r == nullptr) {
        cout << "Supplier tidak menyediakan produk ini." << endl;
    }
    else {
        if(r == s->firstRelasi) {
            deleteFirstRelation(s, r); //sever the relation connection first later
        }
        else if(r->next == nullptr) {
            deleteLastRelation(s, r);
        }
        else {
            deleteMiddleRelation(s, r, p);
        }
    }
}
void deleteFirstRelation(adrSupplier s, adrRelasi r) {
    if(r->next == nullptr) {
        r->toProduk = nullptr;
        s->firstRelasi = nullptr;
    }
    else {
        r->toProduk = nullptr;
        s->firstRelasi = r->next;
        r->next = nullptr;
    }
}
void deleteLastRelation(adrSupplier s, adrRelasi r) {
    adrRelasi last;
    r = s->firstRelasi;

    if(r->next == nullptr) {
        r->toProduk = nullptr;
        s->firstRelasi = nullptr;
    }
    else {
        while(r->next != nullptr) {
            last = r;
            r = r->next;
        }
        r->toProduk = nullptr;
        last->next = nullptr;
    }
}
void deleteMiddleRelation(adrSupplier s, adrRelasi r, adrProduk p) {
    adrRelasi before;
    adrRelasi findR = s->firstRelasi;

    while(findR != nullptr && findR->toProduk != p) {
        before = findR;
        findR = findR->next;
    }
    if(before->next->next == nullptr) {
        r->toProduk = nullptr;
        r = before->next;
        before->next = nullptr;
    }
    else {
        r->toProduk = nullptr;
        r = before->next;
        before->next = r->next;
        r->next = nullptr;
    }
}

void showAllData(ListSupplier L) {

    /*cara display produk?
    ------- DAFTAR SUPPLIER -------
    Supplier: Nama [Lokasi]
    Produk yang disediakan:
    [nama produk] - [harga] - [minimum order quantity]
    Kategori:
    1. Nama - Harga - MOQ
    2. ....
    Kategori:
    1. ...

    Total produk: ???
    */

    adrSupplier s = L.first;

    cout << "\n------- DAFTAR SUPPLIER -------" << endl << endl;
    while(s != nullptr) {
        int counter = 0;

        cout << "Supplier: " << s->infoS.namaSupplier << " [" << s->infoS.lokasi << "]" << endl;
        cout << "Produk yang disediakan: " << endl;
//        adrRelasi r = findRelation(s,p);
        adrRelasi r = s->firstRelasi;
        while(r != nullptr) {
            counter++;
            cout << r->toProduk->infoP.namaProduk << ", ";
            r = r->next;
        }
        s = s->next;
        cout << "\nTotal produk: " << counter << endl << endl;
    }
}
