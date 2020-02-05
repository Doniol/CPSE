.cpu cortex-m0 
.bss
	channel: .fill 0x28
.text 
.align 2 
.global decoder

decoder:
	push {lr} 					@; push lr for ending this subroutine later on
	ldr	r3, =channel			@; channel 40 bytes long
	ldr	r4, =compressed			@; pointer to compressed
	mov	r5, #0					@; index
	mov	r6, #0					@; offset
	mov	r7, #0					@; length
	
main_loop:
	ldrb r0, [r4, r5]			@; put char in r0
	add r5, #1					@; index++
	cmp r0, #0					@; end subroutine when \0, the file has ended
	beq	done
	
	cmp r0, #'@'				@; check if r0, the character, is @ to start decompressing subroutine
	beq	decompress				@; branch to decompression
	bl queue					@; queue characters
	bl uart_put_char			@; print char
	b main_loop					@; loop
	
decompress:
	ldrb r6, [r4, r5]			@; load memory adress into r6
	add r5, #1					@; index++
	ldrb r7, [r4, r5]			@; load memory adress into r7
	add r5, #1					@; index++
	sub r6, #'0'				@; reset offset
	sub r7, #'0'				@; reset length
	
decompress_loop:
	ldrb r0, [r3, r6]			@; load memory into r0
	bl queue					@; bl to queue subroutine
	bl uart_put_char			@; print char
	sub	r7, #1					@; length--
	beq main_loop				@; check r7 == 1 if true compression of this part is finished
	b decompress_loop			@; loop
	
queue:
	push {lr}
	mov r1, #39					@; set queue length in r1

queue_move:
	sub r1, #1 					@; index--
	ldrb r2, [r3, r1] 			@; load memory into r2
	add r1, #1					@; r++
	strb r2, [r3, r1]			@; store character in r3 with index r1 into r2
	sub r1, #1					@; sub 1 from r1

	cmp r1, #0					@; compare r1 with 0
	beq queue_done				@; branch if equal
	b queue_move				@; loop
	
queue_done:
	strb r0, [r3, #0]			@; load char
	pop {pc}	
	
done:
	pop {pc} 					@; pop!