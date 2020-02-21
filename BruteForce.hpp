// BruteForce.hpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include "Polinom.hpp"

class BruteForce : public Polinom {
    public:
        BruteForce(int);
        Polinom multiplication(Polinom const&);
};