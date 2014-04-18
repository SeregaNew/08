#include<iostream>

int main()
{
	int a,b,sum;
	std::cin>>a>>b;
	_asm
	{
		mov eax,a
		add eax,b
		mov sum,eax
	}
	std::cout<<sum;
}