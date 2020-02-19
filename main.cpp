// polinomdriver.cpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include <iostream>
#include <chrono>
#include "Polinom.hpp"
#include "BruteForce.hpp"
using namespace std; 
using namespace std::chrono;

int main() {
    Polinom P1(10);
    Polinom P2(10);
    cout << "Polinom P1: "; P1.print(); 
    cout << "Polinom P2: "; P2.print();
    Polinom P3(P2);

    auto startDnC = high_resolution_clock::now(); 
    P3 = P3.multiplicationDivideAndConquer(P1, P2);
    auto stopDnC = high_resolution_clock::now(); 
    auto durationDnC = duration_cast<microseconds>(stopDnC - startDnC); 

    cout << "Perkalian Divide and Conquer   : "; P3.print();
    cout << "Runtime DnC:   " << durationDnC.count() << " us" << endl;
    
    Polinom P4(P2);

    auto startBF = high_resolution_clock::now(); 
    P4 = P4.multiplicationBruteForce(P1, P2);
    auto stopBF = high_resolution_clock::now(); 
    auto durationBF = duration_cast<microseconds>(stopBF - startBF); 

    cout << "Perkalian Brute Force          : "; P4.print();
    cout << "Runtime BF:   " << durationBF.count() << " us" << endl;
    
    
}