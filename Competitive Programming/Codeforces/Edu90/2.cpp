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
		int zero = 0, one = 0;
		cin >> n;
		for(int i = 0 ; i < n.size() ; i++)
			if( n[i] == '0' )
				zero++;
			else
				one++;
		if( min(zero, one) % 2 )
			cout << "DA" << endl;
		else
			cout << "NET" << endl;
		n.clear();
	}
	return(0);
}