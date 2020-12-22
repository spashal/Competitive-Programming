#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define mp make_pair
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		vector< ll > tt(n, 0), x(n, 0), cur(n, 0);
		ll ans = 0, prev = -2, dest = 0, reach = 0, flag = 0;
		for(int i = 0 ; i < n ; i++)
			cin >> tt[i] >> x[i];
		for(int i = 0 ; i < n ; i++){
			ll time;
			if( i > 0 ){
				if( reach < tt[i] )
					cur[i] = dest;
				else
					cur[i] = cur[i - 1] + flag * (tt[i] - tt[i - 1]);
			}
			if( prev == -2 )
				reach = tt[i];
			if( i > 0 and ( llabs(cur[i] - cur[i - 1]) == (llabs(cur[i] - x[i - 1]) + llabs(cur[i - 1] - x[i - 1]) ) ) )
				ans++;
			if( reach <= tt[i] ){
				if( x[i] <= dest )
					flag = -1;
				else
					flag = 1;
				dest = x[i];
				reach = tt[i] + llabs(cur[i] - x[i]);
				prev = i;
			}
			// cout << cur[i] << " " << reach << " " << prev << " " << ans << endl;
		}
		if( prev == n - 1 or (llabs(dest - cur[n - 1]) == (llabs(dest - x[n - 1]) + llabs(cur[n - 1] - x[n - 1]))) )
			ans++;
		cout << ans << endl;
	}
	return(0);
}