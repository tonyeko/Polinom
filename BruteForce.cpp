// BruteForce.cpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include "BruteForce.hpp"
#include "Polinom.hpp"

BruteForce::BruteForce(Polinom* P) {
        this->P = P;
}

Polinom BruteForce::operator*(Polinom const& P) {
    Polinom result(this->getDerajat()+P.getDerajat());
    for (int i = 0; i <= result.getDerajat(); i++) {
        result.setKoefAt(i, 0);
    }
    for (int i = 0; i <= this->getDerajat(); i++) {
        for (int j = 0; j <= P.getDerajat(); j++) {
            int newKoef = result.getKoefAt(i+j) + this->getKoefAt(i) * P.getKoefAt(j);
            result.setKoefAt(i+j, newKoef);
        }
    }
    // result.print();
    return result;
}