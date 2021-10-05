#include "stimuli.h"

stimuli::stimuli(const sc_module_name &name) : sc_module(name)
{
    sequence = "CAAGATGCCATTGTCCCCCGGCCTCCTGCTGCTGCTGCTCTCCGGG"
               "GCCACGGCCACCGCTGCCCTGCCCCTGGAGGGTGGCCCCACCGGCC"
               "GAGACAGCGAGCATATGCAGGAAAGCGGCAGGAATAAGGAAAAGCA"
               "GCCTCCTGACTTTCCTCGCTTGGTGGTTTGAGTGGACCTCCCAGGC"
               "CAGTGCCGGGCCCCTCATAGGAGAGGAAGCTCGGGAGGTGGCCAGG"
               "CGGCAGGAAGGCGCACCCCCCCAGCAATCCGCGCGCCGGGACAGAA"
               "TGCCCTGCAGGAACTTCTTCTGGAAGACCTTCTCCTCCTGCAAATA"
               "AAACCTCACCCATGAATGCTCACGCAAGTTTAATTACAGACCTGAA";

    counter = 0;
    SC_METHOD(process);
    sensitive << clk.pos();
}

void stimuli::process()
{
    if (counter <= sequence.length())
    {
        std::string data = sequence.substr(counter, 1);
        output.write(data.c_str()[0]);
        counter++;
    }
    else
    {
        sc_stop();
    }
}
