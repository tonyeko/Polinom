// polinomdriver.cpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include <iostream>
#include "Polinom.hpp"
#include "BruteForce.hpp"
using namespace std;

int main() {
    Polinom P1(5);
    Polinom P4(5);
    P1.print(); 
    cout << P1.getDerajat() << endl;
    P4.print(); cout << endl;
    cout << P4.getDerajat() << endl;
    // (P1+P4).print();

    // P4 = P4 + P1;
    // P4.print(); cout << endl;
    // Polinom P2(P1); //cctor 
    Polinom P2 = P1.multiplicationDivideAndConquer(P1, P4);
    P2.print();
    // P2.print();
    // for (int i = 0; i <= P2.getDerajat(); i++) {
    //     P2.setKoefAt(i, 0);
    // }
    // P2.setKoefAt(0, 0);
    // Polinom P3 = P2; //cctor, kalo gini = otomatis jadi CCTOR bukan overloading operator=
    Polinom P3(P2);
    // P3 = P1; //operator=
    // P1 = P1/2; //operator= dan operator/
    P3 = P3.multiplicationBruteForce(P1, P4);
    cout << endl; P3.print();
    
}