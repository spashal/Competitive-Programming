#include<stdio.h>

int n,arr[100005];

void pop()
{
	arr[n]=0;
	n--;
}

void push(int a)
{
	for(int i=n-1;i>=0;i--) arr[i+1]=arr[i];
	arr[0]=a;
	n++;
}

void printq()
{
	for(int i=0;i<n-1;i++) printf("%d ",arr[i]);
	printf("\n");
}

int main()
{
	int num,a;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&a);
		push(a);
		printq();
	}
	for(int i=0;i<num;i++)
	{
		pop();
		printq();
	}
	return 0;
}
