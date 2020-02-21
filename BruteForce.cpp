// BruteForce.cpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include "BruteForce.hpp"
#include "Polinom.hpp"

BruteForce::BruteForce(int n) : Polinom(n) {}

Polinom BruteForce::multiplication(Polinom const& P) {
    Polinom result(this->getDerajat()+P.getDerajat(), true);
    for (int i = 0; i <= this->getDerajat(); i++) {
        for (int j = 0; j <= P.getDerajat(); j++) {
            int newKoef = result.getKoefAt(i+j) + this->getKoefAt(i) * P.getKoefAt(j);
            result.setKoefAt(i+j, newKoef);
        }
    }
    return result;
}