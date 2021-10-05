#ifndef STIMULI_H
#define STIMULI_H

#include <string>
#include <systemc.h>

SC_MODULE(stimuli)
{
public:
    sc_in<bool> clk;
    sc_out<char> output;
    SC_HAS_PROCESS(stimuli);   
    stimuli(const sc_module_name &name);

private:
    std::string sequence;
    void process();
    unsigned int counter;
};

#endif // STIMULI_H
