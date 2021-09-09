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
    ll tests = t;
	while( t-- ){
		cin >> n;
		ll ans = 0;
		ll root = sqrt((ll)2*n);
		for(ll i = 1 ; i <= root ; i++){
			if(((ll)2*n)%i == 0){
				ll temp = (((ll)2*n)/i);
				if(temp + 1 > i and (temp - i + 1) % 2 == 0){
					ans++;
				}
				if(i > temp - 1 and (i - temp + 1) % 2 == 0){
					ans++;
				}
			}
		}
		cout << "Case #" << tests-t << ": " << ans << endl;
	}
	return(0);
}