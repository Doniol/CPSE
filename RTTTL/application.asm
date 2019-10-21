.cpu cortex-m0
.data
string:
    .asciz "Comrade!!"

.text
.align 1
.global application

application:
    LDR R0, =string
    BL print_asciz