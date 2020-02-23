// Polinom.hpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#ifndef POLINOM_HPP
#define POLINOM_HPP

const int MAX_KOEF = 1000;
const int MIN_KOEF = -1000;

class Polinom {
  public:
    Polinom(int);
    Polinom(int, bool);
    Polinom(const Polinom&);
    Polinom(const Polinom&, int, int);
    virtual ~Polinom();
    Polinom& operator=(const Polinom&);
    friend Polinom operator+(const Polinom&, const Polinom&);
    friend Polinom operator*(const Polinom&, const Polinom&);  // overloading untuk brute force
    friend Polinom operator*=(const Polinom&, const Polinom&); // overloading untuk divide and conquer
    friend Polinom multiplicationBruteForce(Polinom P1, Polinom P2);
    friend Polinom multiplicationDivideAndConquer(Polinom P1, Polinom P2);
    void print();
  protected:
    int derajat; // derajat tertinggi
    int* koefisien;
    static bool seeded;
    int getDerajat() const;
    void setDerajat(int);
    int getKoefAt(int idx) const;
    void setKoefAt(int idx, int val);
};

#endif