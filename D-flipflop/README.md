# systemc-examples
This is a D Flip-flop and shift register example, which is a makefile project. 
Just cd into this folder and run the command 

    make all


A Flip-flop or latch is a cicuit that has two stable states and can be used to store state information.<br>
It is called the D Flip-flop because the output Q always takes on the state of the D input at the moment of a rising clock edge.
A simple shift register can be made using only D type Flip-flops, one flip-flop for each data bit. <br>
It is a arranged ia a way that an output from one flip-flop is connected to the input of another.
Shift registers hold the data in their memory which is shifted or moved to their required positions on each clock pulse. <br>
Its truth table: 
<p align="left">
  <img src="Images/TRuth table.png" width="250"/>
</p>

### Circuit:
<p align="left">
  <img src="Images/SIPO_4-bit_shift_register.gif" width="200"/>
</p>

### Model of computation:
<p align="left">
  <img src="Images/D Flip-flopMoC.png" width="400"/>
</p>

### Results:
The above MOC was implemented in systemc (code in this folder) and was able to run successfully .<br>



