#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld n, m, t, a[100005];
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

ll ceila(ld a){
	ll k = a;
	return k;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ld x, y, k;
		cin >> x >> y >> k;
		ll temp = 1;
		while( (ll)(k * (y + 1)) % temp == 0 )
			temp *= x;
		if( temp / x == k * (y + 1) ){
			cout << (temp - 1)/(x - 1) + k << endl;
			continue;
		}
		ld num = x, cost = 1, flag = 0;
		while( num < (k * (y + 1)) ){
			flag = 1;
			cost += num;
			num *= x;
		}
		if( flag )
		{
			num /= x;
			cost -= num;
		}
		cout << setprecision(0) << fixed << ceila(((k * (y + 1)) - num) / (x - 1)) + cost + k << endl;
	}
	return(0);
}