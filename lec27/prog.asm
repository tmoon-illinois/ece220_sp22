        .ORIG   x3000
        ;main
        LD      R6, STACK
        ADD     R5, R6, #0

        ; =============== RUN-TIME STACK ===================
        ; int rBST <- R6 (by callee-build up)
        ; int lBST <- new R5 (by callee-build up)
        ; caller's frame pointer (old R5)
        ; return addr (R7)
        ; return val  <- R6 will point here, just after "JSR ISBST"
        ; node <- R6 (by caller-build up)
        ; min
        ; max (arguments of isBST (3 mem))
        ; int flag <- R5, R6 (main)
        ; book-keeping info (main)
        ; =============== RUN-TIME STACK ===================
        ; BST example
        ;    10
        ;   / \
        ;  3  15
        ; / \
        ;1   4
        ; hardcode local variables of main
        ; int max = 15 (R0)
        ; int min = 1 (R1) 
        ; node *root = x7000 (R2)
        LD      R0, MAX
        LD      R1, MIN
        LD      R2, ROOT
        ; caller-build up (push max, min, root)
        ADD     R6, R6, #-1
        STR     R0, R6, #0
        ADD     R6, R6, #-1
        STR     R1, R6, #0
        ADD     R6, R6, #-1
        STR     R2, R6, #0
        ; call ISBST
        JSR     ISBST
        LDR     R3, R6, #0  ; R3<-mem[R6]
        STR     R3, R5, #0  ; R3->mem[R5], sum = isBST(...);
        ADD     R6, R6, #2
        LDR     R0, R5, #0  ; R0<-mem[R5]
        ;OUT
        HALT

; int isBST(t_node *node, int min, int max){
;   int lBST;
;   int rBST;
;   if(node == NULL)
;      return 1;
;   if(node->val < min || node->val > max)
;      return 0;
;   lBST = isBST(node->left, min, node->val);
;   rBST = isBST(node->right, node->val, max);
;   return lBST && rBST;
;}
ISBST
        ;callee build up
        ADD     R6, R6, #-5
        STR     R7, R6, #3
        STR     R5, R6, #2
        ADD     R5, R6, #1
        ;   if(node == NULL)
        AND     R4, R4, #0
        ADD     R4, R4, #1  ; R4 <= 1 for return 1
        LDR     R0, R5, #4  ; R0 <= node
        BRz     TEARDOWN
        ;   if(node->val < min || node->val > max)
        AND     R4, R4, #0  ; R4 <= 0 for return 0
        LDR     R1, R0, #2  ; R1 <= node->val
        LDR     R2, R5, #5  ; R2 <= min
        NOT     R2, R2
        ADD     R2, R2, #1  ; R2 <= -min
        ADD     R2, R1, R2  ; R2 <= node->val - min
        BRn     TEARDOWN
        LDR     R2, R5, #6  ; R2 <= max
        NOT     R2, R2
        ADD     R2, R2, #1  ; R2 <= -max
        ADD     R2, R1, R2  ; R2 <= node->val - max
        BRp     TEARDOWN
        ;   lBST = isBST(node->left, min, node->val);
        ; node->left <-R6
        ; min
        ; node->val
        ; caller build up (push arguments)
        ADD     R6, R6, #-3
        STR     R1, R6, #2 ; pushing node->val
        LDR     R2, R5, #5  ; R2 <= min
        STR     R2, R6, #1 ; pushing min
        LDR     R3, R0, #0  ; R3 <= node->left
        STR     R3, R6, #0  ;pushing node->left
        JSR     ISBST       ;after this, R6 points return val
        ; caller tear down
        LDR     R3, R6, #0  ; R3 <= return val
        STR     R3, R5, #0  ; lBST <= R3
        ADD     R6, R6, #4
        ;   rBST = isBST(node->right, node->val, max);
        ; node->right <-R6
        ; node->val
        ; max 
        ; caller build up (push arguments)
        ADD     R6, R6, #-3
        LDR     R2, R5, #6  ; R2 <= max
        STR     R2, R6, #2  ; pushing max
        LDR     R0, R5, #4  ; !!!! reload R0 <= node !!!!
        LDR     R2, R0, #2  ; R2 <= node->val
        STR     R2, R6, #1  ; pushing node->val
        ;LDR     R2, R2, #1  ; This was the BUG!!!!! The next line is the correct one
        LDR     R2, R0, #1  ; R2 <= node->right
        STR     R2, R6, #0  ; pushing node->right
        JSR     ISBST       ;after this, R6 points return val
        ; caller tear down
        LDR     R3, R6, #0  ; R3 <= return val
        STR     R3, R5, #-1  ; rBST <= R3
        ADD     R6, R6, #4
        ;   return lBST && rBST;
        LDR     R2, R5, #0  ; R2 <= lBST
        AND     R4, R2, R3  ; R4 = lBST & rBST
TEARDOWN
        STR     R4, R5, #3  ; R4 => return val 
        LDR     R7, R5, #2  ; recover R7 to return addr
        LDR     R5, R5, #1  ; recover R5
        ADD     R6, R6, #4  ; set R6 to return val
        RET
        

STACK   .FILL   x6000
MAX     .FILL   #15
MIN     .FILL   #1
ROOT    .FILL   x7000
        .END
