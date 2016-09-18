#include <iostream>
#include <iterator>
#include <fstream>

#include "GeomDistr.hxx"
#include "Encoder.hxx"
#include "Decoder.hxx"
#include "BinaryOps.hxx"
#include "ExperimentParams.hxx"

#include <cassert>

int main()
{
    const CExperimentParams c_params;

    if(!c_params.isValid())
    {
        std::cerr << "Couldn't set params. Exitting...";
        return 1;
    }

    const unsigned c_uParam = c_params.getM();

    CGeomDistr distr(c_params.getProb());
    CEncoder encoder(c_uParam);

    const unsigned c_uExperimentsCnt = c_params.getExperimentsCnt();

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
    {
    std::ofstream ofResults("results.txt");
    ofResults << "Raw length: " << vNoncompressedUnaries.size() << "\n"
              << "Encoded length: " << vBuf.size() << "\n"
              << "Compressed to: "
              << vBuf.size() * 100.0f / vNoncompressedUnaries.size()
              << "%" << std::endl;
    }

    CDecoder decoder(c_uParam);
    for(unsigned i = 0; i < c_uExperimentsCnt; i++)
    {
        unsigned c_uDecoded = decoder.getBits(vBuf);
        assert(c_uDecoded == vTestVals.at(i));
    }
    assert(vBuf.empty());

    return 0;
}
