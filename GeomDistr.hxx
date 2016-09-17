#ifndef CGEOMDISTR_HXX
#define CGEOMDISTR_HXX

#include <random>

class CGeomDistr
{
public:
    int get();
    explicit CGeomDistr(const double c_dProb);

private:
    std::default_random_engine m_engine;
    std::geometric_distribution<int> m_distr;
};

#endif // CGEOMDISTR_HXX
