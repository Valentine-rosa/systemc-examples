#include <systemc.h>
#include "dff.h"

SC_MODULE (shift_reg) {
	sc_in <bool> shiftclk;
	sc_in <bool> regin;
	sc_out <bool> regout;
	sc_signal<bool> s_dff2,s_dff1,s_dff3;
	

	void shift_reg_method(void);
	void shift_reg_method2(void);
	~shift_reg();

	SC_CTOR (shift_reg) {
	dff dff1("dff1");
	dff dff2("dff2");
	dff dff3("dff3");
	dff dff4("dff4");
	
		SC_METHOD (shift_reg_method2);
		dont_initialize();
		SC_METHOD (shift_reg_method);
			sensitive_pos << shiftclk;
		
	}
};
