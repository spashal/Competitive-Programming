#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
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
		vector< ll > a(n, 0);
		ari;
		sort(a.begin(), a.end());
		vector< ll > :: iterator it;
		it = unique(a.begin(), a.end());
		a.resize(distance(a.begin(), it));
		bool flag = false;
		for(int i = 1 ; i < a.size() ; i++){
			if( a[i - 1] + 1 < a[i] )
				flag = true;
		}
		if( flag )
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return(0);
}