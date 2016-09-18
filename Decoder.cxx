#include "Decoder.hxx"
#include "BinaryOps.hxx"

#include <cmath>

unsigned CDecoder::getBits(const unsigneds_vec &c_vBuf) const
{
    const unsigned c_uDiv = fromUnary(c_vBuf);

    const float c_fLog = std::log2(mc_uM);
    const unsigned c_uLog = static_cast<unsigned>(c_fLog);

    unsigned uRemainder = 0;

    if(c_fLog == c_uLog)
    {
        uRemainder = fromBinary(c_vBuf, c_uDiv, c_uLog);
    }
    else
    {
        const unsigned c_uB = std::ceil(c_fLog);
        const unsigned c_u2BM = std::pow(2.0f, c_uB) - mc_uM;

        const unsigned c_uStraightRemainder = fromBinary(c_vBuf, c_uDiv, c_uB - 1);
        if(c_uStraightRemainder < c_u2BM)
        {
            uRemainder = c_uStraightRemainder;
        }
        else
        {
            const unsigned c_uTrickyRemainder = fromBinary(c_vBuf, c_uDiv, c_uB);
            uRemainder = c_uTrickyRemainder - c_u2BM;
        }
    }
    return c_uDiv * mc_uM + uRemainder;
}

//==

CDecoder::CDecoder(const unsigned c_uM)
    :mc_uM(c_uM)
{

}

