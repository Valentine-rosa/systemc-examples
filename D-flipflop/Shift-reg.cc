#include "Shift-reg.h"

void shift_reg:: shift_reg_method (void){
	
	//din1=regin;

shift_reg_method2();
}
void shift_reg:: shift_reg_method2(void){
	/*dff dff1("dff1");
	dff dff2("dff2");
	dff dff3("dff3");
	dff dff4("dff4");*/
	
	dff1.din(regin);
	dff1.dout(s_dff1);
	dff2.din(s_dff1);
	dff2.dout(s_dff2);
	dff3.din(s_dff2);
	dff3.dout(s_dff3);
	dff4.din(s_dff3);
	dff4.dout(regout);

	dff1.clk(shiftclk);
	dff2.clk(shiftclk);
	dff3.clk(shiftclk);
	dff4.clk(shiftclk);
	
}

shift_reg:: ~shift_reg(){
	//delete gt1;
}
