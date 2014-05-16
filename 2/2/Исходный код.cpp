#include<iostream>
using namespace std;

int main()
{
	char s[]="start abcD caabaad 12345 123456 00000000000001 end";
	int start=0,end=0,len=0;
	_asm
	{
		mov ecx,0
Begin:
		cmp s[ecx],0
		je Len

		inc ecx
		jmp Begin
Len:
		mov end,ecx
		mov len,ecx

///////////////

		mov ecx,0
Start:
		cmp s[ecx],' '
		je Find
		cmp s[ecx],0
		je Find
		jmp Next
Find:
		push ecx

		dec ecx
		mov end,ecx

		mov eax,end
		sub eax,start
		inc eax
		xor edx,edx
		mov ebx,2
		div ebx

		mov ecx,eax
Check:
		mov esi,start
		mov edi,end
		sub edi,ecx
		inc edi
		add esi,ecx
		dec esi
		mov al,s[esi]
		mov ah,s[edi]
		mov s[esi],ah
		mov s[edi],al
		loop Check

		pop ecx
		mov start,ecx
		inc start
Next:
		inc ecx
		cmp ecx,len
		jle Start
End:

	}
	cout<<s<<endl;
}