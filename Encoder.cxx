#include "Encoder.hxx"
#include <cmath>
#include <bitset>

unsigneds_vec toUnary(const unsigned c_uNum)
{
    unsigneds_vec vEncoded;
    vEncoded.resize(c_uNum, 1);
    vEncoded.push_back(0);
    return vEncoded;
}

//==

unsigneds_vec toBinary(const unsigned c_uNum, const unsigned c_uLen)
{
    unsigneds_vec vBinary;
    vBinary.resize(c_uLen, 0);
    for(unsigned i = 0; i < c_uLen; i++)
    {
        const unsigned c_uBit = static_cast<unsigned>(std::pow(2.0f, i)) & c_uNum;
        vBinary[c_uLen - i - 1] = c_uBit == 0 ? 0 : 1;
    }
    return vBinary;
}

//==

void insertVec(unsigneds_vec& vDst, const unsigneds_vec& c_vSrc)
{
    vDst.insert(vDst.end(), c_vSrc.begin(), c_vSrc.end());
}

//==

void CEncoder::putbits(const unsigned c_uNum)
{
    const unsigned c_uPfx = c_uNum / m_uParam;
    const unsigneds_vec c_vUnaryPfx = toUnary(c_uPfx);
    insertVec(m_vBuf, c_vUnaryPfx);

    const unsigned c_uSfx = c_uNum % m_uParam;
    const unsigned c_uSfxLen = std::log2(m_uParam);
    const unsigneds_vec c_vSuffix(toBinary(c_uSfx, c_uSfxLen));
    insertVec(m_vBuf, c_vSuffix);
}

//==

const unsigneds_vec &CEncoder::getBuf() const
{
    return m_vBuf;
}

//==

CEncoder::CEncoder(const unsigned c_uParam)
    :m_uParam(c_uParam)
{
}

