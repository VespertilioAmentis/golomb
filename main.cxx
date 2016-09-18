#include <iostream>
#include <algorithm>
#include <iterator>

#include "GeomDistr.hxx"
#include "Encoder.hxx"
#include "Decoder.hxx"
#include "BinaryOps.hxx"

#include <cassert>
int main()
{
    const unsigned c_uParam = 16;

    CGeomDistr distr(0.01f);
    CEncoder encoder(c_uParam);

    const unsigned c_uExperimentsCnt = 10000;

    unsigneds_vec vTestVals;
    unsigneds_vec vNoncompressedUnaries;

    vTestVals.reserve(c_uExperimentsCnt);
    for(unsigned i = 0; i < c_uExperimentsCnt; i++)
    {
        const unsigned c_uTestVal = distr.get();
        vTestVals.push_back(c_uTestVal);
        encoder.putbits(c_uTestVal);
        insertVec(vNoncompressedUnaries, toUnary(c_uTestVal));
    }

    unsigneds_vec vBuf = encoder.getBuf();
    std::cout << "Compression: "
              << vNoncompressedUnaries.size() / vBuf.size() * 100.0f
              << "%" << std::endl;



    CDecoder decoder(c_uParam);
    for(unsigned i = 0; i < c_uExperimentsCnt; i++)
    {
        unsigned c_uDecoded = decoder.getBits(vBuf);
        assert(c_uDecoded == vTestVals.at(i));
    }
    assert(vBuf.empty());

    return 0;
}
