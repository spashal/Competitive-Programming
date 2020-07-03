#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a, b;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	// ll fibo[100005];
	// fibo[0] = 0;
	// fib[1] = 1;
	// for(int i = 0 ; prev < 1000000009 ; i++){
	// 	fibo[i] = fibo[i-2] + fibo[i-1];
	// }
	cin >> t;
	while( t-- ){
		int i = 0;
		cin >> a >> b >> n;
		// if( max(a, b))
		for(i = 0 ; max(a, b) <= n ; ){
			if( a < b )
				a += b;
			else
				b+= a;
			// cout << max(a, b) << " ";
			i++;
		}
		cout << i << endl;
	}
	return(0);
}