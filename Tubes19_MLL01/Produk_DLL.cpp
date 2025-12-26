#include <iostream>
#include "MainApp.h"

using namespace std;

void createProdukList(ListProduk &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrProduk allocateProduk(string nama, string kat, int harga, int moq) {
    adrProduk p = new elmProduk;
    p->infoP.namaProduk = nama;
    p->infoP.kategori = kat;
    p->infoP.harga = harga;
    p->infoP.moQ = moq;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

bool isEmptyProduk(ListProduk L) {
    return L.first == nullptr && L.last == nullptr;
}

void insertProdukLast(ListProduk &L, adrProduk p) {
    if(isEmptyProduk(L)){
        L.first = p;
        L.last = p;
    }
    else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

adrProduk searchProduk(ListProduk L, string nama) {
    adrProduk p = L.first;
    while(p != nullptr) {
        if(p->infoP.namaProduk == nama) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void printProdukInfo(ListProduk L) {
    adrProduk p = L.first;
    if(isEmptyProduk(L)) {
        cout << "Produk kosong." << endl;
    }
    else {
        int counter = 0;
        cout << "------- DAFTAR PRODUK -------" << endl;
        while (p != nullptr) {
            counter++;
            cout << counter << ". " << p->infoP.namaProduk
                 << " - " << p->infoP.kategori
                 << " - Rp" << p->infoP.harga
                 << " - MOQ: " << p->infoP.moQ << endl;
            p = p->next;
        }
    }
}
