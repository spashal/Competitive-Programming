#include<stdio.h>
#include<string.h>

int main()
{
	int x,y,z,n,sum;
	char s[105];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		sum=0;
		x=0;
		y=0;
		z=0;
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;j++)
			{if(s[j]=='0')
			{
				x=1;
				break;
			}}
		for(int j=0;j<len;j++)
			{if((s[j]-48)%2==0)
			{
				y++;
			}}
		for(int j=0;j<len;j++) sum+=(s[j]-48);
			if(sum%3==0)
			{
				z=1;
			}
			if(x==1 && z==1 && y>1) printf("red\n");
			else printf("cyan\n");
	}
	return 0;
}