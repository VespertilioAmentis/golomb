#ifndef CEXPERIMENTPARAMS_HXX
#define CEXPERIMENTPARAMS_HXX


class CExperimentParams
{
public:
    unsigned getM() const;
    unsigned getExperimentsCnt() const;
    float getProb() const;
    bool isValid() const;
    CExperimentParams();

private:
    unsigned m_uM;
    unsigned m_uExperimentsCnt;
    float m_fProb;
};

#endif // CEXPERIMENTPARAMS_HXX
