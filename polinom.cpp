// Polinom.cpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Polinom.hpp"
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

Polinom::Polinom(int n, bool isZero) {
    derajat = n;
    koefisien = new int[derajat];
    if (isZero) {
        for (int i = 0; i <= derajat; i++) {
            koefisien[i] = 0;
        }
    } else {
        if (!seeded) {
            srand(time(NULL)); 
            seeded = true;
        }
        for (int i = 0; i <= derajat; i++) {
            koefisien[i] = rand() % (MAX_KOEF-MIN_KOEF + 1) + MIN_KOEF;
        }
    }
    
    
}

Polinom::Polinom(const Polinom& pol, int idxLow, int idxHigh) {
    this->derajat = idxHigh - idxLow;
    koefisien = new int[this->derajat];
    for (int i = 0; i <= idxHigh; i++) {
        this->koefisien[i] = pol.koefisien[idxLow+i];
    }
}

Polinom::Polinom(const Polinom& pol) {
    this->derajat = pol.derajat;
    koefisien = new int[this->derajat];
    for (int i = 0; i <= this->derajat; i++) {
        this->koefisien[i] = pol.koefisien[i];
    }
}

Polinom::~Polinom() {
    delete koefisien;
}

Polinom& Polinom::operator=(const Polinom& pol) {
    koefisien = new int[pol.derajat];
    for (int i = 0; i <= pol.derajat; i++) {
        this->koefisien[i] = pol.koefisien[i];
    }
    this->derajat = pol.derajat;
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

void Polinom::print() {
    if (derajat == 0 && koefisien[0] == 0) {
        cout << "0";
    } else {
        if (koefisien[0] != 0) {
            cout << koefisien[0];
        }
        for (int i = 1; i <= derajat; i++) {
            if (koefisien[i] < 0) {
                if (koefisien[i] == -1) {
                    cout << "-";
                } else {
                    cout << koefisien[i];
                }
            } else if (koefisien[i] > 1) {
                if ((i == 1 && koefisien[0] != 0) || i > 1) {
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
        
    }
    cout << endl;
}

Polinom Polinom::multiplicationBruteForce(Polinom P1, Polinom P2) {
    Polinom result(P1.getDerajat()+P2.getDerajat(), true);
    for (int i = 0; i <= P1.getDerajat(); i++) {
        for (int j = 0; j <= P2.getDerajat(); j++) {
            int newKoef = result.getKoefAt(i+j) + P1.getKoefAt(i) * P2.getKoefAt(j);
            result.setKoefAt(i+j, newKoef);
        }
    }
    return result;
}

Polinom Polinom::multiplicationDivideAndConquer(Polinom P1, Polinom P2) {
    if (P1.getDerajat() == 0 || P2.getDerajat() == 0) {
        return multiplicationBruteForce(P1, P2);
    } else {
        int idxMid = P1.getDerajat()/2;
        Polinom P1High(P1, idxMid+1, P1.getDerajat());
        Polinom P1Low(P1, 0, idxMid);
        Polinom P2High(P2, idxMid+1, P2.getDerajat());
        Polinom P2Low(P2, 0, idxMid);
        // cout << "==================" << endl;
        // cout << "P1: "; P1.print(); cout << P1.getDerajat() <<  " " << P1Low.getDerajat() <<  " " << P1High.getDerajat() << endl;
        // cout << "P1High: "; P1High.print();
        // cout << "P1Low: "; P1Low.print(); cout << endl;
        // cout << "P2: "; P2.print(); cout << P2.getDerajat() <<  " " << P2Low.getDerajat() <<  " " << P2High.getDerajat() << endl;
        // cout << "P2High: "; P2High.print();
        // cout << "P2Low: "; P2Low.print(); cout << endl;
        // cout << "==================" << endl;
        
        Polinom P1P2Low = multiplicationDivideAndConquer(P1Low, P2Low);
        Polinom P1LowP2High = multiplicationDivideAndConquer(P1Low, P2High);
        Polinom P1HighP2Low = multiplicationDivideAndConquer(P1High, P2Low);
        Polinom P1P2High = multiplicationDivideAndConquer(P1High, P2High);

        Polinom result(P1.getDerajat()+P2.getDerajat(), true);
        for (int i =0; i <= P1.getDerajat(); i++) {
            // cout << "masuk" << endl;
            result.koefisien[i] += P1P2Low.koefisien[i];
            result.koefisien[i+idxMid] += P1LowP2High.koefisien[i] + P1HighP2Low.koefisien[i];
            result.koefisien[i+2*idxMid] += P1P2High.koefisien[i];
        }

        return result;
    }
}