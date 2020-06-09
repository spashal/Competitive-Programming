#include<stdio.h>
#include<string.h>

long long int max(long long int a,long long int b)
{
	if(a>b) return a;
	return b;
}
char s[1000005];
const long long int mod=1e9+7;
void ammend(int l,int len)
{
	if(s[l-1]>49)
	{
		for(int r=0;r<(s[l-1]-49);r++)
			for(int i=1;i<(len-l+1);i++) if((len-1+i+r*(len-l))<1e6+2) s[len-1+i+r*(len-l)]=s[l-1+i];
	}
}

int main()
{
	int t,x;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&x);
		scanf("%s",s);
		int k=strlen(s);
		long long int len=k;

		for(int l=1;l<=x;l++)
		{	
			if(len<x)	ammend(l,len);
			len=(len+(max(0,(len-l))*(s[l-1]-49))%mod)%mod;
		}
		printf("%lld\n",len);
	}
	return 0;
}