;------------------------------------------------------------------------------------------------------
; Module4: A Simple SoC Application
; Toggle LEDs at a given frequency. 
;------------------------------------------------------------------------------------------------------



; Vector Table Mapped to Address 0 at Reset

                PRESERVE8
                THUMB

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     0x0000FFFC                ; 32K Internal Memory
                DCD     Reset_Handler             ; Reset Handler
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0

                ; External Interrupts
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0
                DCD     0

                AREA    |.text|, CODE, READONLY

; Reset Handler

Reset_Handler   PROC
                GLOBAL  Reset_Handler
                
				
				
				LDR     R1, =0x50000004           ; Write to Mask with value 0xF0
                LDR     R0, =0x00
                STR     R0, [R1]
				
                ENTRY
				
AGAIN
				LDR R0, =0x51000010       ; 将地址0x51000010加载到R0寄存器
				LDR R1, [R0]             ; 从R0指向的地址读取数据到R1寄存器

				LDR R2, =0x00000001            ; 将立即数0x01加载到R2寄存器
				CMP R1, R2               ; 比较R1和R2的值
				BEQ EqualToOne           ; 如果相等（Z标志为1），跳转到EqualToOne

				LDR R2, =0x00000000            ; 将立即数0x03加载到R2寄存器
				CMP R1, R2               ; 比较R1和R2的值
				BEQ EqualToThree         ; 如果相等（Z标志为1），跳转到EqualToThree
				
EqualToOne
                LDR     R1, =0x50000000           ; Write to LED with value 0xAA
                LDR     R0, =0xAA
                STR     R0, [R1]
                B AGAIN

EqualToThree
                LDR     R1, =0x50000000           ; Write to LED with value 0xAA
                LDR     R0, =0x55
                STR     R0, [R1]
                B AGAIN  
		   

				
                ENDP

                ALIGN

                END
