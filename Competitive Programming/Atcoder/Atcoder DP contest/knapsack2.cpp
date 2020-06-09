#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, W, w[105], v[105],dp[100005];
	cin >> n >> W;
	for( int i = 0 ; i < 100005 ; i++ )
		dp[i] = 1000000000000;
	for( int i = 0 ; i < n ; i++ )
		cin >> w[i] >> v[i];
	dp[0] = 0;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 100000 - v[i] ; j > -1 ; j-- )
			dp[j+v[i]] = min(dp[j]+w[i], dp[j+v[i]]);
	for( int j = 100000 ; j > -1 ; j-- )
		if( dp[j] <= W ){
			cout << j << endl;
			break;
		}
	return(0);
}