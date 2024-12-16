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
				LDR R0, =0x51000010       ; ����ַ0x51000010���ص�R0�Ĵ���
				LDR R1, [R0]             ; ��R0ָ��ĵ�ַ��ȡ���ݵ�R1�Ĵ���

				LDR R2, =0x00000001            ; ��������0x01���ص�R2�Ĵ���
				CMP R1, R2               ; �Ƚ�R1��R2��ֵ
				BEQ EqualToOne           ; �����ȣ�Z��־Ϊ1������ת��EqualToOne

				LDR R2, =0x00000000            ; ��������0x03���ص�R2�Ĵ���
				CMP R1, R2               ; �Ƚ�R1��R2��ֵ
				BEQ EqualToThree         ; �����ȣ�Z��־Ϊ1������ת��EqualToThree
				
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
