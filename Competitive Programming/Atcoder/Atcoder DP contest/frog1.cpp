#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, dp[100005], a[100005];
	cin >> n;
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i];
	dp[n-2] = llabs( a[n-2] - a[n-1]);
	dp[n-1] = 0;
	for( int i = n - 3 ; i > -1 ; i-- )
		dp[i] = min( dp[i+1] + llabs(a[i] - a[i+1]), dp[i+2] + llabs( a[i] - a[i+2]));
	cout << dp[0] << endl;
	return(0);
}