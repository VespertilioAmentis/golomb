#ifndef CDECODER_HXX
#define CDECODER_HXX

#include "Encoder.hxx"

class CDecoder
{
public:
    unsigned getBits(const unsigneds_vec& c_vBuf) const;
    explicit CDecoder(const unsigned c_uParam);
private:
    unsigned m_uParam;
};

#endif // CDECODER_HXX
