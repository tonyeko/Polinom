// BruteForce.hpp
// Nama	: Tony Eko Yuwono
// NIM	: 13518030

#include "Polinom.hpp"

class BruteForce : public Polinom {
    public:
        BruteForce(Polinom* P);
        Polinom operator*(Polinom const&);
    protected:
        Polinom* P;
};

