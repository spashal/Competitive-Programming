#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
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
		ll k;
		cin >> n >> m >> k;
		// vector<int> x(n), y(m);
		vector<pair<ll,ll> > p(k, mp(0, 0));
		unordered_map<ll, ll> kk, kk2;
		vector<ll> pari1, pari2;
		ll ans = 0;
		set<int> x, y;
		for(int i = 0 ; i < n ; i++){
			cin >> a[0];
			x.insert(a[0]);
		}
		for(int i = 0 ; i < m ; i++){
			cin >> a[0];
			y.insert(a[0]);
		}
		pari1.resize(x.size(), 0);
		pari2.resize(y.size(), 0);
		for(int i = 0 ; i < k ; i++){
			cin >> p[i].ff >> p[i].ss;
			if(x.find(p[i].ff) == x.end()){
				ll index = distance(x.begin(), x.upper_bound(p[i].ff))-1;
				kk2[index + (1000000)*p[i].ss] += 1;
				ans -= kk2[index + (1000000)*p[i].ss] - 1;
				pari1[index] += 1;
			}
			if(y.find(p[i].ss) == y.end()){
				ll index = distance(y.begin(), y.upper_bound(p[i].ss))-1;
				kk[index + (1000000)*p[i].ff] += 1;
				ans -= kk[index + (1000000)*p[i].ff] - 1;
				pari2[index] += 1;
			}
		}
		for(int i = 0 ; i < x.size() ; i++)
			ans += (pari1[i]*(pari1[i]-1))/2;
		for(int i = 0 ; i < y.size() ; i++)
			ans += (pari2[i]*(pari2[i]-1))/2;
		cout << ans << endl;
	}
	return(0);
}