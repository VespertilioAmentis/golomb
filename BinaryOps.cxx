#include "BinaryOps.hxx"

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
        const unsigned c_uBit = (c_uNum >> i) & 1;
        vBinary[c_uLen - i - 1] = c_uBit;
    }
    return vBinary;
}

//==

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

unsigned fromBinary(const unsigneds_vec& c_vBuf, const unsigned c_uPos,
                    const unsigned c_uLen)
{
    unsigned uRes = 0;
    const unsigned c_uLastBit = c_uPos + c_uLen;
    for(unsigned i = c_uPos + 1; i <= c_uLastBit; i++)
    {
        const unsigned c_uPow = c_uLastBit - i;
        uRes += c_vBuf.at(i) << c_uPow;
    }
    return uRes;
}
