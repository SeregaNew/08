#include<iostream>
using namespace std;

int main()
{
	int mas[]={1,1,1,3,4,4,4,4,4,6,6,8,8,8};
	int a,n=14, res;
	cin>>a;
	int first=0,end=n,mid=first+(end-first)/2;
	_asm
	{
Begin:
		mov eax,end
		cmp first,eax
		jg End
		
		mov ecx,mid
		mov eax,a
		cmp mas[ecx*4],eax
		jg More
		jl Less
		je Find
More:
		mov eax,mid
		mov end,eax
		jmp Next
////////////////////////////////////
Less:
		mov eax,mid
		mov first,eax
		inc first
		jmp Next
////////////////////////////////////
Find:
		mov ecx,mid
		mov eax,mas[ecx*4]
Similar:
		cmp mas[ecx*4-4],eax
		je Yes
		jmp No
Yes:
		dec ecx
		jmp Similar
No:
		mov res,ecx
		inc res
		jmp End
////////////////////////////////////
Next:
		mov eax,end
		cmp first,eax
		jge Mirror
		jmp Cont
Mirror:
		mov ecx,first
		mov res,ecx
		inc res
		jmp End
Cont:
		mov eax,end
		sub eax,first
		xor edx,edx
		mov ebx,2
		div ebx
		add eax,first

		mov mid,eax
		jmp Begin
End:

	}
	cout<<res;
}
