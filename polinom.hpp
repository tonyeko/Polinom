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

    int getKoefAt(int idx) const;
    int getDerajat() const;
    void setKoefAt(int idx, int val);
    void setDerajat(int);

    friend Polinom operator+(const Polinom&, const Polinom&);

    friend Polinom multiplicationBruteForce(Polinom P1, Polinom P2);
    friend Polinom multiplicationDivideAndConquer(Polinom P1, Polinom P2);

    // Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst (diakhiri dengan end-of-line)
    // Jika seluruh koefisien bernilai 0, keluarkan "0"
    void print();

  protected:
    int derajat; // derajat tertinggi
    int* koefisien;
    static bool seeded;
    
};

#endif