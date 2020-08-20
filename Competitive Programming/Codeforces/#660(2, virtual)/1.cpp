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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		if( n >= 31 ){
			cout << "Yes" << endl;
			if( n == 36 )
				cout << "6 10 15 5" << endl;
			else if( n == 40 )
				cout << "6 10 15 9" << endl;
			else if( n == 44 )
				cout << "6 10 15 13" << endl;
			else
				cout << "6 10 14 " << n - 30 << endl;
		}
		else
			cout << "No" << endl;
	}
	return(0);
}