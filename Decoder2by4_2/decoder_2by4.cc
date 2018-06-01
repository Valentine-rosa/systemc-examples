#include"decoder_1by2.h"
#include"andgate.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> de_in1,de_in2,Ag_in1,Ag_in2,Ag_in3,Ag_in4,d_out1,d_out2,d_out3,d_out4;
//MODULE INSTANCES
//decoder instanes
decoder dec1_1("decoder1by2_1");
decoder dec1_2("decoder1by2_2");
//driver instance
driver dr("driver");
//monitor instance
monitor mn("monitor");
//andgate instances
and_gate AG_1("gate_instance_1");
and_gate AG_2("gate_instance_2");
and_gate AG_3("gate_instance_3");
and_gate AG_4("gate_instance_4");

//interconnections b2in modules
//driver interconnections
dr.d_a(de_in1);
dr.d_b(de_in2);
//decoder interconnections
dec1_1.a(de_in1);
dec1_2.a(de_in2);
dec1_1.b(Ag_in1);
dec1_2.b(Ag_in3);
dec1_1.c(Ag_in2);
dec1_2.c(Ag_in4);
//monitor interconnections
mn.m_c(d_out1);
mn.m_d(d_out2);
mn.m_e(d_out3);
mn.m_f(d_out4);
//andgates interconnection
AG_1.a(Ag_in1);
AG_1.b(Ag_in3);
AG_1.c(d_out1);

AG_2.a(Ag_in1);
AG_2.b(Ag_in4);
AG_2.c(d_out2);

AG_3.a(Ag_in2);
AG_3.b(Ag_in3);
AG_3.c(d_out3);

AG_4.a(Ag_in2);
AG_4.b(Ag_in4);
AG_4.c(d_out4);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, de_in1, "binary_input1"); // signals to be traced
sc_trace(tf, de_in2, "binary_input2"); 
sc_trace(tf, d_out1, "d_out1");
sc_trace(tf, d_out2, "d_out2");
sc_trace(tf, d_out3, "d_out3");
sc_trace(tf, d_out4, "d_out4");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(25,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}

