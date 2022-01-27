	.ORIG	x3000
	;User program
        IN
        JSR PUSH
        IN
        JSR PUSH
        IN
        JSR PUSH
        IN
        JSR PUSH
        IN  
        JSR PUSH   ;<-- cause overflow

        JSR POP
        OUT
        JSR POP
        OUT

	HALT
;PUSH subroutine
;IN: R0 (value)
;OUT: R5(0-success, 1-fail)
;R3: STACK_END
;R6: STACK_TOP
PUSH
;callee-save & initialize registers
        ST      R3, SAVE_R3
        ST      R6, SAVE_R6
        AND     R5, R5, #0
        LD      R3, STACK_END
        LD      R6, STACK_TOP
;overflow?
;Check if STACK_TOP = STACK_END - 1
;Or check if STACK_TOP - (STACK_END - 1) = 0
        ADD     R3, R3, #-1
        NOT     R3, R3
        ADD     R3, R3, #1 ; <--   -(STACK_END -1)
        ADD     R3, R6, R3 ; 
        BRz     OVERFLOW
;it is NOT overflow
        STR     R0, R6, #0
        ADD     R6, R6, #-1
        ST      R6, STACK_TOP
        BRnzp   DONE_PUSH
;it is overflow
OVERFLOW
        ADD     R5, R5, #1
;restore registers
DONE_PUSH 
        LD      R6, SAVE_R6
        LD      R3, SAVE_R3
        RET



;POP subroutine
;IN: none
;OUT: R0 (value)
;OUT: R5 (0: success, 1: fail)
;R3: STACK_START
;R6: STACK_TOP
POP
;callee-save & initialize registers
        ST      R3, SAVE_R3
        ST      R6, SAVE_R6
        AND     R5, R5, #0
        LD      R3, STACK_START
        LD      R6, STACK_TOP

;underflow?
;Check if STACK_TOP = STACK_START
;Or check if STACK_TOP - STACK_START = 0
        NOT     R3, R3
        ADD     R3, R3, #1 ; <-- -STACK_START
        ADD     R3, R6, R3
        BRz     UNDERFLOW

;it is NOT underflow
        ADD     R6, R6, #1
        LDR     R0, R6, #0
        ST      R6, STACK_TOP
        BRnzp   DONE_POP
;it is underflow
UNDERFLOW
        ADD     R5, R5, #1
;restore registers
DONE_POP
        LD      R6, SAVE_R6
        LD      R3, SAVE_R3
        RET


;temp memory
Save_R3	.BLKW	#1
Save_R6	.BLKW	#1
STACK_END	.FILL	x3FFD
STACK_START	.FILL	x4000	
STACK_TOP	.FILL	x4000
	.END
;x3FFE  <---STACK_END
;x3FFE
;x3FFF
;x4000  <---STACK_START



