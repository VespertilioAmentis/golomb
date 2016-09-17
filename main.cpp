#include <iostream>
#include <algorithm>
#include <iterator>

#include "GeomDistr.hxx"
#include "Encoder.hxx"
#include "Decoder.hxx"

#include <cassert>
int main()
{
    const unsigned c_uParam = 15;
    const double c_uPow = std::log2(c_uParam);

    CGeomDistr distr(0.01f);
    for(unsigned i = 0; i < 1000; i++)
    {
        const unsigned c_uTestVal = distr.get();

        CEncoder encoder(c_uParam);
        encoder.putbits(c_uTestVal);
        const unsigneds_vec& c_vBuf = encoder.getBuf();

        std::copy(c_vBuf.begin(), c_vBuf.end(),
                  std::ostream_iterator<unsigned>(std::cout, " "));
        std::cout << std::endl;

        CDecoder decoder(c_uParam);
        const unsigned c_uDecoded = decoder.getBits(c_vBuf);
        assert(c_uDecoded == c_uTestVal);
    }
    return 0;
}
