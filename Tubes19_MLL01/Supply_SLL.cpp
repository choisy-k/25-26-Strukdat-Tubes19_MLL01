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
    }
    else if(p == nullptr) {
        cout << "Supplier tidak ditemukan." << endl;
    }
    else {
        //delete relasi
        adrRelasi r = p->firstRelasi;
        while (r != nullptr) {
            adrRelasi bfore = r;
            r = r->next;
            bfore->next = nullptr;
        }
        p->firstRelasi = nullptr;

        //delete supplier
        if(p == L.first) {
            L.first = p->next;
            p->next = nullptr;
        }
        else {
            adrSupplier prev = L.first;
            while(prev != nullptr && prev->next != p) {
                prev = prev->next;
            }
            if(prev != nullptr) {
                prev->next = p->next;
                p->next = nullptr;
            }
        }
    }
    cout << "[SUCCESS] Supplier telah dihapus." << endl;
}
adrSupplier findTopSupplier(ListSupplier L) {
    adrSupplier top = nullptr;
    int maxProduk = 0;

    adrSupplier s = L.first;
    while(s != nullptr) {
        int count = 0;
        adrRelasi r = s->firstRelasi;
        while(r != nullptr) {
            count++;
            r = r->next;
        }

        if(count > maxProduk) {
            maxProduk = count;
            top = s;
        }
        s = s->next;
    }
    return top;
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


