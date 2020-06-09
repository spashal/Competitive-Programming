#include <bits/stdc++.h>
using namespace std;
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
typedef long long int ll;

int main(){
	ll n, k, a[100005], dp[100005];
	cin >> n >> k;
	ari;
	dp[n-1] = 0;
	for( int i = n - 2 ; i > max(n - k - 2,(ll) -1) ; i-- ){
		dp[i] = 10000000000;
		for( int j = i + 1 ; j < n ; j++ ){
			dp[i] = min( dp[j] + llabs(a[i]-a[j]), dp[i]);
		}
	}
	for( int i = n - k - 2 ; i > -1 ; i-- ){
		dp[i] = 10000000000;
		for( int j = i + 1 ; j < i + k + 1 ; j++ )
			dp[i] = min( dp[j] + llabs( a[i] - a[j]), dp[i]);
	}
	cout << dp[0] << endl;
	return(0);
}