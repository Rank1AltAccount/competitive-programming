global clamp

section .text
; rax uint64_t clamp(rdi uint64_t a, rsi uint64_t lo, rdx uint64_t hi)
clamp:
    ; Return a
    mov		rax, rdi

    ; If a < lo return lo
    cmp		rdi, rsi
    cmovb	rax, rsi

    ; If hi < a return hi
    cmp		rdx, rdi
    cmovb	rax, rdx

    ret

