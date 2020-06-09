#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int gcd(int a,int b)
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}

int min(int a,int b)
{
	if(a>b) return b;
	return a;
}
	int d[1005],b[1005];

int main()
{
	int r,c,z,k=0,temp,f;
	scanf("%d%d",&r,&c);

	for(int i=2;i<r+c+1;i++)
	{
		int s=sqrt(i);
		z=0;
		for(int j=2;j<=s;j++)
			if(i%j==0)
				{
					z=1;
					break;
				}
		if(z==0)
		{
			b[k]=i;
			d[i]=1;
			k++;
		}
	}

	if(k<min(r,c))
	{
		for(int i=1;i<=r+c;i++)
		{
			if(d[i]==0)
			{
				for(int j=0;j<k;j++)
				{
					if(gcd(d[i],b[j])!=1)
					{
						z=2;
						break;
					}
					if(z!=2)
					{
						b[k]=i;
						k++;
					}
				}
			}
		}
		if(k<min(r,c))
		{
			for(int i=0;i<r;i++) b[i]=i+2;
			for(int i=0;i<c;i++) b[i+r]=i+r+2;
		}
		else
		{
			int y=r+c-min(r,c);
			f=1;
			for(int i=k;i<r+c;i++)
			{
				for(;f<=r+c;f++)
					if(d[f]==0)
					{
						b[i]=i;
						d[i]=1;
						break;
					}
			}
			if(c==min(r,c))
			{
				for(int i=0;i<c;i++)
				{
					temp=b[i];
					b[i]=b[r+c-i-1];
					b[r+c-i-1]=temp;
				}
			}
		}
	}

	else
	{
		for(int i=1;i<=r+c;i++)
		{
			if(d[i]==0)
			{
				b[k]=i;
				k++;
			}
		}
	}
//	for(int i=0;i<r+c;i++) printf("%d ",b[i]);printf("\n");
	if(r==1 && c==1) printf("0\n");
	else
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++) printf("%d ",b[i]*b[r+j]);
			printf("\n");
	}
	return 0;

}