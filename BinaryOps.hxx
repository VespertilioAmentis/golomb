#ifndef BINARYOPS_HXX
#define BINARYOPS_HXX

#include <vector>

typedef std::vector<unsigned> unsigneds_vec;

//==

unsigneds_vec toUnary(const unsigned c_uNum);
unsigneds_vec toBinary(const unsigned c_uNum, const unsigned c_uLen);

//==

unsigned fromUnary(const unsigneds_vec& c_vBuf);
unsigned fromBinary(const unsigneds_vec& c_vBuf, const unsigned c_uPos,
                    const unsigned c_uLen);
#endif // BINARYOPS_HXX
