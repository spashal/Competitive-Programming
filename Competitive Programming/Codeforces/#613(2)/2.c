#include<stdio.h>

int main()
{
	int t,e,n,f;
	long long int max[100005],maxy,s[100005],a[100005];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		maxy=1e17;
		maxy*=-1;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
			if(j>1)
			{
				s[j]=s[j-1]+a[j-1];
			}
			else if(j==1) s[j]=a[0];
			else s[0]=0;
		}
		s[n]=s[n-1]+a[n-1];
		max[n]=1e17;
		max[n]*=-1;
		for(int j=n-1;j>=0;j--)
		{
			if(max[j+1]<s[j+1]) max[j]=s[j+1];
			else max[j]=max[j+1];
	//		printf("#%lld ",max[j]);
		}
		e=0;
		f=0;
		for(int j=0;j<=n;j++) if(maxy<(max[j]-s[j])) maxy=(max[j]-s[j]);//printf("*%lld ",maxy);}
			for(int j=0;j<n;j++) if(s[n]==s[j]) e++;
			for(int j=1;j<n;j++) if(s[j]==0) f++;
		if((s[n]>maxy && s[n]>=0) || (max[0]==s[n] && maxy==s[n] && e+f==0 && s[n]>=0)) printf("YES\n");
		else printf("NO\n");
	//	printf("@%lld",maxy);
	}
	return 0;
}