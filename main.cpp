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
    // Polinom* PX = new BruteForce(5);
    // Polinom* PY = new BruteForce(5);
    // cout << "====================" << endl;
    // PX->print();
    // PY->print();
    // *PX = multiplication(*PY);
    // PX->print();
    // cout << "====================" << endl;
    int n;
    cout << "Masukkan derajat polinom: "; cin >> n;

    Polinom A(n);
    Polinom B(n);
    cout << "Polinom A: "; A.print(); 
    cout << "Polinom B: "; B.print();

    auto startDnC = high_resolution_clock::now(); 
    Polinom result = multiplicationDivideAndConquer(A, B);
    auto stopDnC = high_resolution_clock::now(); 
    auto durationDnC = duration_cast<microseconds>(stopDnC - startDnC);
    cout << "Perkalian Divide and Conquer   : " << endl; 
    result.print();
    
    auto startBF = high_resolution_clock::now(); 
    result = multiplicationBruteForce(A, B);
    auto stopBF = high_resolution_clock::now(); 
    auto durationBF = duration_cast<microseconds>(stopBF - startBF); 
    cout << "Perkalian Brute Force          : " << endl; 
    result.print();
    
    
    cout << "Runtime DnC    :   " << durationDnC.count() << " us" << endl;
    cout << "Runtime BF     :   " << durationBF.count() << " us" << endl;
    
    
}