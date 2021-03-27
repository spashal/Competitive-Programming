#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[300005];
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
		ari;
		ll ans = 0;
		vector< ll > cc;
		bool found = false;
		for(int i = 1 ; i < n - 1 ; i++)
			if( a[i] != a[i - 1] and a[i] != a[i + 1] and ((a[i] - a[i - 1])/llabs(a[i] - a[i - 1]) * (a[i] - a[i + 1])/llabs(a[i] - a[i + 1])) > 0 )
				cc.pb(i);
		
		ans = cc.size();
		for(int i = 0 ; i < (ans - 2) ; i++){
			if( cc[i] + 1 == cc[i + 1] and cc[i + 1] + 1 == cc[i + 2] ){
				ans -= 3;
				found = true;
				break;
			}
		}
		if( !found )
			for(int i = 0 ; i < ans - 1 ; i++)
				if( cc[i] + 1 == cc[i + 1] ){
					if( cc[i] > 1 and a[cc[i] - 2] != a[cc[i] - 1] and cc[i + 1] < n - 2 and a[cc[i + 1] + 1] != a[cc[i + 1] + 2] and (a[cc[i]] - a[cc[i] + 2]) != 0 and (a[cc[i] - 1] - a[cc[i] + 1]) != 0 and (((a[cc[i]] - a[cc[i] + 2])/llabs(a[cc[i]] - a[cc[i] + 2])) * (a[cc[i] - 1] - a[cc[i] + 1])/llabs(a[cc[i] - 1] - a[cc[i] + 1])) > 0 )
						continue;
					ans -= 2;
					found = true;
					break;
				}
		if( !found and ans > 0 )
			ans -= 1;
		cout << ans << endl;
	}
	return(0);
}