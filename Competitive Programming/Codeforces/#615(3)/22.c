#include<stdio.h>
#include<stdlib.h>

int a[10005][2];
char s[100005];

int main()
{
	int t,e,n,z,temp;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		z=0;
		e=0;
		s[0]='\0';
		scanf("%d",&n);
		for(int j=0;j<n;j++)
			scanf("%d%d",&a[j][0],&a[j][1]);
		for(int j=0;j<n-1;j++)
		{
			for(int k=0;k<(n-1);k++)
			{
				if(a[k][0]>=a[k+1][0] && a[k][1]>=a[k+1][1])
				{
					temp=a[k][0];
					a[k][0]=a[k+1][0];
					a[k+1][0]=temp;

					temp=a[k][1];
					a[k][1]=a[k+1][1];
					a[k+1][1]=temp;
				}
				
			}
		}

		for(int k=0;k<(a[0][0]);k++)
		{
			s[e]='R';
			e++;
		}
		for(int k=0;k<(a[0][1]);k++)
		{
			s[e]='U';
			e++;
		}

		for(int j=0;j<(n-1);j++)
		{
			for(int k=0;k<(a[j+1][0]-a[j][0]);k++)
			{
				s[e]='R';
				e++;
			}
			for(int k=0;k<(a[j+1][1]-a[j][1]);k++)
			{
				s[e]='U';
				e++;
			}
			if((a[j+1][1]-a[j][1])<0 || (a[j+1][0]-a[j][0])<0){z=1;break;}
		}
		s[e]='\0';
		if(z==1) printf("NO\n");
		else printf("YES\n%s\n",s);
	}
	return 0;
}