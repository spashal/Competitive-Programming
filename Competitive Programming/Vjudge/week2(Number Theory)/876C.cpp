#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

int digitSum(ll k){
	ll sum = 0;
	while( k ){
		sum += k % 10;
		k /= 10;
	}
	return sum;
}

int main(){
	cin >> n;
	vector< ll > ans;
	for(ll i = max(0ll, n - 81) ; i <= n ; i++)
		if( i + digitSum(i) == n )
			ans.pb(i);
	cout << (int)ans.size() << endl;
	if( !ans.empty() ){
		for(int i = 0 ; i < ans.size() ; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return(0);
}