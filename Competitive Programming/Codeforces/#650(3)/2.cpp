#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		int one = 0, two = 0;
		for(int i = 0 ; i < n ; i++)
			if( i % 2 != a[i] % 2 ){
				if( i % 2 )
					one++;
				else
					two++;
			}
		if( one == two )
			cout << two << endl;
		else
			cout << "-1" << endl;
	}
	return(0);
}