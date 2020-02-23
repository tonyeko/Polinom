// bruteforce.cpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include "Polinom.hpp"

Polinom multiplicationBruteForce(Polinom P1, Polinom P2) {
    Polinom result(P1.getDerajat()+P2.getDerajat(), true);
    for (int i = 0; i <= P1.getDerajat(); i++) {
        for (int j = 0; j <= P2.getDerajat(); j++) {
            int newKoef = result.getKoefAt(i+j) + P1.getKoefAt(i) * P2.getKoefAt(j);
            result.setKoefAt(i+j, newKoef);
        }
    }
    return result;
}