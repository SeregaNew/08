#include <iostream>

using namespace std;

int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	int temp=0, up=1, down=1, current=1, temp_down=0, result=1;
	_asm
	{
		mov ecx,n
L1:
		mov temp,0
		mov up,1
		mov down,1

		push ecx
				
		mov eax,ecx
		mov ebx,2
		imul ebx
		add eax,1

		mov ecx,eax
L2:
		mov eax,up
		imul x
		mov up,eax
		loop L2

		pop ecx
		mov eax,ecx
		push ecx

		mov ecx,eax
L3:
		mov temp_down,0
		push ecx

L4:
		mov current,1
		push ecx
L5:
		mov eax,current
		imul y
		mov current,eax
		loop L5

		mov eax,current
		add temp_down,eax
		pop ecx
		loop L4

		mov eax,down
		imul temp_down
		mov down,eax
		
		jmp Lnext

Ltemp:
		jmp L1
Lnext:
		pop ecx
		loop L3

		mov eax,up
		mov edx,0
		idiv down
		mov temp,eax

		pop ecx
		mov eax,ecx
		mov ebx,2
		mov edx,0 
		idiv ebx
		
		cmp edx,0
		jne Compare

		jmp Contin

Compare:
		mov eax,temp
		mov ebx,-1
		imul ebx
		mov temp,eax

Contin:
		add temp,1
		mov eax,result
		imul temp
		mov result,eax
		loop Ltemp
	}
	cout<<result;
}