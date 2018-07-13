#include<systemc.h>

SC_MODULE(inverter_gate){
//input and output ports
	sc_in<bool> a;
	sc_out<bool> b;

	void inv(void);
	~inverter_gate();


SC_CTOR(inverter_gate){   //constructor: where the processes are bound to simulation kernel
	SC_METHOD(inv);
	sensitive << a ;
	
	}

};

