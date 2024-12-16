;------------------------------------------------------------------------------------------------------
; Design and Implementation of an AHB VGA Peripheral
; 1)Display text string: "TEST" on VGA. 
; 2)Change the color of the four corners of the image region.
;------------------------------------------------------------------------------------------------------

; Vector Table Mapped to Address 0 at Reset

;                PRESERVE8
;                THUMB

;                AREA    RESET, DATA, READONLY
;                EXPORT  __Vectors

;__Vectors       DCD     0x00007FFC
;                DCD     Reset_Handler             ; Reset Handler
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0

;                ; External Interrupts
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0
;                DCD     0

;                AREA    |.text|, CODE, READONLY

;; Reset Handler

;Reset_Handler   PROC
;                GLOBAL  Reset_Handler
;                ENTRY
;                
;; Write "TEST" to the text console
;                LDR     R1, =0x50000000
;                MOVS    R0, #' '
;                STR     R0, [R1]

;                LDR     R1, =0x50000000
;                MOVS    R0, #'T'
;                STR     R0, [R1]

;                LDR     R1, =0x50000000
;                MOVS    R0, #'E'
;                STR     R0, [R1]

;                LDR     R1, =0x50000000
;                MOVS    R0, #'S'
;                STR     R0, [R1]
;                
;                LDR     R1, =0x50000000
;                MOVS    R0, #'T'
;                STR     R0, [R1]

;; Write four white dots to four corners of the frame buffer

;                LDR     R1, =0x50000004
;                LDR     R0, =0xFF
;                STR     R0, [R1]

;                LDR     R1, =0x50000190
;                LDR     R0, =0xFF
;                STR     R0, [R1]
;        
;                LDR     R1, =0x5000EE04
;                LDR     R0, =0xFF
;                STR     R0, [R1]

;                LDR     R1, =0x5000EF90
;                LDR     R0, =0xFF
;                STR     R0, [R1]
;                
;AGAIN                      
;                B       AGAIN

;                ENDP

;                ALIGN   4                       ; Align to a word boundary

;                END



Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


Heap_Size       EQU     0x00000C00

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


; Vector Table Mapped to Address 0 at Reset

                PRESERVE8
                THUMB

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp              ; Top of Stack
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
                EXPORT  Reset_Handler
                ENTRY
                IMPORT  __main
                LDR     R0, =__main
                BX      R0                  ; Branch to __main
                ENDP

                ALIGN   4                   ; Align to a word boundary


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
