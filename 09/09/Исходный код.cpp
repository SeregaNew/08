#include<iostream>

int main()
{
	unsigned int a=12,b=18,sum=0;
	_asm
	{	
		mov eax,a
		mul b
		mov ecx,eax
L1:
		cmp a,0
		jle L2
		cmp b,0
		jle L2
		mov eax,a
		mov ebx,b
		cmp eax,ebx
		jle L3

		mov edx,0
		mov eax,a
		div b
		mov a,edx
		jmp L1
L3:
		mov edx,0
		mov eax,b
		div a
		mov b,edx
		jmp L1
L2:
		mov ebx,a
		add ebx,b

		mov eax,ecx
		mov edx,0
		div ebx
		mov sum,eax
	}
	std::cout<<sum;
}