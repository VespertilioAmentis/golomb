#ifndef CENCODER_HXX
#define CENCODER_HXX

#include <queue>
typedef std::queue<int> ints_que;

class CEncoder
{
public:
    void putbits(const int c_iBit);
    const ints_que& getBuf() const;
    CEncoder();

private:
    ints_que m_queBuf;
};

#endif // CENCODER_HXX
