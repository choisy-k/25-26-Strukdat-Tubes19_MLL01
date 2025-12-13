#ifndef PRODUK_DLL_H_INCLUDED
#define PRODUK_DLL_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct elmProduk *adrProduk;

struct infotypeProduk {
    string namaProduk;
    string kategori;
    int harga;
    int moQ; //minimum order quantity
};

struct elmProduk {
    infotypeProduk infoP;
    adrProduk next;
    adrProduk prev;
};

struct ListProduk {
    adrProduk first;
    adrProduk last;
};


#endif // PRODUK_DLL_H_INCLUDED
