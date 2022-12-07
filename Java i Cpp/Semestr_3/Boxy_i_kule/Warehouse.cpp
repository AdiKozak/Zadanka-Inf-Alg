#include "nagl.hpp"

Warehouse::Warehouse(int size, Results results) {
    boxy = new Box[size];
    this->size = size;
    this->results = results;
    puste = size;
}

bool Warehouse::add(int urna, int kula, int i) {
    int liczba = boxy[urna].getCount();
    if(liczba == 0) {
        puste--;
    }
    else if(liczba == 1) {
        podwojne++;
    }
    if(liczba == max) {
        max = liczba + 1;
    }

    boxy[urna].moreBall();

    return Seria(boxy[urna].collision(), kula, i, max);
}


bool Warehouse::Seria(bool collision, int kula, int i, int max) {
    if(Bn == 0 && collision)  {
        Bn = kula;
    }
    if(kula == i) {
        Un = puste;
        Ln = max;
    }
    if(Cn == 0 && puste == 0) {
        Cn = kula;
    }
    if(podwojne == i) {
        Dn = kula;
        return false;
    }
    return true;
}

void Warehouse::Wyniki(int index, int n) {
    results.add(index, n, Bn, Un, Ln, Cn, Dn);
}