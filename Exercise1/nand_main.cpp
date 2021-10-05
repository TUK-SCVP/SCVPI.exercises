#include <systemc.h>
#include "nand.h"

SC_MODULE(toplevel)
{
public:
    SC_CTOR(toplevel) : n1("n1"), cnt(0)
    {
        n1.A.bind(A);
        n1.B.bind(B);
        n1.Z.bind(Z);

        SC_METHOD(process);
        sensitive << A << B << Z;
    }

private:
    nand n1;
    unsigned int cnt;

    sc_signal<bool> A;
    sc_signal<bool> B;
    sc_signal<bool> Z;

    void process()
    {
        // REMEMBER, a process runs once during the initialization phase
        // (unless the function dont_initialize() is used to avoid it). Later
        // it will triggered by events in the sensitivity list.

        // Every time a METHOD process is triggered it executes from the
        // beginning to the end. Therefore, two messages will be printed when
        // this process is executed.

        // Keep in mind that this METHOD process is sensitive to changes in
        // signals A, B and Z.

        // This counter counts the number of times this function is called. In
        // other words, it counts the number of times the METHOD process is
        // executed.
        cnt++;

        // Here both signals A and B are set to false.
        // Question:
        //  - Does this action make any difference? Why?
        // First test with the next two lines of code enabled.
        // In a second moment comment out the next two lines of code and see
        // what happens.
        A.write(false);
        B.write(false);

        // This is the first message that is printed when the process is
        // executed.
        std::cout << "SC_METHOD process() trigger counter " << cnt << " simulation time " << sc_time_stamp().to_default_time_units() << " ps Δ cycle " << sc_delta_count() << ":\tA " << (A.read() ? "'1'" : "'0'") << " B " << (B.read() ? "'1'" : "'0'") << " Z " << (Z.read() ? "'1'" : "'0'") << std::endl;

        // Here both signals A and B are set to true.
        A.write(true);
        B.write(true);

        // This is the second message that is printed when the process is
        // executed.
        std::cout << "SC_METHOD process() trigger counter " << cnt << " simulation time " << sc_time_stamp().to_default_time_units() << " ps Δ cycle " << sc_delta_count() << ":\tA " << (A.read() ? "'1'" : "'0'") << " B " << (B.read() ? "'1'" : "'0'") << " Z " << (Z.read() ? "'1'" : "'0'") << std::endl;

        // Uncomment the lines below where signals A and B are modified.
        // Check the output messages in the terminal and try to understand
        // what is going on.
        // Questions:
        //  - How these writes to A and B affect Z?
        //  - Is the process triggered when Z changes?
        //  - Are some of the writes to A and B ignored?

        //A.write(false);
        //B.write(false);
        //A.write(true);
        //B.write(false);
        //A.write(false);
        //B.write(true);

        // Print a new line
        std::cout << std::endl;
    }
};

int sc_main(int, char**)
{
    // The toplevel module is instantiated here. Its constructor will be
    // called.
    toplevel top("toplevel");

    // Simulation starts here.
    sc_start();

    // Return zero after the end of the simulation.
    return 0;
}

