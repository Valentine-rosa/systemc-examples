#include "dff.h"

void dff:: dff_method (void){
	dout=din;
}
void dff:: dff_method2(void){
	inverter_gate inv("inverter_gate");
	Nand_gate nand1("Nand_gate1");
	Nand_gate nand2("Nand_gate2");
	Nand_gate nand3("Nand_gate3");
	Nand_gate nand4("Nand_gate4");
	
	nand1.a(s_din);
	nand1.b(clk);
	nand2.a(clk);
	nand2.b(inv_out);
	
	inv.a(s_din);
	inv.b(inv_out);
	nand3.a(nand1_out);
	nand3.b(nand4_out);
	
	nand4.a(s_dout);
	nand4.b(nand2_out);
	nand1.c(nand1_out);
	nand2.c(nand2_out);

	nand3.c(s_dout);
	nand4.c(nand4_out);	
}

dff:: ~dff(){
	//delete gt1;
}
