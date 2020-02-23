// divideandconquer.cpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include "Polinom.hpp"

int cntKaliDnC = 0;
int cntTambahDnC = 0;

Polinom multiplicationDivideAndConquer(Polinom P1, Polinom P2) {
    if (P1.getDerajat() == 0 || P2.getDerajat() == 0) {
        cntKaliDnC++;
        return multiplicationBruteForce(P1, P2);
    } else {
        int idxMid = (P1.getDerajat()+1)/2;
        Polinom P1High(P1, idxMid, P1.getDerajat());
        Polinom P1Low(P1, 0, idxMid-1);
        Polinom P2High(P2, idxMid, P2.getDerajat());
        Polinom P2Low(P2, 0, idxMid-1);
        Polinom Y = multiplicationDivideAndConquer(P1Low+P1High, P2Low+P2High);
        Polinom U = multiplicationDivideAndConquer(P1Low, P2Low);
        Polinom Z = multiplicationDivideAndConquer(P1High, P2High);

        Polinom result(P1.getDerajat()+P2.getDerajat(), true);
        for (int i = 0; i < P1.getDerajat(); i++) {
            result.koefisien[i] += U.koefisien[i]; 
            result.koefisien[i+idxMid] += (Y.koefisien[i] - U.koefisien[i] - Z.koefisien[i]);
            result.koefisien[i+(2*idxMid)] += Z.koefisien[i];
            cntTambahDnC+=3;
        }

        return result;
    }
}