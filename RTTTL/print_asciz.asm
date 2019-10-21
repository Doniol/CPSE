.cpu cortex-m0
.text
.align 1
.global print_asciz

print_asciz:
    PUSH {R4, LR}
    MOV R4, R0
loop:
    LDRB R0, [R4]
    ADD R0, R0, #0
    BEQ end
    BL uart_put_char
    ADD R4, R4, #1
    B loop
end:
    POP {R4, PC}
