; it isn't completed up to the end
.386 
PUBLIC @Check@8 
.model flat 
.code 
@Check@8 proc 
	mov edx,ecx

	mov esp,1
Begin:
	cmp esp,1
	jne Endd

	mov ecx,1
Pass:
	cmp ecx,82
	jge Second
	;push ecx

	mov eax,ecx
	dec eax
	mov ebx,9
	push edx
	div ebx
	pop edx
	mul ebx
	;inc eax

	mov esi,eax
Operate1:
	inc esi

	mov ebx,esi
	add ebx,9
	cmp esi,ebx
	jge Next1

	cmp ecx,esi
	je Operate1

	mov eax,esi
	mov ebx,82
	mul ebx

	cmp [eax*4+edx],0
	jle Operate1

	mov eax,esi
	mov ebx,82
	mul ebx
	mov ebx,[edx+eax*4]
	push ebx
	
	mov eax,ecx
	mov ebx,82
	mul ebx
	pop ebx
	add eax,ebx
	mov [eax*4+edx],0
	jmp Operate1

Next1:
	;;;;;;;;;;;;;;;;

	mov eax,ecx
	dec eax
	mov ebx,9
	push edx
	div ebx
	pop edx
	mul ebx

	mov ebx,eax
	mov eax,ecx
	sub eax,ebx

	mov esi,eax
	sub esi,9 
Operate2:
	add esi,9
	cmp esi,82
	jge Next2
	cmp ecx,esi
	je Operate2
	
	mov eax,esi
	mov ebx,82
	mul ebx
	cmp [eax*4+edx],0
	jle Operate2

	mov eax,esi
	mov ebx,82
	mul ebx
	mov eax,[edx+eax*4]

	push eax

	mov eax,ecx
	mov ebx,82
	mul ebx
	mov ebx,eax
	pop eax
	add eax,ebx
	mov [eax*4+edx],0
	jmp Operate2

Next2:
	mov eax,ecx
	dec eax
	mov ebx,9
	push edx
	div ebx
	pop edx
	mul ebx
	dec eax

	mov ebx,eax
	mov eax,ecx
	sub eax,ebx

	mov ebx,3
	push edx
	div ebx
	pop edx
	mul ebx
	inc eax
	push eax

	mov eax,ecx
	dec eax
	mov ebx,27
	push edx
	div ebx
	pop edx
	mul ebx
	mov ebx,eax
	pop eax
	add eax,ebx
	mov esi,eax
	dec esi

Operate3:
	inc esi
	mov ebx,ecx
	add ebx,3
	cmp ecx,ebx
	jge Next3
	mov edi,0

Operate3b:
	mov ebx,27
	cmp edi,ebx
	jge Operate3
	mov eax,esi
	add eax,edi
	cmp ecx,eax
	je Operate3b
	mov eax,esi
	add eax,edi
	mov ebx,82
	mul ebx
	mov eax,[eax*4+edx]
	cmp eax,0
	jle Operate3b

	mov eax,esi
	add eax,edi
	mul ebx
	mov eax,[eax*4+edx]

	push eax
	mov eax,ecx
	mul ebx
	mov ebx,eax
	pop eax
	add eax,ebx
	mov [eax*4+edx],0
	jmp Operate3

Next3:
	jmp Pass

Second:
	mov ecx,0

Start:
	inc ecx
	cmp ecx,82
	jge Endd
	mov eax,ecx
	mov ebx,82
	mul ebx
	cmp eax,0
	jne Start

	mov esi,0
	push esp
	;mov esp,0
Find1:
	cmp esi,10
	jge Next4
	mov eax,ecx
	mov ebx,82
	mul ebx
	add eax,esi
	cmp [eax*4+edx],1
	jne Next4
	mov esp,esi
Next4:

Endd:

  ret 
@Check@8 endp 
end 
