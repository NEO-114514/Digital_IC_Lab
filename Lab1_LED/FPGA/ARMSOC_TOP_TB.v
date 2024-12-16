`timescale 1ns / 100ps

module ARMSOC_TOP_TB ();

reg     CLK,
        RESET;

reg     [7:0] KEY;

wire    [7:0] LED;



ARMSOC_TOP U1(
    .CLK(CLK),
    .RESET(RESET),
    .LED(LED),
    .KEY(KEY)
);

always #5 CLK <= ~CLK;
always #50000 KEY[0] <= ~KEY[0];

initial 
begin
    CLK = 1'b0;
 	RESET = 1'b1;
    KEY = 8'b0000_0000;
    #55 RESET = 1'b0;
 	#45 RESET = 1'b1;
    #1000000000
    #1000000000 $stop;
end

endmodule


