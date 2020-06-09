#include<iostream>
using namespace std;

long long int po(int a)
{
	long long int b=1,c=10;
	while((--a)>=0) b*=c;
	return b;
}

int main()
{
	int t,n,h;
	long long int a,b,d;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>a;
		long long int k=po(n);
		long long int l=k*2+a;
		cout<<l<<endl;
		cin>>b;
		cout<<k-b<<endl;
		cin>>d;
		cout<<k-d<<endl;
		cin>>h;
		if(h==-1) return 0; 
	}
	return 0;
}