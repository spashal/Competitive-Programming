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
		if( n % 4 == 0 ){
			for(int i = 0 ; i < n - n / 4 ; i++)
				cout << "9";
			for(int i = 0 ; i < n / 4 ; i++)
				cout << "8";
			cout << endl;
		}
		else{
			for(int i = 0 ; i < n - 1 - n / 4 ; i++)
				cout << "9";
			for(int i = 0 ; i <= n / 4 ; i++)
				cout << "8";
				cout << endl;
		}
	}
	return(0);
}