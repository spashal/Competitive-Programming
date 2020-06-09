#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;

int main(){
	cin >> t;
	while( t-- ){
		ll x, z = 0;
		cin >> n >> x;
		if( n == 1 )
			cout << "Ayush" << endl;
		else{
		vector< ll > adj[n+1];
		for( ll i = 0 ; i < n - 1 ; i++ ){
			ll u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for( ll i = 1 ; i <= n ; i++ )
			if( (ll)adj[i].size() == 1 and i == x ){
				cout << "Ayush" << endl;
				z = 1;
				break;
			}
		if( z != 1 ){
			if( n % 2 == 0 )
				cout << "Ayush" << endl;
			else
				cout << "Ashish" << endl;
		}
	}
	}
	return(0);
}