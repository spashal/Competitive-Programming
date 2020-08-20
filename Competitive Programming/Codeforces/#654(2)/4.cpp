#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[305][305], s[305];
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

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> m;
		if( m % n == 0 )
			cout << "0" << endl;
		else
			cout << "2" << endl;
		ll k;
		if( m % n == 0 )
			k = m / n;
		else
			k = m / n + 1;
		for(int i = 0 ; i < n ; i++){
			if( m % n > i or m % n == 0 )
				s[i] = k;
			else
				s[i] = k - 1;
			for(int j = 0 ; j < n ; j++)
				a[i][j] = 0;
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = i ; s[i] > j - i ; j++){
				a[i][j % n] = 1;
			}
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++)
				cout << a[i][j];
			cout << endl;
		}
	}
	return(0);
}