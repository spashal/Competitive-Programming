#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
string s;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> s;
		int n  = s.size();
		ll ans = 0;
		ll cur = 0;
		for(int i = 0 ; i < n ; i++){
			if( s[i] == '+' )
				cur++;
			else{
				cur--;
				if( cur < 0 ){
					cur = 0;
					ans += i + 1;
				}
			}
			ans++;
			// cout << ans << " ";
		} 
		cout << ans << endl;
		s.clear();
	}
	return(0);
}