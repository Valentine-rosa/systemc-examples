#include <systemc.h>
#include "Nandgate.h"
#include "inverter.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;
	sc_signal<bool> s_din, s_dout, nand1_out, nand2_out, nand4_out, inv_out;
	

	void dff_method(void);
	void dff_method2(void);
	~dff();

	SC_CTOR (dff) {
		SC_METHOD (dff_method2);
		dont_initialize();
		SC_METHOD (dff_method);
			sensitive_pos << clk;
		
	}
};
