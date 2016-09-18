#ifndef CDECODER_HXX
#define CDECODER_HXX

#include "Encoder.hxx"

class CDecoder
{
public:
    unsigned getBits(unsigneds_vec& vBuf) const;
    explicit CDecoder(const unsigned c_uM);
private:
    const unsigned mc_uM;
};

#endif // CDECODER_HXX
