#include <iostream>
#include "MainApp.h"

using namespace std;

void createSupplierList(ListSupplier &L) {
    L.first = nullptr;
}

bool isEmptySupplier(ListSupplier L) {
    return L.first == nullptr;
}

adrSupplier allocateSupplier(string nama, string lokasi) {
    adrSupplier p = new elmSupplier;
    p->infoS.namaSupplier = nama;
    p->infoS.lokasi = lokasi;
    p->next = nullptr;
    p->firstRelasi = nullptr;
    return p;
}

void insertSupplierFirst(ListSupplier &L, adrSupplier p) {
    p->next = L.first;
    L.first = p;
}

adrSupplier searchSupplier(ListSupplier L, string nama) {
    adrSupplier p = L.first;
    while(p != nullptr) {
        if(p->infoS.namaSupplier == nama) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void deleteSupplier(ListSupplier &L, adrSupplier p) {
    if(isEmptySupplier(L)) {
        cout << "List Supplier kosong." << endl;
        return;
    }
    if(p == nullptr) {
        cout << "Supplier tidak ditemukan." << endl;
        return;
    }

    // Hapus semua relasi dari Supplier p
    adrRelasi r = p->firstRelasi;
    while(r != nullptr) {
        adrRelasi temp = r;
        r = r->next;
        delete temp; // Free memory relasi
    }
    p->firstRelasi = nullptr;

    // Hapus supplier dari list
    if(p == L.first) {
        L.first = p->next;
    } else {
        adrSupplier prev = L.first;
        while(prev != nullptr && prev->next != p) {
            prev = prev->next;
        }
        if(prev != nullptr) {
            prev->next = p->next;
        }
    }

    delete p; // Free memory supplier
    cout << "Success! Supplier telah dihapus." << endl;
}

void printSupplierInfo(ListSupplier L) {
    adrSupplier p = L.first;
    if(isEmptySupplier(L)) {
        cout << "Supplier kosong." << endl;
    }
    else {
        cout << "List Supplier: " << endl << endl;
        while (p != nullptr) {
            cout << "Nama   : " << p->infoS.namaSupplier << endl;
            cout << "Lokasi : " << p->infoS.lokasi << endl;
            cout << endl;
            p = p->next;
        }
    }
    cout << endl;
}


