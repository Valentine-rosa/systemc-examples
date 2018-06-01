#ifndef INVERTER_GATE_H_
#define INVERTER_GATE_H_
#include<systemc.h>

SC_MODULE(inverter_gate){
//input and output ports

sc_in<bool> a;
sc_out<bool> b,c;


//constructor: where the processes are bound to simulation kernel
SC_CTOR(inverter_gate){
	SC_METHOD(gate);
	sensitive << a ;
	//dont_initialize();
}

~inverter_gate(){
//delete stuff :P
}

void gate(void){
	b = !a;
        c=a;
}
};




#endif /* INVERTER_GATE_H_ */
