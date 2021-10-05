#include <iostream>
#include <systemc.h>

#include "state_machine.h"
#include "stimuli.h"

int sc_main(int, char**)
{
    stateMachine genomeParser("genomeParser");
    stimuli genomeInput("genomeInput");
    sc_clock clk("clk", sc_time(1, SC_NS));

    sc_signal<char> h1;

    genomeParser.input.bind(h1);
    genomeInput.output.bind(h1);
    genomeParser.clk.bind(clk);
    genomeInput.clk.bind(clk);

    sc_start();

    return 0;
}
