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
		ll p, f, cs, cw, s, w, ans = 0;
		cin >> p >> f >> cs >> cw >> s >> w;
		for(int a1 = 0 ; a1 <= cs and s * a1 <= p ; a1++){
			ll b1, b2, a2;
			b1 = min(cw, (p - s * a1) / w);

			b2 = min(cw - b1, f / w);
			a2 = min(cs - a1, (f - w * b2) / s);
			ans = max(ans, a1 + b1 + a2 + b2);

			a2 = min(cs - a1, f / s);
			b2 = min(cw - b1, (f - s * a2) / w);
			ans = max(ans, a1 + b1 + a2 + b2);
		}
		cout << ans << endl;
	}
	return(0);
}