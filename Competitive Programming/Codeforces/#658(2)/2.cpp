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
		ari;
		ll moves = 1;
		bool top = true;
		for(int i = 2 ; i <= n ; i++){
			if(  a[n - i] > 1 and top )
				moves+= 2;
			else if( a[n - i] == 1 and top ){
				if( i < n and a[n - i - 1] > 1 ){
					moves++;
					i++;
				}
				else if( i < n ){
					moves++;
					i++;
				}
				moves++;
			}
			else if( a[n - 1] > 1 )
				moves ++;
			else
				moves++;
		}
		if( moves % 2 )
			cout << "First" << endl;
		else
			cout << "Second" << endl;
	}
	return(0);
}