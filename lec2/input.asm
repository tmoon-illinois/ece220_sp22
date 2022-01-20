.ORIG x3000


                        ; R1 <- KBSR
                        ; R1 <- mem[FE00]
                        ; R1 <- mem[mem[KBSR_Addr]]
POLL
    LDI     R1, KBSR_Addr
    BRzp    POLL
    LDI     R0, KBDR_Addr

    HALT



KBSR_Addr .FILL xFE00
KBDR_Addr .FILL xFE02
.END
