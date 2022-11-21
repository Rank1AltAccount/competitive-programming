global whichIsLarger

section .text
; eax int whichIsLarger(edi int a, esi int b)
whichIsLarger:
    cmp		edi, esi	; Compare the two arguments
    jb		.isBelow	; Jump to .isBelow if edi < esi
    mov		eax, edi	; If not, return edi. This will be correct even if the arguments are equal
    ret

    .isBelow:
    mov		eax, esi	; Return esi instead of edi
    ret
