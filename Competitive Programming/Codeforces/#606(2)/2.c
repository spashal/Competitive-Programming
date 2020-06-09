#include<stdio.h>

int binarySearch(long int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
}

void merge(long int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    long int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0; 
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(long int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 


int main()
{
    long int a[200005];
    long long int ans=0;
    int n,t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        ans=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
            {
                scanf("%ld",&a[j]);
            }
        mergeSort(a,0,n-1);

        for(int j=n-1;j>-1;j--)
        {   
            if(j>0)
            {
                if(a[j]==a[j-1]);
                else
                {
                    if(a[j]%2==0)
                    {
                        if(binarySearch(a,0,j-1,a[j]/2)==-1)
                        {
                            int k=0;
                            while(a[j]%2==0 && a[j]!=0)
                            {
                                k++;
                                a[j]=a[j]/2;
                                if(binarySearch(a,0,j-1,a[j]/2)!=-1) break;
                            }
                            ans+=k;
                        }
                
                    else ans++;
                    }
                }
            }
            else if(j==0)
            while(a[0]%2==0 && a[0]!=0)
            {
                ans++;
                a[0]=a[0]/2;
            }
        }
        
        printf("%lld\n",ans);
    }
    return 0;
}