#include <systemc.h>
#include "driver.h"
#include "monitor.h"
#include "Shift-reg.h"


int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_din, s_dout;
	sc_clock clock("clk",5,SC_NS,0.5);

	//dff dff1("dff");
	driver dr("driver");
	monitor mon("monitor");
	shift_reg reg("shift_register");
	/*inverter_gate inv("inverter_gate");
	Nand_gate nand1("Nand_gate1");
	Nand_gate nand2("Nand_gate2");
	Nand_gate nand3("Nand_gate3");
	Nand_gate nand4("Nand_gate4");*/
	
	reg.regin(s_din);
	reg.shiftclk(clock);
	reg.regout(s_dout);
	dr.d_din(s_din);
	//dff1.din(s_din);
	mon.m_din(s_din);
	
	//dff1.dout(s_dout);
	mon.m_dout(s_dout);
	//dff1.clk(clock);

	/*nand1.a(s_din);
	nand1.b(clock);
	nand2.a(clock);
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
	nand4.c(nand4_out);*/	

	//sc_trace_file *fp;
	//fp=sc_create_vcd_trace_file("vcd_trace");
	//fp->set_time_unit(1, SC_NS);
	//sc_trace(fp, s_din, "binary_input"); // signals to be traced
	//sc_trace(fp, s_dout, "input_is_zero");
	if( !sc_pending_activity() )
		sc_start(20, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
