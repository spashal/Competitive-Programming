#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll a[100005], b[100005], c[100005], dp[4][2][100005], n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i] >> b[i] >> c[i];
	if( min( a[i], b[i], c[i]) == ( a[i] + b[i] + c[i]) - min( a[i], b[i], c[i]) - max( a[i], b[i], c[i])){
		dp[3][0] = min( a[i], b[i], c[i]);
		
	}
	return(0);
}