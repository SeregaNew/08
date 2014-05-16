#include<iostream>
using namespace std;

int main()
{
	/*int mas[][4]={{1,1,2,0},{2,2,0,3},{3,3,0,0}};
	int sum=0,n=3,m=4;*/

	int mas[][3]={{0,1,1},{1,3,4},{2,2,5},{3,3,3}};
	int sum=0,n=4,m=3;

	/*int mas[][3]={{1,1,1},{2,2,2},{3,3,3}};
	int sum=0,n=3,m=3;*/

	_asm
	{
		mov ecx,0
By_n:
		mov esi,0
By_m:
		cmp esi,ecx
		jge Addd
		jmp Skip
Addd:
		mov eax,m
		mul ecx
		add eax,esi
		mov eax,mas[eax*4]
		add sum,eax
Skip:
		inc esi
		cmp esi,m
		jl By_m
		inc ecx
		cmp ecx,n
		jl By_n

End:

	}
	cout<<sum;
}
