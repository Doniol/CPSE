.cpu cortex-m0 
.bss
	channel: .fill 0x28
.text 
.align 2 
.global decoder

decoder:
	push {lr} 					@; Push lr for ending this subroutine later on
	ldr	r3, =channel			@; Channel 40 bytes long
	ldr	r4, =compressed			@; Pointer to compressed
	mov	r5, #0					@; Index
	mov	r6, #0					@; Offset
	mov	r7, #0					@; Length
	
main_loop:
	ldrb r0, [r4, r5]			@; Put char in r0
	add r5, #1					@; Index++
	cmp r0, #0					@; End subroutine when \0
	beq	done
	
	cmp r0, #'@'				@; Check if the last character is @ to start decompressing subroutine
	beq	decompress				@; Branch to decompress
	bl queue						@; Queueing the channel
	bl uart_put_char			@; Print char
	b main_loop					@; Loop
	
decompress:
	ldrb r6, [r4, r5]			@; Load memory adress into r6
	add r5, #1					@; Index++
	ldrb r7, [r4, r5]			@; Load memory adress into r7
	add r5, #1					@; Index++
	sub r6, #'0'				@; -48
	sub r7, #'0'				@; -48
	
decompressLoop:
	ldrb r0, [r3, r6]			@; Load memory into r0
	bl queue						@; bl to queue subroutine
	bl uart_put_char			@; Print char
	sub	r7, #1					@; Length--
	beq main_loop				@; Check r7 == 1 if true compression of this part is finished
	b decompressLoop			@; Loop
	
queue:
	push {lr}
	mov r1, #39					@; Set queue length in r1

queue_move:
	sub r1, #1 					@; Index--
	ldrb r2, [r3, r1] 			@; Load memory into r2
	add r1, #1					@; r++
	strb r2, [r3, r1]			@; Store characterin r3 with index r1 into r2
	sub r1, #1					@; Sub 1 from r1

	cmp r1, #0					@; Compare r1 with 0
	beq queue_done					@; Branch if equal
	b queue_move					@; Loop
	
queue_done:
	strb r0, [r3, #0]			@; Load char
	pop {pc}	
	
done:
	pop {pc} 					@; End the function