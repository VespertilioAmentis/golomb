#include "Encoder.hxx"
#include "BinaryOps.hxx"

#include <cmath>

void insertVec(unsigneds_vec& vDst, const unsigneds_vec& c_vSrc)
{
    vDst.insert(vDst.end(), c_vSrc.begin(), c_vSrc.end());
}

//==

void CEncoder::putbits(const unsigned c_uN)
{
    const unsigned c_uQ = c_uN / mc_uM;
    insertVec(m_vBuf, toUnary(c_uQ));

    const unsigned c_uR = c_uN % mc_uM;

    unsigned uSfx = 0;
    unsigned uLen = 0;

    const float c_fLog = std::log2(mc_uM);
    const unsigned c_uLog = static_cast<unsigned>(c_fLog);

    if(c_uLog == c_fLog)
    {
        uSfx = c_uR;
        uLen = c_uLog;
    }
    else
    {
        const unsigned c_uB = std::ceil(c_fLog);
        const unsigned c_u2BM = std::pow(2.0f, c_uB) - mc_uM;
        if(c_uR < c_u2BM)
        {
            uSfx = c_uR;
            uLen = c_uB - 1;
        }
        else
        {
            uSfx = c_uR + c_u2BM;
            uLen = c_uB;
        }
    }
    insertVec(m_vBuf, toBinary(uSfx, uLen));
}

//==

const unsigneds_vec &CEncoder::getBuf() const
{
    return m_vBuf;
}

//==

CEncoder::CEncoder(const unsigned c_uM)
    :mc_uM(c_uM)
{
}

