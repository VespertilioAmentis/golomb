#include <iostream>
#include <algorithm>
#include <iterator>

#include "GeomDistr.hxx"
#include "Encoder.hxx"

int main()
{
    CEncoder encoder(4);
    encoder.putbits(9);
    const unsigneds_vec& c_vBuf = encoder.getBuf();

    std::copy(c_vBuf.begin(), c_vBuf.end(),
                std::ostream_iterator<unsigned>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
