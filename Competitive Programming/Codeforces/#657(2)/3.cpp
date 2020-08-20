#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005], b[100005];
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m;
		ll maxi = -1 * INT_MAX, index = -1, ans = 0;
		vector< ll > ar;
		for(int i = 0 ; i < m ; i++){
			cin >> a[i] >> b[i];
			if( maxi < a[i] + (n - 1) * b[i] ){
				index = i;
				maxi = a[i] + (n - 1) * b[i];
			}
		}
		for(int i = 0 ; i < m ; i++)
			ar.pb(a[i]);
		ll left = n;
		bool cruel = false;
		sort(ar.begin(), ar.end(), greater< ll > ());
		for(int i = 0 ; left > 0 and i < m ; i++ ){
			if( cruel ){
				if( i <= m - 1 and ar[i] + (left - 1) * b[index] > left * b[index]){
					left--;
					ans += ar[i];
				}
				else{
					ans += left * b[index];
					left = 0;
					break;
				}
			}
			else if( left > 1 ){
				if( ar[i] != a[index] and ar[i] + a[index] + max(0ll, (left - 2) * b[index]) > a[index] + (left - 1) * b[index] ){
					left--;
					ans += ar[i];
				}
				else if( ar[i] == a[index] ){
					cruel = true;
					left--;
					ans += ar[i];
				}
				else {
					ans += a[index] + (left - 1) * b[index];
					left = 0;
					break;
				}
			}
			else{
				left--;
				ans += ar[i];
			}
			// cout << ans << " ";
		}
		if( left )
			ans += left * b[index];
		cout << ans << endl;
	}
	return(0);
}