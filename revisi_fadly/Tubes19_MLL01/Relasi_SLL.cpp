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
        r->toProduk = p;

        if(s->firstRelasi == nullptr) {
            s->firstRelasi = r;
        }
        else {
            r->next = s->firstRelasi; // insert first
            s->firstRelasi = r;
        }
        cout << "\nSuccess!\n Produk " << p->infoP.namaProduk << " sudah ditambahkan ke Supplier " << s->infoS.namaSupplier << "." << endl;
    }
}

adrRelasi findRelation(adrSupplier s, adrProduk p){
    adrRelasi r = s->firstRelasi;
    while(r != nullptr) {
        if(r->toProduk == p) {
            return r;
        }
        r = r->next;
    }
    return nullptr;
}

void deleteProdukfromSupplier(adrSupplier s, adrProduk p){
    if(s == nullptr || p == nullptr) {
        cout << "Error! Data tidak valid." << endl;
        return;
    }

    adrRelasi r = findRelation(s, p);
    if(r == nullptr) {
        cout << "Supplier tidak menyediakan produk ini." << endl;
        return;
    }

    // Hapus relasi dari list
    if(r == s->firstRelasi) {
        s->firstRelasi = r->next;
    } else {
        adrRelasi prev = s->firstRelasi;
        while(prev != nullptr && prev->next != r) {
            prev = prev->next;
        }
        if(prev != nullptr) {
            prev->next = r->next;
        }
    }

    delete r; // Free memory
    cout << "Produk berhasil dihapus dari supplier." << endl;
}

adrSupplier findTopSupplier(ListSupplier L) {
    adrSupplier top = nullptr;
    int maxProducts = 0;

    adrSupplier s = L.first;
    while(s != nullptr) {
        int count = 0;
        adrRelasi r = s->firstRelasi;
        while(r != nullptr) {
            count++;
            r = r->next;
        }

        if(count > maxProducts) {
            maxProducts = count;
            top = s;
        }
        s = s->next;
    }

    return top;
}

int countProductsBySupplier(adrSupplier s) {
    int count = 0;
    adrRelasi r = s->firstRelasi;
    while(r != nullptr) {
        count++;
        r = r->next;
    }
    return count;
}

void showAllData(ListSupplier L) {
    adrSupplier s = L.first;

    if(s == nullptr) {
        cout << "Tidak ada supplier." << endl;
        return;
    }

    cout << "\n------- DAFTAR SUPPLIER -------" << endl << endl;
    while(s != nullptr) {
        int counter = 0;

        cout << "Supplier: " << s->infoS.namaSupplier << " [" << s->infoS.lokasi << "]" << endl;
        cout << "Produk yang disediakan: " << endl;

        adrRelasi r = s->firstRelasi;
        if(r == nullptr) {
            cout << "  (Tidak ada produk)" << endl;
        } else {
            while(r != nullptr) {
                counter++;
                cout << "  " << counter << ". " << r->toProduk->infoP.namaProduk
                     << " | Kategori: " << r->toProduk->infoP.kategori
                     << " | Harga: Rp" << r->toProduk->infoP.harga
                     << " | MOQ: " << r->toProduk->infoP.moQ << endl;
                r = r->next;
            }
        }
        cout << "Total produk: " << counter << endl << endl;
        s = s->next;
    }
}
