#include<bits/stdc++.h>
using namespace std;

struct bruh
{
	int a;
	_Bool c[31];
	int w;
}t[100005];

int main()
{
	int
	cin>>n;
	for(int i=0;i<n;i++) cin>>t[i].a;
	b[0]=1;
	for(int i=0;i<29;i++) b[i+1]=b[i]*2;
	for(j=0;j<n;j++)
	{
		temp=t[i].a;
		for(int i=30;i>=0;i--)
		{
			if(temp/b[i])
			{
				t[j].c[i]=1;
				temp=temp/b[i];
			}
		}
	}
	for(j=30;j>=0;j--)
	{
		e=0;
		for(int i=0;i<n;i++)
		{
			if(t[i].c[j]) e++;
		}
		if(e) break;
	}
	if(j>1)
	{
		for(int r=0;r<n;r++)
		for(int i=0;i<=j;i++) t[r].w+=t[r].c[i]*b[i];
		sort(t,t+n);
	}
}