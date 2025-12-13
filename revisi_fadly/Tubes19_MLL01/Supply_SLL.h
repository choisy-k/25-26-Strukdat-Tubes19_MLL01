#ifndef SUPPLY_SLL_H_INCLUDED
#define SUPPLY_SLL_H_INCLUDED
#include <iostream>
#include "Relasi_SLL.h"

using namespace std;

typedef struct elmSupplier *adrSupplier;

struct infotypeSupplier {
    string namaSupplier;
    string lokasi;
};

struct elmSupplier {
    infotypeSupplier infoS;
    adrSupplier next;
    adrRelasi firstRelasi;
};

struct ListSupplier {
    adrSupplier first;
};


#endif // SUPPLY_SLL_H_INCLUDED
