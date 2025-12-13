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

void deleteFirst(ListSupplier &L, adrSupplier p) {
    if(isEmptySupplier(L)){
        p = nullptr;
    }
    else if(p->next == nullptr) {
        L.first = nullptr;
    }
    else {
        L.first = p->next;
        p->next = nullptr;
    }
}
void deleteLast(ListSupplier &L, adrSupplier p) {
    adrSupplier last;
    p = L.first;
    if(isEmptySupplier(L)) {
        p = nullptr;
    }
    else if(p->next == nullptr) {
        L.first = nullptr;
    }
    else {
        while(p->next != nullptr) {
            last = p;
            p = p->next;
        }
        last->next = nullptr;
    }
}
void deleteMiddle(ListSupplier &L, adrSupplier p) {
    adrSupplier before;
    adrSupplier findP = L.first;
    while(findP != nullptr && findP->infoS.namaSupplier != p->infoS.namaSupplier) {
        before = findP;
        findP = findP->next;
    }
    if(before->next->next == nullptr) {
        p = before->next;
        before->next = nullptr;
    }
    else {
        p = before->next;
        before->next = p->next;
        p->next = nullptr;
    }
}

void deleteSupplier(ListSupplier &L, adrSupplier p) {
    if(isEmptySupplier(L)) {
        cout << "List Supplier kosong." << endl;
    }
    else if(p == nullptr) {
        cout << "Supplier tidak ditemukan." << endl;
    }
    else {
        //hapus semua relasi dari Supplier p
        adrRelasi r = p->firstRelasi;
        while(r != nullptr) {
            r->toProduk = nullptr;
            r = r->next;
        }
        p->firstRelasi = nullptr;

        if(p == L.first) {
            deleteFirst(L, p); //sever the relation connection first later
        }
        else if(p->next == nullptr) {
            deleteLast(L, p);
        }
        else {
            deleteMiddle(L, p);
        }
        cout << "Success! Supplier telah dihapus." << endl;
    }
}

adrSupplier searchSupplier(ListSupplier L, string nama) {
    adrSupplier p = L.first;
    adrSupplier findP = nullptr;

    while(p!=nullptr && findP == nullptr) {
        if(p->infoS.namaSupplier == nama) {
            findP = p;
        }
        p= p->next;
    }
    return findP;
}

adrSupplier findTopSupplier();





void printInfotess(ListSupplier L) {
    adrSupplier p = L.first;
    if(isEmptySupplier(L)) {
        cout << "Supplier kosong." << endl;
    }
    else {
        cout << "List Supplier: " << endl << endl;
        while (p!=nullptr) {
            cout << "Nama   : " << p->infoS.namaSupplier << endl;
            cout << "Lokasi : " << p->infoS.lokasi << endl;
            cout << endl;
            p = p->next;
        }
    }
    cout << endl;
}
