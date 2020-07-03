#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m, t, a[100005];
string n;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		cout << n[0];
		for(int i = 1 ; i < n.size() - 1 ; i+=2)
			cout << n[i];
		cout << n[n.size()-1] << endl;
	}
	return(0);
}