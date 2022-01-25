	.ORIG	x3000
	LEA	R3,Binary
	LD	R6,ASCII
	LD	R7,COUNT
AGAIN	
        ST      R7, SAVE_R7 ; save counter in R7
	TRAP	x23
        LD      R7, SAVE_R7 ; restore counter from R7
	ADD	R0,R0,R6
	STR	R0,R3,#0
	ADD	R3,R3,#1
	ADD	R7,R7,#-1
	BRp	AGAIN
        HALT
ASCII	.FILL	#-48
COUNT	.FILL	#3
SAVE_R7 .BLKW   #1
Binary	.BLKW	#3
	.END
