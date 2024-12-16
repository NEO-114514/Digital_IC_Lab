`timescale 1ns / 1ns

module ARMSOC_TOP_TB ();

reg     CLK,
        RESET;

wire    [2:0] VGA_RED;
wire    [2:0] VGA_GREEN;
wire    [1:0] VGA_BLUE;
wire          VGA_HSYNC;            // VGA Horizontal Sync
wire          VGA_VSYNC;            // VGA Vertical Sync

reg           UART_RXD;             // 输入到 DUT 的串口信号
wire          UART_TXD;             // 从 DUT 输出的串口信号

// DUT 实例化
ARMSOC_TOP U1(
    .CLK(CLK),
    .RESET(RESET),
    .VGA_RED(VGA_RED),
    .VGA_GREEN(VGA_GREEN),
    .VGA_BLUE(VGA_BLUE),
    .VGA_HSYNC(VGA_HSYNC),
    .VGA_VSYNC(VGA_VSYNC),

    .UART_RXD(UART_RXD),
    .UART_TXD(UART_TXD)
);

// 时钟周期 10ns，对应 100MHz 时钟
always #5 CLK <= ~CLK;

// 初始化过程
initial 
begin
    CLK = 1'b1;
    RESET = 1'b1;
    UART_RXD = 1'b1; // 默认空闲状态为高电平
    
    // 复位过程
    #55 RESET = 1'b0;
    #45 RESET = 1'b1;

    // 延时后开始发送字符 'A'
    #100000; // 等待系统稳定
    send_uart_char(8'h41); // ASCII 'A'

    // 停止仿真
    #100000000;
    $stop;
end

// 模拟发送 UART 字符
task send_uart_char(input [7:0] data);
    integer i;
    begin
        // 起始位：低电平
        UART_RXD = 1'b0;
        #(52083); // 1 位持续时间

        // 数据位：低位在前，逐位发送
        for (i = 0; i < 8; i = i + 1) begin
            UART_RXD = data[i];
            #(52083); // 1 位持续时间
        end
        UART_RXD = 1'b1;
        #(52083);
        // 停止位：高电平
        UART_RXD = 1'b1;
        #(52083); // 1 位持续时间
    end
endtask

endmodule
