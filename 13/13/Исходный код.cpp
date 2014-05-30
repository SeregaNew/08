#include <iostream> 
 using namespace std;

extern "C"  int __fastcall Check(int[][10],int);
 
void main() 
{
	int mas[82][10];

	for(int i=1;i<82;i++)
		cin>>mas[i][0];
	cout<<endl;

	for(int i=1;i<82;i++)
		for(int j=1;j<10;j++)
			mas[i][j]=1;
	bool k=0;
	while(k)
	{
		k=Check(mas,1);
	}

	for(int i=1;i<82;i++)
	{
		cout<<mas[i][0]<<" ";
		if(i%9==0) cout<<endl;
	}
} 