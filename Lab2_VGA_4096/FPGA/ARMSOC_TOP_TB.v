`timescale 1ns / 1ns

module ARMSOC_TOP_TB ();

reg     CLK,
        RESET;

wire    [2:0] VGA_RED;
wire    [2:0] VGA_GREEN;
wire    [1:0] VGA_BLUE;
wire          VGA_HSYNC;            // VGA Horizontal Sync
wire          VGA_VSYNC;            // VGA Vertical Sync


ARMSOC_TOP U1(
    .CLK(CLK),
    .RESET(RESET),
    .VGA_RED(VGA_RED),
    .VGA_GREEN(VGA_GREEN),
    .VGA_BLUE(VGA_BLUE),
    .VGA_HSYNC(VGA_HSYNC),
    .VGA_VSYNC(VGA_VSYNC)
);

always #5 CLK <= ~CLK;

initial 
begin
    CLK = 1'b1;
 	RESET = 1'b1;
    
    #55 RESET = 1'b0;
 	#45 RESET = 1'b1;
    #1000000000
    #1000000000 $stop;
end

endmodule


