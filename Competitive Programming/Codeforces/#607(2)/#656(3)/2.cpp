#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[105];
bool ash[55];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < 2 * n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		for(int i = 1 ; i <= n ; i++)
			ash[i] = false;
		for(int i = 0 ; i < 2 * n ; i++){
			if( !ash[a[i]] ){
				ash[a[i]] = true;
				cout << a[i] << " ";
			}
		}
		cout << endl;
	}
	return(0);
}