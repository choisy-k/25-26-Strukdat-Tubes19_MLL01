#include <iostream>
#include <string>
#include "MainApp.h"

using namespace std;

void connectSuptoProd(adrSupplier s, adrProduk p){
    if(s == nullptr || p == nullptr) {
        cout << "[ERROR] Salah satu atau kedua data tidak ditemukan di list." << endl;
    }
    else {
        adrRelasi r = new elmRelasi;
        r->next = nullptr;
        r->toProduk = p;

        if(s->firstRelasi == nullptr) {
            s->firstRelasi = r;
        }
        else {
            //insertFirst
            r->next = s->firstRelasi;
            s->firstRelasi = r;
        }
        //cout << "\n[SUCCESS] Produk " << p->infoP.namaProduk << " ditambahkan ke Supplier " << s->infoS.namaSupplier << "." << endl;
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
        cout << "[ERROR] Data tidak valid." << endl;
    }
    else {
        adrRelasi r = findRelation(s, p);
        if(r == nullptr) {
            cout << "[ERROR] Supplier tidak menyediakan produk ini." << endl;
        }
        else {
            if(r == s->firstRelasi) {
                s->firstRelasi = r->next;
                r->next = nullptr;
            }
            else {
                adrRelasi prev = s->firstRelasi;
                while(prev != nullptr && prev->next != r) {
                    prev = prev->next;
                }
                if(prev != nullptr) {
                    prev->next = r->next;
                    r->next = nullptr;
                }
            }
        }
    }
    cout << "[SUCCESS] Produk berhasil dihapus dari supplier." << endl;
}

int countProductsBySupplier(adrSupplier s) {
    int countP = 0;
    adrRelasi r = s->firstRelasi;
    while(r != nullptr) {
        countP++;
        r = r->next;
    }
    return countP;
}

void showAllData(ListSupplier L) {
    adrSupplier s = L.first;

    if(s == nullptr) {
        cout << "[ERROR] Tidak ada supplier." << endl;
        return;
    }

    cout << "\n------- DAFTAR SUPPLIER DAN PRODUK -------" << endl << endl;
    while(s != nullptr) {
        int counter = 0;

        cout << "Supplier: " << s->infoS.namaSupplier
             << " [" << s->infoS.lokasi << "]" << endl;
        cout << "Produk yang disediakan: " << endl;

        adrRelasi r = s->firstRelasi;
        if(r == nullptr) {
            cout << "  ---N/A---" << endl;
        } else {
            while(r != nullptr) {
                counter++;
                // manual padding with .length()
                string namaP = r->toProduk->infoP.namaProduk;
                string kat = r->toProduk->infoP.kategori;
                string harga = "Rp " + to_string(r->toProduk->infoP.harga);

                while(namaP.length() < 15) {
                    namaP += " ";
                }
                while (kat.length() < 10) {
                    kat += " ";
                }
                while(harga.length() < 7) {
                    harga += " ";
                }

                cout << "  " << counter << ". " << namaP
                     << " | " << kat
                     << " | " << harga
                     << " | MOQ: " << r->toProduk->infoP.moQ << endl;
                r = r->next;
            }
        }
        cout << "Total produk: " << counter << endl << endl;
        s = s->next;
    }
}
