// polinomdriver.cpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include <iostream>
#include "Polinom.hpp"
using namespace std;

int main() {
    Polinom P1(5);
    Polinom P4(5);
    P1.printKoef(); cout << endl; P4.printKoef();
    // P1.input();
    Polinom P2(P1); //cctor 
    for (int i = 0; i <= P2.getDerajat(); i++) {
        P2.setKoefAt(i, 0);
    }
    P2.setKoefAt(5, 1);
    cout << endl; P2.printKoef();
    // Polinom P3 = P2; //cctor, kalo gini = otomatis jadi CCTOR bukan overloading operator=
    Polinom P3(P2);
    P3 = P1; //operator=
    cout << endl; P3.printKoef();   
    // P1 = P1/2; //operator= dan operator/
    P2.print();
}