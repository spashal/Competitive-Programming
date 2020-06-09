#include<stdio.h>

int max(int a,int b)
{
	if(a>b) return a;
	return b;
}

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}

int main()
{
	int t,a,b,c,d,g,r;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d%d",&r,&b,&g);
		if(max(r,b)>max(b,g))
		{
			a=r;
			c=max(b,g);
			d=min(b,g);
		}
		else if(max(r,b)==b && max(b,g)==b)
		{
			a=b;
			c=max(r,g);
			d=min(r,g);
		}
		else
		{
			a=g;
			c=max(r,b);
			d=min(r,b);
		}
		if(a==c && c==d)
		{
			if(d%2==0)
				printf("%d\n",c+d/2);
				else printf("%d\n",1+3*(d-1)/2);
		}
		else if(a!=c && c!=d)
		{
			if(a-c>d) printf("%d\n",c+d);
			else 
			{
				int k1=a-d,k2=a-c;
				d=d-k2;
				if(d%2==0)
				printf("%d\n",k1+k2+d*3/2);
				else printf("%d\n",k1+k2+1+3*(d-1)/2);
			}
		}
		else
		{
		if(a==c)
			{
			if(d%2==0)
				printf("%d\n",c+d/2);
				else printf("%d\n",c-d+1+3*(d-1)/2);
			}
			else
			{
			
				if(2*c<=a) printf("%d\n",2*c);
				else
				{
					int k=a-d;
					d=d-k;
					if(d%2==0)
					printf("%d\n",2*k+3*d/2);
					else printf("%d\n",2*k+1+3*(d-1)/2);
				
				}
			}
	}
	}
	return 0;
}