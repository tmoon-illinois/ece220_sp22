.ORIG x3000


            ; R1 <- DSR
            ; R1 <- mem[FE04]
            ; R1 <- mem[mem[_Addr]]
    LD      R0, MyChar
POLL
    LDI     R1, DSR_Addr
    BRzp    POLL
    STI     R0, DDR_Addr

    HALT


MyChar      .FILL x45
DSR_Addr .FILL xFE04
DDR_Addr .FILL xFE06
.END
