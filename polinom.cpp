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
    int length = n+1; // length array = derajat + 1
    if (!seeded) {
        srand(time(NULL)); 
        seeded = true;
    }
    
    int powerOfTwo = 1;
    while (powerOfTwo < length) {
        powerOfTwo *= 2;
    }
    bool isPowerOfTwo = (powerOfTwo == length);
    
    koefisien = new int[powerOfTwo];
    for (int i = 0; i < length; i++) {
        koefisien[i] = rand() % (MAX_KOEF-MIN_KOEF + 1) + MIN_KOEF;
    }
    
    if (!isPowerOfTwo) {
        for (int i = length; i <= powerOfTwo; i++) {
            koefisien[i] = 0;
        }
    }
    derajat = powerOfTwo-1;
}

Polinom::Polinom(int n, bool isZero) {
    int length = n+1;
    int powerOfTwo = 1;
    while (powerOfTwo < length) {
        powerOfTwo *= 2;    
    }
    bool isPowerOfTwo = (powerOfTwo == length);
    
    koefisien = new int[powerOfTwo];

    if (isZero) {
        for (int i = 0; i <= powerOfTwo; i++) {
            koefisien[i] = 0;
        }
    } else {
        if (!seeded) {
            srand(time(NULL)); 
            seeded = true;
        }
        for (int i = 0; i < length; i++) {
            koefisien[i] = rand() % (MAX_KOEF-MIN_KOEF + 1) + MIN_KOEF;
        }
        if (!isPowerOfTwo) {
           for (int i = length; i <= powerOfTwo; i++) {
                koefisien[i] = 0;
            }
        }
    }
    
    derajat = powerOfTwo-1;
}

Polinom::Polinom(const Polinom& pol, int idxLow, int idxHigh) {
    this->derajat = idxHigh - idxLow;
    koefisien = new int[this->derajat];
    for (int i = 0; i <= this->derajat; i++) {
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

Polinom operator+(const Polinom& p1, const Polinom& p2) {
    Polinom out(p1.getDerajat(), true);
    for (int i = 0; i <= out.getDerajat(); i++) {
        out.koefisien[i] = p1.koefisien[i] + p2.koefisien[i];
    }
    return out;
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
        int idxMid = (P1.getDerajat()+1)/2;
        Polinom P1High(P1, idxMid, P1.getDerajat());
        Polinom P1Low(P1, 0, idxMid-1);
        Polinom P2High(P2, idxMid, P2.getDerajat());
        Polinom P2Low(P2, 0, idxMid-1);
        // cout << "==================" << endl;
        // cout << "P1: "; P1.print(); cout << P1.getDerajat() <<  " " << P1Low.getDerajat() <<  " " << P1High.getDerajat() << endl;
        // cout << "P1High: "; P1High.print();
        // cout << "P1Low: "; P1Low.print(); cout << endl;
        // cout << "P2: "; P2.print(); cout << P2.getDerajat() <<  " " << P2Low.getDerajat() <<  " " << P2High.getDerajat() << endl;
        // cout << "P2High: "; P2High.print();
        // cout << "P2Low: "; P2Low.print(); cout << endl;
        // cout << "==================" << endl;
        
        // Polinom P1P2Low = multiplicationDivideAndConquer(P1Low, P2Low);
        // Polinom P1LowP2High = multiplicationDivideAndConquer(P1Low, P2High);
        // Polinom P1HighP2Low = multiplicationDivideAndConquer(P1High, P2Low);
        // Polinom P1P2High = multiplicationDivideAndConquer(P1High, P2High);

        // Polinom result(P1.getDerajat()+P2.getDerajat(), true);
        // for (int i = 0; i < P1.getDerajat(); i++) {
        //     result.koefisien[i] += P1P2Low.koefisien[i];
        //     result.koefisien[i+idxMid] += P1LowP2High.koefisien[i] + P1HighP2Low.koefisien[i];
        //     result.koefisien[i+(2*idxMid)] += P1P2High.koefisien[i];
        // }
        // cout << "TESSSS" << endl; (P1Low + P1High).print();

        // Polinom P1new = P1Low+P1High;
        // Polinom P2new = P2Low+P2High;
        // cout << "==================" << endl;
        // cout << "P1High: "; P1High.print(); 
        // cout << "P1Low: "; P1Low.print(); cout << endl;
        // cout << P1Low.getDerajat() << " " << P2High.getDerajat() << endl;
        // P1new.print();
        // cout << "==================" << endl;
        Polinom Y = multiplicationDivideAndConquer(P1Low+P1High, P2Low+P2High);
        Polinom U = multiplicationDivideAndConquer(P1Low, P2Low);
        Polinom Z = multiplicationDivideAndConquer(P1High, P2High);
        
        Polinom result(P1.getDerajat()+P2.getDerajat(), true);
        for (int i = 0; i < P1.getDerajat(); i++) {
            result.koefisien[i] += U.koefisien[i];
            result.koefisien[i+idxMid] += (Y.koefisien[i] - U.koefisien[i] - Z.koefisien[i]);
            result.koefisien[i+(2*idxMid)] += Z.koefisien[i];
        }

        return result;
    }
}