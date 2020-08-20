#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, h[200005], b[200005], dp[200005];

int main(){
	cin >> n;
	int base = 1;
	while( base <= n )
		base *= 2;
	vector< ll > tree(base * 2, 0);
	for(int i = 0 ; i < n ; i++)
		cin >> h[i];
	for(int i = 0 ; i < n ; i++)
		cin >> b[i];
	for(int i = 0 ; i < n ; i++){
		ll query = base + h[i];
		ll yet_best = 0;
		while( query > 1 ){
			if( query % 2 )
				yet_best = max(yet_best, tree[query - 1]);
			query /= 2;
		}
		dp[h[i]] = yet_best + b[i];
		for(int j = base + h[i] ; j > 0 ; j /= 2)
			tree[j] = max(tree[j], dp[h[i]]);
	}
	ll ans = 0;
	for(int i = 0 ; i <= n ; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return(0);
}