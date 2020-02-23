// main.cpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include <iostream>
#include <chrono>
#include <math.h>       /* log */
#include "Polinom.hpp"
using namespace std; 
using namespace std::chrono;

extern int cntKaliDnC;
extern int cntTambahDnC;

int main() {
    int n;
    cout << "Masukkan derajat polinom: "; cin >> n;
    while (n < 0) {
        cout << "Masukan tidak sesuai!" << endl;
        cout << "Masukkan derajat polinom: "; 
        cin >> n;
    }

    Polinom A(n);
    Polinom B(n);
    cout << "Polinom A: "; A.print(); 
    cout << "Polinom B: "; B.print();
    cout << endl;

    auto startBF = steady_clock::now(); 
    Polinom result = A * B; // overloading untuk brute force
    auto stopBF = steady_clock::now(); 
    auto durationBF = duration_cast<microseconds>(stopBF - startBF); 
    cout << "Perkalian Brute Force          : " << endl; 
    result.print();
    cout << endl;

    auto startDnC = steady_clock::now(); 
    result = (A *= B); // overloading untuk divide and conquer
    auto stopDnC = steady_clock::now(); 
    auto durationDnC = duration_cast<microseconds>(stopDnC - startDnC);
    cout << "Perkalian Divide and Conquer   : " << endl; 
    result.print();
    cout << endl;
    
    int length = n+1;
    cout << "====     Algoritma Brute Force    ==== " << endl;
    cout << "Runtime                : " << durationBF.count() << " us" << endl;
    cout << "Jumlah operasi kali    : " << pow(length, 2) << endl; 
    cout << "Jumlah operasi tambah  : " << pow(length, 2) << endl; 
    cout << "==== Algoritma Divide and Conquer ==== " << endl;
    cout << "Runtime                : " << durationDnC.count() << " us" << endl;
    cout << "Jumlah operasi kali    : " << cntKaliDnC << endl; 
    cout << "Jumlah operasi tambah  : " << cntTambahDnC << endl;
}