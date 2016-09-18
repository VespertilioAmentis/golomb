#include "ExperimentParams.hxx"

unsigned CExperimentParams::getM() const
{
    return m_uM;
}

//==

unsigned CExperimentParams::getExperimentsCnt() const
{
    return m_uExperimentsCnt;
}

//==

float CExperimentParams::getProb() const
{
    return m_fProb;
}

//==

CExperimentParams::CExperimentParams()
    :m_uM(0)
    ,m_uExperimentsCnt(0)
    ,m_fProb(0)
{}

