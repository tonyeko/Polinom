// Polinom.cpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "polinom.hpp"
using namespace std;

bool Polinom::seeded = false;


Polinom::Polinom(int n) {
    derajat = n;
    if (!seeded) {
        srand(time(NULL)); 
        seeded = true;
    }
    koefisien = new int[derajat];
    for (int i = 0; i <= derajat; i++) {
        koefisien[i] = rand() % (MAX_KOEF-MIN_KOEF + 1) + MIN_KOEF;
    }
}

Polinom::Polinom(const Polinom& pol) {
    this->derajat = pol.derajat;
    koefisien = new int[derajat];
    for (int i = 0; i <= derajat; i++) {
        this->koefisien[i] = pol.koefisien[i];
    }
}

Polinom::~Polinom() {
    delete koefisien;
}

Polinom& Polinom::operator=(const Polinom& pol) {
    this->derajat = pol.derajat;
    for (int i = 0; i <= derajat; i++) {
        this->koefisien[i] = pol.koefisien[i];
    }
    return *this;
}

int Polinom::getKoefAt(int idx) const {
    return this->koefisien[idx];
}

int Polinom::getDerajat() const {
    return this->derajat;
}

void Polinom::setKoefAt(int idx, int val) {
    this->koefisien[idx] = val;
}

void Polinom::setDerajat(int der) {
    this->derajat = der;
}

void Polinom::printKoef() {
    for (int i = 0; i <= this->derajat; i++) {
        cout << this->koefisien[i] << endl;
    }
}

void Polinom::print() {
    for (int i = 0; i <= derajat; i++) {
        if (koefisien[i] < 0) {
            if (koefisien[i] == -1) {
                cout << "-";
            } else {
                cout << koefisien[i];
            }
        } else if (koefisien[i] > 1) {
            if (i != 0) {
                cout << "+";
            }
            cout << koefisien[i];
        }
        if (koefisien[i] != 0 && i != 0) {
            if (i == 1) {
                cout << "x";
            } else {
                cout << "x^" << i;
            }
        }
    }
    cout << endl;
}

