#include<bits/stdc++.h>

int main()
{
	int
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		max[i]=0;
		for(int j=0;j<m;j++)
		{
			cin>>a;
			if(a>max[i]) max[i]=a;
		}
	}
	for(int i=0;i<n;i++)
		if(max1<max[i])
		{
			max1=max[i];
			max1i=i;
		}

	for(int i=0;i<n;i++)
	{
		if(i!=max1i && max2<max[i])
		{
			max2=max[i];
			max2i=i;
		}
	}
}