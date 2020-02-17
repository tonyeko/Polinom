// Polinom.hpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#ifndef POLINOM_HPP
#define POLINOM_HPP

const int MAX_KOEF = 1000;
const int MIN_KOEF = -1000;

class Polinom {
  public:
    Polinom(int);
    Polinom(const Polinom&);
    ~Polinom();
    Polinom& operator=(const Polinom&);

    int getKoefAt(int idx) const;
    int getDerajat() const;
    void setKoefAt(int idx, int val);
    void setDerajat(int);
    
    // Mencetak seluruh koefisien polinom. Untuk setiap koefisien akhiri dengan end-of-line
    // Cetaklah apa adanya dari koefisien ke-0 hingga derajat tertinggi (termasuk apabila koefisien = 0)
    void printKoef();

    // Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst (diakhiri dengan end-of-line)
    // Jika seluruh koefisien bernilai 0, keluarkan "0"
    void print();

  protected:
    int derajat; // derajat tertinggi
    int* koefisien;
    static bool seeded;
    
};

#endif