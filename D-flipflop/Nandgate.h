#include<systemc.h>

SC_MODULE(Nand_gate){
//input and output ports
	sc_in<bool> a,b;
	sc_out<bool> c;
	

	void nand(void);
	~Nand_gate();


SC_CTOR(Nand_gate){   //constructor: where the processes are bound to simulation kernel
	SC_METHOD(nand);
	sensitive <<a <<b;
	
	}

};





