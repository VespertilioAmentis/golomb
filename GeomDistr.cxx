#include "GeomDistr.hxx"

int CGeomDistr::get()
{
    return m_distr(m_engine);
}

//==

CGeomDistr::CGeomDistr(const double c_dProb)
    :m_distr(c_dProb)
{}

