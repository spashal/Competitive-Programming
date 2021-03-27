#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, aa[200005];
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
		ll a, b;
		cin >> n >> m >> a >> b;
		for(int i = 0 ; i < m ; i++)
			cin >> aa[i];
		ll maxT;
		if( a > b )
			maxT = n - a + llabs(a - b) - 1;
		else
			maxT = a + llabs(a - b) - 1;
		ll tame = 1, ctr = 0;
		// cout << maxT << " & \n";
		sort(aa, aa + m, greater< ll > ());
		for(int i = 0 ; i < m ; i++)
			if( maxT >= aa[i] + tame ){
				tame++;
				ctr++;
			}
		cout << ctr << endl;
	}
	return(0);
}