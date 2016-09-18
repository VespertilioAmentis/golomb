#ifndef CENCODER_HXX
#define CENCODER_HXX

#include <vector>

typedef std::vector<unsigned> unsigneds_vec;

class CEncoder
{
public:
    void putbits(const unsigned c_uN);
    const unsigneds_vec &getBuf() const;
    explicit CEncoder(const unsigned c_uM);

private:
    const unsigned mc_uM;
    unsigneds_vec m_vBuf;
};

#endif // CENCODER_HXX
