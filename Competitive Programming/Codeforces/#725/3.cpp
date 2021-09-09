#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
vector< ll > a;
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
		ll l, r;
		cin >> n >> l >> r;
		a.resize(n, 0);
		ari;
		set< ll > st;
		sort(a.begin(), a.end());
		vector<ll> :: iterator ub, lb;
		ll ans = 0;
		for(int i = 0 ; i < n ; i++){
			if(a[i] > r)
				break;
			ub = upper_bound(a.begin(), a.end(), r-a[i]);
			lb = lower_bound(a.begin(), a.end(), l-a[i]);
			if(ub != a.end()){
				ans += distance(lb, ub);
				if(2*a[i] <= r and l <= 2*a[i])
					ans--;
			}
			else{
				ans += distance(lb, ub);
				if(2*a[i] <= r and l <= 2*a[i])
					ans--;
			}
		}
		a.clear();
		cout << ans/2 << endl;
	}
	return(0);
}