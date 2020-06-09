#include<stdio.h>

int main()
{
	int t,h,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&h,&m);
		int a=23-h;
		int b=60-m;
		b+=a*60;
		printf("%d\n",b);
	}
	return 0;
}