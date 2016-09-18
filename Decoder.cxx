#include "Decoder.hxx"
#include <algorithm>

unsigned fromUnary(const unsigneds_vec& c_vBuf)
{
    for(unsigned uDiv = 0; uDiv < c_vBuf.size(); uDiv++)
    {
        if(c_vBuf.at(uDiv) == 0)
        {
            return uDiv;
        }
    }
    return -1;
}

//==

unsigned fromBinary(const unsigneds_vec& c_vBuf, const unsigned c_uPos)
{
    unsigned uRes = 0;
    for(unsigned i = c_uPos; i < c_vBuf.size(); i++)
    {
        const unsigned c_uPow = c_vBuf.size() - i - 1;
        uRes += c_vBuf.at(i) << c_uPow;
    }
    return uRes;
}

//==

unsigned CDecoder::getBits(const unsigneds_vec &c_vBuf) const
{
    const c_uDiv = fromUnary(c_vBuf);
    const unsigned c_uMod = fromBinary(c_vBuf, uDiv);
    return uDiv * m_uParam + c_uMod;
}

//==

CDecoder::CDecoder(const unsigned c_uParam)
    :m_uParam(c_uParam)
{

}

