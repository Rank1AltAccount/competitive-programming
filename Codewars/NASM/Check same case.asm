global samecase

; Letter ranges from ASCII table (inclusive)
%define UPPERCASE_START	65
%define UPPERCASE_END	90
%define LOWERCASE_START	97
%define LOWERCASE_END	122 

section .text    
; eax int samecase(dil char a, sil char b)
samecase:
    ; Check if a and b are letters
    cmp		dil, UPPERCASE_START
    jb		.notLetters
    cmp		dil, LOWERCASE_END
    ja 		.notLetters

    cmp 	sil, UPPERCASE_START
    jb		.notLetters
    cmp		sil, LOWERCASE_END
    ja		.notLetters
    
    ; Check if a and b is in range (90; 97) between letters
    cmp		dil, UPPERCASE_END
    ja		.checkABetween
    
    cmp		dil, UPPERCASE_END
    ja		.checkBBetween

    .checkBetweenPassed:
    ; Check if a and b are the same case
    cmp 	dil, UPPERCASE_END
    jbe 	.isBUppercase
    ja		.isBLowercase
	 
    .isBUppercase:
    cmp		sil, UPPERCASE_END
    jbe		.areSameCase
    ja		.notSameCase
	    
    .isBLowercase:
    cmp		sil, LOWERCASE_START
    jae 	.areSameCase
    jb 		.notSameCase
    
    .checkABetween:
    cmp		dil, LOWERCASE_START
    jb		.notLetters
    jmp		.checkBetweenPassed
    
    .checkBBetween:
    cmp		sil, LOWERCASE_START
    jb		.notLetters
    jmp		.checkBetweenPassed

    .notLetters:
    mov 	eax, -1
    ret
    
    .areSameCase:
    mov 	eax, 1
    ret
    
    .notSameCase:
    mov 	eax, 0
    ret
