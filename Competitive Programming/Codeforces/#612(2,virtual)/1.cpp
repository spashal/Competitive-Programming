#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int t,l,y;
	char s[1000];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		char r[1000]={0};
		cin>>l>>s;
		for(y=0;strcmp(s,r)!=0;y++)
		{
			strcpy(r,s);			
			for(int j=l-2;j>=0;j--)
			{
				if(s[j]=='A') s[j+1]='A';
			}
		//	cout<<s<<'\n';
		}
		cout<<y-1<<'\n';
	}
}