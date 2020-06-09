#include<stdio.h>
#include<string.h>

int main()
{
	int n,m,q;
	long long int y;
	char N[30][30],M[30][30];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",N[i]);
	for(int i=0;i<m;i++) scanf("%s",M[i]);
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%lld",&y);
		printf("%s%s\n",N[(y-1)%n],M[(y-1)%m]);
	}
	return 0;
}