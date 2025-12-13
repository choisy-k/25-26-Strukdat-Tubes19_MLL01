#ifndef RELASI_SLL_H_INCLUDED
#define RELASI_SLL_H_INCLUDED
#include <iostream>
#include "Produk_DLL.h"

using namespace std;

typedef struct elmRelasi *adrRelasi;

struct elmRelasi {
    adrRelasi next;
    adrProduk toProduk;
};


#endif // RELASI_SLL_H_INCLUDED
